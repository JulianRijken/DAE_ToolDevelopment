cmake_minimum_required(VERSION 3.16)
project(calculator LANGUAGES CXX)

#TODO: include targets
add_subdirectory(CalculatorLib)

add_subdirectory(CalculatorCmd)
add_subdirectory(CalculatorForm)


#TODO2: set install definitions
include(InstallRequiredSystemLibraries)

set(CPACK_RESOURCE_FILE_LICENESE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")

set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)





