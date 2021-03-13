set(SERVER_DESTINATION ${CMAKE_SOURCE_DIR}/bin/server)

include_directories(${ZMQ_INCLUDE})
link_directories(${ZMQ_LIB})

add_executable(server server.c)

target_link_libraries(server PUBLIC libzmq-v141-mt-4_3_2)

install(TARGETS server DESTINATION ${SERVER_DESTINATION})
install(FILES ${ZMQ_DRIVERS} DESTINATION ${SERVER_DESTINATION}) 