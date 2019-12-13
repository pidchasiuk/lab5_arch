cmake_minimum_required(VERSION 3.5)

project(lab5)

add_executable(lab5 main.cpp)

set(CMAKE_CXX_STANDARD 11)
add_library(Todo todo.cpp)

target_link_libraries(lab5 PUBLIC Todo)


