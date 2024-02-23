if(MathLibShared)
	add_definitions(-DMATH_LIB_SHARED) #Define MATH_LIB_SHARED for Vector2f.h
	set(LIB_TYPE SHARED)
else()
	set(LIB_TYPE STATIC)
endif()

add_library(MathLib ${LIB_TYPE}
	Vector2f.cpp
	Vector2f.h
)

target_include_directories(MathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
