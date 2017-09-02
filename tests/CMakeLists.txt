cmake_minimum_required(VERSION 3.6)

set (CMAKE_PREFIX_PATH "‪C:\\Qt\\Tools\\QtCreator\\bin\\Qt5Test.dll")

enable_testing()
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Test REQUIRED)

set(TEST_SOURCE_FILES Tests.cpp)
add_test(TEST_SOURCE_FILES Tests.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})
target_link_libraries(runTests Qt5::Test core)