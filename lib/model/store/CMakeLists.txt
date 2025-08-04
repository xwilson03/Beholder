find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(store
  store.cpp
)
target_include_directories(store
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(store
  PRIVATE
    Qt6::Widgets
)
