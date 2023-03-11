cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME factory)

set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES
  src/*.cpp
  src/**/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
