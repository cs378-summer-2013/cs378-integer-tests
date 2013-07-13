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

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==
#include <vector>
#include <iostream>
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

	void test_shift_left_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4, 0, 0};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 2, x);
		CPPUNIT_ASSERT((p - x) == 5);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_left_digits_2 () {
		const int a[] = {1};
		const int b[] = {1, 0, 0, 0, 0};
		int x[10];
		const int* p = shift_left_digits(a, a + 1, 4, x);
		CPPUNIT_ASSERT((p - x) == 5);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_left_digits_3 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2, 3, 4};
		int x[10];
		const int* p = shift_left_digits(a, a + 3, 0, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	// ------------------
	// shift_right_digits
	// ------------------

	void test_shift_right_digits_1 () {
		const int a[] = {1, 2, 3, 4};
		const int b[] = {1, 2};
		int x[10];
		const int* p = shift_right_digits(a, a + 4, 2, x);
		CPPUNIT_ASSERT((p - x) == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_right_digits_2 () {
		const int a[] = {1, 2, 3, 4};
		const int b[] = {0};
		int x[10];
		const int* p = shift_right_digits(a, a + 4, 4, x);
		CPPUNIT_ASSERT((p - x) == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_right_digits_3 () {
		const int a[] = {1, 2, 3, 4};
		const int b[] = {1};
		int x[10];
		const int* p = shift_right_digits(a, a + 4, 3, x);
		CPPUNIT_ASSERT((p - x) == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}


	// -----------
	// plus_digits
	// -----------

	void test_plus_digits_1 () {
		const int a[] = {1, 2, 3};
		const int b[] = {5};
		const int c[] = {1, 2, 8};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_2 () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {8, 0, 1};
		//int x[10];
		std::vector<int> x(10);
		std::vector<int>::iterator p = plus_digits(a, a + 3, b, b + 3, x.begin());
		CPPUNIT_ASSERT(p - x.begin() == 3);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c));
	}

	void test_plus_digits_3 () {
		const int a[] = {5};
		const int b[] = {1, 2, 3};
		const int c[] = {1, 2, 8};
		int x[10];
		const int* p = plus_digits(a, a + 1, b, b + 3, x);
		CPPUNIT_ASSERT((p - x) == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
	void test_plus_digits_4 () {
		const int a[] = {0};
		const int b[] = {0};
		const int c[] = {0};
		int x[10];
		const int* p = plus_digits(a, a + 1, b, b + 1, x);
		CPPUNIT_ASSERT((p - x) == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
	void test_plus_digits_5 () {
		const int a[] = {9, 9, 9};
		const int b[] = {1};
		const int c[] = {1, 0, 0, 0};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT((p - x) == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_6 () {
		const int a[] = {9, 9, 9};
		const int b[] = {1, 1, 1};
		const int c[] = {1, 1, 1, 0};
		int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT((p - x) == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_7 () {
		const int a[] = {27, 21, 18, 0, 0};
		const int b[] = {0};
		const int c[] = {2, 9, 2, 8, 0, 0};
		int x[10];
		const int* p = plus_digits(a, a + 5, b, b + 1, x);
		CPPUNIT_ASSERT((p - x) == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

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
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_minus_digits_2 () {
		const int a[] = {1, 0, 0};
		const int b[] = {9, 9};
		const int c[] = {1};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 2, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_minus_digits_3 () {
		const int a[] = {8, 0, 1};
		const int b[] = {5, 6, 7};
		const int c[] = {2, 3, 4};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
	void test_minus_digits_4 () {
		const int a[] = {1, 0, 0};
		const int b[] = {1, 0, 0};
		const int c[] = {0};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_minus_digits_5 () {
		const int a[] = {1, 0, 0};
		const int b[] = {1};
		const int c[] = {9, 9};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_minus_digits_6 () {
		int a[] = {1, 0, 0};
		const int b[] = {1};
		const int c[] = {9, 9};
		const int* p = minus_digits(a, a + 3, b, b + 1, a);
		CPPUNIT_ASSERT(p - a == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(a), p, c));
	}

	void test_minus_digits_7 () {
		int a[] = {1, 0, 8};
		const int b[] = {2, 3};
		const int c[] = {8, 5};
		int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 2, x);
		CPPUNIT_ASSERT(p - x == 2);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	// -----------------
	// multiplies_digits
	// -----------------


	void test_multiplies_digits_1 () {
		const int a[] = {1, 1, 1};
		const int b[] = {3, 3, 3};
		const int c[] = {3, 6, 9, 6, 3};
		int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 5);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_multiplies_digits_2 () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {1, 3, 2, 6, 7, 8};
		int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_multiplies_digits_3 () {
		const int a[] = {1};
		const int b[] = {5, 6, 7};
		const int c[] = {5, 6, 7};
		int x[10];
		const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_multiplies_digits_4 () {
		const int a[] = {0};
		const int b[] = {5, 6, 7};
		const int c[] = {0};
		int x[10];
		const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_multiplies_digits_5 () {
		const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		const int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		const int c[] = {1,5,2,4,1,5,7,8,7,5,0,1,9,0,5,2,1};
		int x[20];
		const int* p = multiplies_digits(a, a + 9, b, b + 9, x);
		CPPUNIT_ASSERT(p - x == 17);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_multiplies_digits_6 () {
		const int a[] = {9, 7, 6};
		const int b[] = {3, 2, 1};
		const int c[] = {3, 1, 3, 2, 9, 6};
		int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	// --------------
	// divides_digits
	// --------------

	void test_divides_digits_1 () {
		const int a[] = {9, 7, 6, 8};
		const int b[] = {2, 3};
		const int c[] = {4, 2, 4};
		int x[10];
		const int* p = divides_digits(a, a + 4, b, b + 2, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_divides_digits_2 () {
		const int a[] = {9, 7, 6, 8};
		const int b[] = {0};
		const int c[] = {0};
		int x[10];
		const int* p = divides_digits(a, a + 4, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_divides_digits_3 () {
		const int a[] = {1,0,0,0,0,0};
		const int b[] = {2, 3};
		const int c[] = {4, 3, 4, 7};
		int x[10];
		const int* p = divides_digits(a, a + 6, b, b + 2, x);
		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_divides_digits_4 () {
		const int a[] = {1};
		const int b[] = {2, 3};
		const int c[] = {0};
		int x[10];
		const int* p = divides_digits(a, a + 1, b, b + 2, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_divides_digits_5 () {
		const int a[] = {9, 7, 6, 8};
		const int b[] = {1};
		const int c[] = {9, 7, 6, 8};
		int x[10];

		const int* p = divides_digits(a, a + 4, b, b + 1, x);

		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
	void test_divides_digits_6 () {
		const int a[] = {1};
		const int b[] = {1};
		const int c[] = {1};
		int x[10];
		const int* p = divides_digits(a, a + 1, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

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
			const Integer<int> x("-3");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}
	}


	void test_constructor_5 () {
		try {
			const Integer<int> x("123a456");
			CPPUNIT_ASSERT(false);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}
	}
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
			CPPUNIT_ASSERT(false);
		}
	}

	void test_abs_2 () {
		try {
			const Integer<int> x = -98765;
			const Integer<int> y = abs(x);
			CPPUNIT_ASSERT(x == -98765);
			CPPUNIT_ASSERT(y ==  98765);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}
	void test_abs_3 () {
		try {
			Integer<int>  x = -123;
			x.abs();
			CPPUNIT_ASSERT(x == 123);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	// --------
	// equal_to
	// --------

	void test_equal_to_1 () {
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
			CPPUNIT_ASSERT(false);
		}
	}

	void test_equal_to_2 () {
		try {
			const Integer<int> x = 1;
			const Integer<int> y = -1;
			CPPUNIT_ASSERT(      x != y);
			CPPUNIT_ASSERT(      x == 1);
			CPPUNIT_ASSERT(  1 == x);
			CPPUNIT_ASSERT(    y == -1);
			CPPUNIT_ASSERT(   -1 == y);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_equal_to_3 () {
		try {
			const Integer<int> x = 123;
			const Integer<int> y ("123");
			const Integer<int> z (-123);
			CPPUNIT_ASSERT(      x == y);
			CPPUNIT_ASSERT(      x == 123);
			CPPUNIT_ASSERT(  123 == x);
			CPPUNIT_ASSERT(    y != z);
			CPPUNIT_ASSERT(!(123 != y));}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	// --------
	// negation
	// --------

	void test_negation_1 () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = -x;;
			CPPUNIT_ASSERT(y == -98765);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_negation_2 () {
		try {
			const Integer<int> x ("-123");
			const Integer<int> y = -x;;
			CPPUNIT_ASSERT(y == 123);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_negation_3 () {
		try {
			const Integer<int> x (123);
			const Integer<int> y = -(-x);
			CPPUNIT_ASSERT(y == 123);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	// ------
	// output
	// ------

	void test_output_1 () {
		try {
			const Integer<int> x = 98765;
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "98765");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}
	}

	void test_output_2 () {
		try {
			const Integer<int> x ("123");
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "123");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}
	}

	void test_output_3 () {
		try {
			const Integer<int> x (123);
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "123");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}
	}

	// ---
	// pow
	// ---

	void test_pow_1 () {
		try {
			Integer<int>       x = 2;
			const int          e =  2;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 2);
			CPPUNIT_ASSERT( x ==    4);
			CPPUNIT_ASSERT(&x ==   &y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}
	}

	void test_pow_2 () {
		try {
			const Integer<int> x = 98765;
			const int          e =  9867;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == 98765);
			CPPUNIT_ASSERT(e ==  9867);
			CPPUNIT_ASSERT(y ==     0);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_3 () {
		try {
			Integer<int>       x = 100;
			const int          e =  0;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 0);
			CPPUNIT_ASSERT( x ==    1);
			CPPUNIT_ASSERT(&x ==   &y);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);}
	}

	void test_pow_4() {
		try {
			const Integer<int> x = 100;
			const int          e =  2;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == 100);
			CPPUNIT_ASSERT(e ==  2);
			CPPUNIT_ASSERT(y ==    10000);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_5() {
		try {
			const Integer<int> x = 9;
			const int          e =  5;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == 9);
			CPPUNIT_ASSERT(e ==  5);
			CPPUNIT_ASSERT(y ==    59049);}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_1() {
		try {
			Integer<int> x = 123;
			Integer<int> y = 123;
			CPPUNIT_ASSERT(!(x < y));
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_2() {
		try {
			Integer<int> x = -123;
			Integer<int> y = 123;
			CPPUNIT_ASSERT((x < y));
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_3() {
		try {
			Integer<int> x = 1;
			Integer<int> y = 123;
			CPPUNIT_ASSERT((x < y));
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_4() {
		try {
			Integer<int> x = -123;
			Integer<int> y = -123;
			CPPUNIT_ASSERT(!(x < y));
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_5() {
		try {
			Integer<int> x = 0;
			Integer<int> y = -123;
			CPPUNIT_ASSERT(!(x < y));
			Integer<int> z = 123;
			CPPUNIT_ASSERT((x < z));
			CPPUNIT_ASSERT((y < z));
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_6() {
		try {
			Integer<int> x = -1;
			Integer<int> y = -123;
			CPPUNIT_ASSERT(y < x);
			Integer<int> z = 1;
			CPPUNIT_ASSERT((x < z));
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_7() {
		try {
			Integer<int> x = 0;
			Integer<int> y = -1;
			Integer<int> z = 1;
			CPPUNIT_ASSERT(x < z);
			CPPUNIT_ASSERT(y < x);
			CPPUNIT_ASSERT(y < z);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_lessthan_8() {
		try {
			Integer<int> x = -45;
			Integer<int> y = -4;
			Integer<int> z = -125;
			CPPUNIT_ASSERT(x < y);
			CPPUNIT_ASSERT(z < y);
			CPPUNIT_ASSERT(z < x);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	//--------
	//<<=
	//--------

	void test_shift_left_equal_1() {
		try {
			Integer<int> x = -45;
			x <<= 4;
			CPPUNIT_ASSERT(x == -450000);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}


	void test_shift_left_equal_2() {
		try {
			Integer<int> x = -45;
			Integer<int> a = 23;
			a <<= 0;
			CPPUNIT_ASSERT(a == 23);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_shift_left_equal_3() {
		try {
			Integer<int> x = 0;
			x <<= 4;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}
	//-------
	//>>=
	//-------

	void test_shift_right_equal_1() {
		try {
			Integer<int> x = -45;
			x >>= 1;
			CPPUNIT_ASSERT(x == -4);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}


	void test_shift_right_equal_2() {
		try {
			Integer<int> a = 23;
			a >>= 3;
			CPPUNIT_ASSERT(a == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_shift_right_equal_3() {
		try {
			Integer<int> a = 0;
			a >>= 3;
			CPPUNIT_ASSERT(a == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_shift_right_equal_4() {
		try {
			Integer<int> x = 123;
			x >>= 0;
			CPPUNIT_ASSERT(x == 123);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}


	//----------
	//plus equals
	//----------
	void test_plus_equal_1() {
		try {
			Integer<int> x = 123;
			x += 1;
			CPPUNIT_ASSERT(x == 124);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_2() {
		try {
			Integer<int> x = 123;
			x += 3;
			CPPUNIT_ASSERT(x == 126);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_3() {
		try {
			Integer<int> x (123);
			Integer<int> y (-123);
			x += y;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_4() {
		try {
			Integer<int> x = -123;
			x += -1;
			CPPUNIT_ASSERT(x == -124);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_5() {
		try {
			Integer<int> x = 123;
			x += -1;
			CPPUNIT_ASSERT(x == 122);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_6() {
		try {
			Integer<int> x = -123;
			x += 1;
			CPPUNIT_ASSERT(x == -122);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_7() {
		try {
			Integer<int> x = 123;
			x += -345;
			CPPUNIT_ASSERT(x == -222);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_plus_equal_8() {
		try {
			Integer<int> x = -123;
			x += 123;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	//--------
	//minus equals
	//---------
	void test_minus_equal_1() {
		try {
			Integer<int> x = 123;
			x -= -345;
			CPPUNIT_ASSERT(x == 468);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_minus_equal_2() {
		try {
			Integer<int> x = 123;
			x -= 0;
			CPPUNIT_ASSERT(x == 123);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_minus_equal_3() {
		try {
			Integer<int> x = 123;
			x -= 123;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_minus_equal_4() {
		try {
			Integer<int> x = -123;
			x -= 123;
			CPPUNIT_ASSERT(x == -246);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_minus_equal_5() {
		try {
			Integer<int> x = -123;
			x -= -123;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_times_equal_1() {
		try {
			Integer<int> x = 1;
			x *= 1;
			CPPUNIT_ASSERT(x == 1);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_times_equal_2() {
		try {
			Integer<int> x = -123;
			x *= 1;
			CPPUNIT_ASSERT(x == -123);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_times_equal_3() {
		try {
			Integer<int> x = -123;
			x *= -123;
			CPPUNIT_ASSERT(x == 15129);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_times_equal_4() {
		try {
			Integer<int> x = 1;
			x *= 1;
			CPPUNIT_ASSERT(x == 1);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}
	void test_times_equal_5() {
		try {
			Integer<int> x = 0;
			x *= 123434;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_times_equal_6() {
		try {
			Integer<int> x = 0;
			x *= 123434;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_times_equal_7() {
		try {
			Integer<int> x = 234;
			x *= -2;
			CPPUNIT_ASSERT(x == -468);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}


	void test_divides_equal_1() {
		try {
			Integer<int> x = 1;
			x /= 1;
			CPPUNIT_ASSERT(x == 1);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}
	void test_divides_equal_2() {
		try {
			Integer<int> x = -10;
			x /= 2;
			CPPUNIT_ASSERT(x == -5);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}
	void test_divides_equal_3() {
		try {
			Integer<int> x = 10;
			x /= -2;
			CPPUNIT_ASSERT(x == -5);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}
	void test_divides_equal_4() {
		try {
			Integer<int> x = -10;
			x /= 0;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_mod_equal_1() {
		try {
			Integer<int> x = 10;
			x %= 2;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_mod_equal_2() {
		try {
			Integer<int> x = 100;
			x %= 7;

			CPPUNIT_ASSERT(x == 2);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_mod_equal_3() {
		try {
			Integer<int> x = 10;
			x %= 2;
			std::cout << x;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}

	void test_mod_equal_4() {
		try {
			Integer<int> x = 66;
			x %= 6;
			CPPUNIT_ASSERT(x == 0);
		}
		catch (std::invalid_argument& e){
			CPPUNIT_ASSERT(false);
		}
	}
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
	CPPUNIT_TEST(test_plus_digits_4);
	CPPUNIT_TEST(test_plus_digits_5);
	CPPUNIT_TEST(test_plus_digits_6);
	CPPUNIT_TEST(test_plus_digits_7);
	CPPUNIT_TEST(test_minus_digits_1);
	CPPUNIT_TEST(test_minus_digits_2);
	CPPUNIT_TEST(test_minus_digits_3);
	CPPUNIT_TEST(test_minus_digits_4);
	CPPUNIT_TEST(test_minus_digits_5);
	CPPUNIT_TEST(test_minus_digits_6);
	CPPUNIT_TEST(test_minus_digits_7);
	CPPUNIT_TEST(test_multiplies_digits_1);
	CPPUNIT_TEST(test_multiplies_digits_2);
	CPPUNIT_TEST(test_multiplies_digits_3);
	CPPUNIT_TEST(test_multiplies_digits_4);
	CPPUNIT_TEST(test_multiplies_digits_5);
	CPPUNIT_TEST(test_multiplies_digits_6);
	CPPUNIT_TEST(test_divides_digits_1);
	CPPUNIT_TEST(test_divides_digits_2);
	CPPUNIT_TEST(test_divides_digits_3);
	CPPUNIT_TEST(test_divides_digits_4);
	CPPUNIT_TEST(test_divides_digits_5);
	CPPUNIT_TEST(test_divides_digits_6);
	CPPUNIT_TEST(test_equal_to_1);
	CPPUNIT_TEST(test_lessthan_1);
	CPPUNIT_TEST(test_lessthan_2);
	CPPUNIT_TEST(test_lessthan_3);
	CPPUNIT_TEST(test_lessthan_4);
	CPPUNIT_TEST(test_lessthan_5);
	CPPUNIT_TEST(test_lessthan_6);
	CPPUNIT_TEST(test_lessthan_7);
	CPPUNIT_TEST(test_lessthan_8);
	CPPUNIT_TEST(test_equal_to_2);
	CPPUNIT_TEST(test_equal_to_3);
	CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
	CPPUNIT_TEST(test_constructor_5);
	CPPUNIT_TEST(test_abs_1);
	CPPUNIT_TEST(test_abs_2);
	CPPUNIT_TEST(test_abs_3);
	CPPUNIT_TEST(test_negation_1);
	CPPUNIT_TEST(test_negation_2);
	CPPUNIT_TEST(test_negation_3);
	CPPUNIT_TEST(test_output_1);
	CPPUNIT_TEST(test_output_2);
	CPPUNIT_TEST(test_output_3);
	CPPUNIT_TEST(test_shift_left_equal_1);
	CPPUNIT_TEST(test_shift_left_equal_2);
	CPPUNIT_TEST(test_shift_left_equal_3);
	CPPUNIT_TEST(test_shift_right_equal_1);
	CPPUNIT_TEST(test_shift_right_equal_2);
	CPPUNIT_TEST(test_shift_right_equal_3);
	CPPUNIT_TEST(test_shift_right_equal_4);
	CPPUNIT_TEST(test_plus_equal_1);
	CPPUNIT_TEST(test_plus_equal_2);
	CPPUNIT_TEST(test_plus_equal_3);
	CPPUNIT_TEST(test_plus_equal_4);
	CPPUNIT_TEST(test_plus_equal_5);
	CPPUNIT_TEST(test_plus_equal_6);
	CPPUNIT_TEST(test_plus_equal_7);
	CPPUNIT_TEST(test_plus_equal_8);
	CPPUNIT_TEST(test_minus_equal_1);
	CPPUNIT_TEST(test_minus_equal_2);
	CPPUNIT_TEST(test_minus_equal_3);
	CPPUNIT_TEST(test_minus_equal_4);
	CPPUNIT_TEST(test_minus_equal_5);
	CPPUNIT_TEST(test_times_equal_1);
	CPPUNIT_TEST(test_times_equal_2);
	CPPUNIT_TEST(test_times_equal_3);
	CPPUNIT_TEST(test_times_equal_4);
	CPPUNIT_TEST(test_times_equal_5);
	CPPUNIT_TEST(test_times_equal_6);
	CPPUNIT_TEST(test_times_equal_7);
	CPPUNIT_TEST(test_divides_equal_1);
	CPPUNIT_TEST(test_divides_equal_2);
	CPPUNIT_TEST(test_divides_equal_3);
	CPPUNIT_TEST(test_divides_equal_4);
	CPPUNIT_TEST(test_mod_equal_1);
	CPPUNIT_TEST(test_mod_equal_2);
	CPPUNIT_TEST(test_mod_equal_3);
	CPPUNIT_TEST(test_mod_equal_4);
	CPPUNIT_TEST(test_pow_1);
	//CPPUNIT_TEST(test_pow_2);
	CPPUNIT_TEST(test_pow_3);
	CPPUNIT_TEST(test_pow_4);
	CPPUNIT_TEST(test_pow_5);
	CPPUNIT_TEST_SUITE_END();
};

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
