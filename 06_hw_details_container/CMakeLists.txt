cmake_minimum_required(VERSION 3.5)

project(container)

add_executable(container main.cpp)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(container PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(container PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

set_target_properties(container PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
