cmake_minimum_required(VERSION 3.22.0-rc2)

set(CMAKE_C_COMPILER "D:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/MinGW/bin/g++.exe")
set(CMAKE_C_STANDARD 99)

project(TestEngine)

#SET(GCC_COVERAGE_LINK_FLAGS "-lmingw32 -lSDL2main -lSDL2 -LD:/MinGW/lib")
set(SDL2_INCLUDE_DIR "D:/MinGW/include/")
set(SDL2_LIBRARY_DIR "D:/MinGW/lib/")
include_directories(${SDL2_INCLUDE_DIR})

file (GLOB_RECURSE TestEngine_SOURCES CONFIGURE_DEPENDS "src/*.c")

add_executable(${PROJECT_NAME} ${TestEngine_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "inc/")
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)
target_link_libraries(${PROJECT_NAME} PRIVATE -lmingw32 ${SDL2_LIBRARY_DIR}/libSDL2main.a ${SDL2_LIBRARY_DIR}/libSDL2.dll.a -mwindows)