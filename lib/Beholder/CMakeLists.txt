find_package(Qt6 COMPONENTS Quick REQUIRED)

install(
  FILES
    qmldir
    NamePlate.qml
    NumberInput.qml
    StatBox.qml
    StatLine.qml
    CombatPanel.qml
    EquipmentPanel.qml
  DESTINATION
    ${CMAKE_INSTALL_QMLDIR}/Beholder
)