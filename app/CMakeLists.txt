find_package(Qt6 COMPONENTS Quick REQUIRED)

# Add primary application executable
add_executable(Beholder
  main.cpp
)
target_link_libraries(Beholder
  PRIVATE
    Qt6::Quick
)
set_target_properties(Beholder PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)

install(
  TARGETS Beholder
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
  FILES main.qml
  DESTINATION ${CMAKE_INSTALL_QMLDIR}
)