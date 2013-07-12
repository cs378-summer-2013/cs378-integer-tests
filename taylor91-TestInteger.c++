// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2013
// Glenn P. Downing
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

#define private public
#define protected public

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

#include "Integer.h"

// -----------
// TestInteger
// -----------

struct TestInteger : CppUnit::TestFixture {
	// -----------------
	// shift_left_digits
	// -----------------

	void test_shift_left_digits () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4, 0, 0};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 2, x);
		CPPUNIT_ASSERT((p - x) == 5);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_left_digits_2 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 0, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_left_digits_3 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 0};
		int x[10];
		const int* p = shift_left_digits(a, a + 2, 1, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	// ------------------
	// shift_right_digits
	// ------------------

	void test_shift_right_digits () {
		const int a[] = {2, 3, 4};
		const int b[] = {2};
		int x[10];
		const int* p = shift_right_digits(a, a + 3, 2, x);
		CPPUNIT_ASSERT((p - x) == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_right_digits_2 () {
		const int a[] = {2, 3, 4};
		int *b;
		int x[10];
		const int* p = shift_right_digits(a, a + 2, 2, x);
		CPPUNIT_ASSERT((p - x) == 0);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	void test_shift_right_digits_3 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4};
		int x[10];
		const int* p = shift_right_digits(a, a + 3, 0, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

	// -----------
	// plus_digits
	// -----------

	void test_plus_digits () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {8, 0, 1};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_plus_digits_2 () {
		const int a[] = {3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {6, 0, 1};
		int x[10];
		const int* p = plus_digits(b, b + 3, a, a + 2, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_plus_digits_3 () {
		const int a[] = {1};
		const int b[] = {1};
		const int c[] = {2};
		int x[10];
		const int* p = plus_digits(a, a + 1, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
	// ------------
	// minus_digits
	// ------------

	void test_minus_digits () {
		const int a[] = {8, 0, 1};
		const int b[] = {5, 6, 7};
		const int c[] = {2, 3, 4};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_minus_digits_2 () {
		const int a[] = {1, 0, 0};
		const int b[] = {1};
		const int c[] = {9, 9};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_minus_digits_3 () {
		const int a[] = {8, 0, 0};
		const int b[] = {8, 0, 0};
		const int c[] = {0};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// -----------------
	// multiplies_digits
	// -----------------

	void test_multiplies_digits () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {1, 3, 2, 6, 7, 8};
		int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_multiplies_digits_2 () {
		const int a[] = {5};
		const int b[] = {2};
		const int c[] = {1, 0};
		int x[10];
		const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_multiplies_digits_3 () {
		const int a[] = {9, 9, 9};
		const int b[] = {9, 9, 9};
		const int c[] = {9, 9, 8, 0, 0, 1};
		int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
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

	void test_divides_digits_2 () {
		const int a[] = {1, 0, 0};
		const int b[] = {2};
		const int c[] = {5, 0};
		int x[10];
		const int* p = divides_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_divides_digits_3 () {
		const int a[] = {2, 5};
		const int b[] = {2};
		const int c[] = {1, 2};
		int x[10];
		const int* p = divides_digits(a, a + 2, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 2);
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
			const Integer<int> x(2);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_4 () {
		try {
			const Integer<int> x(0);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_5 () {
		try {
			const Integer<int> x(-123);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_6 () {
		try {
			const Integer<int> x("-234");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_7 () {
		try {
			const Integer<int> x("0");
			CPPUNIT_ASSERT(x == 0);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_constructor_8 () {
		try {
			const Integer<int> x("0005");
			CPPUNIT_ASSERT(x == 5);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}
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

	void test_abs_3 () {
		try {
			Integer<int> x = 98765;
			Integer<int>& y = x.abs();
			CPPUNIT_ASSERT( x == 98765);
			CPPUNIT_ASSERT(&x == &y);}
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

	void test_equal_to_2() {
		const Integer<int> x = -51;
		const Integer<int> y = -51;
		CPPUNIT_ASSERT( x == y );
		CPPUNIT_ASSERT( !(x != y) );
		CPPUNIT_ASSERT( x == -51 );
		CPPUNIT_ASSERT( y == -51 );
	}

	void test_equal_to_3() {
		const Integer<int> x = -51;
		const Integer<int> y = 51;
		CPPUNIT_ASSERT( x != y );
		CPPUNIT_ASSERT( !(x == y) );
		CPPUNIT_ASSERT( x == -51 );
		CPPUNIT_ASSERT( y == 51 );
	}

	void test_equal_to_4() {
		const Integer<int> x = 0;
		const Integer<int> y = 0;
		CPPUNIT_ASSERT( x == y );
		CPPUNIT_ASSERT( !(x != y ));
		CPPUNIT_ASSERT( x == 0 );
		CPPUNIT_ASSERT( y == 0 );
	}

	// ---------
	// less_than
	// ---------

	void test_less_than() {
		const Integer<int> x = 123;
		const Integer<int> y = 123;
		CPPUNIT_ASSERT(!(x < y));
	}

	void test_less_than_2() {
		const Integer<int> x = 123;
		const Integer<int> y = 12;
		CPPUNIT_ASSERT(y < x);
	}

	void test_less_than_3() {
		const Integer<int> x = 5000;
		const Integer<int> y = 5001;
		CPPUNIT_ASSERT(x < y);
	}

	void test_less_than_4() {
		const Integer<int> x = 0;
		const Integer<int> y = -10;
		CPPUNIT_ASSERT(y < x);
	}

	void test_less_than_5() {
		const Integer<int> x = -11;
		const Integer<int> y = -10;
		CPPUNIT_ASSERT(x < y);
	}

	void test_less_than_6() {
		const Integer<int> x = -999;
		const Integer<int> y = -10;
		CPPUNIT_ASSERT(x < y);
	}

	void test_less_than_7() {
		const Integer<int> x = 9;
		const Integer<int> y = -10;
		CPPUNIT_ASSERT(y < x);
	}

	// -----------
	// plus_equals
	// -----------

	void test_plus_equals() {
		Integer<int> x = 1;
		x += 1;
		CPPUNIT_ASSERT(x == 2);
	}

	void test_plus_equals_2() {
		Integer<int> x = 1;
		x += 9;
		CPPUNIT_ASSERT(x == 10);
	}

	void test_plus_equals_3() {
		Integer<int> x = 6;
		x += 7;
		CPPUNIT_ASSERT(x == 13);
	}

	void test_plus_equals_4() {
		Integer<int> x = 12345;
		Integer<int> y = 87655;
		x += y;
		CPPUNIT_ASSERT(x == 100000);
	}

	void test_plus_equals_5() {
		Integer<int> x = -6;
		Integer<int> y = -4;
		x += y;
		CPPUNIT_ASSERT(x == -10);
	}

	void test_plus_equals_6() {
		Integer<int> x = 6;
		x += -3;
		CPPUNIT_ASSERT(x == 3);
	}

	void test_plus_equals_7() {
		Integer<int> x = -10;
		x += 3;
		CPPUNIT_ASSERT(x == -7);
	}

	void test_plus_equals_8() {
		Integer<int> x = 10;
		x += 0;
		CPPUNIT_ASSERT(x == 10);	
	}

	void test_plus_equals_9() {
		Integer<int> x = 0;
		x += 10;
		CPPUNIT_ASSERT(x == 10);	
	}

	// -----------
	// minus_equals
	// -----------

	void test_minus_equals() {
		Integer<int> x = 1;
		x -= -1;
		CPPUNIT_ASSERT(x == 2);
	}

	void test_minus_equals_2() {
		Integer<int> x = -1;
		x -= 1;
		CPPUNIT_ASSERT(x == -2);
	}

	void test_minus_equals_3() {
		Integer<int> x = 1;
		x -= 1;
		CPPUNIT_ASSERT(x == 0);
	}

	void test_minus_equals_4() {
		Integer<int> x = 10;
		x -= 5;
		CPPUNIT_ASSERT(x == 5);
	}

	void test_minus_equals_5() {
		Integer<int> x = 5;
		x -= 10;
		CPPUNIT_ASSERT(x == -5);
	}

	void test_minus_equals_6() {
		Integer<int> x = -60;
		x -= -30;
		CPPUNIT_ASSERT(x == -30);
	}

	void test_minus_equals_7() {
		Integer<int> x = -30;
		x -= -60;
		CPPUNIT_ASSERT(x == 30);
	}

	// ------------
	// times_equals 
	// ------------

	void test_times_equals() {
		Integer<int> x = 5;
		x *= 2;
		CPPUNIT_ASSERT(x == 10);
	}

	void test_times_equals_2() {
		Integer<int> x = 10;
		x *= 10;
		CPPUNIT_ASSERT(x == 100);	
	}

	void test_times_equals_3() {
		Integer<int> x = 200;
		x *= 25;
		CPPUNIT_ASSERT(x == 5000);	
	}

	void test_times_equals_4() {
		Integer<int> x = 2000;
		x *= 1000;
		CPPUNIT_ASSERT(x == 2000000);
	}

	void test_times_equals_5() {
		Integer<int> x = 1111;
		x *= 1111;
		CPPUNIT_ASSERT(x == 1234321);
	}

	void test_times_equals_6() {
		Integer<int> x = 999999;
		x *= 99999;
		Integer<int> correct("99998900001");
		CPPUNIT_ASSERT(x == correct);
	}

	void test_times_equals_7() {
		Integer<int> x = 10000;
		x *= 10000;
		Integer<int> correct("100000000");
		CPPUNIT_ASSERT(x == correct);
	}
	
	void test_times_equals_8() {
		Integer<int> x = 20000;
		x *= 1000;
		Integer<int> correct("20000000");
		CPPUNIT_ASSERT(x == correct);
	}

	void test_times_equals_9() {
		Integer<int> x = 2;
		x *= -5;
		CPPUNIT_ASSERT(x == -10);
	}
	
	void test_times_equals_10() {
		Integer<int> x = -2;
		x *= -5;
		CPPUNIT_ASSERT(x == 10);
	}

	void test_times_equals_11() {
		Integer<int> x = -2;
		x *= 5;
		CPPUNIT_ASSERT(x == -10);
	}

	// --------------
	// divides_equals
	// --------------
	
	void test_divides_equals() {
		Integer<int> x = 5;
		x /= 2;
		CPPUNIT_ASSERT(x == 2);
	}

	void test_divides_equals_2() {
		Integer<int> x = 10;
		x /= 10;
		CPPUNIT_ASSERT(x == 1);	
	}

	void test_divides_equals_3() {
		Integer<int> x = 200;
		x /= 25;
		CPPUNIT_ASSERT(x == 8);	
	}

	void test_divides_equals_4() {
		Integer<int> x = 200;
		x /= 2;
		CPPUNIT_ASSERT(x == 100);	
	}

	void test_divides_equals_5() {
		Integer<int> x = 200;
		x /= -2;
		CPPUNIT_ASSERT(x == -100);	
	}

	void test_divides_equals_6() {
		Integer<int> x = -200;
		x /= -2;
		CPPUNIT_ASSERT(x == 100);	
	}

	// ----------
	// mod_equals 
	// ----------

	void test_mod_equals() {
		Integer<int> x = 200;
		x %= 2;
		CPPUNIT_ASSERT(x == 0);	
	}

	void test_mod_equals_2() {
		Integer<int> x = 55;
		x %= 7;
		CPPUNIT_ASSERT(x == 6);	
	}

	void test_mod_equals_3() {
		Integer<int> x = 100;
		x %= 57;
		CPPUNIT_ASSERT(x == 43);	
	}
	// ------------------
	// shift_right_equals
	// ------------------

	void test_shift_right_equals() {
		Integer<int> x = 12345;
		x >>= 1;
		CPPUNIT_ASSERT(x == 1234);
	}

	void test_shift_right_equals_2() {
		Integer<int> x = 12345;
		x >>= 0;
		CPPUNIT_ASSERT(x == 12345);
	}

	void test_shift_right_equals_3() {
		Integer<int> x = 12345;
		x >>= 3;
		CPPUNIT_ASSERT(x == 12);
	}

	void test_shift_right_equals_4() {
		Integer<int> x = 12345;
		x >>= 6;
		std::ostringstream out;
		out << x;
		CPPUNIT_ASSERT(out.str() == "");
	}

	// ------------------
	//	shift_left_equals 
	// ------------------

	void test_shift_left_equals() {
		Integer<int> x = 1234;
		x <<= 1;
		CPPUNIT_ASSERT(x == 12340);
	}

	void test_shift_left_equals_2() {
		Integer<int> x = 12345;
		x <<= 0;
		CPPUNIT_ASSERT(x == 12345);
	}

	void test_shift_left_equals_3() {
		Integer<int> x = -5;
		x <<= 3;
		CPPUNIT_ASSERT(x == -5000);
	}

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
			const Integer<int> x = -98765;
			const Integer<int> y = -x;
			CPPUNIT_ASSERT(y == 98765);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_negation_3 () {
		try {
			const Integer<int> x = 0;
			const Integer<int> y = -x;
			CPPUNIT_ASSERT(y == 0);}
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

	void test_output_3 () {
		try {
			const Integer<int> x = 0;
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "0");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	// ---
	// pow
	// ---

	void test_pow_1 () {
		try {
			Integer<int>       x = 10;
			const int          e =  2;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 2);
			CPPUNIT_ASSERT( x == 100);
			CPPUNIT_ASSERT(&x ==   &y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_pow_2 () {
		try {
			Integer<int>       x = 100;
			const int          e =  100;
			Integer<int>&      y = x.pow(e);
			Integer<int> correct("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
			CPPUNIT_ASSERT( e == 100);
			CPPUNIT_ASSERT( x == correct);
			CPPUNIT_ASSERT(&x ==   &y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}}

	void test_pow_3 () {
		try {
			const Integer<int> x = 10;
			const int          e = -1;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(false);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(true);}}

	// ----------
	// valid_test
	// ----------
	
	void test_valid() {
		Integer<int> x (10);
		x.container.push_back((int)'A');
		if (x.valid())
			CPPUNIT_ASSERT(false);
		else
			CPPUNIT_ASSERT(true);
	}
	
	void test_valid_2() {
		Integer<int> x ("10");
		if (x.valid())
			CPPUNIT_ASSERT(true);
		else
			CPPUNIT_ASSERT(false);
	}

	void test_valid_3() {
		Integer<int> x (100000);
		if (x.valid())
			CPPUNIT_ASSERT(true);
		else
			CPPUNIT_ASSERT(false);
	}

	// -----------------------
	// test_trim_leading_zeros 
	// -----------------------
	
	void test_trim_leading_zeros() {
		Integer<int> x (321);
		x.container[0] = 0;	
		x.trim_leading_zeros(x.container);
		CPPUNIT_ASSERT(x == 21);
	}

	void test_trim_leading_zeros_2() {
		Integer<int> x (321);
		x.trim_leading_zeros(x.container);
		CPPUNIT_ASSERT(x == 321);
	}

	void test_trim_leading_zeros_3() {
		Integer<int> x (50000);
		x.container[0] = 0;	
		x.trim_leading_zeros(x.container);
		CPPUNIT_ASSERT(x == 0);
	}

	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE(TestInteger);
	CPPUNIT_TEST(test_shift_left_digits);
	CPPUNIT_TEST(test_shift_left_digits_2);
	CPPUNIT_TEST(test_shift_left_digits_3);
	CPPUNIT_TEST(test_shift_right_digits);
	CPPUNIT_TEST(test_shift_right_digits_2);
	CPPUNIT_TEST(test_shift_right_digits_3);
	CPPUNIT_TEST(test_plus_digits);
	CPPUNIT_TEST(test_plus_digits_2);
	CPPUNIT_TEST(test_plus_digits_3);
	CPPUNIT_TEST(test_minus_digits);
	CPPUNIT_TEST(test_minus_digits_2);
	CPPUNIT_TEST(test_minus_digits_3);
	CPPUNIT_TEST(test_multiplies_digits);
	CPPUNIT_TEST(test_multiplies_digits_2);
	CPPUNIT_TEST(test_multiplies_digits_3);
	CPPUNIT_TEST(test_divides_digits);
	CPPUNIT_TEST(test_divides_digits_2);
	CPPUNIT_TEST(test_divides_digits_3);
	CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_2);
	CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
	CPPUNIT_TEST(test_constructor_5);
	CPPUNIT_TEST(test_constructor_6);
	CPPUNIT_TEST(test_constructor_7);
	CPPUNIT_TEST(test_constructor_8);
	CPPUNIT_TEST(test_abs_1);
	CPPUNIT_TEST(test_abs_2);
	CPPUNIT_TEST(test_abs_3);
	CPPUNIT_TEST(test_equal_to);
	CPPUNIT_TEST(test_equal_to_2);
	CPPUNIT_TEST(test_equal_to_3);
	CPPUNIT_TEST(test_equal_to_4);
	CPPUNIT_TEST(test_less_than);
	CPPUNIT_TEST(test_less_than_2);
	CPPUNIT_TEST(test_less_than_3);
	CPPUNIT_TEST(test_less_than_4);
	CPPUNIT_TEST(test_less_than_5);
	CPPUNIT_TEST(test_less_than_6);
	CPPUNIT_TEST(test_less_than_7);
	CPPUNIT_TEST(test_plus_equals);
	CPPUNIT_TEST(test_plus_equals_2);
	CPPUNIT_TEST(test_plus_equals_3);
	CPPUNIT_TEST(test_plus_equals_4);
	CPPUNIT_TEST(test_plus_equals_5);
	CPPUNIT_TEST(test_plus_equals_6);
	CPPUNIT_TEST(test_plus_equals_7);
	CPPUNIT_TEST(test_plus_equals_8);
	CPPUNIT_TEST(test_plus_equals_9);
	CPPUNIT_TEST(test_minus_equals);
	CPPUNIT_TEST(test_minus_equals_2);
	CPPUNIT_TEST(test_minus_equals_3);
	CPPUNIT_TEST(test_minus_equals_4);
	CPPUNIT_TEST(test_minus_equals_5);
	CPPUNIT_TEST(test_minus_equals_6);
	CPPUNIT_TEST(test_minus_equals_7);
	CPPUNIT_TEST(test_times_equals);
	CPPUNIT_TEST(test_times_equals_2);
	CPPUNIT_TEST(test_times_equals_3);
	CPPUNIT_TEST(test_times_equals_4);
	CPPUNIT_TEST(test_times_equals_5);
	CPPUNIT_TEST(test_times_equals_6);
	CPPUNIT_TEST(test_times_equals_7);
	CPPUNIT_TEST(test_times_equals_8);
	CPPUNIT_TEST(test_times_equals_9);
	CPPUNIT_TEST(test_times_equals_10);
	CPPUNIT_TEST(test_times_equals_11);
	CPPUNIT_TEST(test_divides_equals);
	CPPUNIT_TEST(test_divides_equals_2);
	CPPUNIT_TEST(test_divides_equals_3);
	CPPUNIT_TEST(test_divides_equals_4);
	CPPUNIT_TEST(test_divides_equals_5);
	CPPUNIT_TEST(test_divides_equals_6);
	CPPUNIT_TEST(test_mod_equals);
	CPPUNIT_TEST(test_mod_equals_2);
	CPPUNIT_TEST(test_mod_equals_3);
	CPPUNIT_TEST(test_shift_right_equals);
	CPPUNIT_TEST(test_shift_right_equals_2);
	CPPUNIT_TEST(test_shift_right_equals_3);
	CPPUNIT_TEST(test_shift_right_equals_4);
	CPPUNIT_TEST(test_shift_left_equals);
	CPPUNIT_TEST(test_shift_left_equals_2);
	CPPUNIT_TEST(test_shift_left_equals_3);
	CPPUNIT_TEST(test_negation);
	CPPUNIT_TEST(test_negation_2);
	CPPUNIT_TEST(test_negation_3);
	CPPUNIT_TEST(test_output);
	CPPUNIT_TEST(test_output_2);
	CPPUNIT_TEST(test_output_3);
	CPPUNIT_TEST(test_pow_1);
	CPPUNIT_TEST(test_pow_2);
	CPPUNIT_TEST(test_pow_3);
	CPPUNIT_TEST(test_valid);
	CPPUNIT_TEST(test_valid_2);
	CPPUNIT_TEST(test_valid_3);
	CPPUNIT_TEST(test_trim_leading_zeros);
	CPPUNIT_TEST(test_trim_leading_zeros_2);
	CPPUNIT_TEST(test_trim_leading_zeros_3);
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
