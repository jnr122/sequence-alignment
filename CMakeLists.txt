cmake_minimum_required(VERSION 3.13)
project(sequence_alignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(sequence_alignment main.cpp Grid.cpp Sequence_pair.cpp)
add_executable(testing testing.cpp Grid.cpp Sequence_pair.cpp)