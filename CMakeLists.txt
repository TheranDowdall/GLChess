cmake_minimum_required(VERSION 3.21.1)

project(Chess)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} app/app.cpp)

add_subdirectory(src)
add_subdirectory(vendor)