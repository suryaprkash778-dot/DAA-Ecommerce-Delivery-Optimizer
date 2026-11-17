# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(EcommerceOptimizer C)

# Set the C standard (C11 is standard for modern C development)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Compile main.c into an executable named EcommerceOptimizer
add_executable(EcommerceOptimizer main.c)
