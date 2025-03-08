find_package(Qt6 COMPONENTS Quick REQUIRED)

add_library(qrc
  qml.qrc
)

# Add primary application executable
add_executable(beholder
  main.cpp
)
target_link_libraries(beholder
  PRIVATE
    Qt6::Quick
    qrc
)
set_target_properties(beholder PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)

install(
  TARGETS beholder
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
