find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(inventorypanel
  inventorypanel.cpp
)
target_include_directories(inventorypanel
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(inventorypanel
  PRIVATE
    Qt6::Widgets
  PUBLIC
    badge
    panel
)
