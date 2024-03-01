add_executable(GameExe main.cpp)

if(MathLibShared)
add_custom_command(TARGET GameExe POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:MathLib>
	$<TARGET_FILE_DIR:GameExe>
)
endif()