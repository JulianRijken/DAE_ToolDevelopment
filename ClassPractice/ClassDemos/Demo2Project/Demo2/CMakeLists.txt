# CMakeList.txt : CMake project for Demo2, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Demo2 "Demo2.cpp" "Demo2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Demo2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_link_libraries(Demo2 PRIVATE nlohmann_json::nlohmann_json)