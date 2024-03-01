cmake_minimum_required (VERSION 3.8)
project("CommandLineProject")

# Include the FetchContent module for CMake
include(FetchContent)

# Declare the nlohmann_json library as a fetch content
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3 # Specify the version of the library we want to use
)

# add glm
FetchContent_Declare(
  glm
  URL https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip
  DOWNLOAD_NO_PROGRESS ON
  DOWNLOAD_DIR ${CMAKE_BINARY_DIR}/downloads
)
FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
  FetchContent_Populate(glm)
endif()


# Make fetch content available
FetchContent_MakeAvailable(json)
FetchContent_MakeAvailable(glm)


 # Include sub-projects.
add_subdirectory ("CommandLine")

