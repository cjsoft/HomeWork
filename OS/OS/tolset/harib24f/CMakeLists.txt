cmake_minimum_required(VERSION 3.14)
project(OS_race_condition)
aux_source_directory(${PROJECT_SOURCE_DIR} SRCS)
add_custom_target(${PROJECT_NAME} COMMAND mingw32-make -C ${PROJECT_SOURCE_DIR} default
        CLION_EXE_DIR=${PROJECT_BINARY_DIR}
        DEPENDS ${SRCS}
        )
add_executable(dumb ${SRCS})