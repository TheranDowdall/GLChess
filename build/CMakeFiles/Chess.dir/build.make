# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = C:\dev\VScode\VScode_compilers\C-C++\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\dev\VScode\VScode_compilers\C-C++\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\VScode\Projects\C-C++\Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\VScode\Projects\C-C++\Chess\build

# Include any dependencies generated for this target.
include CMakeFiles/Chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess.dir/flags.make

CMakeFiles/Chess.dir/cmake_pch.hxx.gch: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/cmake_pch.hxx.gch: CMakeFiles/Chess.dir/includes_CXX.rsp
CMakeFiles/Chess.dir/cmake_pch.hxx.gch: CMakeFiles/Chess.dir/cmake_pch.hxx.cxx
CMakeFiles/Chess.dir/cmake_pch.hxx.gch: CMakeFiles/Chess.dir/cmake_pch.hxx
CMakeFiles/Chess.dir/cmake_pch.hxx.gch: CMakeFiles/Chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chess.dir/cmake_pch.hxx.gch"
	C:\dev\VScode\VScode_compilers\C-C++\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include C:/dev/VScode/Projects/C-C++/Chess/build/CMakeFiles/Chess.dir/cmake_pch.hxx -MD -MT CMakeFiles/Chess.dir/cmake_pch.hxx.gch -MF CMakeFiles\Chess.dir\cmake_pch.hxx.gch.d -o CMakeFiles\Chess.dir\cmake_pch.hxx.gch -c C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles\Chess.dir\cmake_pch.hxx.cxx

CMakeFiles/Chess.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/cmake_pch.hxx.i"
	C:\dev\VScode\VScode_compilers\C-C++\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include C:/dev/VScode/Projects/C-C++/Chess/build/CMakeFiles/Chess.dir/cmake_pch.hxx -E C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles\Chess.dir\cmake_pch.hxx.cxx > CMakeFiles\Chess.dir\cmake_pch.hxx.i

CMakeFiles/Chess.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/cmake_pch.hxx.s"
	C:\dev\VScode\VScode_compilers\C-C++\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include C:/dev/VScode/Projects/C-C++/Chess/build/CMakeFiles/Chess.dir/cmake_pch.hxx -S C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles\Chess.dir\cmake_pch.hxx.cxx -o CMakeFiles\Chess.dir\cmake_pch.hxx.s

CMakeFiles/Chess.dir/app/app.cpp.obj: CMakeFiles/Chess.dir/flags.make
CMakeFiles/Chess.dir/app/app.cpp.obj: CMakeFiles/Chess.dir/includes_CXX.rsp
CMakeFiles/Chess.dir/app/app.cpp.obj: ../app/app.cpp
CMakeFiles/Chess.dir/app/app.cpp.obj: CMakeFiles/Chess.dir/cmake_pch.hxx
CMakeFiles/Chess.dir/app/app.cpp.obj: CMakeFiles/Chess.dir/cmake_pch.hxx.gch
CMakeFiles/Chess.dir/app/app.cpp.obj: CMakeFiles/Chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chess.dir/app/app.cpp.obj"
	C:\dev\VScode\VScode_compilers\C-C++\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include C:/dev/VScode/Projects/C-C++/Chess/build/CMakeFiles/Chess.dir/cmake_pch.hxx -MD -MT CMakeFiles/Chess.dir/app/app.cpp.obj -MF CMakeFiles\Chess.dir\app\app.cpp.obj.d -o CMakeFiles\Chess.dir\app\app.cpp.obj -c C:\dev\VScode\Projects\C-C++\Chess\app\app.cpp

CMakeFiles/Chess.dir/app/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess.dir/app/app.cpp.i"
	C:\dev\VScode\VScode_compilers\C-C++\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include C:/dev/VScode/Projects/C-C++/Chess/build/CMakeFiles/Chess.dir/cmake_pch.hxx -E C:\dev\VScode\Projects\C-C++\Chess\app\app.cpp > CMakeFiles\Chess.dir\app\app.cpp.i

CMakeFiles/Chess.dir/app/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess.dir/app/app.cpp.s"
	C:\dev\VScode\VScode_compilers\C-C++\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include C:/dev/VScode/Projects/C-C++/Chess/build/CMakeFiles/Chess.dir/cmake_pch.hxx -S C:\dev\VScode\Projects\C-C++\Chess\app\app.cpp -o CMakeFiles\Chess.dir\app\app.cpp.s

# Object files for target Chess
Chess_OBJECTS = \
"CMakeFiles/Chess.dir/app/app.cpp.obj"

# External object files for target Chess
Chess_EXTERNAL_OBJECTS =

../bin/Chess.exe: CMakeFiles/Chess.dir/cmake_pch.hxx.gch
../bin/Chess.exe: CMakeFiles/Chess.dir/app/app.cpp.obj
../bin/Chess.exe: CMakeFiles/Chess.dir/build.make
../bin/Chess.exe: ../lib/libchessGame.a
../bin/Chess.exe: CMakeFiles/Chess.dir/linklibs.rsp
../bin/Chess.exe: CMakeFiles/Chess.dir/objects1.rsp
../bin/Chess.exe: CMakeFiles/Chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\bin\Chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess.dir/build: ../bin/Chess.exe
.PHONY : CMakeFiles/Chess.dir/build

CMakeFiles/Chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Chess.dir/clean

CMakeFiles/Chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\dev\VScode\Projects\C-C++\Chess C:\dev\VScode\Projects\C-C++\Chess C:\dev\VScode\Projects\C-C++\Chess\build C:\dev\VScode\Projects\C-C++\Chess\build C:\dev\VScode\Projects\C-C++\Chess\build\CMakeFiles\Chess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chess.dir/depend

