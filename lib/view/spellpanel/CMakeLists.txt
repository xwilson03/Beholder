find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(spellpanel
  spellpanel.cpp
)
target_include_directories(spellpanel
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(spellpanel
  PRIVATE
    Qt6::Widgets
  PUBLIC
    badge
    panel
)
