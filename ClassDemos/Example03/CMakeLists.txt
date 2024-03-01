cmake_minimum_required(VERSION 3.28)
project(GameProject) #Give the project a name

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

option(MathLibShared "MathLib shared library" ON)

add_subdirectory(Game)
add_subdirectory(MathLib)

target_link_libraries(GameExe PUBLIC MathLib)