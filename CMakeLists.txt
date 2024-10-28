CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

set(project opengl)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(${project} C CXX)

include_directories(
  Dependencies/glad/include
  Engine/include
  Dependencies/imgui
)

file(GLOB sources
  Engine/src/*.cpp
  Dependencies/glad/src/*.c
  Dependencies/imgui/*.cpp
  Engine/include/*.cpp
)

add_subdirectory(Dependencies/GLFW)
add_subdirectory(Engine/include/glm)

add_executable(${project} ${sources})
target_link_libraries(${project} GL glfw)
target_include_directories(${project} PRIVATE Engine/include/glm)
