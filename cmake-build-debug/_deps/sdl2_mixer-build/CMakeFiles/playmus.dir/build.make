# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Users\User\Desktop\113-2_oop\bad-ice-cream

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug

# Include any dependencies generated for this target.
include _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/flags.make

_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/flags.make
_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/includes_C.rsp
_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj: D:/Users/User/Desktop/113-2_oop/bad-ice-cream/PTSD/lib/sdl2_mixer/playmus.c
_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj"
	cd /d D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj -MF CMakeFiles\playmus.dir\playmus.c.obj.d -o CMakeFiles\playmus.dir\playmus.c.obj -c D:\Users\User\Desktop\113-2_oop\bad-ice-cream\PTSD\lib\sdl2_mixer\playmus.c

_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/playmus.dir/playmus.c.i"
	cd /d D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Users\User\Desktop\113-2_oop\bad-ice-cream\PTSD\lib\sdl2_mixer\playmus.c > CMakeFiles\playmus.dir\playmus.c.i

_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/playmus.dir/playmus.c.s"
	cd /d D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Users\User\Desktop\113-2_oop\bad-ice-cream\PTSD\lib\sdl2_mixer\playmus.c -o CMakeFiles\playmus.dir\playmus.c.s

# Object files for target playmus
playmus_OBJECTS = \
"CMakeFiles/playmus.dir/playmus.c.obj"

# External object files for target playmus
playmus_EXTERNAL_OBJECTS =

_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/playmus.c.obj
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/build.make
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2_mixer-build/libSDL2_mixerd.a
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2-build/libSDL2maind.a
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2-build/libSDL2d.a
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/linkLibs.rsp
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/objects1.rsp
_deps/sdl2_mixer-build/playmus.exe: _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable playmus.exe"
	cd /d D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\playmus.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/build: _deps/sdl2_mixer-build/playmus.exe
.PHONY : _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/build

_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/clean:
	cd /d D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build && $(CMAKE_COMMAND) -P CMakeFiles\playmus.dir\cmake_clean.cmake
.PHONY : _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/clean

_deps/sdl2_mixer-build/CMakeFiles/playmus.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Users\User\Desktop\113-2_oop\bad-ice-cream D:\Users\User\Desktop\113-2_oop\bad-ice-cream\PTSD\lib\sdl2_mixer D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build D:\Users\User\Desktop\113-2_oop\bad-ice-cream\cmake-build-debug\_deps\sdl2_mixer-build\CMakeFiles\playmus.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/sdl2_mixer-build/CMakeFiles/playmus.dir/depend

