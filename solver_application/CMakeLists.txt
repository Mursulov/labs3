cmake_minimum_required(VERSION 3.16)
project(solver_application)

add_executable(solver_app main.cpp)
target_link_libraries(solver_app PRIVATE formatter_ex solver)
