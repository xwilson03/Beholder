find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(combatpanel
  combatpanel.cpp
)
target_include_directories(combatpanel
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(combatpanel
  PRIVATE
    Qt6::Widgets
  PUBLIC
    badge
    panel
)
