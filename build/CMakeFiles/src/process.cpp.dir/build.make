# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samir/Scheduler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samir/Scheduler/build

# Include any dependencies generated for this target.
include CMakeFiles/src/process.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/src/process.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/src/process.cpp.dir/flags.make

CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.o: CMakeFiles/src/process.cpp.dir/flags.make
CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.o: ../src/sched_process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samir/Scheduler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.o -c /home/samir/Scheduler/src/sched_process.cpp

CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samir/Scheduler/src/sched_process.cpp > CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.i

CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samir/Scheduler/src/sched_process.cpp -o CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.s

CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.o: CMakeFiles/src/process.cpp.dir/flags.make
CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.o: ../src/scheduler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samir/Scheduler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.o -c /home/samir/Scheduler/src/scheduler.cpp

CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samir/Scheduler/src/scheduler.cpp > CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.i

CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samir/Scheduler/src/scheduler.cpp -o CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.s

# Object files for target src/process.cpp
src/process_cpp_OBJECTS = \
"CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.o" \
"CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.o"

# External object files for target src/process.cpp
src/process_cpp_EXTERNAL_OBJECTS =

libsrc/process.cpp.a: CMakeFiles/src/process.cpp.dir/src/sched_process.cpp.o
libsrc/process.cpp.a: CMakeFiles/src/process.cpp.dir/src/scheduler.cpp.o
libsrc/process.cpp.a: CMakeFiles/src/process.cpp.dir/build.make
libsrc/process.cpp.a: CMakeFiles/src/process.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samir/Scheduler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libsrc/process.cpp.a"
	$(CMAKE_COMMAND) -P CMakeFiles/src/process.cpp.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src/process.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/src/process.cpp.dir/build: libsrc/process.cpp.a

.PHONY : CMakeFiles/src/process.cpp.dir/build

CMakeFiles/src/process.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/src/process.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/src/process.cpp.dir/clean

CMakeFiles/src/process.cpp.dir/depend:
	cd /home/samir/Scheduler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samir/Scheduler /home/samir/Scheduler /home/samir/Scheduler/build /home/samir/Scheduler/build /home/samir/Scheduler/build/CMakeFiles/src/process.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/src/process.cpp.dir/depend

