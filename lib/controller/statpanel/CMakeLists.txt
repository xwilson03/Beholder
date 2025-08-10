find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(statpanel_controller
  statpanel_controller.cpp
)
target_include_directories(statpanel_controller
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(statpanel_controller
  PRIVATE
    Qt6::Widgets
  PUBLIC
    statpanel
    store
)
