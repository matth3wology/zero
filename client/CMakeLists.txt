set(CLIENT_DESTINATION ${CMAKE_SOURCE_DIR}/bin/client)

include_directories(${ZMQ_INCLUDE})
link_directories(${ZMQ_LIB})

add_executable(client client.c)

target_link_libraries(client PUBLIC libzmq-v141-mt-4_3_2)


install(TARGETS client DESTINATION ${CLIENT_DESTINATION})
install(FILES ${ZMQ_DRIVERS} DESTINATION ${CLIENT_DESTINATION}) 