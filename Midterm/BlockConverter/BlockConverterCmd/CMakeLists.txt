add_executable(BlockConverterCmd "main.cpp")

target_link_libraries(BlockConverterCmd PRIVATE BlockConverterLib)
install(TARGETS BlockConverterCmd DESTINATION bin)
