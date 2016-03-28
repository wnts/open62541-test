/*
 * server.h
 *
 *  Created on: Mar 16, 2016
 *      Author: wouter
 */

#ifndef SRC_SERVER_H_
#define SRC_SERVER_H_
#include "ua_server.h"

UA_StatusCode temperature_sensor_read(void * handle, const UA_NodeId node_id, UA_Boolean source_timestamp,
									  const UA_NumericRange *range, UA_DataValue * datavalue);


#endif /* SRC_SERVER_H_ */
