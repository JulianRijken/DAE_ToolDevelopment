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
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/0.9.9.8
)


# Make fetch content available
FetchContent_MakeAvailable(json)
FetchContent_MakeAvailable(glm)


 # Include sub-projects.
add_subdirectory ("CommandLine")

