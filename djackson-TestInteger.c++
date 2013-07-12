// ------------------
// TestInteger.c++
// Dan Jackson
// CS 378 Summer 2013
// ------------------

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
#include <ctime>		// for debugging

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

    void test_shift_left_digits1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits2 () {
        const int a[] = {4, 7, 5, 2, 6, 0};
        const int b[] = {4, 7, 5, 2, 6, 0, 0, 0, 0, 0};
              int x[15];
        const int* p = shift_left_digits(a, a + 6, 4, x);
        CPPUNIT_ASSERT((p - x) == 10);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 0, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits2 () {
        const int a[] = {2, 3, 4};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 3, x);
        CPPUNIT_ASSERT((p - x) == 0);}

    void test_shift_right_digits3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 0, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits2 () {
        const int a[] = {-2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {3, 3, 3};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_plus_digits3 () {
        const int a[] = {-2, 3, 4};
        const int b[] = {-5, 6, 7};
        const int c[] = {-8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // ------------
    // minus_digits
    // ------------

    void test_minus_digits1 () {
        const int a[] = {8, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits2 () {
        const int a[] = {1, 0, 0, 0, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {9, 9, 4, 3, 4};
              int x[10];
        const int* p = minus_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits3 () {
        const int a[] = {8, 0, 1};
        const int b[] = {-5, 6, 7};
        const int c[] = {1, 3, 6, 8};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits2 () {
        const int a[] = {2, 3, 4};
        const int b[] = {6, 7};
        const int c[] = {1, 5, 6, 7, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {-5, 6, 7};
        const int c[] = {-1, 3, 2, 6, 7, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	 }

    // --------------
    // divides_digits
    // --------------

    void test_divides_digits1 () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits2 () {
        const int a[] = {1};
        const int b[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = divides_digits(a, a + 1, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	 void test_divides_digits3 () {
        const int a[] = {1, 3, 4, 9, 1, 6, 1, 3};
        const int b[] = {5, 6};
        const int c[] = {2, 4, 0, 9, 2, 1};
              int x[10];
        const int* p = divides_digits(a, a + 8, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	 void test_divides_digits4 () {
        const int a[] = {1, 2, 3, 4};
        const int b[] = {1, 2, 3, 4};
        const int c[] = {1};
              int x[10];
        const int* p = divides_digits(a, a + 4, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 1);
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
            const Integer<int> x("-26");}
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

    // --------
    // equal_to
    // --------

    void test_equal_to1 () {
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

	  void test_equal_to2 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 0);
            CPPUNIT_ASSERT(  0 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 0));
            CPPUNIT_ASSERT(!(0 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

	  void test_equal_to3 () {
        try {
            const Integer<int> x = -214;
            const Integer<int> y = -214;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == -214);
            CPPUNIT_ASSERT(  -214 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != -214));
            CPPUNIT_ASSERT(!(-214 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

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

    // ------
    // output
    // ------

    void test_output1 () {
        try {
            const Integer<int> x = 98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output2 () {
        try {
            const Integer<int> x = -98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output3 () {
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
            Integer<int>       x = 2;
            const int          e = 20;
				Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 20);
				CPPUNIT_ASSERT( y == 1048576);
            CPPUNIT_ASSERT(&x ==   &y);
			}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 5;
            const int          e =  12;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e == 12);
            CPPUNIT_ASSERT(y == 244140625);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

	// ---
	// mod
	// ---

	void test_mod_1 () {
		try
		{
			Integer<int> x = 324;
			Integer<int> y = 100;
			Integer<int> z = x % y;
			CPPUNIT_ASSERT(z == 24);	
			CPPUNIT_ASSERT(x == 324);
			CPPUNIT_ASSERT(y == 100);	
		}
		catch (std::invalid_argument& e)
		{
			CPPUNIT_ASSERT(false);
		}
	}
	void test_mod_2 () {
		try
		{
			Integer<int> x = 324;
			Integer<int> y = 100;
			x %=y;
			CPPUNIT_ASSERT(x == 24);
			CPPUNIT_ASSERT(y == 100);	
		}
		catch (std::invalid_argument& e)
		{
			CPPUNIT_ASSERT(false);
		}
	}

	void test_mod_3 () {
		try
		{
			Integer<int> x = 324;
			Integer<int> y = 0;
			Integer<int> z = x % y;
			CPPUNIT_ASSERT(false);
		}
		catch (std::invalid_argument& e)
		{
			CPPUNIT_ASSERT(strcmp(e.what(), "%="));
		}
	}
	
	// ----------------
	// shift_left_equal
	//	----------------
	
	void test_shift_left_equal_1()
	{
		Integer<int> x = 7657;
		x <<= 4;
		CPPUNIT_ASSERT(x == 76570000);
	}

	void test_shift_left_equal_2()
	{
		Integer<int> x = 7657;
		x <<= 0;
		CPPUNIT_ASSERT(x == 7657);
	}
	void test_shift_left_equal_3()
	{
		Integer<int> x("3497");
		x <<= 3;
		const Integer<int> y("3497000");
		CPPUNIT_ASSERT(x == y);
	}

	// -----------------
	// shift_right_equal
	//	-----------------
	
	void test_shift_right_equal_1()
	{
		Integer<int> x = 76579;
		x >>= 4;
		CPPUNIT_ASSERT(x == 7);
	}

	void test_shift_right_equal_2()
	{
		Integer<int> x = 7657;
		x >>= 0;
		CPPUNIT_ASSERT(x == 7657);
	}
	void test_shift_right_equal_3()
	{
		Integer<int> x(3497);
		x >>= 3;
		CPPUNIT_ASSERT(x == 3);
	}

	// ----------
	// plus_equal
	//	----------
	
	void test_plus_equal_1()
	{
		Integer<int> x = 76579;
		Integer<int> y = 3435;
		x += y;
		CPPUNIT_ASSERT(x == 80014);
		CPPUNIT_ASSERT(y == 3435);
	}

	void test_plus_equal_2()
	{
		Integer<int> x = -21;
		Integer<int> y = 23;
		x += y;
		CPPUNIT_ASSERT(x == 2);
		CPPUNIT_ASSERT(y == 23);
	}
	void test_plus_equal_3()
	{
		Integer<int> x(545);
		Integer<int> y(0);
		x += y;
		CPPUNIT_ASSERT(x == 545);
		CPPUNIT_ASSERT(y == 0);
	}
	
	void test_plus_equal_4()
	{
		Integer<int> x(0);
		Integer<int> y(545);
		x += y;
		CPPUNIT_ASSERT(x == 545);
		CPPUNIT_ASSERT(y == 545);
		CPPUNIT_ASSERT(x == y);
	}


	// -----------
	// minus_equal
	//	-----------
	
	void test_minus_equal_1()
	{
		Integer<int> x = 76579;
		Integer<int> y = 3435;
		x -= y;
		CPPUNIT_ASSERT(x == 73144);
		CPPUNIT_ASSERT(y == 3435);
	}

	void test_minus_equal_2()
	{
		Integer<int> x = 21;
		Integer<int> y = -23;
		x -= y;
		CPPUNIT_ASSERT(x == 44);
		CPPUNIT_ASSERT(y == -23);
	}
	void test_minus_equal_3()
	{
		Integer<int> x(545);
		Integer<int> y(0);
		x -= y;
		CPPUNIT_ASSERT(x == 545);
		CPPUNIT_ASSERT(y == 0);
	}


	// -----------
	// times_equal
	//	-----------
	
	void test_times_equal_1()
	{
		Integer<int> x = 45;
		Integer<int> y = 78;
		x *= y;
		CPPUNIT_ASSERT(x == 3510);
		CPPUNIT_ASSERT(y == 78);
	}

	void test_times_equal_2()
	{
		Integer<int> x = 1;
		Integer<int> y = 21;
		x *= y;
		CPPUNIT_ASSERT(x == 21);
		CPPUNIT_ASSERT(y == 21);
	}
	void test_times_equal_3()
	{
		Integer<int> x(-477);
		Integer<int> y(3);
		x *= y;
		CPPUNIT_ASSERT(x == -1431);
		CPPUNIT_ASSERT(y == 3);
	}
	void test_times_equal_4()
	{
		Integer<int> x(477);
		Integer<int> y(-3);
		x *= y;
		CPPUNIT_ASSERT(x == -1431);
		CPPUNIT_ASSERT(y == -3);
	}
	void test_times_equal_5()
	{
		Integer<int> x(-477);
		Integer<int> y(-3);
		x *= y;
		CPPUNIT_ASSERT(x == 1431);
		CPPUNIT_ASSERT(y == -3);
	}


	// -------------
	// divide_equals
	//	-------------
	void test_divide_equal_1()
	{
		Integer<int> x = 120;
		Integer<int> y = 55;
		x /= y;
		CPPUNIT_ASSERT(x == 2);
		CPPUNIT_ASSERT(y == 55);
	}

	void test_divide_equal_2()
	{
		Integer<int> x = 5457;
		Integer<int> y = 1;
		x /= y;
		CPPUNIT_ASSERT(x == 5457);
		CPPUNIT_ASSERT(y == 1);
	}
	void test_divide_equal_3()
	{
		Integer<int> x(-477);
		Integer<int> y(47);
		x /= y;
		CPPUNIT_ASSERT(x == -10);
		CPPUNIT_ASSERT(y == 47);
	}
	void test_divide_equal_4()
	{
		Integer<int> x(477);
		Integer<int> y(-47);
		x /= y;
		CPPUNIT_ASSERT(x == -10);
		CPPUNIT_ASSERT(y == -47);
	}
	void test_divide_equal_5()
	{
		Integer<int> x(-477);
		Integer<int> y(-47);
		x /= y;
		CPPUNIT_ASSERT(x == 10);
		CPPUNIT_ASSERT(y == -47);
	}


	// ----------
	// shift_left
	//	----------
	
	void test_shift_left_1()
	{
		Integer<int> x = 7657;
		Integer<int> y = x << 4;
		CPPUNIT_ASSERT(y == 76570000);
		CPPUNIT_ASSERT(x == 7657);
	}

	void test_shift_left_2()
	{
		Integer<int> x = 7657;
		Integer<int> y = x << 0;
		CPPUNIT_ASSERT(x == y);
	}
	void test_shift_left_3()
	{
		Integer<int> x("3497");
		Integer<int> y = x << 3;
		CPPUNIT_ASSERT(x == 3497);
		CPPUNIT_ASSERT(y == 3497000);
	}

	// -----------
	// shift_right
	//	-----------
	
	void test_shift_right_1()
	{
		Integer<int> x = 76579;
		Integer<int> y = x >> 4;
		CPPUNIT_ASSERT(x == 76579);
		CPPUNIT_ASSERT(y == 7);
	}

	void test_shift_right_2()
	{
		Integer<int> x = 7657;
		Integer<int> y = x >> 0;
		CPPUNIT_ASSERT(x == 7657);
		CPPUNIT_ASSERT(y == 7657);
	}
	void test_shift_right_3()
	{
		Integer<int> x(3497);
		Integer<int> y = x >> 3;
		CPPUNIT_ASSERT(x == 3497);
		CPPUNIT_ASSERT(y == 3);
	}

	// ----
	// plus
	//	----
	
	void test_plus_1()
	{
		Integer<int> x = 76579;
		Integer<int> y = 3435;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 80014);
		CPPUNIT_ASSERT(y == 3435);
		CPPUNIT_ASSERT(x == 76579);
	}

	void test_plus_2()
	{
		Integer<int> x = -21;
		Integer<int> y = 23;
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 2);
		CPPUNIT_ASSERT(y == 23);
		CPPUNIT_ASSERT(x == -21);
	}
	void test_plus_3()
	{
		Integer<int> x(545);
		Integer<int> y(0);
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 545);
		CPPUNIT_ASSERT(y == 0);
		CPPUNIT_ASSERT(x == 545);
	}
	
	void test_plus_4()
	{
		Integer<int> x(0);
		Integer<int> y(545);
		Integer<int> z = x + y;
		CPPUNIT_ASSERT(z == 545);
		CPPUNIT_ASSERT(y == 545);
		CPPUNIT_ASSERT(x == 0);
	}


	// -----------
	// minus_equal
	//	-----------
	
	void test_minus_1()
	{
		Integer<int> x = 76579;
		Integer<int> y = 3435;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 73144);
		CPPUNIT_ASSERT(y == 3435);
		CPPUNIT_ASSERT(x == 76579);
	}

	void test_minus_2()
	{
		Integer<int> x = 21;
		Integer<int> y = -23;
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 44);
		CPPUNIT_ASSERT(y == -23);
		CPPUNIT_ASSERT(x == 21);
	}
	void test_minus_3()
	{
		Integer<int> x(545);
		Integer<int> y(0);
		Integer<int> z = x - y;
		CPPUNIT_ASSERT(z == 545);
		CPPUNIT_ASSERT(y == 0);
		CPPUNIT_ASSERT(x == 545);
	}


	// -----------
	// times_equal
	//	-----------
	
	void test_times_1()
	{
		Integer<int> x = 45;
		Integer<int> y = 78;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 3510);
		CPPUNIT_ASSERT(y == 78);
		CPPUNIT_ASSERT(x == 45);
	}

	void test_times_2()
	{
		Integer<int> x = 1;
		Integer<int> y = 21;
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 21);
		CPPUNIT_ASSERT(y == 21);
		CPPUNIT_ASSERT(x == 1);
	}
	void test_times_3()
	{
		Integer<int> x(-477);
		Integer<int> y(3);
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == -1431);
		CPPUNIT_ASSERT(y == 3);
		CPPUNIT_ASSERT(x == -477);
	}
	void test_times_4()
	{
		Integer<int> x(477);
		Integer<int> y(-3);
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == -1431);
		CPPUNIT_ASSERT(y == -3);
		CPPUNIT_ASSERT(x == 477);
	}
	void test_times_5()
	{
		Integer<int> x(-477);
		Integer<int> y(-3);
		Integer<int> z = x * y;
		CPPUNIT_ASSERT(z == 1431);
		CPPUNIT_ASSERT(y == -3);
		CPPUNIT_ASSERT(x == -477);
	}


	// -------------
	// divide_equals
	//	-------------
	void test_divide_1()
	{
		Integer<int> x = 120;
		Integer<int> y = 55;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 2);
		CPPUNIT_ASSERT(y == 55);
		CPPUNIT_ASSERT(x == 120);
	}

	void test_divide_2()
	{
		Integer<int> x = 5457;
		Integer<int> y = 1;
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 5457);
		CPPUNIT_ASSERT(y == 1);
		CPPUNIT_ASSERT(x == 5457);
	}
	void test_divide_3()
	{
		Integer<int> x(-477);
		Integer<int> y(47);
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == -10);
		CPPUNIT_ASSERT(y == 47);
		CPPUNIT_ASSERT(x == -477);
	}
	void test_divide_4()
	{
		Integer<int> x(477);
		Integer<int> y(-47);
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == -10);
		CPPUNIT_ASSERT(y == -47);
		CPPUNIT_ASSERT(x == 477);
	}
	void test_divide_5()
	{
		Integer<int> x(-477);
		Integer<int> y(-47);
		Integer<int> z = x / y;
		CPPUNIT_ASSERT(z == 10);
		CPPUNIT_ASSERT(y == -47);
		CPPUNIT_ASSERT(x == -477);
	}
	
	
	



    // -----
    // suite
    // -----

   CPPUNIT_TEST_SUITE(TestInteger);
   CPPUNIT_TEST(test_shift_left_digits1);
	CPPUNIT_TEST(test_shift_left_digits2);
	CPPUNIT_TEST(test_shift_left_digits3);
   CPPUNIT_TEST(test_shift_right_digits1);
   CPPUNIT_TEST(test_shift_right_digits2);
   CPPUNIT_TEST(test_shift_right_digits3);
   CPPUNIT_TEST(test_plus_digits1);
	CPPUNIT_TEST(test_plus_digits2);
	CPPUNIT_TEST(test_plus_digits3);
   CPPUNIT_TEST(test_minus_digits1);
   CPPUNIT_TEST(test_minus_digits2);
   CPPUNIT_TEST(test_minus_digits3);
   CPPUNIT_TEST(test_multiplies_digits1);
	CPPUNIT_TEST(test_multiplies_digits2);
	CPPUNIT_TEST(test_multiplies_digits3);
   CPPUNIT_TEST(test_divides_digits1);
	CPPUNIT_TEST(test_divides_digits2);
	CPPUNIT_TEST(test_divides_digits3);
	CPPUNIT_TEST(test_divides_digits4);
   CPPUNIT_TEST(test_constructor_1);
   CPPUNIT_TEST(test_constructor_2);
   CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
   CPPUNIT_TEST(test_abs_1);
   CPPUNIT_TEST(test_abs_2);
	CPPUNIT_TEST(test_equal_to1);
	CPPUNIT_TEST(test_equal_to2);
	CPPUNIT_TEST(test_equal_to3);
   CPPUNIT_TEST(test_negation);
   CPPUNIT_TEST(test_output1);
	CPPUNIT_TEST(test_output2);
	CPPUNIT_TEST(test_output3);
   CPPUNIT_TEST(test_pow_1);
   CPPUNIT_TEST(test_pow_2);
	CPPUNIT_TEST(test_mod_1);
	CPPUNIT_TEST(test_mod_2);
	CPPUNIT_TEST(test_mod_3);
	CPPUNIT_TEST(test_shift_left_equal_1);
	CPPUNIT_TEST(test_shift_left_equal_2);
	CPPUNIT_TEST(test_shift_left_equal_3);
	CPPUNIT_TEST(test_shift_right_equal_1);
	CPPUNIT_TEST(test_shift_right_equal_2);
	CPPUNIT_TEST(test_shift_right_equal_3);
	CPPUNIT_TEST(test_plus_equal_1);
	CPPUNIT_TEST(test_plus_equal_2);
	CPPUNIT_TEST(test_plus_equal_3);
	CPPUNIT_TEST(test_plus_equal_4);
	CPPUNIT_TEST(test_minus_equal_1);
	CPPUNIT_TEST(test_minus_equal_2);
	CPPUNIT_TEST(test_minus_equal_3);
	CPPUNIT_TEST(test_times_equal_1);
	CPPUNIT_TEST(test_times_equal_2);
	CPPUNIT_TEST(test_times_equal_3);
	CPPUNIT_TEST(test_times_equal_4);
	CPPUNIT_TEST(test_times_equal_5);
	CPPUNIT_TEST(test_divide_equal_1);
	CPPUNIT_TEST(test_divide_equal_2);
	CPPUNIT_TEST(test_divide_equal_3);
	CPPUNIT_TEST(test_divide_equal_4);
	CPPUNIT_TEST(test_divide_equal_5);
	CPPUNIT_TEST(test_shift_left_1);
	CPPUNIT_TEST(test_shift_left_2);
	CPPUNIT_TEST(test_shift_left_3);
	CPPUNIT_TEST(test_shift_right_1);
	CPPUNIT_TEST(test_shift_right_2);
	CPPUNIT_TEST(test_shift_right_3);
	CPPUNIT_TEST(test_plus_1);
	CPPUNIT_TEST(test_plus_2);
	CPPUNIT_TEST(test_plus_3);
	CPPUNIT_TEST(test_plus_4);
	CPPUNIT_TEST(test_minus_1);
	CPPUNIT_TEST(test_minus_2);
	CPPUNIT_TEST(test_minus_3);
	CPPUNIT_TEST(test_times_1);
	CPPUNIT_TEST(test_times_2);
	CPPUNIT_TEST(test_times_3);
	CPPUNIT_TEST(test_times_4);
	CPPUNIT_TEST(test_times_5);
	CPPUNIT_TEST(test_divide_1);
	CPPUNIT_TEST(test_divide_2);
	CPPUNIT_TEST(test_divide_3);
	CPPUNIT_TEST(test_divide_4);
	CPPUNIT_TEST(test_divide_5);
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
