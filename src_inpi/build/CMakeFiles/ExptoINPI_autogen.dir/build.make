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
CMAKE_SOURCE_DIR = D:\Expt-o\ExptoINPI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Expt-o\ExptoINPI\build

# Utility rule file for ExptoINPI_autogen.

# Include the progress variables for this target.
include CMakeFiles\ExptoINPI_autogen.dir\progress.make

CMakeFiles\ExptoINPI_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\Expt-o\ExptoINPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ExptoINPI"
	echo >nul && "C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen D:/Expt-o/ExptoINPI/build/CMakeFiles/ExptoINPI_autogen.dir/AutogenInfo.cmake Debug

ExptoINPI_autogen: CMakeFiles\ExptoINPI_autogen
ExptoINPI_autogen: CMakeFiles\ExptoINPI_autogen.dir\build.make

.PHONY : ExptoINPI_autogen

# Rule to build all files generated by this target.
CMakeFiles\ExptoINPI_autogen.dir\build: ExptoINPI_autogen

.PHONY : CMakeFiles\ExptoINPI_autogen.dir\build

CMakeFiles\ExptoINPI_autogen.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExptoINPI_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ExptoINPI_autogen.dir\clean

CMakeFiles\ExptoINPI_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Expt-o\ExptoINPI D:\Expt-o\ExptoINPI D:\Expt-o\ExptoINPI\build D:\Expt-o\ExptoINPI\build D:\Expt-o\ExptoINPI\build\CMakeFiles\ExptoINPI_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ExptoINPI_autogen.dir\depend

