cmake_minimum_required(VERSION 3.21)
project(tictactoe_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(tictactoe_cpp main.cpp player.h tictactoe.h tictactoe.cpp player.cpp)
