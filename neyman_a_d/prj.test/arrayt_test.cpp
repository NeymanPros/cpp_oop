#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <arrayt/arrayt.hpp>

TEST_CASE("Check") {
	Arrayt<int> a;
	CHECK(a.size() == 0);
} 