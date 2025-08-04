find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(panel
  panel.cpp
)
target_include_directories(panel
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(panel
  PRIVATE
    Qt6::Widgets
)
