cmake_minimum_required(VERSION 3.8)


set(PROJECT_NAME word_elemination)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.12.0\\5.12.0\\mingw73_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(HEADER_FILES
        initialform.h
        auth.h
        user.h
        challenge.h
        common.h
        localconnect.h
        serverconnect.h
        userhomeform.h
        macrodef.h
    )
set(SOURCE_FILES
        main.cpp
        initialform.cpp
        auth.cpp
        user.cpp
        challenge.cpp
        common.cpp
        localconnect.cpp
        serverconnect.cpp
        userhomeform.cpp
    )
# set(RESOURCE_FILE resource.qrc)

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

add_executable(${PROJECT_NAME} ${SYSTEM_TYPE} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL)
