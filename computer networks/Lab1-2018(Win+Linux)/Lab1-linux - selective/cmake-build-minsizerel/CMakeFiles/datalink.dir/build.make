# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel"

# Include any dependencies generated for this target.
include CMakeFiles/datalink.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/datalink.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/datalink.dir/flags.make

CMakeFiles/datalink.dir/datalink.c.obj: CMakeFiles/datalink.dir/flags.make
CMakeFiles/datalink.dir/datalink.c.obj: ../datalink.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/datalink.dir/datalink.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datalink.dir\datalink.c.obj   -c "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\datalink.c"

CMakeFiles/datalink.dir/datalink.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datalink.dir/datalink.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\datalink.c" > CMakeFiles\datalink.dir\datalink.c.i

CMakeFiles/datalink.dir/datalink.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datalink.dir/datalink.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\datalink.c" -o CMakeFiles\datalink.dir\datalink.c.s

CMakeFiles/datalink.dir/protocol.c.obj: CMakeFiles/datalink.dir/flags.make
CMakeFiles/datalink.dir/protocol.c.obj: ../protocol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/datalink.dir/protocol.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datalink.dir\protocol.c.obj   -c "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\protocol.c"

CMakeFiles/datalink.dir/protocol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datalink.dir/protocol.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\protocol.c" > CMakeFiles\datalink.dir\protocol.c.i

CMakeFiles/datalink.dir/protocol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datalink.dir/protocol.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\protocol.c" -o CMakeFiles\datalink.dir\protocol.c.s

CMakeFiles/datalink.dir/lprintf.c.obj: CMakeFiles/datalink.dir/flags.make
CMakeFiles/datalink.dir/lprintf.c.obj: ../lprintf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/datalink.dir/lprintf.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datalink.dir\lprintf.c.obj   -c "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\lprintf.c"

CMakeFiles/datalink.dir/lprintf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datalink.dir/lprintf.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\lprintf.c" > CMakeFiles\datalink.dir\lprintf.c.i

CMakeFiles/datalink.dir/lprintf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datalink.dir/lprintf.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\lprintf.c" -o CMakeFiles\datalink.dir\lprintf.c.s

CMakeFiles/datalink.dir/crc32.c.obj: CMakeFiles/datalink.dir/flags.make
CMakeFiles/datalink.dir/crc32.c.obj: ../crc32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/datalink.dir/crc32.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datalink.dir\crc32.c.obj   -c "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\crc32.c"

CMakeFiles/datalink.dir/crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datalink.dir/crc32.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\crc32.c" > CMakeFiles\datalink.dir\crc32.c.i

CMakeFiles/datalink.dir/crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datalink.dir/crc32.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\crc32.c" -o CMakeFiles\datalink.dir\crc32.c.s

CMakeFiles/datalink.dir/getopt.c.obj: CMakeFiles/datalink.dir/flags.make
CMakeFiles/datalink.dir/getopt.c.obj: ../getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/datalink.dir/getopt.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\datalink.dir\getopt.c.obj   -c "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\getopt.c"

CMakeFiles/datalink.dir/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datalink.dir/getopt.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\getopt.c" > CMakeFiles\datalink.dir\getopt.c.i

CMakeFiles/datalink.dir/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datalink.dir/getopt.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\getopt.c" -o CMakeFiles\datalink.dir\getopt.c.s

# Object files for target datalink
datalink_OBJECTS = \
"CMakeFiles/datalink.dir/datalink.c.obj" \
"CMakeFiles/datalink.dir/protocol.c.obj" \
"CMakeFiles/datalink.dir/lprintf.c.obj" \
"CMakeFiles/datalink.dir/crc32.c.obj" \
"CMakeFiles/datalink.dir/getopt.c.obj"

# External object files for target datalink
datalink_EXTERNAL_OBJECTS =

datalink.exe: CMakeFiles/datalink.dir/datalink.c.obj
datalink.exe: CMakeFiles/datalink.dir/protocol.c.obj
datalink.exe: CMakeFiles/datalink.dir/lprintf.c.obj
datalink.exe: CMakeFiles/datalink.dir/crc32.c.obj
datalink.exe: CMakeFiles/datalink.dir/getopt.c.obj
datalink.exe: CMakeFiles/datalink.dir/build.make
datalink.exe: CMakeFiles/datalink.dir/linklibs.rsp
datalink.exe: CMakeFiles/datalink.dir/objects1.rsp
datalink.exe: CMakeFiles/datalink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable datalink.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\datalink.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/datalink.dir/build: datalink.exe

.PHONY : CMakeFiles/datalink.dir/build

CMakeFiles/datalink.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\datalink.dir\cmake_clean.cmake
.PHONY : CMakeFiles/datalink.dir/clean

CMakeFiles/datalink.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective" "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective" "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel" "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel" "D:\git-repos\HomeWork\computer networks\Lab1-2018(Win+Linux)\Lab1-linux - selective\cmake-build-minsizerel\CMakeFiles\datalink.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/datalink.dir/depend

