# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1356/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1356/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build

# Include any dependencies generated for this target.
include CMakeFiles/sigle_principle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sigle_principle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sigle_principle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sigle_principle.dir/flags.make

CMakeFiles/sigle_principle.dir/src/main.cpp.o: CMakeFiles/sigle_principle.dir/flags.make
CMakeFiles/sigle_principle.dir/src/main.cpp.o: /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/src/main.cpp
CMakeFiles/sigle_principle.dir/src/main.cpp.o: CMakeFiles/sigle_principle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sigle_principle.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sigle_principle.dir/src/main.cpp.o -MF CMakeFiles/sigle_principle.dir/src/main.cpp.o.d -o CMakeFiles/sigle_principle.dir/src/main.cpp.o -c /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/src/main.cpp

CMakeFiles/sigle_principle.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sigle_principle.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/src/main.cpp > CMakeFiles/sigle_principle.dir/src/main.cpp.i

CMakeFiles/sigle_principle.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sigle_principle.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/src/main.cpp -o CMakeFiles/sigle_principle.dir/src/main.cpp.s

# Object files for target sigle_principle
sigle_principle_OBJECTS = \
"CMakeFiles/sigle_principle.dir/src/main.cpp.o"

# External object files for target sigle_principle
sigle_principle_EXTERNAL_OBJECTS =

sigle_principle: CMakeFiles/sigle_principle.dir/src/main.cpp.o
sigle_principle: CMakeFiles/sigle_principle.dir/build.make
sigle_principle: CMakeFiles/sigle_principle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sigle_principle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sigle_principle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sigle_principle.dir/build: sigle_principle
.PHONY : CMakeFiles/sigle_principle.dir/build

CMakeFiles/sigle_principle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sigle_principle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sigle_principle.dir/clean

CMakeFiles/sigle_principle.dir/depend:
	cd /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build /media/pdi/PED/development/cpp/cpp_learn/design_patterns/single_responsibility_principle/build/CMakeFiles/sigle_principle.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sigle_principle.dir/depend
