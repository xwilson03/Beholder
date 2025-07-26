find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(statpanel
  statpanel.cpp
)
target_include_directories(statpanel
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(statpanel
  PRIVATE
    Qt6::Widgets
)
