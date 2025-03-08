find_package(Qt6 COMPONENTS Quick REQUIRED)

install(
  FILES
    qmldir
    NamePlate.qml
    NumberInput.qml
  DESTINATION
    ${CMAKE_INSTALL_QMLDIR}/Beholder
)