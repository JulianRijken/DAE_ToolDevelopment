# Add source to this project's executable.
add_executable (CommandLine "CommandLine.cpp" "CommandLine.h")

# Link the nlohmann_json and glm libraries
target_link_libraries(CommandLine PRIVATE nlohmann_json::nlohmann_json glm)

# Set C++ standard to C++20
set_property(TARGET CommandLine PROPERTY CXX_STANDARD 20)

# Copy resources to the build directory
add_custom_target(copy_resources ALL)
add_custom_command(TARGET copy_resources POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources 
    $<TARGET_FILE_DIR:CommandLine>/resources)

# Include directories for glm
target_include_directories(CommandLine PRIVATE ${glm_SOURCE_DIR})