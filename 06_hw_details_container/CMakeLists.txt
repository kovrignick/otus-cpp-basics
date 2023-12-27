cmake_minimum_required(VERSION 3.5)

project(container)

add_executable(container main.cpp)

set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)