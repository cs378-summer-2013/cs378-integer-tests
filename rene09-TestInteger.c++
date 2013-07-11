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
#include <list>      // list

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

/* Enable testing Integer private members. */
#define private public

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
		const int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		const int b[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			  int x[30];
		const int* p = shift_left_digits(a, a + 17, 10, x);
		CPPUNIT_ASSERT((p - x) == 27);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_left_digits_3 () {
		const int a[] = {1};
		const int b[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			  int x[300];
		const int* p = shift_left_digits(a, a+1, 100, x);
		CPPUNIT_ASSERT((p - x) == 101);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_left_digits_4 () {
		const std::list<int> a = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		const std::list<int> b = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			  std::list<int> x(27);
		const std::list<int>::iterator p = shift_left_digits(a.begin(), a.end(), 10, x.begin());
		CPPUNIT_ASSERT((x.size()) == 27);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, b.begin()));
	}

	// -------------------
	// add_equal_op
	// -------------------

	void test_add_equal_op_1 () {
		Integer<int> a(9999);
		const Integer<int> b(1);
		const std::vector<int> x = {1, 0, 0, 0, 0};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 5);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_add_equal_op_2 () {
		Integer<int> a(234512);
		const Integer<int> b(1000201);
		const std::vector<int> x = {1, 2, 3, 4, 7, 1, 3};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 7);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_add_equal_op_3 () {
		Integer<int> a("2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {1, 2, 3, 4, 7, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 89);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_add_equal_op_4 () {
		Integer<int> a(9999);
		const Integer<int> b(-1);
		const std::vector<int> x = {9, 9, 9, 8};

		a += b;
                
		CPPUNIT_ASSERT(a.stuff.size() == 4);
                CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}
        
    void test_add_equal_op_5 () {
		Integer<int> a(1);
		const Integer<int> b(-9999);
		const std::vector<int> x = {9, 9, 9, 8};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
                CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_add_equal_op_6 () {
		Integer<int> a(1);
		const Integer<int> b(-1);
		const std::vector<int> x = {0};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_add_equal_op_7 () {
		Integer<int> a(-9999);
		const Integer<int> b(-1);
		const std::vector<int> x = {1, 0, 0, 0, 0};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 5);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	void test_add_equal_op_8 () {
		Integer<int> a(-234512);
		const Integer<int> b(-1000201);
		const std::vector<int> x = {1, 2, 3, 4, 7, 1, 3};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 7);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	void test_add_equal_op_9 () {
		Integer<int> a("-2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("-10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {1, 2, 3, 4, 7, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 89);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	void test_add_equal_op_10 () {
		Integer<int> a(-1);
		const Integer<int> b(9999);
		const std::vector<int> x = {9, 9, 9, 8};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(!a.isNegative);
	}
        
    void test_add_equal_op_11 () {
		Integer<int> a(-9999);
		const Integer<int> b(1);
		const std::vector<int> x = {9, 9, 9, 8};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	void test_add_equal_op_12 () {
		Integer<int> a(-1);
		const Integer<int> b(-1);
		const std::vector<int> x = {2};

		a += b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}


	// -------------------
	// add_subtract_op
	// -------------------

	void test_subtract_equal_op_1 () {
		Integer<int> a(9999);
		const Integer<int> b(-1);
		const std::vector<int> x = {1, 0, 0, 0, 0};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 5);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_subtract_equal_op_2 () {
		Integer<int> a(1);
		const Integer<int> b(-9999);
		const std::vector<int> x = {1, 0, 0, 0, 0};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 5);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_subtract_equal_op_3 () {
		Integer<int> a("2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("-10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {1, 2, 3, 4, 7, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 89);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}
        
    void test_subtract_equal_op_4 () {
		Integer<int> a(-9999);
		const Integer<int> b(1);
		const std::vector<int> x = {1, 0, 0, 0, 0};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 5);
		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_subtract_equal_op_5 () {
		Integer<int> a(-1);
		const Integer<int> b(9999);
		const std::vector<int> x = {1, 0, 0, 0, 0};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 5);
                CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_subtract_equal_op_6 () {
		Integer<int> a("-2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {1, 2, 3, 4, 7, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 89);
		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_subtract_equal_op_7 () {
		Integer<int> a(-10000);
		const Integer<int> b(-1);
		const std::vector<int> x = {9, 9, 9, 9};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	void test_subtract_equal_op_8 () {
		Integer<int> a(-1);
		const Integer<int> b(-10000);
		const std::vector<int> x = {9, 9, 9, 9};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(!a.isNegative);
	}

	void test_subtract_equal_op_9 () {
		Integer<int> a("-2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("-10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {7, 6, 5, 6, 8, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 88);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(!a.isNegative);
	}
        
    void test_subtract_equal_op_10 () {
		Integer<int> a(10000);
		const Integer<int> b(1);
		const std::vector<int> x = {9, 9, 9, 9};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(!a.isNegative);
	}

	void test_subtract_equal_op_11 () {
		Integer<int> a(1);
		const Integer<int> b(10000);
		const std::vector<int> x = {9, 9, 9, 9};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	void test_subtract_equal_op_12 () {
		Integer<int> a("2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {7, 6, 5, 6, 8, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};

		a -= b;

		CPPUNIT_ASSERT(a.stuff.size() == 88);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
		CPPUNIT_ASSERT(a.isNegative);
	}

	// -------------------
	// multiply_equal_op
	// -------------------

	// arg1 bigger, both positive
	void test_multiply_equal_op_1 () {
		Integer<int> a(9999);
		const Integer<int> b(377);
		const std::vector<int> x = {3, 7, 6, 9, 6, 2, 3};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 7);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	// arg2 bigger, both positive
	void test_multiply_equal_op_2 () {
		Integer<int> a(234512);
		const Integer<int> b(91000202);
		const std::vector<int> x = {2, 1, 3, 4, 0, 6, 3, 9, 3, 7, 1, 4, 2, 4};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 14);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	// arg2 bigger and positive, arg1 negative
	void test_multiply_equal_op_3 () {
		Integer<int> a("-2345129999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		const Integer<int> b("10002011111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		const std::vector<int> x = {2, 3, 4, 5, 6, 0, 1, 6, 3, 1, 6, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 9, 7, 3, 7, 4, 1, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 176);
		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	// arg2 bigger and negative, arg1 positive 
	void test_multiply_equal_op_4 () {
		Integer<int> a(9999);
		const Integer<int> b(-1987654321);
		const std::vector<int> x = {1, 9, 8, 7, 4, 5, 5, 5, 5, 5, 5, 6, 7, 9};

		a *= b;
                
		CPPUNIT_ASSERT(a.stuff.size() == 14);
        CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}
    
    // arg1 bigger and positive, arg2 negative
    void test_multiply_equal_op_5 () {
		Integer<int> a(9999);
		const Integer<int> b(-1);
		const std::vector<int> x = {9, 9, 9, 9};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
        CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

    // arg1 bigger and negative, arg2 positive
	void test_multiply_equal_op_6 () {
		Integer<int> a(-1);
		const Integer<int> b(9999);
		const std::vector<int> x = {9, 9, 9, 9};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

    // arg1 bigger and negative, arg2 negative
	void test_multiply_equal_op_7 () {
		Integer<int> a(-9999);
		const Integer<int> b(-1);
		const std::vector<int> x = {9, 9, 9, 9};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

    // arg2 bigger and negative, arg1 negative
	void test_multiply_equal_op_8 () {
		Integer<int> a(-1);
		const Integer<int> b(-9999);
		const std::vector<int> x = {9, 9, 9, 9};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 4);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

    // arg2 negative, arg1 negative
	void test_multiply_equal_op_9 () {
		Integer<int> a("-234");
		const Integer<int> b("-567");
		const std::vector<int> x = {1, 3, 2, 6, 7, 8};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 6);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

    // arg2 positive, arg1 positive
	void test_multiply_equal_op_10 () {
		Integer<int> a(234);
		const Integer<int> b(567);
		const std::vector<int> x = {1, 3, 2, 6, 7, 8};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 6);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}
     
    // arg2 negative, arg1 positive   
    void test_multiply_equal_op_11 () {
		Integer<int> a(-234);
		const Integer<int> b(567);
		const std::vector<int> x = {1, 3, 2, 6, 7, 8};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 6);
		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	// arg2 positive, arg1 negative
	void test_multiply_equal_op_12 () {
		Integer<int> a(234);
		const Integer<int> b(-567);
		const std::vector<int> x = {1, 3, 2, 6, 7, 8};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 6);
		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	/* Handles 1s. */
	void test_multiply_equal_op_13 () {
		Integer<int> a(234);
		const Integer<int> b(1);
		const std::vector<int> x = {2, 3, 4};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 3);
		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	/* Handle 0. */
	void test_multiply_equal_op_14 () {
		Integer<int> a(234);
		const Integer<int> b("0");
		const std::vector<int> x = {0};

		a *= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	// ----------------
	// divides_equal_op
	// ----------------

	void test_divides_equal_op_1 () {
		Integer<int> a(132678);
		const Integer<int> b("567");
		const std::vector<int> x = {2, 3, 4};

		a /= b;

		CPPUNIT_ASSERT(a.stuff.size() == 3);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_2 () {
		try {
			Integer<int> a("132678");
			const Integer<int> b(0);
			const std::vector<int> x = {2, 3, 4};

			a /= b;

			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Cannot divide by zero.") == 0);
		}
	}

	void test_divides_equal_op_3 () {
		Integer<int> a(132678);
		const Integer<int> b(1);
		const std::vector<int> x = {1, 3, 2, 6, 7, 8};

		a /= b;

		CPPUNIT_ASSERT(a.stuff.size() == 6);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_4 () {
		Integer<int> a(132678);
		const Integer<int> b(132678);
		const std::vector<int> x = {1};

		a /= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_5 () {
		Integer<int> a("0");
		const Integer<int> b(132678);
		const std::vector<int> x = {0};

		a /= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_6 () {
		Integer<int> a("158");
		const Integer<int> b(132678);
		const std::vector<int> x = {0};

		a /= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_7 () {
		Integer<int> a("13");
		const Integer<int> b(10);
		const std::vector<int> x = {1};

		a /= b;

		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_8 () {
		Integer<int> a("-13");
		const Integer<int> b(10);
		const std::vector<int> x = {1};

		a /= b;

		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_9 () {
		Integer<int> a("13");
		const Integer<int> b(-10);
		const std::vector<int> x = {1};

		a /= b;

		CPPUNIT_ASSERT(a.isNegative);
		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_divides_equal_op_10 () {
		Integer<int> a("-13");
		const Integer<int> b(-10);
		const std::vector<int> x = {1};

		a /= b;

		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	// ------------
	// mod_equal_op
	// ------------

	void test_mod_equal_op_1 () {
		Integer<int> a(132678);
		const Integer<int> b("567");
		const std::vector<int> x = {0};

		a %= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_mod_equal_op_2 () {
		try {
			Integer<int> a("132678");
			const Integer<int> b(0);
			const std::vector<int> x = {2, 3, 4};

			a %= b;

			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Cannot divide by zero.") == 0);
		}
	}

	void test_mod_equal_op_3 () {
		Integer<int> a(132678);
		const Integer<int> b(1);
		const std::vector<int> x = {0};

		a %= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_mod_equal_op_4 () {
		Integer<int> a(132678);
		const Integer<int> b(132678);
		const std::vector<int> x = {0};

		a %= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_mod_equal_op_5 () {
		Integer<int> a("0");
		const Integer<int> b(132678);
		const std::vector<int> x = {0};

		a %= b;

		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_mod_equal_op_6 () {
		Integer<int> a("158");
		const Integer<int> b(132678);
		const std::vector<int> x = {1, 5, 8};

		a %= b;

		CPPUNIT_ASSERT(a.stuff.size() == 3);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_mod_equal_op_7 () {
		Integer<int> a("13");
		const Integer<int> b(10);
		const std::vector<int> x = {3};

		a %= b;

		CPPUNIT_ASSERT(!a.isNegative);
		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), x.begin()));
	}

	void test_mod_equal_op_8 () {
		try {
			Integer<int> a("-13");
			const Integer<int> b(10);
			const std::vector<int> x = {7};

			a %= b;

			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Cannot take negative arguments.") == 0);
		}	
	}

	void test_mod_equal_op_9 () {
		try {
			Integer<int> a("13");
			const Integer<int> b(-10);
			const std::vector<int> x = {7};

			a %= b;

			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Cannot take negative arguments.") == 0);
		}	
	}

	void test_mod_equal_op_10 () {
		try {
			Integer<int> a("-13");
			const Integer<int> b(-10);
			const std::vector<int> x = {3};

			a %= b;

			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Cannot take negative arguments.") == 0);
		}	
	}

	// -------------------
	// shift_left_equal_op
	// -------------------

	void test_shift_left_equal_op_1 () {
		Integer<int> a(234);
		const Integer<int> b(23400);
		a <<= 2;
		CPPUNIT_ASSERT(a.stuff.size() == 5);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), b.stuff.begin()));
	}

	void test_shift_left_equal_op_2 () {
		Integer<int> a("999999999999999999999999999");
		const Integer<int> b("999999999999999999999999999000");
		a <<= 3;
		CPPUNIT_ASSERT(a.stuff.size() != 27);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), b.stuff.begin()));
	}

	void test_shift_left_equal_op_3 () {
		Integer<int> a("1");
		const Integer<int> b("100000000000000000000000000000");
		a <<= 29;
		CPPUNIT_ASSERT(a.stuff.size() == 30);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), b.stuff.begin()));
	}

	// -------------------
	// shift_left_operator
	// -------------------

	void test_shift_left_op_1 () {
		Integer<int> a(234);
		const Integer<int> b = a << 2;
		CPPUNIT_ASSERT(b.stuff.size() == 5);
	}

	void test_shift_left_op_2 () {
		Integer<int> a("999999999999999999999999999");
		const Integer<int> b = a << 3;
		CPPUNIT_ASSERT(b.stuff.size() != 27);
	}

	void test_shift_left_op_3 () {
		Integer<int> a("1");
		const Integer<int> b = a << 29;
		CPPUNIT_ASSERT(b.stuff.size() == 30);
	}

	// ------------------
	// shift_right_digits
	// ------------------

	void test_shift_right_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {2};
			  int x[10];
		const int* p = shift_right_digits(a, a + 3, 2, x);
		CPPUNIT_ASSERT((p - x) == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

	void test_shift_right_digits_2 () {
		const std::vector<int> a = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		const std::vector<int> b = {1};
			  std::vector<int> x(101);
		const std::vector<int>::iterator p = shift_right_digits(a.begin(), a.end(), 100, x.begin());
		CPPUNIT_ASSERT((p - x.begin()) == 1);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, b.begin()));
	}

	void test_shift_right_digits_3 () {
		const std::list<int> a = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		const std::list<int> b = {9, 9, 9, 9};
			  std::list<int> x(4);
		const std::list<int>::iterator p = shift_right_digits(a.begin(), a.end(), 13, x.begin());
		CPPUNIT_ASSERT((x.size()) == 4);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, b.begin()));
	}


	// --------------------
	// shift_right_equal_op
	// --------------------

	void test_shift_right_equal_op_1 () {
	   Integer<int> a(23400);
	   const Integer<int> b(234);
		a >>= 2;
		CPPUNIT_ASSERT(a.stuff.size() == 3);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), b.stuff.begin()));
	}

	void test_shift_right_equal_op_2 () {
		Integer<int> a("999999999999999999999999999000");
		const Integer<int> b("999999999999999999999999999");
		a >>= 3;
		CPPUNIT_ASSERT(a.stuff.size() == 27);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), b.stuff.begin()));
	}

	void test_shift_right_equal_op_3 () {
		Integer<int> a("100000000000000000000000000000");
		const Integer<int> b("1");
		a >>= 29;
		CPPUNIT_ASSERT(a.stuff.size() == 1);
		CPPUNIT_ASSERT(std::equal(a.stuff.begin(), a.stuff.end(), b.stuff.begin()));
	}

	// --------------------
	// shift_right_operator
	// --------------------

	void test_shift_right_op_1 () {
		Integer<int> a(234);
		const Integer<int> b = a >> 2;
		CPPUNIT_ASSERT(b.stuff.size() == 1);
	}

	void test_shift_right_op_2 () {
		Integer<int> a("999999999999999999999999999");
		const Integer<int> b = a >> 3;
		CPPUNIT_ASSERT(b.stuff.size() == 24);
	}

	void test_shift_right_op_3 () {
		Integer<int> a("100000000000000000000000000000");
		const Integer<int> b = a >> 29;
		CPPUNIT_ASSERT(b.stuff.size() == 1);
	}

	// -----------
	// plus_digits
	// -----------

	void test_plus_digits_01 () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 5};
		const int c[] = {7, 9, 9};
			  int x[10];
		const int* p = plus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_02 () {
		const int a[] = {2, 3, 4, 7, 8, 9};
		const int b[] =          {5, 6, 5};
		const int c[] = {2, 3, 5, 3, 5, 4};
			  int x[10];
		const int* p = plus_digits(a, a + 6, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_03 () {
		const int a[] =                            {2, 3, 4};
		const int b[] = {5, 6, 5, 9, 9, 9, 9, 9, 9, 9, 9, 9};
		const int c[] = {5, 6, 6, 0, 0, 0, 0, 0, 0, 2, 3, 3};
			  int x[12];
		const int* p = plus_digits(a, a + 3, b, b + 12, x);
		CPPUNIT_ASSERT(p - x == 12);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_04 () {
		const int a[] = {0};
		const int b[] = {0};
		const int c[] = {0};
			  int x[1];
		const int* p = plus_digits(a, a + 1, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 1);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_05 () {
		const int a[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
		const int b[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
		const int c[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 8};
			  int x[12];
		const int* p = plus_digits(a, a + 9, b, b + 9, x);
		CPPUNIT_ASSERT(p - x == 10);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_plus_digits_06 () {
		const std::vector<int> a = {0};
		const std::vector<int> b = {0};
		const std::vector<int> c = {0};
			  std::vector<int> x(1);
		const std::vector<int>::iterator p = plus_digits(a.begin(), a.end(), b.begin(), b.end(), x.begin());
		CPPUNIT_ASSERT(p - x.begin() == 1);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c.begin()));
	}

	void test_plus_digits_07 () {
		const std::vector<int> a = {9, 9, 9, 9, 9, 9, 9, 9, 9};
		const std::deque<int> b = {9, 9, 9, 9, 9, 9, 9, 9, 9};
		const std::list<int> c = {1, 9, 9, 9, 9, 9, 9, 9, 9, 8};
			  int x[12];
		const int* p = plus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
		CPPUNIT_ASSERT(p - x == 10);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));
	}

	void test_plus_digits_08 () {
		const std::deque<int> a = {9, 9, 9, 9, 9, 9, 9, 9, 9};
		const std::deque<int> b = {9, 9, 9, 9, 9, 9, 9, 9, 9};
		const std::list<int> c = {1, 9, 9, 9, 9, 9, 9, 9, 9, 8};
			  std::vector<int> x(12);
		const std::vector<int>::iterator p = plus_digits(a.begin(), a.end(), b.begin(), b.end(), x.begin());
		CPPUNIT_ASSERT(p - x.begin() == 10);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c.begin()));
	}

	// ------------
	// minus_digits
	// ------------

	void test_minus_digits_01 () {
		const int a[] = {8, 0, 1};
		const int b[] = {5, 6, 7};
		const int c[] = {2, 3, 4};
			  int x[10];
		const int* p = minus_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 3);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	void test_minus_digits_02 () {
		const int a[] = {8, 0, 1, 1, 1};
		const int b[] = {5, 6, 7};
		const int c[] = {7, 9, 5, 4, 4};
			  int x[10];
		const int* p = minus_digits(a, a + 5, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 5);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}	

	void test_minus_digits_03 () {
		const std::vector<int> a = {8, 0, 1};
		const std::vector<int> b = {8, 0, 1};
		const std::vector<int> c = {0};
			  std::vector<int> x(10);
		const std::vector<int>::iterator p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x.begin());
		CPPUNIT_ASSERT(p - x.begin() == 1);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c.begin()));
	}

	void test_minus_digits_04 () {
		const std::deque<int> a = {1, 0, 0, 0, 0};
		const std::deque<int> b = {1};
		const std::deque<int> c = {9, 9, 9, 9};
			  std::deque<int> x(10);
		const std::deque<int>::iterator p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x.begin());
		CPPUNIT_ASSERT(p - x.begin() == 4);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c.begin()));
	}

	void test_minus_digits_05 () {
		const std::vector<int> a = {8, 0, 1};
		const std::deque<int> b = {5, 6, 7};
		const int c[] = {2, 3, 4};
			  std::list<int> x(3);
		const std::list<int>::iterator p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x.begin());
		CPPUNIT_ASSERT(x.size() == 3);
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c));
	}

	void test_minus_digits_06 () {
		const std::vector<int> a = {8, 0, 0};
		const std::deque<int> b = {7, 9, 9};
		const int c[] = {0};
			  std::list<int> x(1);
		const std::list<int>::iterator p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x.begin());
		CPPUNIT_ASSERT(x.size() == 1);
                // FIX LATER !!!!
		CPPUNIT_ASSERT(std::equal(x.begin(), p, c));
	}

	// -----------------
	// multiplies_digits
	// -----------------

	void test_multiplies_digits_1 () {
		const int a[] = {2, 3, 4};
		const int b[] = {5, 6, 7};
		const int c[] = {1, 3, 2, 6, 7, 8};
			  int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
        
        void test_multiplies_digits_2 () {
		const int a[] = {2, 3, 4};
		const int b[] = {7};
		const int c[] = {1, 6, 3, 8};
			  int x[10];
		const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
        
        void test_multiplies_digits_3 () {
		const int a[] = {7};
		const int b[] = {2, 3, 4};
		const int c[] = {1, 6, 3, 8};
			  int x[10];
		const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}
        
	void test_multiplies_digits_4 () {
		const std::vector<int> a = {2, 3, 4};
		const std::deque<int> b = {5, 6, 7};
		const std::list<int> c = {1, 3, 2, 6, 7, 8};
			  int x[10];
		const int* p = multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), x);
		CPPUNIT_ASSERT(p - x == 6);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));
	}
        
        void test_multiplies_digits_5 () {
		const std::vector<int> a = {2, 3, 4};
		const std::deque<int> b = {7};
		const std::list<int> c = {1, 6, 3, 8};
			  int x[10];
		const int* p = multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), x);
		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));
	}
        
        void test_multiplies_digits_6 () {
		const std::vector<int> a = {7};
		const std::deque<int> b = {2, 3, 4};
		const std::list<int> c = {1, 6, 3, 8};
			  int x[10];
		const int* p = multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), x);
		CPPUNIT_ASSERT(p - x == 4);
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c.begin()));
	}

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
		CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	}

	// -----------
	// constructor
	// -----------

	void test_constructor_1 () {
		try {
			const Integer<int> x("abc");
			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_2 () {
		try {
			const Integer<int> x("2");}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_constructor_3 () {
		try {
			const Integer<int> x(2);
		}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);
		}
	}

	void test_constructor_4 () {
		try {
			const Integer<int> x(2);
			std::vector<int> y(1, 2);
			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative == false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_constructor_5 () {
		try {
			const Integer<int> x(2);
		std::vector<int> y(1, 486);
		CPPUNIT_ASSERT(!std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
		CPPUNIT_ASSERT(x.isNegative == false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_6 () {
		try {
			const Integer<int> x("2");
			std::vector<int> y(1, 2);

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative == false);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_7 () {
		try {
			const Integer<int> x("2");
			std::vector<int> y(1, 486);
			CPPUNIT_ASSERT(!std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative == false);
	   }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_8 () {
		try {
			const Integer<int> x("-2");
			std::vector<int> y(1, 2);
			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_9 () {
		try {
			const Integer<int> x(-2);
			std::vector<int> y(1, 2);
			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
		   CPPUNIT_ASSERT(x.isNegative);
	   }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_10 () {
		try {
			const Integer<int> x("-");
			CPPUNIT_ASSERT(false);
	   }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_11 () {
		try {
			const Integer<int> x(48693451);
			std::vector<int> y = {4, 8, 6, 9, 3, 4, 5, 1};
			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
		   CPPUNIT_ASSERT(!x.isNegative);
	   }
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_12 () {
		try {
			const Integer<int> x("48693451");
			std::vector<int> y = {4, 8, 6, 9, 3, 4, 5, 1};

			/*std::cout << std::endl << "Mayor McCheeseface: ";
			for (int e : x.stuff) {
			std::cout << e << " ";
			}
			std::cout << std::endl;*/

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(!x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_13 () {
		try {
			const Integer<int> x(-48693451);
			std::vector<int> y = {4, 8, 6, 9, 3, 4, 5, 1};
			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
	   }
	}

	void test_constructor_14 () {
		try {
			const Integer<int> x("-48693451");
			std::vector<int> y = {4, 8, 6, 9, 3, 4, 5, 1};

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_15 () {
		try {
			const Integer<int> x("999999999999999999999999999999");
		std::vector<int> y = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
		CPPUNIT_ASSERT(!x.isNegative);
	}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_16 () {
		try {
			const Integer<int> x("-999999999999999999999999999999");
			std::vector<int> y = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_17 () {
		try {
			const Integer<int> x(32767);
			std::vector<int> y = {3, 2, 7, 6, 7};

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(!x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}

	void test_constructor_18 () {
		try {
			const Integer<int> x(-32767);
			std::vector<int> y = {3, 2, 7, 6, 7};

			CPPUNIT_ASSERT(std::equal(x.stuff.begin(), x.stuff.end(), y.begin()));
			CPPUNIT_ASSERT(x.isNegative);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	   }
	}


	// ---
	// abs
	// ---

	void test_abs_1 () {
		try {
			Integer<int>  x = -98765;
			Integer<int>& y = x.abs();
			CPPUNIT_ASSERT( x == 98765);
			CPPUNIT_ASSERT(&x == &y);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_abs_2 () {
		try {
			const Integer<int> x = -98765;
			const Integer<int> y = abs(x);
			CPPUNIT_ASSERT(x == -98765);
			CPPUNIT_ASSERT(y ==  98765);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_abs_3 () {
		try {
			const Integer<int> x = 2147483647;
			const Integer<int> y = abs(x);
			CPPUNIT_ASSERT(x != -2147483647);
			CPPUNIT_ASSERT(y ==  2147483647);
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
			CPPUNIT_ASSERT(!(98765 != y));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_equal_to_2 () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = -98765;
			CPPUNIT_ASSERT(      x != y);
			CPPUNIT_ASSERT(      x == 98765);
			CPPUNIT_ASSERT(  98765 == x);
			CPPUNIT_ASSERT(    !(x == y));
			CPPUNIT_ASSERT(    !(x != 98765));
			CPPUNIT_ASSERT(!(98765 == y));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_equal_to_3 () {
		try {
			const Integer<int> x ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			const Integer<int> y = 98765;
			CPPUNIT_ASSERT(      x != y);
			CPPUNIT_ASSERT(      x == Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921"));
			CPPUNIT_ASSERT(  Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921") == x);
			CPPUNIT_ASSERT(    !(x == y));
			CPPUNIT_ASSERT(    !(x != Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921")) );
			CPPUNIT_ASSERT(!(98765 != y));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_equal_to_4 () {
		try {
			const Integer<int> x ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			const Integer<int> y ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			CPPUNIT_ASSERT(      x == y);
			CPPUNIT_ASSERT(      x == Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921"));
			CPPUNIT_ASSERT(  Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921") == x);
			CPPUNIT_ASSERT(    !(x != y));
			CPPUNIT_ASSERT(    !(x != Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921")));
			CPPUNIT_ASSERT(!(Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921") != y));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	// ---------
	// less than
	// ---------

	void test_less_than_1 () {
		try {
			const Integer<int> x = 987;
			const Integer<int> y = 98765;
			CPPUNIT_ASSERT(      x < y);
			CPPUNIT_ASSERT(      x < 98765);
			CPPUNIT_ASSERT(  !(98765 < x));
			CPPUNIT_ASSERT(    !(y < x));
			CPPUNIT_ASSERT(!(98765 < y));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}	
	}

	void test_less_than_2 () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = 98765;
			CPPUNIT_ASSERT(      !(x < y));
			CPPUNIT_ASSERT(      !(x < 98765));
			CPPUNIT_ASSERT(  !(98765 < x));
			CPPUNIT_ASSERT(    !(y < x));
			CPPUNIT_ASSERT(!(98765 < y));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}	
	}

	void test_less_than_3 () {
		try {
			const Integer<int> x ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			const Integer<int> y ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			CPPUNIT_ASSERT(      !(x < y));
			CPPUNIT_ASSERT(      !(x < Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921")));
			CPPUNIT_ASSERT(  !(Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921") < x));
			CPPUNIT_ASSERT(    !(x < y));
			CPPUNIT_ASSERT(    !(x < Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921")));
			CPPUNIT_ASSERT(!(Integer<int> ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921") < y));
		}
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
			const Integer<int> y = -x;
			CPPUNIT_ASSERT(y == -98765);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

		void test_negation_2 () {
		try {
			const Integer<int> x = 98765;
			const Integer<int> y = -x;
			CPPUNIT_ASSERT(x == 98765);
			CPPUNIT_ASSERT(x != y);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

		void test_negation_3 () {
		try {
			const Integer<int> x ("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			const Integer<int> y = -x;
			CPPUNIT_ASSERT(y == Integer<int> ("-99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921"));
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
			CPPUNIT_ASSERT(out.str() == "98765");
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_output_2 () {
		try {
			const Integer<int> x("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999921");
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_output_3 () {
		try {
			const Integer<int> x = -98765;
			std::ostringstream out;
			out << x;
			CPPUNIT_ASSERT(out.str() == "-98765");
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	// ---
	// pow
	// ---

	void test_pow_1 () {
		try {
			Integer<int>       x = 2;
			const int          e =  4423;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 4423);
			CPPUNIT_ASSERT( x == Integer<int>("285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608"));
			CPPUNIT_ASSERT(&x ==   &y);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_2 () {
		try {
			const Integer<int> x = 2;
			const int          e =  4423;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == 2);
			CPPUNIT_ASSERT(e ==  4423);
			CPPUNIT_ASSERT(y ==  Integer<int>("285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608"));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_3 () {
		try {
			Integer<int>       x = 4423;
			const int          e =  0;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 0);
			CPPUNIT_ASSERT( x == 1);
			CPPUNIT_ASSERT(&x ==   &y);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_4 () {
		try {
			Integer<int>       x = -4423;
			const int          e =  0;
			Integer<int>&      y = x.pow(e);
			CPPUNIT_ASSERT( e == 0);
			CPPUNIT_ASSERT( x == -1);
			CPPUNIT_ASSERT(&x ==   &y);
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_5 () {
		try {
			const Integer<int> x = Integer<int>("285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608");
			const int          e =  1;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == Integer<int>("285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608"));
			CPPUNIT_ASSERT(e ==  1);
			CPPUNIT_ASSERT(y ==  Integer<int>("285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608"));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	void test_pow_6 () {
		try {
			const Integer<int> x = Integer<int>("-285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608");
			const int          e =  1;
			const Integer<int> y = pow(x, e);
			CPPUNIT_ASSERT(x == Integer<int>("-285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608"));
			CPPUNIT_ASSERT(e ==  1);
			CPPUNIT_ASSERT(y ==  Integer<int>("-285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580608"));
		}
		catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(false);
		}
	}

	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE(TestInteger);
	CPPUNIT_TEST(test_add_equal_op_1);
	CPPUNIT_TEST(test_add_equal_op_2);
	CPPUNIT_TEST(test_add_equal_op_3);
	CPPUNIT_TEST(test_add_equal_op_4);
	CPPUNIT_TEST(test_add_equal_op_5);
	CPPUNIT_TEST(test_add_equal_op_6);
	CPPUNIT_TEST(test_add_equal_op_7);
	CPPUNIT_TEST(test_add_equal_op_8);
	CPPUNIT_TEST(test_add_equal_op_9);
	CPPUNIT_TEST(test_add_equal_op_10);
    CPPUNIT_TEST(test_add_equal_op_11);
	CPPUNIT_TEST(test_add_equal_op_12);

	CPPUNIT_TEST(test_subtract_equal_op_1);
	CPPUNIT_TEST(test_subtract_equal_op_2);
	CPPUNIT_TEST(test_subtract_equal_op_3);
	CPPUNIT_TEST(test_subtract_equal_op_4);
	CPPUNIT_TEST(test_subtract_equal_op_5);
	CPPUNIT_TEST(test_subtract_equal_op_6);
    CPPUNIT_TEST(test_subtract_equal_op_7);
    CPPUNIT_TEST(test_subtract_equal_op_8);
    CPPUNIT_TEST(test_subtract_equal_op_9);
    CPPUNIT_TEST(test_subtract_equal_op_10);
    CPPUNIT_TEST(test_subtract_equal_op_11);
    CPPUNIT_TEST(test_subtract_equal_op_12);

    CPPUNIT_TEST(test_multiply_equal_op_1);
	CPPUNIT_TEST(test_multiply_equal_op_2);
	CPPUNIT_TEST(test_multiply_equal_op_3);
	CPPUNIT_TEST(test_multiply_equal_op_4);
	CPPUNIT_TEST(test_multiply_equal_op_5);
	CPPUNIT_TEST(test_multiply_equal_op_6);
	CPPUNIT_TEST(test_multiply_equal_op_7);
	CPPUNIT_TEST(test_multiply_equal_op_8);
	CPPUNIT_TEST(test_multiply_equal_op_9);
	CPPUNIT_TEST(test_multiply_equal_op_10);
    CPPUNIT_TEST(test_multiply_equal_op_11);
	CPPUNIT_TEST(test_multiply_equal_op_12);
	CPPUNIT_TEST(test_multiply_equal_op_13);
	CPPUNIT_TEST(test_multiply_equal_op_14);

	CPPUNIT_TEST(test_divides_equal_op_1);
	CPPUNIT_TEST(test_divides_equal_op_2);
	CPPUNIT_TEST(test_divides_equal_op_3);
	CPPUNIT_TEST(test_divides_equal_op_4);
	CPPUNIT_TEST(test_divides_equal_op_5);
	CPPUNIT_TEST(test_divides_equal_op_6);
	CPPUNIT_TEST(test_divides_equal_op_7);

	CPPUNIT_TEST(test_mod_equal_op_1);
	CPPUNIT_TEST(test_mod_equal_op_2);
	CPPUNIT_TEST(test_mod_equal_op_3);
	CPPUNIT_TEST(test_mod_equal_op_4);
	CPPUNIT_TEST(test_mod_equal_op_5);
	CPPUNIT_TEST(test_mod_equal_op_6);
	CPPUNIT_TEST(test_mod_equal_op_7);
	CPPUNIT_TEST(test_mod_equal_op_8);
	CPPUNIT_TEST(test_mod_equal_op_9);
	CPPUNIT_TEST(test_mod_equal_op_10);
            
	CPPUNIT_TEST(test_shift_left_digits_1);
	CPPUNIT_TEST(test_shift_left_digits_2);
	CPPUNIT_TEST(test_shift_left_digits_3);
	CPPUNIT_TEST(test_shift_left_digits_4);
	CPPUNIT_TEST(test_shift_left_equal_op_1);
	CPPUNIT_TEST(test_shift_left_equal_op_2);
	CPPUNIT_TEST(test_shift_left_equal_op_3);
	CPPUNIT_TEST(test_shift_left_op_1);
	CPPUNIT_TEST(test_shift_left_op_2);
	CPPUNIT_TEST(test_shift_left_op_3);
	CPPUNIT_TEST(test_shift_right_digits_1);
	CPPUNIT_TEST(test_shift_right_digits_2);
	CPPUNIT_TEST(test_shift_right_digits_3);
	CPPUNIT_TEST(test_shift_right_equal_op_1);
	CPPUNIT_TEST(test_shift_right_equal_op_2);
	CPPUNIT_TEST(test_shift_right_equal_op_3);
	CPPUNIT_TEST(test_shift_right_op_1);
	CPPUNIT_TEST(test_shift_right_op_2);
	CPPUNIT_TEST(test_shift_right_op_3);

	CPPUNIT_TEST(test_plus_digits_01);
	CPPUNIT_TEST(test_plus_digits_02);
	CPPUNIT_TEST(test_plus_digits_03);
	CPPUNIT_TEST(test_plus_digits_04);
	CPPUNIT_TEST(test_plus_digits_05);
	CPPUNIT_TEST(test_plus_digits_06);
	CPPUNIT_TEST(test_plus_digits_07);
	CPPUNIT_TEST(test_plus_digits_08);

	CPPUNIT_TEST(test_minus_digits_01);
	CPPUNIT_TEST(test_minus_digits_02);
	CPPUNIT_TEST(test_minus_digits_03);
	CPPUNIT_TEST(test_minus_digits_04);
	CPPUNIT_TEST(test_minus_digits_05);
	CPPUNIT_TEST(test_minus_digits_06);
            
	CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
	CPPUNIT_TEST(test_multiplies_digits_4);
    CPPUNIT_TEST(test_multiplies_digits_5);
    CPPUNIT_TEST(test_multiplies_digits_6);                 
		// CPPUNIT_TEST(test_divides_digits);

	CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_2);
	CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
	CPPUNIT_TEST(test_constructor_5);
	CPPUNIT_TEST(test_constructor_6);
	CPPUNIT_TEST(test_constructor_7);
	CPPUNIT_TEST(test_constructor_8);
	CPPUNIT_TEST(test_constructor_9);
	CPPUNIT_TEST(test_constructor_10);
	CPPUNIT_TEST(test_constructor_11);
	CPPUNIT_TEST(test_constructor_12);
	CPPUNIT_TEST(test_constructor_13);
	CPPUNIT_TEST(test_constructor_14);
	CPPUNIT_TEST(test_constructor_15);
	CPPUNIT_TEST(test_constructor_16);
	CPPUNIT_TEST(test_constructor_17);
	CPPUNIT_TEST(test_constructor_18);

	CPPUNIT_TEST(test_abs_1);
	CPPUNIT_TEST(test_abs_2);
	CPPUNIT_TEST(test_abs_3);
	CPPUNIT_TEST(test_equal_to_1);
	CPPUNIT_TEST(test_equal_to_2);
	CPPUNIT_TEST(test_equal_to_3);
	CPPUNIT_TEST(test_equal_to_4);
	CPPUNIT_TEST(test_less_than_1);
	CPPUNIT_TEST(test_less_than_2);
	CPPUNIT_TEST(test_less_than_3);
	CPPUNIT_TEST(test_negation_1);
	CPPUNIT_TEST(test_negation_2);
	CPPUNIT_TEST(test_negation_3);
	CPPUNIT_TEST(test_output_1);
	CPPUNIT_TEST(test_output_2);
	CPPUNIT_TEST(test_output_3);
	CPPUNIT_TEST(test_pow_1);
	CPPUNIT_TEST(test_pow_2);
	CPPUNIT_TEST(test_pow_3);
	CPPUNIT_TEST(test_pow_4);
	CPPUNIT_TEST(test_pow_5);
	CPPUNIT_TEST(test_pow_6);
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
	return 0;
}

