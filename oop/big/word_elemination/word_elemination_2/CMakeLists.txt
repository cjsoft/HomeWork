cmake_minimum_required(VERSION 3.8)


set(PROJECT_NAME word_elemination_2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.12.0\\5.12.0\\mingw73_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5RemoteObjects REQUIRED)
include(QtAwesome/CMakeLists.txt)
list(APPEND HEADER_FILES
        forms/initialform.h
        auth.h
        user.h
        challenge.h
        common.h
        localconnect.h
        serverconnect.h
        forms/userhomeform.h
        forms/addwordform.h
        forms/playform.h
        forms/listusersform.h
        macrodef.h
    )

list(APPEND SOURCE_FILES
        word_elemination.rc
        main.cpp
        forms/initialform.cpp
        auth.cpp
        user.cpp
        challenge.cpp
        common.cpp
        localconnect.cpp
        serverconnect.cpp
        forms/userhomeform.cpp
        forms/addwordform.cpp
        forms/playform.cpp
        forms/listusersform.cpp
    )

list(APPEND UI_FILES
        initialform
        userhomeform
        addwordform
        playform
        listusersform
        )
list(APPEND RESOURCE_FILES
        qdarkstyle/style.qrc
        )
message(${RESOURCE_FILES})
# Set non-Debug build as GUI application.
# Debug build remains consle application.
if(NOT CMAKE_BUILD_TYPE MATCHES Debug) #Release, RelWithDebInfo and MinSizeRel
    if(WIN32) # Check if we are on Windows
        set(SYSTEM_TYPE WIN32)
    elseif(APPLE) # MacOS X
        set(SYSTEM_TYPE MACOSX_BUNDLE)
    else() # UNIX
        set(SYSTEM_TYPE EXCLUDE_FROM_ALL)
    endif()
    message("System type is" ${SYSTEM_TYPE})
endif()
file(REMOVE "forms/uicall.cmd")
foreach(VFILE IN LISTS UI_FILES)
#    add_custom_command(OUTPUT ui_${VFILE}.h
#            COMMAND uic ${VFILE}.ui
#            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/forms
#            )
#    message(${VFILE})
    file(APPEND "forms/uicall.cmd" "uic.exe ${PROJECT_SOURCE_DIR}/forms/${VFILE}.ui -o ${PROJECT_SOURCE_DIR}/forms/ui_${VFILE}.h\n")
#    execute_process(COMMAND echo uic.exe ${PROJECT_SOURCE_DIR}/forms/${VFILE}.ui -o ${PROJECT_SOURCE_DIR}/forms/ui_${VFILE}.h >> forms/uicall.cmd)
endforeach()
add_executable(${PROJECT_NAME} ${SYSTEM_TYPE} ${SOURCE_FILES} ${RESOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL Qt5::RemoteObjects)
