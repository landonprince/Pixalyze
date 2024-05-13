cmake_minimum_required(VERSION 3.28)
project(Pixalyze)

set(CMAKE_CXX_STANDARD 20)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)


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
        include/core/utils.h
        src/commands/help_command.cpp
        include/commands/help_command.h
        src/commands/load_command.cpp
        include/commands/load_command.h
        src/commands/show_command.cpp
        include/commands/show_command.h
        src/commands/command_trie.cpp
        include/commands/command_trie.h
        src/commands/analyze_command.cpp
        include/commands/analyze_command.h
        src/commands/grayscale_command.cpp
        include/commands/grayscale_command.h
        src/commands/color_command.cpp
        include/commands/color_command.h
        src/commands/save_command.cpp
        include/commands/save_command.h
        src/commands/edges_command.cpp
        include/commands/edges_command.h
        src/commands/ascii_command.cpp
        include/commands/ascii_command.h)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(Pixalyze ${OpenCV_LIBS})