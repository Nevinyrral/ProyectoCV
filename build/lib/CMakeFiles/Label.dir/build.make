# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/fs20167/.cmake/bin/cmake

# The command to remove a file.
RM = /home/fs20167/.cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fs20167/ProjectCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fs20167/ProjectCV/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/Label.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/Label.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/Label.dir/flags.make

lib/CMakeFiles/Label.dir/Label.cxx.o: lib/CMakeFiles/Label.dir/flags.make
lib/CMakeFiles/Label.dir/Label.cxx.o: ../lib/Label.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs20167/ProjectCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/Label.dir/Label.cxx.o"
	cd /home/fs20167/ProjectCV/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Label.dir/Label.cxx.o -c /home/fs20167/ProjectCV/lib/Label.cxx

lib/CMakeFiles/Label.dir/Label.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Label.dir/Label.cxx.i"
	cd /home/fs20167/ProjectCV/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs20167/ProjectCV/lib/Label.cxx > CMakeFiles/Label.dir/Label.cxx.i

lib/CMakeFiles/Label.dir/Label.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Label.dir/Label.cxx.s"
	cd /home/fs20167/ProjectCV/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs20167/ProjectCV/lib/Label.cxx -o CMakeFiles/Label.dir/Label.cxx.s

lib/CMakeFiles/Label.dir/Label.cxx.o.requires:

.PHONY : lib/CMakeFiles/Label.dir/Label.cxx.o.requires

lib/CMakeFiles/Label.dir/Label.cxx.o.provides: lib/CMakeFiles/Label.dir/Label.cxx.o.requires
	$(MAKE) -f lib/CMakeFiles/Label.dir/build.make lib/CMakeFiles/Label.dir/Label.cxx.o.provides.build
.PHONY : lib/CMakeFiles/Label.dir/Label.cxx.o.provides

lib/CMakeFiles/Label.dir/Label.cxx.o.provides.build: lib/CMakeFiles/Label.dir/Label.cxx.o


# Object files for target Label
Label_OBJECTS = \
"CMakeFiles/Label.dir/Label.cxx.o"

# External object files for target Label
Label_EXTERNAL_OBJECTS =

lib/libLabel.a: lib/CMakeFiles/Label.dir/Label.cxx.o
lib/libLabel.a: lib/CMakeFiles/Label.dir/build.make
lib/libLabel.a: lib/CMakeFiles/Label.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fs20167/ProjectCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLabel.a"
	cd /home/fs20167/ProjectCV/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/Label.dir/cmake_clean_target.cmake
	cd /home/fs20167/ProjectCV/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Label.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/Label.dir/build: lib/libLabel.a

.PHONY : lib/CMakeFiles/Label.dir/build

lib/CMakeFiles/Label.dir/requires: lib/CMakeFiles/Label.dir/Label.cxx.o.requires

.PHONY : lib/CMakeFiles/Label.dir/requires

lib/CMakeFiles/Label.dir/clean:
	cd /home/fs20167/ProjectCV/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/Label.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/Label.dir/clean

lib/CMakeFiles/Label.dir/depend:
	cd /home/fs20167/ProjectCV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fs20167/ProjectCV /home/fs20167/ProjectCV/lib /home/fs20167/ProjectCV/build /home/fs20167/ProjectCV/build/lib /home/fs20167/ProjectCV/build/lib/CMakeFiles/Label.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/Label.dir/depend
