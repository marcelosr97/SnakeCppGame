# CMakeLists.txt file for SnakeCppGame project.

cmake_minimum_required (VERSION 3.5)
project(SnakeCppGame VERSION 0.1.0)

# Libraries
find_package(OpenCV COMPONENTS)
Include_directories(${OpenCV_INCLUDE_DIRS})

# Source and header files 
Include_directories(src/panel/ src/snake/ src/common/ src/keylistener)
set(SOURCES src/main.cpp src/panel/panel.cpp src/snake/snake.cpp src/keylistener/keylistener.cpp)
set(HEADERS src/panel/panel.h src/snake/snake.h src/common/common_defines.h src/keylistener/keylistener.h)
add_executable(SnakeCppGame ${SOURCES} ${HEADERS})

target_link_libraries(SnakeCppGame ${OpenCV_LIBS})