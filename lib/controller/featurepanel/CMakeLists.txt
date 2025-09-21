find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(featurepanel_controller
  featurepanel_controller.cpp
)
target_include_directories(featurepanel_controller
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(featurepanel_controller
  PRIVATE
    Qt6::Widgets
  PUBLIC
    featurepanel
    store
)
