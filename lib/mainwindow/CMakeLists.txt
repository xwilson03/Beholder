find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(main_window
  mainwindow.cpp
)
target_include_directories(main_window
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(main_window
  PRIVATE
    Qt6::Widgets
    nameplate
)
