project(dectest_test)
add_executable(doctest_test doctest_test.cpp)
add_test(NAME doctest_test COMMAND doctest_test)

project(rational_test)
add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)
add_test(NAME rational_test COMMAND rational_test)

project(arrayt_test)
add_executable(arrayt_test arrayt_test.cpp)
target_link_libraries(arrayt_test arrayt)
add_test(NAME arrayt_test COMMAND arrayt_test)
