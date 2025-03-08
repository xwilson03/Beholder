# Configure CMake version and project metadata
cmake_minimum_required(VERSION 3.21.1)
project(
  Beholder
  VERSION 0.0.0.0
  DESCRIPTION "A DnD Companion App."
  LANGUAGES CXX
)

# Set and require C++ Standard 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt meta-compilers
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Enable compile commands generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_QMLDIR ${CMAKE_INSTALL_PREFIX}/qml)
add_compile_definitions(QML_DIR="${CMAKE_INSTALL_QMLDIR}")

# Add subdirectories
add_subdirectory(src)
