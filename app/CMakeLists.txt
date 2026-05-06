add_executable(Beholder
  main.cpp
)

install(
  TARGETS Beholder
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
