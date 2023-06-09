project(dectest_test)
add_executable(doctest_test doctest_test.cpp)
add_test(NAME doctest_test COMMAND doctest_test)

project(rational_test)
add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)
add_test(NAME rational_test COMMAND rational_test)

project(arrayd_test)
add_executable(arrayd_test arrayd_test.cpp)
target_link_libraries(arrayd_test arrayd)
add_test(NAME arrayd_test COMMAND arrayd_test)

project(arrayt_test)
add_executable(arrayt_test arrayt_test.cpp)
target_link_libraries(arrayt_test arrayt)
add_test(NAME arrayt_test COMMAND arrayt_test)

project(matrixs_test)
add_executable(matrixs_test matrixs_test.cpp)
target_link_libraries(matrixs_test matrixs)
add_test(NAME matrixs_test COMMAND matrixs_test)