
cmake_minimum_required(VERSION 2.8)

project (Lasty_LD26)

#adjust library paths if necessary

#SDL2
set(ENV{DXSDK_DIR} .) #workaround issue in SDL cmake file
add_subdirectory(libs/SDL2)
include_directories(libs/SDL2/include)

#GLEW  (must be built manually first)
include_directories(libs/glew/include)
find_library(GLEW_LIBRARY NAMES glew32 PATHS libs/glew/lib)

message("GLEW_LIB: ${GLEW_LIBRARY}")

#Opengl
find_package(OpenGL)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

add_executable(lasty_ld26_minimalism main.cpp game.cpp font.cpp)

target_link_libraries(lasty_ld26_minimalism ${GLEW_LIBRARY} SDL2 ${OPENGL_LIBRARY})

