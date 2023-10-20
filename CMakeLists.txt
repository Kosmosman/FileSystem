CMAKE_MINIMUM_REQUIRED(VERSION 3.25)
PROJECT(FileSystem)
SET(CMAKE_CXX_STANDARD 20)

add_library(Model
        model/filesystem_manager.cpp
        model/filesystem_manager.h
        model/finder.tpp
        model/finder.h)

add_executable(FileSystem main.cpp)
target_link_libraries(FileSystem Model)
target_include_directories(FileSystem PRIVATE model)