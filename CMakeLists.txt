cmake_minimum_required(VERSION 3.10)
project(EtherBrowser)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(WEBKIT2GTK REQUIRED webkit2gtk-4.1)

# Include directories
include_directories(
    ${GTK3_INCLUDE_DIRS}
    ${WEBKIT2GTK_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include  # To include your header files
)

# Add the source files
set(SOURCES
    src/main.cpp
    src/core/BrowserEngine.cpp
    src/core/Renderer.cpp
    src/core/SearchManager.cpp
    src/ui/MainWindow.cpp
    src/ui/Searchbar.cpp
)

# Add the executable
add_executable(EtherBrowser ${SOURCES})

# Link the libraries
target_link_libraries(EtherBrowser
    ${GTK3_LIBRARIES}
    ${WEBKIT2GTK_LIBRARIES}
)

# Optional: Set up resource files if needed (like stylesheets and icons)
file(GLOB ICONS ${CMAKE_SOURCE_DIR}/resources/icons/*)
file(GLOB STYLES ${CMAKE_SOURCE_DIR}/resources/styles/*)

# You can copy resources to the build folder if needed
add_custom_command(TARGET EtherBrowser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources/icons
        ${CMAKE_BINARY_DIR}/resources/icons
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources/styles
        ${CMAKE_BINARY_DIR}/resources/styles
)

# Test if necessary (optional, as it depends on how your tests are structured)
enable_testing()

# Add custom tests (uncomment if needed)
# add_subdirectory(tests)

