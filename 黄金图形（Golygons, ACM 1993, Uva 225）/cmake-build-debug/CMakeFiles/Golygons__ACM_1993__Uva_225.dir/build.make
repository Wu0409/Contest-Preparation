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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Golygons__ACM_1993__Uva_225.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Golygons__ACM_1993__Uva_225.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Golygons__ACM_1993__Uva_225.dir/flags.make

CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.o: CMakeFiles/Golygons__ACM_1993__Uva_225.dir/flags.make
CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.o -c "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/main.cpp"

CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/main.cpp" > CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.i

CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/main.cpp" -o CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.s

# Object files for target Golygons__ACM_1993__Uva_225
Golygons__ACM_1993__Uva_225_OBJECTS = \
"CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.o"

# External object files for target Golygons__ACM_1993__Uva_225
Golygons__ACM_1993__Uva_225_EXTERNAL_OBJECTS =

Golygons__ACM_1993__Uva_225: CMakeFiles/Golygons__ACM_1993__Uva_225.dir/main.cpp.o
Golygons__ACM_1993__Uva_225: CMakeFiles/Golygons__ACM_1993__Uva_225.dir/build.make
Golygons__ACM_1993__Uva_225: CMakeFiles/Golygons__ACM_1993__Uva_225.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Golygons__ACM_1993__Uva_225"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Golygons__ACM_1993__Uva_225.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Golygons__ACM_1993__Uva_225.dir/build: Golygons__ACM_1993__Uva_225

.PHONY : CMakeFiles/Golygons__ACM_1993__Uva_225.dir/build

CMakeFiles/Golygons__ACM_1993__Uva_225.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Golygons__ACM_1993__Uva_225.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Golygons__ACM_1993__Uva_225.dir/clean

CMakeFiles/Golygons__ACM_1993__Uva_225.dir/depend:
	cd "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）" "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）" "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug" "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug" "/Users/wuyuanchen/Documents/Contest-Preparation/黄金图形（Golygons, ACM 1993, Uva 225）/cmake-build-debug/CMakeFiles/Golygons__ACM_1993__Uva_225.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Golygons__ACM_1993__Uva_225.dir/depend

