cmake_minimum_required(VERSION 3.5)
project(FileSystem)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(FORMS view/mainwindow.ui)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(View
        view/mainwindow.cpp
        view/mainwindow.h
        view/tree_model.h view/finder.h)

target_link_libraries(View PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_executable(FileSystem main.cpp)
target_include_directories(FileSystem PRIVATE view)
target_link_libraries(FileSystem PRIVATE View Qt6::Widgets)