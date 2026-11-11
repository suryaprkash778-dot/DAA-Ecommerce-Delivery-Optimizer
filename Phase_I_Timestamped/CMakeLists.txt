# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(EcommerceOptimizer)

# The syllabus mandates C++17 or later[cite: 1]
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compile main.cpp into an executable named EcommerceOptimizer[cite: 1]
add_executable(EcommerceOptimizer main.cpp)
