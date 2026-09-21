add_library(io_money
    io.cppm
)
target_sources(io_money
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            io.cppm
)
target_link_libraries(io_money
    PUBLIC
        reflectcpp::reflectcpp
        schema_money
)
