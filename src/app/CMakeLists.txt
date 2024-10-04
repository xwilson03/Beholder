# Add primary application executable
qt_add_executable(${PROJECT_NAME}
  main.cpp
  qml.qrc
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt6::Quick Qt6::Gui
)
set_target_properties(${PROJECT_NAME} PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)