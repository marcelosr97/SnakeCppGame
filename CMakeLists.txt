# CMakeList.txt: proyecto de CMake para CMakeProject1, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.5)
project(SnakeCppGame VERSION 0.1.0)

# Libraries
find_package(OpenCV COMPONENTS)
Include_directories(${OpenCV_INCLUDE_DIRS})

# Source and header files 
Include_directories(include)
set(SOURCES src/main.cpp src/panel.cpp)
set(HEADERS include/panel.h)
add_executable(SnakeCppGame ${SOURCES} ${HEADERS})

target_link_libraries(SnakeCppGame ${OpenCV_LIBS})