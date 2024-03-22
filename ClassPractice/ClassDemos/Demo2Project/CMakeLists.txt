# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Demo2Project")

include(FetchContent)

Set(PETCHCONTENT_QUIET FALSE)


FetchContent_Declare(
	json
	GIT_REPOSITORY "https://github.com/nlohmann/json.git"
	GIT_TAG v3.11.3 #version
	GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(json)

add_custom_target(copy_resources ALL)

add_custom_command(TARGET copy_resources POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:Demo2>/resources)

# Include sub-projects.
add_subdirectory ("Demo2")
