/* WARNING: This is a generated file.
 * Any manual changes will be overwritten.

 */
#include "namespace_init.h"
#include "server.h"
UA_INLINE void namespace_init(UA_Server *server) {

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=1;i=1002), 1:TemperatureSensorType
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "TemperatureSensorType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 1002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "TemperatureSensorType");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=1002/1:TemperatureSensorType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=1;i=6001), 1:Temperature
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Temperature");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_Double opcua_node_variable_t_ns_1_i_6001_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar( &attr.value, &opcua_node_variable_t_ns_1_i_6001_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
UA_Double_deleteMembers(&opcua_node_variable_t_ns_1_i_6001_variant_DataContents);
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6001);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 1002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Temperature");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6001), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 2368), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6001), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6001/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6003), EngineeringUnits
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6003);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EngineeringUnits");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6003), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 80), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6003), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6001/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6002), EURange
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6002);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EURange");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6002), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6001/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6004), InstrumentRange
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "InstrumentRange");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6004);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "InstrumentRange");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6004), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 80), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6004), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6001/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6005), ValuePrecision
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "ValuePrecision");
attr.description = UA_LOCALIZEDTEXT("", "The maximum precision that the server can maintain for the item based on restrictions in the target environment.");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6005);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "ValuePrecision");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6005), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 80), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6005), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: i=85/Objects using i=35/Organizes
// Node: opcua_node_object_t(ns=1;i=5002), 1:TemperatureSensor1
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "TemperatureSensor1");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 5002);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 85);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 35);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "TemperatureSensor1");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 5002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(1, 1002), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=5002/1:TemperatureSensor1 using i=47/HasComponent
// Node: opcua_node_variable_t(ns=1;i=6006), 1:Temperature
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Temperature");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_Double opcua_node_variable_t_ns_1_i_6006_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar( &attr.value, &opcua_node_variable_t_ns_1_i_6006_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
UA_Double_deleteMembers(&opcua_node_variable_t_ns_1_i_6006_variant_DataContents);
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6006);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 5002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Temperature");
const UA_DataSource temperature_sensor_datasource = { .handle = NULL, .read = temperature_sensor_read, .write = NULL };
UA_Server_addDataSourceVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, temperature_sensor_datasource, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6006), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 2368), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6006/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6008), EngineeringUnits
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6008);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6006);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EngineeringUnits");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6008), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6006/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6007), EURange
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6007);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6006);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EURange");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6007), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=1;i=6006/1:Temperature using i=46/HasProperty
// Node: opcua_node_variable_t(ns=1;i=6009), InstrumentRange
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "InstrumentRange");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(1, 6009);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(1, 6006);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "InstrumentRange");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(1, 6009), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);
}
