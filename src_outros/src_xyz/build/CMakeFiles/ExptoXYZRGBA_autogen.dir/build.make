# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Expt-o\ExptoXYZRGBA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Expt-o\ExptoXYZRGBA\build

# Utility rule file for ExptoXYZRGBA_autogen.

# Include the progress variables for this target.
include CMakeFiles\ExptoXYZRGBA_autogen.dir\progress.make

CMakeFiles\ExptoXYZRGBA_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\Expt-o\ExptoXYZRGBA\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ExptoXYZRGBA"
	echo >nul && "C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen D:/Expt-o/ExptoXYZRGBA/build/CMakeFiles/ExptoXYZRGBA_autogen.dir/AutogenInfo.cmake Debug

ExptoXYZRGBA_autogen: CMakeFiles\ExptoXYZRGBA_autogen
ExptoXYZRGBA_autogen: CMakeFiles\ExptoXYZRGBA_autogen.dir\build.make

.PHONY : ExptoXYZRGBA_autogen

# Rule to build all files generated by this target.
CMakeFiles\ExptoXYZRGBA_autogen.dir\build: ExptoXYZRGBA_autogen

.PHONY : CMakeFiles\ExptoXYZRGBA_autogen.dir\build

CMakeFiles\ExptoXYZRGBA_autogen.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExptoXYZRGBA_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ExptoXYZRGBA_autogen.dir\clean

CMakeFiles\ExptoXYZRGBA_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Expt-o\ExptoXYZRGBA D:\Expt-o\ExptoXYZRGBA D:\Expt-o\ExptoXYZRGBA\build D:\Expt-o\ExptoXYZRGBA\build D:\Expt-o\ExptoXYZRGBA\build\CMakeFiles\ExptoXYZRGBA_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ExptoXYZRGBA_autogen.dir\depend
