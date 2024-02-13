cmake_minimum_required(VERSION 3.7.2)

project(topk_words)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    topk_words
    topk_words.cpp
)

target_compile_options(topk_words PRIVATE 
    -g
    -Wall
    -Wextra
    -Werror
    -Wno-unused-parameter
    -pedantic
)
