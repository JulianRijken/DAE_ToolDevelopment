add_executable(CalculatorCmd "main.cpp")

target_link_libraries(CalculatorCmd PRIVATE CalculatorLib)

install(TARGETS CalculatorCmd DESTINATION bin)