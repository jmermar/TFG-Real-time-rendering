# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /C/msys64/mingw64/bin/cmake.exe

# The command to remove a file.
RM = /C/msys64/mingw64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /F/personal/uni/tfg/codigo/OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /F/personal/uni/tfg/codigo/OpenGL/build

# Include any dependencies generated for this target.
include CMakeFiles/renderer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/renderer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/renderer.dir/flags.make

CMakeFiles/renderer.dir/src/Window.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/Window.cpp.obj: ../src/Window.cpp
CMakeFiles/renderer.dir/src/Window.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/renderer.dir/src/Window.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/Window.cpp.obj -MF CMakeFiles/renderer.dir/src/Window.cpp.obj.d -o CMakeFiles/renderer.dir/src/Window.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/Window.cpp

CMakeFiles/renderer.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/Window.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/Window.cpp > CMakeFiles/renderer.dir/src/Window.cpp.i

CMakeFiles/renderer.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/Window.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/Window.cpp -o CMakeFiles/renderer.dir/src/Window.cpp.s

CMakeFiles/renderer.dir/src/Mesh.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/Mesh.cpp.obj: ../src/Mesh.cpp
CMakeFiles/renderer.dir/src/Mesh.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/renderer.dir/src/Mesh.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/Mesh.cpp.obj -MF CMakeFiles/renderer.dir/src/Mesh.cpp.obj.d -o CMakeFiles/renderer.dir/src/Mesh.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/Mesh.cpp

CMakeFiles/renderer.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/Mesh.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/Mesh.cpp > CMakeFiles/renderer.dir/src/Mesh.cpp.i

CMakeFiles/renderer.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/Mesh.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/Mesh.cpp -o CMakeFiles/renderer.dir/src/Mesh.cpp.s

CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj: ../src/MeshLoader.cpp
CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj -MF CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj.d -o CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/MeshLoader.cpp

CMakeFiles/renderer.dir/src/MeshLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/MeshLoader.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/MeshLoader.cpp > CMakeFiles/renderer.dir/src/MeshLoader.cpp.i

CMakeFiles/renderer.dir/src/MeshLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/MeshLoader.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/MeshLoader.cpp -o CMakeFiles/renderer.dir/src/MeshLoader.cpp.s

CMakeFiles/renderer.dir/src/Shader.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/Shader.cpp.obj: ../src/Shader.cpp
CMakeFiles/renderer.dir/src/Shader.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/renderer.dir/src/Shader.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/Shader.cpp.obj -MF CMakeFiles/renderer.dir/src/Shader.cpp.obj.d -o CMakeFiles/renderer.dir/src/Shader.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/Shader.cpp

CMakeFiles/renderer.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/Shader.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/Shader.cpp > CMakeFiles/renderer.dir/src/Shader.cpp.i

CMakeFiles/renderer.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/Shader.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/Shader.cpp -o CMakeFiles/renderer.dir/src/Shader.cpp.s

CMakeFiles/renderer.dir/src/Texture.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/Texture.cpp.obj: ../src/Texture.cpp
CMakeFiles/renderer.dir/src/Texture.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/renderer.dir/src/Texture.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/Texture.cpp.obj -MF CMakeFiles/renderer.dir/src/Texture.cpp.obj.d -o CMakeFiles/renderer.dir/src/Texture.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/Texture.cpp

CMakeFiles/renderer.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/Texture.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/Texture.cpp > CMakeFiles/renderer.dir/src/Texture.cpp.i

CMakeFiles/renderer.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/Texture.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/Texture.cpp -o CMakeFiles/renderer.dir/src/Texture.cpp.s

CMakeFiles/renderer.dir/src/Material.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/Material.cpp.obj: ../src/Material.cpp
CMakeFiles/renderer.dir/src/Material.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/renderer.dir/src/Material.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/Material.cpp.obj -MF CMakeFiles/renderer.dir/src/Material.cpp.obj.d -o CMakeFiles/renderer.dir/src/Material.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/Material.cpp

CMakeFiles/renderer.dir/src/Material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/Material.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/Material.cpp > CMakeFiles/renderer.dir/src/Material.cpp.i

CMakeFiles/renderer.dir/src/Material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/Material.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/Material.cpp -o CMakeFiles/renderer.dir/src/Material.cpp.s

CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj: ../src/MaterialTextured.cpp
CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj -MF CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj.d -o CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/MaterialTextured.cpp

CMakeFiles/renderer.dir/src/MaterialTextured.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/MaterialTextured.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/MaterialTextured.cpp > CMakeFiles/renderer.dir/src/MaterialTextured.cpp.i

CMakeFiles/renderer.dir/src/MaterialTextured.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/MaterialTextured.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/MaterialTextured.cpp -o CMakeFiles/renderer.dir/src/MaterialTextured.cpp.s

CMakeFiles/renderer.dir/src/mainPBR.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/mainPBR.cpp.obj: ../src/mainPBR.cpp
CMakeFiles/renderer.dir/src/mainPBR.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/renderer.dir/src/mainPBR.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/mainPBR.cpp.obj -MF CMakeFiles/renderer.dir/src/mainPBR.cpp.obj.d -o CMakeFiles/renderer.dir/src/mainPBR.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/mainPBR.cpp

CMakeFiles/renderer.dir/src/mainPBR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/mainPBR.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/mainPBR.cpp > CMakeFiles/renderer.dir/src/mainPBR.cpp.i

CMakeFiles/renderer.dir/src/mainPBR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/mainPBR.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/mainPBR.cpp -o CMakeFiles/renderer.dir/src/mainPBR.cpp.s

CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj: ../src/tiny_obj_loader.cpp
CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj -MF CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj.d -o CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/tiny_obj_loader.cpp

CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/tiny_obj_loader.cpp > CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.i

CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/tiny_obj_loader.cpp -o CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.s

CMakeFiles/renderer.dir/src/glad.c.obj: CMakeFiles/renderer.dir/flags.make
CMakeFiles/renderer.dir/src/glad.c.obj: ../src/glad.c
CMakeFiles/renderer.dir/src/glad.c.obj: CMakeFiles/renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/renderer.dir/src/glad.c.obj"
	/C/msys64/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/renderer.dir/src/glad.c.obj -MF CMakeFiles/renderer.dir/src/glad.c.obj.d -o CMakeFiles/renderer.dir/src/glad.c.obj -c /F/personal/uni/tfg/codigo/OpenGL/src/glad.c

CMakeFiles/renderer.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/renderer.dir/src/glad.c.i"
	/C/msys64/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /F/personal/uni/tfg/codigo/OpenGL/src/glad.c > CMakeFiles/renderer.dir/src/glad.c.i

CMakeFiles/renderer.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/renderer.dir/src/glad.c.s"
	/C/msys64/mingw64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /F/personal/uni/tfg/codigo/OpenGL/src/glad.c -o CMakeFiles/renderer.dir/src/glad.c.s

# Object files for target renderer
renderer_OBJECTS = \
"CMakeFiles/renderer.dir/src/Window.cpp.obj" \
"CMakeFiles/renderer.dir/src/Mesh.cpp.obj" \
"CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj" \
"CMakeFiles/renderer.dir/src/Shader.cpp.obj" \
"CMakeFiles/renderer.dir/src/Texture.cpp.obj" \
"CMakeFiles/renderer.dir/src/Material.cpp.obj" \
"CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj" \
"CMakeFiles/renderer.dir/src/mainPBR.cpp.obj" \
"CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj" \
"CMakeFiles/renderer.dir/src/glad.c.obj"

# External object files for target renderer
renderer_EXTERNAL_OBJECTS =

renderer.exe: CMakeFiles/renderer.dir/src/Window.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/Mesh.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/MeshLoader.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/Shader.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/Texture.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/Material.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/MaterialTextured.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/mainPBR.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/tiny_obj_loader.cpp.obj
renderer.exe: CMakeFiles/renderer.dir/src/glad.c.obj
renderer.exe: CMakeFiles/renderer.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable renderer.exe"
	/C/msys64/mingw64/bin/cmake.exe -E rm -f CMakeFiles/renderer.dir/objects.a
	/C/msys64/mingw64/bin/ar.exe qc CMakeFiles/renderer.dir/objects.a $(renderer_OBJECTS) $(renderer_EXTERNAL_OBJECTS)
	/C/msys64/mingw64/bin/g++.exe -O2 -Wl,--whole-archive CMakeFiles/renderer.dir/objects.a -Wl,--no-whole-archive -o renderer.exe -Wl,--out-implib,librenderer.dll.a -Wl,--major-image-version,0,--minor-image-version,0  -lmingw32 -lopengl32 -lSDL2main -lSDL2 -lSDL2_image -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 

# Rule to build all files generated by this target.
CMakeFiles/renderer.dir/build: renderer.exe
.PHONY : CMakeFiles/renderer.dir/build

CMakeFiles/renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/renderer.dir/clean

CMakeFiles/renderer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /F/personal/uni/tfg/codigo/OpenGL /F/personal/uni/tfg/codigo/OpenGL /F/personal/uni/tfg/codigo/OpenGL/build /F/personal/uni/tfg/codigo/OpenGL/build /F/personal/uni/tfg/codigo/OpenGL/build/CMakeFiles/renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/renderer.dir/depend

