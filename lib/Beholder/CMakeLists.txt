find_package(Qt6 COMPONENTS Quick REQUIRED)

install(
  FILES
    qmldir
    NamePlate.qml
  DESTINATION
    ${CMAKE_INSTALL_QMLDIR}/Beholder
)