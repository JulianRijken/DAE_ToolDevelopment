cmake_minimum_required(VERSION 3.24)
project(GamePorject2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Game)
add_subdirectory(IComponent)

#Link librarie to GameExe
target_link_libraries(GameExe PUBLIC IComponentLib)