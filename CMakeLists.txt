cmake_minimum_required(VERSION 3.10)
project(xcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/window.cpp
    src/sphere.cpp
)

add_executable(xcode ${SOURCES})

find_package(X11 REQUIRED)
target_link_libraries(xcode ${X11_LIBRARIES})
target_include_directories(xcode PRIVATE ${X11_INCLUDE_DIR})

