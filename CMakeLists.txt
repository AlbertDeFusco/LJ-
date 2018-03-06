cmake_minimum_required(VERSION 2.8)
PROJECT(LJ CXX)

# Debug means -O0 -g
# Release means at least -O2
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Compile for Debug or Release"
    FORCE)
endif(NOT CMAKE_BUILD_TYPE)
message(STATUS "The build type is ${CMAKE_BUILD_TYPE}")

file (GLOB lj_source ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(lj ${lj_source})
