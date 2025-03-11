
cmake_minimum_required(VERSION 3.10)
project(MinDistance)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MinDistance3D 
    src/main.cpp 
    src/MinDistance.cpp
)
