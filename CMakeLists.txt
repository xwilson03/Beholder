# Configure CMake version and project metadata
cmake_minimum_required(VERSION 3.21.1)
project(
  beholder
  VERSION 0.0.0.0
  DESCRIPTION "A DnD Companion App."
  LANGUAGES CXX
)

# Set and require C++ Standard 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Qt6 Libraries and set up Qt compilation environment
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add package subdirectories
add_subdirectory(src/app)