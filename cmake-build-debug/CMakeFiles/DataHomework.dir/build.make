# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "/Users/wangjiao/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.6668.126/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/wangjiao/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.6668.126/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangjiao/Desktop/编程相关/DataHomework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataHomework.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataHomework.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataHomework.dir/flags.make

CMakeFiles/DataHomework.dir/9-20.cpp.o: CMakeFiles/DataHomework.dir/flags.make
CMakeFiles/DataHomework.dir/9-20.cpp.o: ../9-20.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataHomework.dir/9-20.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataHomework.dir/9-20.cpp.o -c /Users/wangjiao/Desktop/编程相关/DataHomework/9-20.cpp

CMakeFiles/DataHomework.dir/9-20.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataHomework.dir/9-20.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangjiao/Desktop/编程相关/DataHomework/9-20.cpp > CMakeFiles/DataHomework.dir/9-20.cpp.i

CMakeFiles/DataHomework.dir/9-20.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataHomework.dir/9-20.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangjiao/Desktop/编程相关/DataHomework/9-20.cpp -o CMakeFiles/DataHomework.dir/9-20.cpp.s

# Object files for target DataHomework
DataHomework_OBJECTS = \
"CMakeFiles/DataHomework.dir/9-20.cpp.o"

# External object files for target DataHomework
DataHomework_EXTERNAL_OBJECTS =

DataHomework: CMakeFiles/DataHomework.dir/9-20.cpp.o
DataHomework: CMakeFiles/DataHomework.dir/build.make
DataHomework: CMakeFiles/DataHomework.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataHomework"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataHomework.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataHomework.dir/build: DataHomework

.PHONY : CMakeFiles/DataHomework.dir/build

CMakeFiles/DataHomework.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataHomework.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataHomework.dir/clean

CMakeFiles/DataHomework.dir/depend:
	cd /Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangjiao/Desktop/编程相关/DataHomework /Users/wangjiao/Desktop/编程相关/DataHomework /Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug /Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug /Users/wangjiao/Desktop/编程相关/DataHomework/cmake-build-debug/CMakeFiles/DataHomework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataHomework.dir/depend

