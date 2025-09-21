find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(inventorypanel_controller
  inventorypanel_controller.cpp
)
target_include_directories(inventorypanel_controller
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(inventorypanel_controller
  PRIVATE
    Qt6::Widgets
  PUBLIC
    inventorypanel
    store
)
