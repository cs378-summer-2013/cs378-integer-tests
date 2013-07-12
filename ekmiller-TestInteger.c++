// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------
// Modified by Zachary Lozano
// and Eli Miller
// July 2013
// --------------------------------

/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Integer.c++ TestInteger.c++ -o TestInteger -lcppunit -ldl
% valgrind TestInteger > TestInteger.out
*/



// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#include "Integer.h"

// -----------
// TestInteger
// -----------

struct TestInteger : CppUnit::TestFixture {
	// -----------------
	// shift_left_digits
	// -----------------

	void test_shift_left_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4, 0, 0};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 2, x);
		CPPUNIT_ASSERT((p - x) == 5);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_left_digits_2 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4, 0, 0, 0, 0, 0};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 5, x);
		CPPUNIT_ASSERT((p - x) == 8);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_left_digits_3 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 0, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	// ------------------
	// shift_right_digits
	// ------------------

	void test_shift_right_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2};
		int x[10];
		const int* p = shift_right_digits(a, a + 3, 2, x);
		CPPUNIT_ASSERT((p - x) == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_right_digits_2 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4};
		int x[10];
		const int* p = shift_right_digits(a, a + 3, 0, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_right_digits_3 () {
		const int a[] = {2, 3, 4};
		const int b[] = {0};
		int x[10];
		const int* p = shift_right_digits(a, a + 3, 3, x);
		CPPUNIT_ASSERT((p - x) == 0);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	// -----------
	// plus_digits
	// -----------

	void test_plus_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {8, 0, 1};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 3, x);

		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_plus_digits_2 () {
		const int a[] = {9, 9, 9};
		const int b[] = {9, 9, 9};
		const int c[] = {1, 9, 9, 8};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 3, x);

		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_plus_digits_3 () {
		const int a[] = {9, 9, 9};
		const int b[] = {1};
		const int c[] = {1, 0, 0, 0};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 1, x);

		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// ------------
	// minus_digits
	// ------------

	void test_minus_digits_1 () {
		const int a[] = {8, 0, 1};
		const int b[] = {5, 6, 7};
		const int c[] = {2, 3, 4};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_minus_digits_2 () {
		const int a[] = {9, 9, 9};
		const int b[] = {9, 9, 9};
		const int c[] = {0, 0, 0};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_minus_digits_3 () {
		const int a[] = {1, 0, 0};
		const int b[] = {1};
		const int c[] = {0, 9, 9};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// -----------------
	// multiplies_digits
	// -----------------

	void test_multiplies_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {1, 3, 2, 6, 7, 8};
		int x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_multiplies_digits_2 () {
		const int a[] = {1, 2, 3};
		const int b[] = {1};
		const int c[] = {1, 2, 3};
		int x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_multiplies_digits_3 () {
		const int a[] = {9, 9, 9};
		const int b[] = {9, 9, 9};
		const int c[] = {9, 9, 8, 0, 0, 1};
		int x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_multiplies_digits_4 () {
		const int a[] = {9, 9, 9};
		const int b[] = {0};
		const int c[] = {0};
		int x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// --------------
	// divides_digits
	// --------------

	void test_divides_digits () {
		const int a[] = {1, 3, 2, 6, 7, 8};
		const int b[] = {5, 6, 7};
		const int c[] = {2, 3, 4};
		int x[10];
		const int* p = divides_digits(a, a + 6, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// -----------
	// constructor
	// -----------

	void test_constructor_1 () {
		try {
			const Integer<int> x("abc");
			CPPUNIT_ASSERT(false);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

	void test_constructor_2 () {
		try {
			const Integer<int> x("2");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_3 () {
		try {
			const Integer<int> x(2);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_4 () {
		try {
			const Integer<int> x = 1234;
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	// --------
	// addition
	// --------

	void test_Integer_addition_1 () {
		Integer<int> x = 123;
		Integer<int> y =  12;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 135); }

	void test_Integer_addition_2 () {
		Integer<int> x = 123;
		Integer<int> y = -12;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 111); }

	void test_Integer_addition_3 () {
		Integer<int> x = -123;
		Integer<int> y =   12;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == -111); }

	void test_Integer_addition_4 () {
		Integer<int> x = -123;
		Integer<int> y =  -12;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == -135); }

	void test_Integer_addition_5 () {
		Integer<int> x =  12;
		Integer<int> y = 123;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 135); }

	void test_Integer_addition_6 () {
		Integer<int> x =   12;
		Integer<int> y = -123;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == -111); }

	void test_Integer_addition_7 () {
		Integer<int> x = -12;
		Integer<int> y = 123;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 111); }

	void test_Integer_addition_8 () {
		Integer<int> x =  -12;
		Integer<int> y = -123;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == -135); }

	// -----------
	// subtraction
	// -----------

	void test_Integer_subtraction_1 () {
		Integer<int> x = 123;
		Integer<int> y = 12;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 111); }

	void test_Integer_subtraction_2 () {
		Integer<int> x = -123;
		Integer<int> y = 12;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == -135); }

	void test_Integer_subtraction_3 () {
		Integer<int> x = 123;
		Integer<int> y = -12;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 135); }

	void test_Integer_subtraction_4 () {
		Integer<int> x = -123;
		Integer<int> y = -12;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 111); }

	void test_Integer_subtraction_5 () {
		Integer<int> x = 12;
		Integer<int> y = 123;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == -111); }

	void test_Integer_subtraction_6 () {
		Integer<int> x = -12;
		Integer<int> y = 123;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == -135); }

	void test_Integer_subtraction_7 () {
		Integer<int> x = 12;
		Integer<int> y = -123;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 135); }

	void test_Integer_subtraction_8 () {
		Integer<int> x = -12;
		Integer<int> y = -123;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 111); }

	// --------------
	// multiplication
	// --------------

	void test_Integer_multiplication_1 () {
		Integer<int> x =  2;
		Integer<int> y = 12;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 24); }

	void test_Integer_multiplication_2 () {
		Integer<int> x = -2;
		Integer<int> y = 12;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == -24); }

	void test_Integer_multiplication_3 () {
		Integer<int> x =   2;
		Integer<int> y = -12;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == -24); }

	void test_Integer_multiplication_4 () {
		Integer<int> x =  -2;
		Integer<int> y = -12;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 24); }

	void test_Integer_multiplication_5 () {
		Integer<int> x = 0;
		Integer<int> y = 123098;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 0); }

	void test_Integer_multiplication_6 () {
		Integer<int> x = 124125;
		Integer<int> y = 0;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 0); }

	// -------
	// divison
	// -------

	void test_Integer_division_1 () {
		Integer<int> x = 100;
		Integer<int> y = 10;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 10); }

	void test_Integer_division_2 () {
		Integer<int> x = 109;
		Integer<int> y = 10;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 10); }

	void test_Integer_division_3 () {
		Integer<int> x = -109;
		Integer<int> y = 10;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == -10); }

	void test_Integer_division_4 () {
		Integer<int> x = 109;
		Integer<int> y = -10;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == -10); }

	void test_Integer_division_5 () {
		Integer<int> x = 10;
		Integer<int> y = 1202184821;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 0); }

	void test_Integer_division_6 () {
		Integer<int> x = -100;
		Integer<int> y = -100;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 1); }

	void test_Integer_division_7 () {
		try {
			Integer<int>  x = -98765;
			Integer<int>  y = 0;
			Integer<int>  z = x / y;
			CPPUNIT_ASSERT(false); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(true); } }

	// ---
	// abs
	// ---

	void test_abs_1 () {
		try {
			Integer<int>  x = -98765;
			Integer<int>& y = x.abs();
			CPPUNIT_ASSERT( x == 98765);
			CPPUNIT_ASSERT(&x == &y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_abs_2 () {
		try {
			const Integer<int> x = -98765;
			const Integer<int> y = abs(x);
			CPPUNIT_ASSERT(x == -98765);
			CPPUNIT_ASSERT(y ==  98765);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}


	// --------
	// equal_to
	// --------

	void test_equal_to () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = 98765;
			CPPUNIT_ASSERT(      x == y);
			CPPUNIT_ASSERT(      x == 98765);
			CPPUNIT_ASSERT(  98765 == x);
			CPPUNIT_ASSERT(    !(x != y));
			CPPUNIT_ASSERT(    !(x != 98765));
			CPPUNIT_ASSERT(!(98765 != y));}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}
	
	void test_equal_to_2 () {
		try {
			const Integer<int> x = -98765;
			const Integer<int> y =  98765;
			CPPUNIT_ASSERT(      x != y);
			CPPUNIT_ASSERT(      x == -98765);
			CPPUNIT_ASSERT(  -98765 == x);
			CPPUNIT_ASSERT(    !(x == y));
			CPPUNIT_ASSERT(    !(x != 98765));
			CPPUNIT_ASSERT(!(98765 != y));}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_equal_to_3 () {
		try {
			const Integer<int> x = 0;
			const Integer<int> y = 0;
			CPPUNIT_ASSERT(      x == y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}


	// -----------------
	// less_than (equal)
	// -----------------

	void test_less_than_1 () {
		try {
			const Integer<int> x = 12345;
			const Integer<int> y =  1234;
			CPPUNIT_ASSERT(      y <  x);
			CPPUNIT_ASSERT(      y <  12345);
			CPPUNIT_ASSERT(      y <= 12345);
			CPPUNIT_ASSERT(      x <= 12345); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_less_than_2 () {
		try {
			const Integer<int> x = -12345;
			const Integer<int> y =   1234;
			CPPUNIT_ASSERT(      x <  y);
			CPPUNIT_ASSERT(      x <= y);
			CPPUNIT_ASSERT(      x <= -12345); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false); }}

	void test_less_than_3 () {
		try {
			const Integer<int> x = -12345;
			const Integer<int> y =  12345;
			CPPUNIT_ASSERT(      x <  y);
			CPPUNIT_ASSERT(      x <= y);
			CPPUNIT_ASSERT(      x <= -12345); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false); }}

	void test_less_than_4 () {
		try {
			const Integer<int> x =  12345;
			const Integer<int> y =  12345;
			CPPUNIT_ASSERT(      x <= y);
			CPPUNIT_ASSERT(      x <= 12345); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false); }}


	// --------------------
	// greater_than (equal)
	// --------------------

	void test_greater_than_1 () {
		try {
			const Integer<int> x = 12345;
			const Integer<int> y =  1234;
			CPPUNIT_ASSERT(      !(y >  x));
			CPPUNIT_ASSERT(      x > y);
			CPPUNIT_ASSERT(      x >= 12345);
			CPPUNIT_ASSERT(      x >= y); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_greater_than_2 () {
		try {
			const Integer<int> x = -12345;
			const Integer<int> y =   1234;
			CPPUNIT_ASSERT(      !(x >  y));
			CPPUNIT_ASSERT(      y >= x);
			CPPUNIT_ASSERT(      x >= -12345); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false); }}

	void test_greater_than_3 () {
		try {
			const Integer<int> x = -1234;
			const Integer<int> y = -1234;
			CPPUNIT_ASSERT(      !(x >  y));
			CPPUNIT_ASSERT(      y >= x);
			CPPUNIT_ASSERT(      x >= -12345); }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false); }}

	// --------
	// negation
	// --------

	void test_negation () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = -x;
			CPPUNIT_ASSERT(y == -98765);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_negation_2 () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = -(-x);
			CPPUNIT_ASSERT(y == 98765);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_negation_3 () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = -98765;
			CPPUNIT_ASSERT(y == -98765);
			CPPUNIT_ASSERT(y != x);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}


	// ------
	// output
	// ------

	void test_output () {
		try {
			const Integer<int> x = 98765;
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "98765");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_output_2 () {
		try {
			const Integer<int> x = -98765;
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "-98765");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}


	// ---
	// pow
	// ---

	void test_pow_1 () {
		try {
			Integer<int>       x = 10;
			const int          e =  3;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 3);
			CPPUNIT_ASSERT( x == 1000);
			CPPUNIT_ASSERT(&x == &y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_pow_2 () {
		try {
			const Integer<int> x = 124;
			const int          e =  14;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == 124);
			CPPUNIT_ASSERT(e ==  14);
			CPPUNIT_ASSERT(y == Integer<int>("203190590417428920928489701376"));}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_pow_3 () {
		try {
			Integer<int>       x = 10;
			const int          e = -2;
			x.pow(e);
			CPPUNIT_ASSERT(false);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(true);}}


	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE(TestInteger);
	CPPUNIT_TEST(test_shift_left_digits_1);
	CPPUNIT_TEST(test_shift_left_digits_2);
	CPPUNIT_TEST(test_shift_left_digits_3);
	CPPUNIT_TEST(test_shift_right_digits_1);
	CPPUNIT_TEST(test_shift_right_digits_2);
	CPPUNIT_TEST(test_shift_right_digits_3);
	CPPUNIT_TEST(test_plus_digits_1);
	CPPUNIT_TEST(test_plus_digits_2);
	CPPUNIT_TEST(test_plus_digits_3);
	CPPUNIT_TEST(test_minus_digits_1);
	CPPUNIT_TEST(test_minus_digits_2);
	CPPUNIT_TEST(test_minus_digits_3);
	CPPUNIT_TEST(test_multiplies_digits_1);
	CPPUNIT_TEST(test_multiplies_digits_2);
	CPPUNIT_TEST(test_multiplies_digits_3);
	//CPPUNIT_TEST(test_divides_digits);
	CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_2);
	CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
	CPPUNIT_TEST(test_Integer_addition_1);
	CPPUNIT_TEST(test_Integer_addition_2);
	CPPUNIT_TEST(test_Integer_addition_3);
	CPPUNIT_TEST(test_Integer_addition_4);
	CPPUNIT_TEST(test_Integer_addition_5);
	CPPUNIT_TEST(test_Integer_addition_6);
	CPPUNIT_TEST(test_Integer_addition_7);
	CPPUNIT_TEST(test_Integer_addition_8);
	CPPUNIT_TEST(test_Integer_subtraction_1);
	CPPUNIT_TEST(test_Integer_subtraction_2);
	CPPUNIT_TEST(test_Integer_subtraction_3);
	CPPUNIT_TEST(test_Integer_subtraction_4);
	CPPUNIT_TEST(test_Integer_subtraction_5);
	CPPUNIT_TEST(test_Integer_subtraction_6);
	CPPUNIT_TEST(test_Integer_subtraction_7);
	CPPUNIT_TEST(test_Integer_subtraction_8);
	CPPUNIT_TEST(test_Integer_multiplication_1);
	CPPUNIT_TEST(test_Integer_multiplication_2);
	CPPUNIT_TEST(test_Integer_multiplication_3);
	CPPUNIT_TEST(test_Integer_multiplication_4);
	CPPUNIT_TEST(test_Integer_multiplication_5);
	CPPUNIT_TEST(test_Integer_multiplication_6);
	CPPUNIT_TEST(test_Integer_division_1);
	CPPUNIT_TEST(test_Integer_division_2);
	CPPUNIT_TEST(test_Integer_division_3);
	CPPUNIT_TEST(test_Integer_division_4);
	CPPUNIT_TEST(test_Integer_division_5);
	CPPUNIT_TEST(test_Integer_division_6);
	CPPUNIT_TEST(test_Integer_division_7);
	CPPUNIT_TEST(test_abs_1);
	CPPUNIT_TEST(test_abs_2);
	CPPUNIT_TEST(test_equal_to);
	CPPUNIT_TEST(test_less_than_1);
	CPPUNIT_TEST(test_less_than_2);
	CPPUNIT_TEST(test_less_than_3);
	CPPUNIT_TEST(test_less_than_4);
	CPPUNIT_TEST(test_greater_than_1);
	CPPUNIT_TEST(test_greater_than_2);
	CPPUNIT_TEST(test_greater_than_3);
	CPPUNIT_TEST(test_negation);
	CPPUNIT_TEST(test_negation_2);
	CPPUNIT_TEST(test_negation_3);
	CPPUNIT_TEST(test_output);
	CPPUNIT_TEST(test_output_2);
	CPPUNIT_TEST(test_pow_1);
	CPPUNIT_TEST(test_pow_2);
	CPPUNIT_TEST(test_pow_3);
	CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
	using namespace std;
	cout << "TestInteger.c++" << endl;

	CppUnit::TextTestRunner tr;
	tr.addTest(TestInteger::suite());
	tr.run();

	cout << "Done." << endl;
	return 0;}
