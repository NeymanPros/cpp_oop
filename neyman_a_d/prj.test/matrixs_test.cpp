#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <matrixs/matrixs.hpp>
#include <iostream>
TEST_CASE("Matrix:Reloaded") {
	std::pair<int, int> pp = { 0, 0 };
	MatrixS a(pp);

	CHECK(a.nCols() == 0);
	CHECK(a.nRows() == 0);

	MatrixS b(2, 3);
	for (int i = 0; i < b.nRows(); i++) {
		for (int j = 0; j < b.nCols(); j++) {
			b.at(i, j) = i + j;
		}
	}

	CHECK(b.at(1, 2) == 3);

	a = b;

	CHECK(a.at(0, 0) == b.at(0, 0));

	pp = { 5, 1 };
	a.resize(pp);

	CHECK(a.at(1, 0) == b.at(1, 0));
}