cmake_minimum_required(VERSION 3.16)
project(calculatorform LANGUAGES CXX)

#TODO: SET CORRECT QT BASE DIR HERE
set(QtBaseDir "C:/Qt/6.6.2/mingw_64")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED Core)
find_package(Qt6 REQUIRED Gui)
find_package(Qt6 REQUIRED Widgets)

qt_add_executable(calculatorform
    calculatorform.cpp calculatorform.h calculatorform.ui
    main.cpp
)

set_target_properties(calculatorform PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(calculatorform PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

add_custom_command(TARGET calculatorform POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_if_different "${QtBaseDir}/bin/Qt6Core.dll"
$<TARGET_FILE_DIR:calculatorform>
COMMAND ${CMAKE_COMMAND} -E copy_if_different "${QtBaseDir}/bin/Qt6Gui.dll"
$<TARGET_FILE_DIR:calculatorform>
COMMAND ${CMAKE_COMMAND} -E copy_if_different "${QtBaseDir}/bin/Qt6Widgets.dll"
$<TARGET_FILE_DIR:calculatorform>
COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:calculatorform>/platforms"
COMMAND ${CMAKE_COMMAND} -E copy_if_different "${QtBaseDir}/plugins/platforms/qwindows.dll"
"$<TARGET_FILE_DIR:calculatorform>/platforms"
)


##the following part will generate installation rules.
install(TARGETS calculatorform DESTINATION bin)

#TODO2: Use foreach to replace first 3 install commands
install(FILES "${QtBaseDir}/bin/Qt6Core.dll" DESTINATION bin)
install(FILES "${QtBaseDir}/bin/Qt6Gui.dll" DESTINATION bin)
install(FILES "${QtBaseDir}/bin/Qt6Widgets.dll" DESTINATION bin)

install(FILES "${QtBaseDir}/plugins/platforms/qwindows.dll" DESTINATION bin/platforms)

include (InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "2")


set(CPACK_PACKAGE_INSTALL_DIRECTORY "ExampleJulator")
#set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
set(CPACK_CREATE_DESKTOP_LINKS "calculatorform" "ExampleJulator")
set(CPACK_PACKAGE_EXECUTABLES  "calculatorform" "ExampleJulator")


set(CPACK_NSIS_INSTALLED_ICON_NAME "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
set(CPACK_)


set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)
