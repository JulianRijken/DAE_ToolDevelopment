set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED Core)
find_package(Qt6 REQUIRED Gui)
find_package(Qt6 REQUIRED Widgets)

qt_add_executable(BlockConverterForm
    calculatorform.cpp
    main.cpp
)

set_target_properties(BlockConverterForm PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(BlockConverterForm PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

target_link_libraries(BlockConverterForm PRIVATE BlockConverterLib)
install(TARGETS BlockConverterForm DESTINATION bin)
