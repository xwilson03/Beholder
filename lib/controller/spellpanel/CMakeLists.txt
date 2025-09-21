find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(spellpanel_controller
  spellpanel_controller.cpp
)
target_include_directories(spellpanel_controller
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(spellpanel_controller
  PRIVATE
    Qt6::Widgets
  PUBLIC
    spellpanel
    store
)
