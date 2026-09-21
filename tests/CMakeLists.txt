find_package(GTest REQUIRED)

function(add_schema_test aName)
    set(LIB_TARGET  schema_${aName})
    set(TEST_TARGET ${aName}Test)
    set(TEST_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/${aName})
    set(TEST_CPP    ${TEST_DIR}/test_${aName}.cpp)

    add_executable(${TEST_TARGET}
        ${TEST_CPP}
    )
    target_include_directories(${TEST_TARGET}
        PRIVATE ${TEST_DIR}
    )
    target_link_libraries(${TEST_TARGET}
        PRIVATE
            GTest::gtest_main
            ${LIB_TARGET}
    )

    add_test(
        NAME ${TEST_TARGET}
        COMMAND ${TEST_TARGET}
    )
    set_tests_properties(${TEST_TARGET}
        PROPERTIES
        WORKING_DIRECTORY ${TEST_DIR}
    )
endfunction()

add_schema_test(money)
