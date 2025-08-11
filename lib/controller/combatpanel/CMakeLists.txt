find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(combatpanel_controller
  combatpanel_controller.cpp
)
target_include_directories(combatpanel_controller
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(combatpanel_controller
  PRIVATE
    Qt6::Widgets
  PUBLIC
    combatpanel
    store
)
