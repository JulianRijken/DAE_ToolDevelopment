

# Add source to this project's executable.
add_executable (CommandLine "CommandLine.cpp" "CommandLine.h")
target_link_libraries(CommandLine PRIVATE nlohmann_json::nlohmann_json)


set_property(TARGET CommandLine PROPERTY CXX_STANDARD 20)
