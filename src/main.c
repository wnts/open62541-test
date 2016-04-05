#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


#include "ua_types.h"
#include "ua_server.h"
#include "logger_stdout.h"
#include "networklayer_tcp.h"
#include "namespace_init.h"

#include "temperature.h"
#include "logger.h"

#define  I2C_BUS    "/dev/i2c-2"

void createTemperatureSensorNode(UA_Server * pServer);



UA_Boolean running = UA_TRUE;
/**
 * NodeIds for our TemperatureSensorType object and its member variable.
 */
UA_NodeId g_TemperatureSensor1NodeId;
UA_NodeId g_TemperatureSensor1TemperatureNodeId;
int i2c_fd;

static void stopHandler(int signal)
{
	printf("Received Ctrl-C\n");
	running = 0;
}

// open i2c bus for reading temp sensor
static void datasources_init(void)
{
    if((i2c_fd = open(I2C_BUS, O_RDWR)) < 0)
        perror("Error opening i2c bus");
}

UA_StatusCode temperature_sensor_read(void * handle, const UA_NodeId node_id, UA_Boolean source_timestamp,
									  const UA_NumericRange *range, UA_DataValue * data_value)
{
	UA_DateTime sourceTimestamp = UA_DateTime_now();
    int result = 0;
    if(i2c_fd < 0)
        return UA_STATUSCODE_BADNOTREADABLE;
    if(!temperature_get(i2c_fd, CONVERSION_CURRENT, &result))
    	return UA_STATUSCODE_BADNOTREADABLE;
    data_value->hasValue = true;
    data_value->hasSourceTimestamp = true;
    data_value->hasServerTimestamp = true;
    data_value->sourceTimestamp = sourceTimestamp;
	UA_Variant_setScalarCopy(&data_value->value, &result, &UA_TYPES[UA_TYPES_INT32]);
	return UA_STATUSCODE_GOOD;
}

void createNodes(UA_Server * pServer)
{
	// populate address space with our types (automatically generated, see open62541-notes.txt)
	namespace_init(pServer);
	// create our temperature sensor object
	createTemperatureSensorNode(pServer);
	// create the object for testing events
}




/*
 *  Create instance of TemperatureSensorType.
 *  This is pretty tedious, as described in open62541-notes.txt
 *  Maybe I can also implement my FreeOpcUa high-level wrapper on top of open62541?
 */
void createTemperatureSensorNode(UA_Server * pServer)
{



	UA_ObjectAttributes ObjAttr = { .displayName = UA_LOCALIZEDTEXT("", "TemperatureSensor1"),
									.description = UA_LOCALIZEDTEXT("", "Beaglebone Grove Temperature Sensor") };
	// Create the object
	// We explictly pass no type with this function because this hasn't the intended effect (it doesn't "instantiate" the whole object for you)
	// If we'd pass the NodeId of TemperatureSensorType with this function, it will create the object, as well
	// as its member variables. It won't however, create HasTypeDefinition references on the member variables, or create its properties.
	g_TemperatureSensor1NodeId = UA_NODEID_STRING(1, "TemperatureSensor1");
	UA_Server_addObjectNode(pServer,
							g_TemperatureSensor1NodeId,						// requested NodeId for the new object
							UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),	// Parent node of the new object
							UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),		// reference between parent and new object (child)
							UA_QUALIFIEDNAME(1, "TemperatureSensor1"),		// Browsename
							UA_NODEID_NULL,									// NodeId of object type
							ObjAttr,										// attributes for the new object
							NULL,											// (optional) instantiation callback
							NULL);											// (optional) pointer to variable receiving actual nodeid

	// add a HasTypeDefinition reference to TemperatureSensor1 object
	UA_Server_addReference(pServer,
						   g_TemperatureSensor1NodeId,										// NodeId of source
						   UA_NODEID_NUMERIC(0, UA_NS0ID_HASTYPEDEFINITION),				// NodeId of ReferenceType
						   UA_EXPANDEDNODEID_NUMERIC(1, UA_NS1ID_TEMPERATURESENSORTYPE),	// NodeId of target
						   UA_TRUE);														// isForward

	// add Temperature member variable to TemperatureSensor1 object
	// Unlike with an object, we do pass the type with this function, because it has the intended effect.
	// The addVariableNode will also create the correct properties of the variable.
	UA_VariableAttributes VarAttr;
	UA_VariableAttributes_init(&VarAttr);
	UA_Int32 initialTemperature = 0;
	UA_Variant_setScalar(&VarAttr.value, &initialTemperature, &UA_TYPES[UA_TYPES_DOUBLE]);
	VarAttr.displayName = UA_LOCALIZEDTEXT("", "Temperature");
	g_TemperatureSensor1TemperatureNodeId = UA_NODEID_STRING(1, "TemperatureSensor1_Temperature");
	UA_DataSource TemperatureSensor1TemperatureDataSource = { .handle = NULL,
															  .read = temperature_sensor_read,
															  .write = NULL };

	UA_Server_addVariableNode(pServer,
							  g_TemperatureSensor1TemperatureNodeId,
							  g_TemperatureSensor1NodeId,
							  UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
							  UA_QUALIFIEDNAME(1, "Temperature"),
							  UA_NODEID_NUMERIC(0, UA_NS0ID_ANALOGITEMTYPE),
							  VarAttr,
							  NULL,
							  NULL);

	// Connect datasource to the Temperature variable of TemperatureSensor1
	UA_Server_setVariableNode_dataSource(pServer, g_TemperatureSensor1TemperatureNodeId, TemperatureSensor1TemperatureDataSource);


}

int main(void)
{

	signal(SIGINT, stopHandler);

	// create server config
	UA_ServerConfig server_config = UA_ServerConfig_standard;
	// create network layer
	UA_ServerNetworkLayer network_layer = UA_ServerNetworkLayerTCP(UA_ConnectionConfig_standard, 16664);

	// configure server with newly created network layer
	server_config.logger = Logger;
	server_config.networkLayers = &network_layer;
	server_config.networkLayersSize = 1;

	// create server
	UA_Server * server = UA_Server_new(server_config);

	// populate address space
	createNodes(server);

	// start server
	datasources_init();
	UA_Server_run(server, &running);
	UA_Server_delete(server);


    return 0;
}
