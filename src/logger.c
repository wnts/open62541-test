#include <stdio.h>
#include <stdarg.h>

#include "logger.h"

#include "ua_types.h"
#include "ua_types_generated.h"
#include "ua_log.h"


const char *LogLevelNames[6] = {"trace", "debug", "info", "warning", "error", "fatal"};
const char *LogCategoryNames[6] = {"network", "channel", "session", "server", "client", "userland"};


/**
 * Custom logger function, based on Logger_Stdout from the open62541 library itself (src_extra/logger_stdout.c)
 * This one doesn't write network related messages to the stdout because
 * they tend to clutter everything else.
 */
void Logger(UA_LogLevel level, UA_LogCategory category, const char *msg, ...) {
	if(category == UA_LOGCATEGORY_NETWORK)
		return;
	UA_String t = UA_DateTime_toString(UA_DateTime_now());
    printf("[%.23s] %s/%s\t", t.data, LogLevelNames[level], LogCategoryNames[category]);
	UA_ByteString_deleteMembers(&t);
    va_list ap;
    va_start(ap, msg);
    vprintf(msg, ap);
    va_end(ap);
    printf("\n");
}
