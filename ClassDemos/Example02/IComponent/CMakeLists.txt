add_library(
	# Picking SHARED instead of INTERFACE makes a dll 
	# https://cmake.org/cmake/help/latest/command/add_library.html#interface-libraries
	IComponentLib INTERFACE #Choose a name here
	IComponent.h
	Sprite.h
)

target_include_directories(
	IComponentLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)