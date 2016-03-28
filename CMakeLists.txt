cmake_minimum_required(VERSION 2.8)

project(open62541-test C)

aux_source_directory(src SRC_LIST)

#include_directories(SYSTEM /opt/arm-linux-gnueabihf/usr/local/include)

set (EXE_NAME open62541-test-server)
add_executable(${EXE_NAME} ${SRC_LIST})

find_library(LIBOPEN62541 open62541)
find_path(VAR ${OPEN62541_INCLUDE_DIR} open62541)
include_directories(${OPEN62541_INCLUDE_DIR})
include_directories(${CMAKE_FIND_ROOT_PATH}/usr/local/include/open62541)

target_link_libraries(${EXE_NAME} m ${LIBOPEN62541})


