# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/taka/mousekey

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/taka/mousekey/build

# Include any dependencies generated for this target.
include CMakeFiles/../keymouse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../keymouse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../keymouse.dir/flags.make

CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o: CMakeFiles/../keymouse.dir/flags.make
CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o: ../src/testsrc/TestMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/taka/mousekey/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o -c /home/taka/mousekey/src/testsrc/TestMain.cpp

CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/taka/mousekey/src/testsrc/TestMain.cpp > CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.i

CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/taka/mousekey/src/testsrc/TestMain.cpp -o CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.s

CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.requires:

.PHONY : CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.requires

CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.provides: CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.requires
	$(MAKE) -f CMakeFiles/../keymouse.dir/build.make CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.provides.build
.PHONY : CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.provides

CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.provides.build: CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o


CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o: CMakeFiles/../keymouse.dir/flags.make
CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o: ../src/ControllMouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/taka/mousekey/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o -c /home/taka/mousekey/src/ControllMouse.cpp

CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/taka/mousekey/src/ControllMouse.cpp > CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.i

CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/taka/mousekey/src/ControllMouse.cpp -o CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.s

CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.requires:

.PHONY : CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.requires

CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.provides: CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.requires
	$(MAKE) -f CMakeFiles/../keymouse.dir/build.make CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.provides.build
.PHONY : CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.provides

CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.provides.build: CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o


# Object files for target ../keymouse
__/keymouse_OBJECTS = \
"CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o" \
"CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o"

# External object files for target ../keymouse
__/keymouse_EXTERNAL_OBJECTS =

../keymouse: CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o
../keymouse: CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o
../keymouse: CMakeFiles/../keymouse.dir/build.make
../keymouse: CMakeFiles/../keymouse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/taka/mousekey/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../keymouse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../keymouse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../keymouse.dir/build: ../keymouse

.PHONY : CMakeFiles/../keymouse.dir/build

CMakeFiles/../keymouse.dir/requires: CMakeFiles/../keymouse.dir/src/testsrc/TestMain.cpp.o.requires
CMakeFiles/../keymouse.dir/requires: CMakeFiles/../keymouse.dir/src/ControllMouse.cpp.o.requires

.PHONY : CMakeFiles/../keymouse.dir/requires

CMakeFiles/../keymouse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../keymouse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../keymouse.dir/clean

CMakeFiles/../keymouse.dir/depend:
	cd /home/taka/mousekey/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/taka/mousekey /home/taka/mousekey /home/taka/mousekey/build /home/taka/mousekey/build /home/taka/mousekey/build/keymouse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../keymouse.dir/depend

