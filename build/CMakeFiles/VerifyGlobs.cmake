# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# TestEngine_SOURCES at CMakeLists.txt:11 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Cprojects/TestEngine/src/*.c")
set(OLD_GLOB
  "C:/Cprojects/TestEngine/src/Engine/Engine.c"
  "C:/Cprojects/TestEngine/src/Engine/GameWindow.c"
  "C:/Cprojects/TestEngine/src/main.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Cprojects/TestEngine/build/CMakeFiles/cmake.verify_globs")
endif()
