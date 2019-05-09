cmake_minimum_required(VERSION 3.8)


set(PROJECT_NAME word_elemination_3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.12.0\\5.12.0\\mingw73_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

include(client/QtAwesome/CMakeLists.txt)
list(APPEND HEADER_FILESC
        client/forms/initialform.h
        utils/user.h
        utils/challenge.h
        client/clientcommon.h
        client/localconnect.h
        client/forms/userhomeform.h
        client/forms/addwordform.h
        client/forms/playform.h
        client/forms/listusersform.h
        client/clientcommon.h
        utils/macrodef.h
    )
list(APPEND SOURCE_FILESC
        word_elemination.rc
        client/main.cpp
        client/forms/initialform.cpp
        utils/user.cpp
        utils/challenge.cpp
        client/clientcommon.cpp
        client/localconnect.cpp
        client/forms/userhomeform.cpp
        client/forms/addwordform.cpp
        client/forms/playform.cpp
        client/forms/listusersform.cpp
        client/clientcommon.cpp
    )
list(APPEND HEADER_FILESS
        server/auth.h
        utils/user.h
        utils/challenge.h
        server/serverconnect.h
        server/servercommon.h
        server/ConnManager.h
        utils/macrodef.h
        server/server.h
    )

list(APPEND SOURCE_FILESS
        word_elemination.rc
        server/auth.cpp
        utils/user.cpp
        utils/challenge.cpp
        server/serverconnect.cpp
        server/servercommon.cpp
        server/ConnManager.cpp
        server/server.cpp
        )

list(APPEND UI_FILES
        initialform
        userhomeform
        addwordform
        playform
        listusersform
        )
list(APPEND RESOURCE_FILESC
        qdarkstyle/style.qrc
        )
message(${RESOURCE_FILESC})
# Set non-Debug build as GUI application.
# Debug build remains consle application.
if(NOT CMAKE_BUILD_TYPE MATCHES Debug) #Release, RelWithDebInfo and MinSizeRel
    if(WIN32) # Check if we are on Windows
#        set(SYSTEM_TYPE WIN32 utils/sigmoid.h)
    elseif(APPLE) # MacOS X
#        set(SYSTEM_TYPE MACOSX_BUNDLE utils/sigmoid.h)
    else() # UNIX
#        set(SYSTEM_TYPE)
    endif()
    message("System type is" ${SYSTEM_TYPE})
endif()
file(REMOVE "client/forms/uicall.cmd")
foreach(VFILE IN LISTS UI_FILES)
#    add_custom_command(OUTPUT ui_${VFILE}.h
#            COMMAND uic ${VFILE}.ui
#            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/forms
#            )
#    message(${VFILE})
    file(APPEND "client/forms/uicall.cmd" "uic.exe ${PROJECT_SOURCE_DIR}/client/forms/${VFILE}.ui -o ${PROJECT_SOURCE_DIR}/client/forms/ui_${VFILE}.h\n")
#    execute_process(COMMAND echo uic.exe ${PROJECT_SOURCE_DIR}/forms/${VFILE}.ui -o ${PROJECT_SOURCE_DIR}/forms/ui_${VFILE}.h >> forms/uicall.cmd)
endforeach()
add_executable(${PROJECT_NAME}_client ${SYSTEM_TYPE} ${SOURCE_FILESC} ${RESOURCE_FILESC})
add_executable(${PROJECT_NAME}_server ${SYSTEM_TYPE} ${SOURCE_FILESS})
#add_executable(client tcptest/client.cpp)
target_link_libraries(${PROJECT_NAME}_client Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL Qt5::Network)
target_link_libraries(${PROJECT_NAME}_server Qt5::Network Qt5::Core)
#target_link_libraries(client Qt5::Network Qt5::Core)