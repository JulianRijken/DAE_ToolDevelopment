cmake_minimum_required (VERSION 3.8)
project("CommandLineProject")

# Include the FetchContent module for CMake
include(FetchContent)

# DEclare the nlohmann_json library as a fetch content
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3 # Specify the version of the library we want to use
)

 # Make fetch content available
 FetchContent_MakeAvailable(json)

 # Include sub-projects.
add_subdirectory ("CommandLine")

