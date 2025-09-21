find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Beholder
  main.cpp
)
target_link_libraries(Beholder
  PRIVATE
    Qt6::Widgets
    combatpanel
    combatpanel_controller
    featurepanel
    featurepanel_controller
    main_window
    nameplate
    nameplate_controller
    statpanel
    statpanel_controller
    store
)
set_target_properties(Beholder PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
)

install(
  TARGETS Beholder
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
