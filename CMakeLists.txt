cmake_minimum_required(VERSION 3.19)
project(zero)

set(ZMQ_LIB ${CMAKE_SOURCE_DIR}/zmq/lib)
set(ZMQ_INCLUDE ${CMAKE_SOURCE_DIR}/zmq/include)
set(ZMQ_DRIVERS ${ZMQ_LIB}/libsodium.dll ${ZMQ_LIB}/libzmq-v141-mt-4_3_2.dll)

add_subdirectory(server)
add_subdirectory(client)