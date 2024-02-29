

# Add source to this project's executable.
add_executable (CommandLine "CommandLine.cpp" "CommandLine.h")
target_link_libraries(CommandLine PRIVATE nlohmann_json::nlohmann_json)


set_property(TARGET CommandLine PROPERTY CXX_STANDARD 20)


add_custom_target(copy_resources ALL)
add_custom_command(TARGET copy_resources POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/resources 
					$<TARGET_FILE_DIR:CommandLine>/resources)