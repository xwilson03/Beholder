add_library(io_money
    io.cpp
)
target_link_libraries(io_money
    PUBLIC
        reflectcpp::reflectcpp
        schema_money
)
