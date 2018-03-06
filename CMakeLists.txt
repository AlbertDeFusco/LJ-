cmake_minimum_required(VERSION 2.8.12)
PROJECT(LJ CXX)

set(CMAKE_MACOSX_RPATH ON)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Debug means -O0 -g
# Release means at least -O2
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Compile for Debug or Release"
    FORCE)
endif(NOT CMAKE_BUILD_TYPE)
message(STATUS "The build type is ${CMAKE_BUILD_TYPE}")

add_library(particle SHARED ${PROJECT_SOURCE_DIR}/src/particle.cpp)
target_include_directories(particle PUBLIC ${PROJECT_SOURCE_DIR}/include)
install(TARGETS particle DESTINATION lib)

add_library(lj SHARED ${PROJECT_SOURCE_DIR}/src/lennard-jones.cpp)
target_include_directories(lj PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(lj particle)
install(TARGETS lj DESTINATION lib)

add_executable(potential_energy ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/io.cpp)
target_link_libraries(potential_energy lj particle)
install(TARGETS potential_energy DESTINATION bin)
