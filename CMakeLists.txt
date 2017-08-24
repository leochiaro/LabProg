cmake_minimum_required(VERSION 3.6)
project(provaQT)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_PREFIX_PATH "/Qt/5.7/mingw53_32/lib/cmake/Qt5Widgets")

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp Subject.h Observer.h Resource.cpp Resource.h MainWindow.cpp MainWindow.h)
add_executable(provaQT main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(provaQT core)