cmake_minimum_required(VERSION 3.5)

project(Guess_my_number)

add_executable(
	guess_my_number
	guess_my_number.cpp
	guess_my_num_utils.cpp
)

set_target_properties(guess_my_number PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
