add_library(CalculatorLib STATIC "calculator.cpp")

target_include_directories(CalculatorLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}")
