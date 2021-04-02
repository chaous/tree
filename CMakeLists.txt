cmake_minimum_required(VERSION 3.17)
project(tree C)

set(CMAKE_C_STANDARD 11)

add_executable(tree main.c tree.h tree.c input.h input.c)