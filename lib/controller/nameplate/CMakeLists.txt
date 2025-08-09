find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(nameplate_controller
  nameplate_controller.cpp
)
target_include_directories(nameplate_controller
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(nameplate_controller
  PRIVATE
    Qt6::Widgets
  PUBLIC
    nameplate
    store
)
