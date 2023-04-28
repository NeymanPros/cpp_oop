add_executable(doctest_test doctest_test.cpp)
target_link_libraries(doctest_test rational)
add_test(NAME doctest_test COMMAND doctest_test)

add_executable(arrayt_test arrayt_test.cpp)
target_link_libraries(arrayt_test arrayt)
add_test(NAME arrayt_test COMMAND arrayt_test)
