# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gal/Desktop/ex4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gal/Desktop/ex4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex4.dir/flags.make

CMakeFiles/ex4.dir/main.cpp.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex4.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex4.dir/main.cpp.o -c /home/gal/Desktop/ex4/main.cpp

CMakeFiles/ex4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/Desktop/ex4/main.cpp > CMakeFiles/ex4.dir/main.cpp.i

CMakeFiles/ex4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/Desktop/ex4/main.cpp -o CMakeFiles/ex4.dir/main.cpp.s

CMakeFiles/ex4.dir/MySerialServer.cpp.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/MySerialServer.cpp.o: ../MySerialServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex4.dir/MySerialServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex4.dir/MySerialServer.cpp.o -c /home/gal/Desktop/ex4/MySerialServer.cpp

CMakeFiles/ex4.dir/MySerialServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex4.dir/MySerialServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/Desktop/ex4/MySerialServer.cpp > CMakeFiles/ex4.dir/MySerialServer.cpp.i

CMakeFiles/ex4.dir/MySerialServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex4.dir/MySerialServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/Desktop/ex4/MySerialServer.cpp -o CMakeFiles/ex4.dir/MySerialServer.cpp.s

CMakeFiles/ex4.dir/MyTestClientHandler.cpp.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/MyTestClientHandler.cpp.o: ../MyTestClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ex4.dir/MyTestClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex4.dir/MyTestClientHandler.cpp.o -c /home/gal/Desktop/ex4/MyTestClientHandler.cpp

CMakeFiles/ex4.dir/MyTestClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex4.dir/MyTestClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/Desktop/ex4/MyTestClientHandler.cpp > CMakeFiles/ex4.dir/MyTestClientHandler.cpp.i

CMakeFiles/ex4.dir/MyTestClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex4.dir/MyTestClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/Desktop/ex4/MyTestClientHandler.cpp -o CMakeFiles/ex4.dir/MyTestClientHandler.cpp.s

CMakeFiles/ex4.dir/Matrix.cpp.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/Matrix.cpp.o: ../Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ex4.dir/Matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex4.dir/Matrix.cpp.o -c /home/gal/Desktop/ex4/Matrix.cpp

CMakeFiles/ex4.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex4.dir/Matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/Desktop/ex4/Matrix.cpp > CMakeFiles/ex4.dir/Matrix.cpp.i

CMakeFiles/ex4.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex4.dir/Matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/Desktop/ex4/Matrix.cpp -o CMakeFiles/ex4.dir/Matrix.cpp.s

CMakeFiles/ex4.dir/MyClientHandler.cpp.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/MyClientHandler.cpp.o: ../MyClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ex4.dir/MyClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex4.dir/MyClientHandler.cpp.o -c /home/gal/Desktop/ex4/MyClientHandler.cpp

CMakeFiles/ex4.dir/MyClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex4.dir/MyClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gal/Desktop/ex4/MyClientHandler.cpp > CMakeFiles/ex4.dir/MyClientHandler.cpp.i

CMakeFiles/ex4.dir/MyClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex4.dir/MyClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gal/Desktop/ex4/MyClientHandler.cpp -o CMakeFiles/ex4.dir/MyClientHandler.cpp.s

# Object files for target ex4
ex4_OBJECTS = \
"CMakeFiles/ex4.dir/main.cpp.o" \
"CMakeFiles/ex4.dir/MySerialServer.cpp.o" \
"CMakeFiles/ex4.dir/MyTestClientHandler.cpp.o" \
"CMakeFiles/ex4.dir/Matrix.cpp.o" \
"CMakeFiles/ex4.dir/MyClientHandler.cpp.o"

# External object files for target ex4
ex4_EXTERNAL_OBJECTS =

ex4: CMakeFiles/ex4.dir/main.cpp.o
ex4: CMakeFiles/ex4.dir/MySerialServer.cpp.o
ex4: CMakeFiles/ex4.dir/MyTestClientHandler.cpp.o
ex4: CMakeFiles/ex4.dir/Matrix.cpp.o
ex4: CMakeFiles/ex4.dir/MyClientHandler.cpp.o
ex4: CMakeFiles/ex4.dir/build.make
ex4: CMakeFiles/ex4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ex4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex4.dir/build: ex4

.PHONY : CMakeFiles/ex4.dir/build

CMakeFiles/ex4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex4.dir/clean

CMakeFiles/ex4.dir/depend:
	cd /home/gal/Desktop/ex4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gal/Desktop/ex4 /home/gal/Desktop/ex4 /home/gal/Desktop/ex4/cmake-build-debug /home/gal/Desktop/ex4/cmake-build-debug /home/gal/Desktop/ex4/cmake-build-debug/CMakeFiles/ex4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex4.dir/depend

