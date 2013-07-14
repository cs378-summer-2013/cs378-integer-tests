// --------------------------------
// cs378-integer/src/TestInteger.c++
// Copyright (C) 2013
// CS w378 C++ STL w/ Dr. Downing
// Summer 2013
// Kevin Tran
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
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	    }

	    void test_shift_left_digits2 () {
	        const int a[] = {2, 3, 4, 5, 6};
	        const int b[] = {2, 3, 4, 0, 0};
	        int x[10];
	        const int* p = shift_left_digits(a, a + 3, 2, x);
	        CPPUNIT_ASSERT((p - x) == 5);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	    }

	    void test_shift_left_digits3 () {
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

	    void test_shift_right_digits1 () {
	        const int a[] = {2, 3, 4};
	        const int b[] = {2};
	        int x[10];
	        const int* p = shift_right_digits(a, a + 3, 2, x);
	        CPPUNIT_ASSERT((p - x) == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	    }

	    void test_shift_right_digits2 () {
	        const int a[] = {1, 2, 3};
	        const int b[] = {1, 2};
	        int x[10];
	        const int* p = shift_right_digits(a, a + 3, 1, x);
	        CPPUNIT_ASSERT((p - x) == 2);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	    }

	    void test_shift_right_digits3 () {
	        const int a[] = {2, 3, 4};
	        const int b[] = {2, 3, 4};
	        int x[10];
	        const int* p = shift_right_digits(a, a + 3, 0, x);
	        CPPUNIT_ASSERT((p - x) == 3);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	    }

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
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_plus_digits2 () {
	        const int a[] = {1};
	        const int b[] = {2};
	        const int c[] = {3};
	        int x[10];
	        const int* p = plus_digits(a, a + 1, b, b + 1, x);
	        CPPUNIT_ASSERT(p - x == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_plus_digits3 () {
	        const int a[] = {0, 0, 0};
	        const int b[] = {1, 2, 3};
	        const int c[] = {3};
	        int x[10];
	        const int* p = plus_digits(a, a + 3, b + 2, b + 3, x);
	        CPPUNIT_ASSERT(p - x == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }


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
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_minus_digits2 () {
	        const int a[] = {1, 0};
	        const int b[] = {9};
	        const int c[] = {1};
	        int x[10];
	        const int* p = minus_digits(a, a + 2, b, b + 1, x);
	        CPPUNIT_ASSERT(p - x == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_minus_digits3 () {
	        const int a[] = {1, 2};
	        const int b[] = {1, 1};
	        const int c[] = {1};
	        int x[10];
	        const int* p = minus_digits(a, a + 2, b, b + 2, x);
	        CPPUNIT_ASSERT(p - x == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

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
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_multiplies_digits2 () {
	        const int a[] = {1, 0};
	        const int b[] = {2};
	        const int c[] = {2, 0};
	        int x[10];
	        const int* p = multiplies_digits(a, a + 2, b, b + 1, x);
	        CPPUNIT_ASSERT(p - x == 2);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }


	    void test_multiplies_digits3 () {
	        const int a[] = {2, 3, 6};
	        const int b[] = {4, 5};
	        const int c[] = {1, 0, 6, 2, 0};
	        int x[20];
	        const int* p = multiplies_digits(a, a + 3, b, b + 2, x);
	        CPPUNIT_ASSERT(p - x == 5);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }


	    // --------------
	    // divides_digits
	    // --------------

	    void test_divides_digits1 () {
	        const int a[] = {4};
	        const int b[] = {2};
	        const int c[] = {2};
	        int x[10];
	        const int* p = divides_digits(a, a + 1, b, b + 1, x);
	        CPPUNIT_ASSERT(p - x == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_divides_digits2 () {
	        const int a[] = {2, 0};
	        const int b[] = {1, 0};
	        const int c[] = {2};
	        int x[10];
	        const int* p = divides_digits(a, a + 2, b, b + 2, x);
	        CPPUNIT_ASSERT(p - x == 1);
	        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	    }

	    void test_divides_digits3 () {
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

	    void test_constructor1 () {
	        try {
	            const Integer<int> x("abc");
	            CPPUNIT_ASSERT(false);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));
	        }
	    }

	    void test_constructor2 () {
	        try {
	            const Integer<int> x("2");
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    void test_constructor3 () {
	        try {
	            const Integer<int> x(2);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    // ---
	    // abs
	    // ---

	    void test_abs1 () {
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

	    void test_abs2 () {
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


	    // --------
	    // negation
	    // --------

	    void test_negation1 () {
	        try {
	            const Integer<int> x = 98765;
	            const Integer<int> y = -x;
	            CPPUNIT_ASSERT(x ==  98765);
	            CPPUNIT_ASSERT(y == -98765);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    void test_negation2 () {
	        try {
	            const Integer<int> x = -98765;
	            const Integer<int> y = -x;
	            CPPUNIT_ASSERT(x == -98765);
	            CPPUNIT_ASSERT(y ==  98765);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    // ------
	    // output
	    // ------

	    void test_output1 () {
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

	    void test_output2 () {
	        try {
	            const Integer<int> x = 111111111;
	            std::ostringstream out;
	            out << x;
	            CPPUNIT_ASSERT(out.str() == "111111111");
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    void test_output3 () {
	        try {
	            const Integer<int> x ("123456789");
	            std::ostringstream out;
	            out << x;
//	            std::cout << out.str();
	            CPPUNIT_ASSERT(out.str() == "123456789");
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }


	    // ---
	    // pow
	    // ---

	    void test_pow1 () {
	        try {
	            const Integer<int> x =    1;
	            const int          e = 9867;
	            const Integer<int> y = pow(x, e);
	            CPPUNIT_ASSERT(x ==    1);
	            CPPUNIT_ASSERT(y ==    1);
	            CPPUNIT_ASSERT(e == 9867);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    void test_pow2 () {
	        try {
	            const Integer<int> x = 98765;
	            const int          e =  1;
	            const Integer<int> y = pow(x, e);
	            CPPUNIT_ASSERT(x == 98765);
	            CPPUNIT_ASSERT(y == 98765);
	            CPPUNIT_ASSERT(e ==     1);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }

	    void test_pow3 () {
	        try {
	            const Integer<int> x = 2;
	            const int          e = 8;
	            const Integer<int> y = pow(x, e);
	            CPPUNIT_ASSERT(x == 2);
	            CPPUNIT_ASSERT(y == 256);
	            CPPUNIT_ASSERT(e == 8);
	        }
	        catch (std::invalid_argument& e) {
	            CPPUNIT_ASSERT(false);
	        }
	    }


	    // ---------
	    // operators
	    // ---------

	    void test_plus_equal1 () {
	        Integer<int> x = 1;
	        x += Integer<int>(1);
	        CPPUNIT_ASSERT(x == Integer<int>(2));
	    }

	    void test_plus_equal2 () {
	        Integer<int> x = 1;
	        x += 1;
	        CPPUNIT_ASSERT(x == 2);
	    }

	    void test_plus_equal3 () {
	        Integer<int> x ("12345");
	        x += 1;
	        CPPUNIT_ASSERT(x == Integer<int>("12346"));
	    }

	    void test_multiply_equal1 () {
	        Integer<int> x = 2;
	        x *= 4;
	        CPPUNIT_ASSERT(x == 8);
	    }

	    void test_multiply_equal2 () {
	        Integer<int> x = 2;
	        x *= -1;
	        CPPUNIT_ASSERT(x == -2);
	    }

	    void test_multiply_equal3 () {
	        Integer<int> x ("10");
	        x *= x;
	        CPPUNIT_ASSERT(x == Integer<int>("100"));
	    }

	    void test_divide_equal1 () {
	        Integer<int> x = 15;
	        x /= 5;
	        CPPUNIT_ASSERT(x == 3);
	    }

	    void test_divide_equal2 () {
	        Integer<int> x = 13;
	        x /= 4;
	        CPPUNIT_ASSERT(x == 3);
	    }

	    void test_divide_equal3 () {
	        Integer<int> x ("100");
	        x /= Integer<int> ("10");
	        CPPUNIT_ASSERT(x == Integer<int>("10"));
	    }

	    void test_mod_equal1 () {
	        Integer<int> x = 15;
	        x %= 5;
	        CPPUNIT_ASSERT(x == 0);
	    }

	    void test_mod_equal2 () {
	        Integer<int> x = 11;
	        x %= 4;
	        CPPUNIT_ASSERT(x == 3);
	    }

	    void test_mod_equal3 () {
	        Integer<int> x = 100;
	        x %= 95;
	        CPPUNIT_ASSERT(x == 5);
	    }

	    void test_shift_left_equal1 () {
	        Integer<int> x = 10;
	        x <<= 1;
	        CPPUNIT_ASSERT(x == 100);
	    }

	    void test_shift_left_equal2 () {
	        Integer<int> x = 12345;
	        x <<= 2;
	        CPPUNIT_ASSERT(x == 1234500);
	    }

	    void test_shift_left_equal3 () {
	        Integer<int> x = 1;
	        x <<= 2;
	        CPPUNIT_ASSERT(x == 100);
	    }

	    void test_shift_right_equal1 () {
	        Integer<int> x = 10;
	        x >>= 1;
	        CPPUNIT_ASSERT(x == 1);
	    }

	    void test_shift_right_equal2 () {
	        Integer<int> x = 100;
	        x >>= 2;
	        CPPUNIT_ASSERT(x == 1);
	    }

	    void test_shift_right_equal3 () {
	        Integer<int> x = 12345;
	        x >>= 2;
	        CPPUNIT_ASSERT(x == 123);
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

    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);

    CPPUNIT_TEST(test_abs1);
    CPPUNIT_TEST(test_abs2);

    CPPUNIT_TEST(test_negation1);
    CPPUNIT_TEST(test_negation2);

    CPPUNIT_TEST(test_output1);
    CPPUNIT_TEST(test_output2);
    CPPUNIT_TEST(test_output3);

    CPPUNIT_TEST(test_pow1);
    CPPUNIT_TEST(test_pow2);
    CPPUNIT_TEST(test_pow3);

    CPPUNIT_TEST(test_plus_equal1);
    CPPUNIT_TEST(test_plus_equal2);
    CPPUNIT_TEST(test_plus_equal3);


    CPPUNIT_TEST(test_multiply_equal1);
    CPPUNIT_TEST(test_multiply_equal2);
    CPPUNIT_TEST(test_multiply_equal3);

//    CPPUNIT_TEST(test_divide_equal1);
//    CPPUNIT_TEST(test_divide_equal2);
//    CPPUNIT_TEST(test_divide_equal3);

    CPPUNIT_TEST(test_mod_equal1);
    CPPUNIT_TEST(test_mod_equal2);
    CPPUNIT_TEST(test_mod_equal3);

    CPPUNIT_TEST(test_shift_left_equal1);
    CPPUNIT_TEST(test_shift_left_equal2);
    CPPUNIT_TEST(test_shift_left_equal3);

    CPPUNIT_TEST(test_shift_right_equal1);
    CPPUNIT_TEST(test_shift_right_equal2);
    CPPUNIT_TEST(test_shift_right_equal3);

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
