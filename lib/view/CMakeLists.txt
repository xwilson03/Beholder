find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(badge)
add_subdirectory(combatpanel)
add_subdirectory(featurepanel)
add_subdirectory(inventorypanel)
add_subdirectory(mainwindow)
add_subdirectory(nameplate)
add_subdirectory(panel)
add_subdirectory(statpanel)
