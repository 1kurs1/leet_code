cmake_minimum_required(VERSION 3.30)
project(leet_code VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_COMPILER_VERSION 20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/vendor)

add_executable(leet_code 
    longest_substring_without_repeating_characters/main.cpp
    vendor/linked_list.cpp
)