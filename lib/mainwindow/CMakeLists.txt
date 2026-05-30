find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_library(mainwindow
  mainwindow.cpp
)
target_include_directories(mainwindow
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(mainwindow
  PRIVATE
    Qt6::Widgets
  PUBLIC
    map
    topbar
)
