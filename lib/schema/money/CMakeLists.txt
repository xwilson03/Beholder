add_library(schema_money)
target_sources(schema_money
  PUBLIC
    FILE_SET CXX_MODULES
    FILES
      money.cppm
)
target_link_libraries(schema_money
  PUBLIC
    reflectcpp::reflectcpp
)
