project(Selective)

add_executable(datalink datalink.c protocol.c lprintf.c crc32.c getopt.c)
target_link_libraries(datalink m)
if(WIN32)
    target_link_libraries(datalink wsock32 ws2_32)
endif()