cmake_minimum_required(VERSION 3.2.0)
project(Coros VERSION 0.1.0 LANGUAGES C CXX)

include_directories("Src/")
include_directories("Src/PCH/")
include_directories("Libs/GLFW/include/")

add_subdirectory("Libs/")

add_library(Coros STATIC "Src/Coros.cpp" "Src/Coros_glfw.cpp")


if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(Coros PUBLIC -DCOROS_BUILD_RELEASE)
    message("Release")
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(Coros PUBLIC -DCOROS_BUILD_DEBUG)
    message("Debug")
endif()