# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build

# Include any dependencies generated for this target.
include CMakeFiles/lib3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lib3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lib3.dir/flags.make

CMakeFiles/lib3.dir/solution3.cpp.o: CMakeFiles/lib3.dir/flags.make
CMakeFiles/lib3.dir/solution3.cpp.o: ../solution3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lib3.dir/solution3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib3.dir/solution3.cpp.o -c /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/solution3.cpp

CMakeFiles/lib3.dir/solution3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib3.dir/solution3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/solution3.cpp > CMakeFiles/lib3.dir/solution3.cpp.i

CMakeFiles/lib3.dir/solution3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib3.dir/solution3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/solution3.cpp -o CMakeFiles/lib3.dir/solution3.cpp.s

CMakeFiles/lib3.dir/solution3.cpp.o.requires:

.PHONY : CMakeFiles/lib3.dir/solution3.cpp.o.requires

CMakeFiles/lib3.dir/solution3.cpp.o.provides: CMakeFiles/lib3.dir/solution3.cpp.o.requires
	$(MAKE) -f CMakeFiles/lib3.dir/build.make CMakeFiles/lib3.dir/solution3.cpp.o.provides.build
.PHONY : CMakeFiles/lib3.dir/solution3.cpp.o.provides

CMakeFiles/lib3.dir/solution3.cpp.o.provides.build: CMakeFiles/lib3.dir/solution3.cpp.o


# Object files for target lib3
lib3_OBJECTS = \
"CMakeFiles/lib3.dir/solution3.cpp.o"

# External object files for target lib3
lib3_EXTERNAL_OBJECTS =

liblib3.a: CMakeFiles/lib3.dir/solution3.cpp.o
liblib3.a: CMakeFiles/lib3.dir/build.make
liblib3.a: CMakeFiles/lib3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblib3.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lib3.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lib3.dir/build: liblib3.a

.PHONY : CMakeFiles/lib3.dir/build

CMakeFiles/lib3.dir/requires: CMakeFiles/lib3.dir/solution3.cpp.o.requires

.PHONY : CMakeFiles/lib3.dir/requires

CMakeFiles/lib3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lib3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lib3.dir/clean

CMakeFiles/lib3.dir/depend:
	cd /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build /home/dc/5W/LeetCode_1000/leetcode_cpp/005.Longest-Palindromic-Substring/build/CMakeFiles/lib3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lib3.dir/depend

