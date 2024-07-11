cmake_minimum_required(VERSION 3.2.0)
project(UI VERSION 0.1.0 LANGUAGES C CXX)

set(COROS_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Coros") 

# For Cpp_Properties
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sets the output dirs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory("Coros/")

include_directories("Coros/Src/")
include_directories("Coros/Libs/GLFW/include/")

add_executable(UI main.cpp)

target_precompile_headers(UI PUBLIC Coros/Src/PCH/PCH.H)

target_link_libraries(UI Coros glfw)
