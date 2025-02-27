# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dev_at/projects/PDF_GRAPHS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dev_at/projects/PDF_GRAPHS/build

# Include any dependencies generated for this target.
include CMakeFiles/myLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myLib.dir/flags.make

CMakeFiles/myLib.dir/src/Wrapper.cpp.o: CMakeFiles/myLib.dir/flags.make
CMakeFiles/myLib.dir/src/Wrapper.cpp.o: ../src/Wrapper.cpp
CMakeFiles/myLib.dir/src/Wrapper.cpp.o: CMakeFiles/myLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev_at/projects/PDF_GRAPHS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myLib.dir/src/Wrapper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myLib.dir/src/Wrapper.cpp.o -MF CMakeFiles/myLib.dir/src/Wrapper.cpp.o.d -o CMakeFiles/myLib.dir/src/Wrapper.cpp.o -c /home/dev_at/projects/PDF_GRAPHS/src/Wrapper.cpp

CMakeFiles/myLib.dir/src/Wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myLib.dir/src/Wrapper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dev_at/projects/PDF_GRAPHS/src/Wrapper.cpp > CMakeFiles/myLib.dir/src/Wrapper.cpp.i

CMakeFiles/myLib.dir/src/Wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myLib.dir/src/Wrapper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dev_at/projects/PDF_GRAPHS/src/Wrapper.cpp -o CMakeFiles/myLib.dir/src/Wrapper.cpp.s

CMakeFiles/myLib.dir/src/CSV.cpp.o: CMakeFiles/myLib.dir/flags.make
CMakeFiles/myLib.dir/src/CSV.cpp.o: ../src/CSV.cpp
CMakeFiles/myLib.dir/src/CSV.cpp.o: CMakeFiles/myLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dev_at/projects/PDF_GRAPHS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/myLib.dir/src/CSV.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myLib.dir/src/CSV.cpp.o -MF CMakeFiles/myLib.dir/src/CSV.cpp.o.d -o CMakeFiles/myLib.dir/src/CSV.cpp.o -c /home/dev_at/projects/PDF_GRAPHS/src/CSV.cpp

CMakeFiles/myLib.dir/src/CSV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myLib.dir/src/CSV.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dev_at/projects/PDF_GRAPHS/src/CSV.cpp > CMakeFiles/myLib.dir/src/CSV.cpp.i

CMakeFiles/myLib.dir/src/CSV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myLib.dir/src/CSV.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dev_at/projects/PDF_GRAPHS/src/CSV.cpp -o CMakeFiles/myLib.dir/src/CSV.cpp.s

# Object files for target myLib
myLib_OBJECTS = \
"CMakeFiles/myLib.dir/src/Wrapper.cpp.o" \
"CMakeFiles/myLib.dir/src/CSV.cpp.o"

# External object files for target myLib
myLib_EXTERNAL_OBJECTS =

libmyLib.so: CMakeFiles/myLib.dir/src/Wrapper.cpp.o
libmyLib.so: CMakeFiles/myLib.dir/src/CSV.cpp.o
libmyLib.so: CMakeFiles/myLib.dir/build.make
libmyLib.so: CMakeFiles/myLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dev_at/projects/PDF_GRAPHS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libmyLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myLib.dir/build: libmyLib.so
.PHONY : CMakeFiles/myLib.dir/build

CMakeFiles/myLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myLib.dir/clean

CMakeFiles/myLib.dir/depend:
	cd /home/dev_at/projects/PDF_GRAPHS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dev_at/projects/PDF_GRAPHS /home/dev_at/projects/PDF_GRAPHS /home/dev_at/projects/PDF_GRAPHS/build /home/dev_at/projects/PDF_GRAPHS/build /home/dev_at/projects/PDF_GRAPHS/build/CMakeFiles/myLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myLib.dir/depend

