# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/text_editor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/text_editor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/text_editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text_editor.dir/flags.make

CMakeFiles/text_editor.dir/main.cpp.obj: CMakeFiles/text_editor.dir/flags.make
CMakeFiles/text_editor.dir/main.cpp.obj: ../main.cpp
CMakeFiles/text_editor.dir/main.cpp.obj: CMakeFiles/text_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/text_editor.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/text_editor.dir/main.cpp.obj -MF CMakeFiles\text_editor.dir\main.cpp.obj.d -o CMakeFiles\text_editor.dir\main.cpp.obj -c "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\main.cpp"

CMakeFiles/text_editor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/text_editor.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\main.cpp" > CMakeFiles\text_editor.dir\main.cpp.i

CMakeFiles/text_editor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/text_editor.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\main.cpp" -o CMakeFiles\text_editor.dir\main.cpp.s

# Object files for target text_editor
text_editor_OBJECTS = \
"CMakeFiles/text_editor.dir/main.cpp.obj"

# External object files for target text_editor
text_editor_EXTERNAL_OBJECTS =

text_editor.exe: CMakeFiles/text_editor.dir/main.cpp.obj
text_editor.exe: CMakeFiles/text_editor.dir/build.make
text_editor.exe: CMakeFiles/text_editor.dir/linklibs.rsp
text_editor.exe: CMakeFiles/text_editor.dir/objects1.rsp
text_editor.exe: CMakeFiles/text_editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable text_editor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\text_editor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text_editor.dir/build: text_editor.exe
.PHONY : CMakeFiles/text_editor.dir/build

CMakeFiles/text_editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\text_editor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/text_editor.dir/clean

CMakeFiles/text_editor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app" "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app" "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\cmake-build-debug" "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\cmake-build-debug" "C:\Users\Admin\Documents\GitHub\Assignment 4 - text editor app\cmake-build-debug\CMakeFiles\text_editor.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/text_editor.dir/depend

