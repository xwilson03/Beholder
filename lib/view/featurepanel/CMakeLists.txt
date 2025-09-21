find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(featurepanel
  featurepanel.cpp
)
target_include_directories(featurepanel
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(featurepanel
  PRIVATE
    Qt6::Widgets
  PUBLIC
    badge
    panel
)
