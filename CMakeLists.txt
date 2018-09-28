cmake_minimum_required(VERSION 3.6)

#project name
project(blackjack)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ./src/main.cpp ./src/pile.cpp)

# include directories
include_directories(./src)

# target
add_executable(blackjack ${SOURCE_FILES})