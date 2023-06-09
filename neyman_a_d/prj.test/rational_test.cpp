#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <rational/rational.hpp>

TEST_CASE("rational") {
	int32_t eq = 2;
	int32_t mn = 2;
	Rational err(3, 0); //exception; denom_ = 1

	Rational a(6, 2);
	Rational b(3, 1); 
	CHECK(a == b); //reduction
	
	a /= 2;
	b = b / 2;
	CHECK(a == b);
	
	a = a + 2;     //a == 7/2
	eq = 2 + b;    //b == 3/2
	CHECK(eq < a);

	b = a / b;     //b == 7/3
	CHECK(b >= 2);

	b *= 2;
	CHECK(a >= -b);

	std::cin >> a;
	std::cout << a;
}