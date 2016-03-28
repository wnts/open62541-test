#include <stdio.h>
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

#define  I2C_BUS    "/dev/i2c-2"



UA_Boolean running = UA_TRUE;
UA_Logger logger = Logger_Stdout;
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




int main(void)
{

	signal(SIGINT, stopHandler);

	// create server config
	UA_ServerConfig server_config = UA_ServerConfig_standard;
	// create network layer
	UA_ServerNetworkLayer network_layer = UA_ServerNetworkLayerTCP(UA_ConnectionConfig_standard, 16664);

	// configure server with newly created network layer
	server_config.logger = Logger_Stdout;
	server_config.networkLayers = &network_layer;
	server_config.networkLayersSize = 1;

	// create server
	UA_Server * server = UA_Server_new(server_config);
    namespace_init(server);

    // initialize datasources
    datasources_init();




	// start server
	UA_Server_run(server, &running);
	UA_Server_delete(server);


    return 0;
}
