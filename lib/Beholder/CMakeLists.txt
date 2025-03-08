find_package(Qt6 COMPONENTS Quick REQUIRED)

install(
  FILES
    qmldir
    NamePlate.qml
    NumberInput.qml
    StatBox.qml
    StatLine.qml
    CombatPanel.qml
  DESTINATION
    ${CMAKE_INSTALL_QMLDIR}/Beholder
)