find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(badge
  badge.cpp
)
target_include_directories(badge
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(badge
  PRIVATE
    Qt6::Widgets
)
