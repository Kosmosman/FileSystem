cmake_minimum_required(VERSION 3.20)
project(FileSystem)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(Model
        model/filesystem_manager.cpp
        model/filesystem_manager.h
        model/finder.tpp
        model/finder.h)

set(FORMS view/mainwindow.ui)

add_library(View
        view/mainwindow.cpp
        view/mainwindow.h
        view/scroll_area.h
        view/files_labels.h
        )

target_link_libraries(View PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_library(Controller controller/controller.h)
target_link_libraries(Controller PRIVATE Model)
target_include_directories(Controller PRIVATE Model)

add_executable(FileSystem main.cpp)
target_link_libraries(FileSystem PRIVATE Model Controller View Qt6::Widgets)
target_include_directories(FileSystem PRIVATE model)
target_include_directories(FileSystem PRIVATE controller)
target_include_directories(FileSystem PRIVATE view)
