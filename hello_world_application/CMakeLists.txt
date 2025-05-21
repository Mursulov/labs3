cmake_minimum_required(VERSION 3.16)
project(hello_world_application)

add_executable(hello_world main.cpp)
target_link_libraries(hello_world PRIVATE formatter_ex)
