cmake_minimum_required(VERSION 3.5)

project(05.homework)

add_executable(statistics
    statistics.cpp
    Min.cpp
    Max.cpp
    Mean.cpp
    Std.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(statistics PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(statistics PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(statistics PUBLIC cxx_std_17)

