find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(nameplate
  nameplate.cpp
)
target_include_directories(nameplate
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(nameplate
  PRIVATE
    Qt6::Widgets
)
