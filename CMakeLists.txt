# Configure CMake version and project metadata
cmake_minimum_required(VERSION 3.21.1)
project(
  Beholder
  VERSION 0.0.0.0
  DESCRIPTION "A DnD Companion App."
  LANGUAGES CXX
)

# Set and require C++ Standard 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compile commands generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(app)
