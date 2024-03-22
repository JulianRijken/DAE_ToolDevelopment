set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED Core)
find_package(Qt6 REQUIRED Gui)
find_package(Qt6 REQUIRED Widgets)

qt_add_executable(CalculatorForm
    calculatorform.cpp
    main.cpp
)

set_target_properties(CalculatorForm PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(CalculatorForm PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

install(TARGETS CalculatorForm DESTINATION bin)
