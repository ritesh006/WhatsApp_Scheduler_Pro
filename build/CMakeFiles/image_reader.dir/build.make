# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = C:/mingw64/bin/cmake.exe

# The command to remove a file.
RM = C:/mingw64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/build

# Include any dependencies generated for this target.
include CMakeFiles/image_reader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image_reader.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image_reader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_reader.dir/flags.make

CMakeFiles/image_reader.dir/src/image_reader.c.obj: CMakeFiles/image_reader.dir/flags.make
CMakeFiles/image_reader.dir/src/image_reader.c.obj: CMakeFiles/image_reader.dir/includes_C.rsp
CMakeFiles/image_reader.dir/src/image_reader.c.obj: C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/src/image_reader.c
CMakeFiles/image_reader.dir/src/image_reader.c.obj: CMakeFiles/image_reader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/image_reader.dir/src/image_reader.c.obj"
	C:/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/image_reader.dir/src/image_reader.c.obj -MF CMakeFiles/image_reader.dir/src/image_reader.c.obj.d -o CMakeFiles/image_reader.dir/src/image_reader.c.obj -c C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/src/image_reader.c

CMakeFiles/image_reader.dir/src/image_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/image_reader.dir/src/image_reader.c.i"
	C:/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/src/image_reader.c > CMakeFiles/image_reader.dir/src/image_reader.c.i

CMakeFiles/image_reader.dir/src/image_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/image_reader.dir/src/image_reader.c.s"
	C:/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/src/image_reader.c -o CMakeFiles/image_reader.dir/src/image_reader.c.s

# Object files for target image_reader
image_reader_OBJECTS = \
"CMakeFiles/image_reader.dir/src/image_reader.c.obj"

# External object files for target image_reader
image_reader_EXTERNAL_OBJECTS =

image_reader.exe: CMakeFiles/image_reader.dir/src/image_reader.c.obj
image_reader.exe: CMakeFiles/image_reader.dir/build.make
image_reader.exe: src/check_time/libcheck_time.a
image_reader.exe: src/menu/libmenu.a
image_reader.exe: src/validate_contact/libcontact.a
image_reader.exe: CMakeFiles/image_reader.dir/linkLibs.rsp
image_reader.exe: CMakeFiles/image_reader.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable image_reader.exe"
	C:/mingw64/bin/cmake.exe -E rm -f CMakeFiles/image_reader.dir/objects.a
	C:/mingw64/bin/ar.exe qc CMakeFiles/image_reader.dir/objects.a @CMakeFiles/image_reader.dir/objects1.rsp
	C:/mingw64/bin/gcc.exe -Wl,--whole-archive CMakeFiles/image_reader.dir/objects.a -Wl,--no-whole-archive -o image_reader.exe -Wl,--out-implib,libimage_reader.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/image_reader.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/image_reader.dir/build: image_reader.exe
.PHONY : CMakeFiles/image_reader.dir/build

CMakeFiles/image_reader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_reader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_reader.dir/clean

CMakeFiles/image_reader.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/build C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/build C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/build/CMakeFiles/image_reader.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/image_reader.dir/depend

