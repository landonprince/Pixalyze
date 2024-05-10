cmake_minimum_required(VERSION 3.28)
project(Pixalyze)

set(CMAKE_CXX_STANDARD 20)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Pixalyze main.cpp
        include/core/command_factory.h
        include/commands/command.h
        include/commands/quit_command.h
        include/core/image_manager.h
        src/commands/quit_command.cpp
        src/commands/command.cpp
        src/core/command_factory.cpp
        src/core/image_manager.cpp
        include/commands/command_impl.h
        include/core/utils.h)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(Pixalyze ${OpenCV_LIBS})