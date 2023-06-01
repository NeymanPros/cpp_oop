#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <arrayt/arrayt.hpp>

TEST_CASE("arraytest") {
	int i = -4;
	ArrayT <int> a(5, i);
	CHECK(a[2] == i);

	for (int t = 0; t < a.ssize(); t++) {
		a[t] = t;
	}

	CHECK(a[4] == 4);

	a.remove(1);

	CHECK(a[1] == 2);

	ptrdiff_t rs = 8;
	a.resize(rs);

	CHECK(a.ssize() == rs);

	for (int t = 0; t < a.ssize(); t++) {
		a[t] = t;
	}

	ptrdiff_t p = 5;
	a.insert(p, 88);

	CHECK(a[5] == 88);

	CHECK(a[p-1] == 4);
}
