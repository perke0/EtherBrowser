cmake_minimum_required(VERSION 3.10)

project(MyBrowser)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(MyBrowser ${SOURCES})

# Include directories
target_include_directories(MyBrowser PRIVATE include)

# Link Qt libraries (example for Qt5)
find_package(Qt5Widgets REQUIRED)
target_link_libraries(MyBrowser Qt5::Widgets)
