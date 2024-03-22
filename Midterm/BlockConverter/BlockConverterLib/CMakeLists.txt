add_library(BlockConverterLib STATIC "calculator.cpp")

target_include_directories(BlockConverterLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}")
