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

    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 1, x);
        CPPUNIT_ASSERT((p - x) == 2);
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
        const int a[] = {5, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 1, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {5, 5};
        const int b[] = {0};
        const int c[] = {5, 5};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_4 () {
        const int a[] = {9, 9, 9, 9, 9};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0, 0, 0};
              int x[10];
        const int* p = plus_digits(a, a + 5, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    // ------------
    // minus_digits
    // ------------

    void test_minus_digits_1 () {
        const int a[] = {8, 0, 1};
        const int b[] = {0};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_2 () {
        const int a[] = {8, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {1, 0, 0, 0};
        const int b[] = {9, 9, 9};
        const int c[] = {1};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_4 () {
        const int a[] = {2, 3, 4};
        const int b[] = {1};
        const int c[] = {2, 3, 3};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

	void test_multiplies_digits_1 () {
        const int a[] = {5};
        const int b[] = {1, 2, 5};
        const int c[] = {6, 2, 5};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_2 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_multiplies_digits_3 () {
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        const int b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        const int c[] = {1, 2, 1, 9, 3, 2, 6, 3, 1, 1, 1, 2, 6, 3, 5, 2, 6, 9};
              int x[20];
        const int* p = multiplies_digits(a, a + 9, b, b + 9, x);
        CPPUNIT_ASSERT(p - x == 18);
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
            const Integer<int> x(2);}
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

    void test_output_1 () {
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
            Integer<int>       x = 2;
            const int          e =  20;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 20);

            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

	//plus equal
	
    void test_plus_equal_1 () {
        Integer<int> a = 234;
        Integer<int> b = 0;
        Integer<int> c = 234;
        a += b;
        CPPUNIT_ASSERT(a == c);}

	void test_plus_equal_2 () {
        Integer<int> a = 234;
        Integer<int> b = 767;
        Integer<int> c = 1001;
        a += b;
        CPPUNIT_ASSERT(a == c);}

	void test_plus_equal_3 () {
        Integer<int> a = 1234;
        Integer<int> b = 1000;
        Integer<int> c = 2234;
        a += b;
        CPPUNIT_ASSERT(a == c);}

	//minus equal

	void test_minus_equal_1 () {
        Integer<int> a = 234;
        Integer<int> b = 1;
        Integer<int> c = 233;
        a -= b;
        CPPUNIT_ASSERT(a == c);}

	void test_minus_equal_2 () {
        Integer<int> a = 234;
        Integer<int> b = 233;
        Integer<int> c = 1;
        a -= b;
        CPPUNIT_ASSERT(a == c);}

	void test_minus_equal_3 () {
        Integer<int> a = 234;
        Integer<int> b = 200;
        Integer<int> c = 34;
        a -= b;
        CPPUNIT_ASSERT(a == c);}

	//times equal

	void test_times_equal_1 () {
        Integer<int> a = 234;
        Integer<int> b = 1;
        Integer<int> c = 234;
        a *= b;
        CPPUNIT_ASSERT(a == c);}

	void test_times_equal_2 () {
        Integer<int> a = 234;
        Integer<int> b = 567;
        Integer<int> c = 132678;
        a *= b;
        CPPUNIT_ASSERT(a == c);}

	void test_times_equal_3 () {
        Integer<int> a = 125;
        Integer<int> b = 50;
        Integer<int> c = 6250;
        a *= b;
        CPPUNIT_ASSERT(a == c);}


	//shift left digits

	void test_left_equal_1 () {
        Integer<int> a = 234;
		Integer<int> c = 23400;
        a <<= 2;
        CPPUNIT_ASSERT(a == c);}

	void test_left_equal_2 () {
        Integer<int> a = 23456789;
		Integer<int> c ("23456789000");
        a <<= 3;
        CPPUNIT_ASSERT(a == c);}

	void test_left_equal_3 () {
        Integer<int> a = 2;
		Integer<int> c = 2000;
        a <<= 3;
        CPPUNIT_ASSERT(a == c);}

	//shift right digits

	void test_right_equal_1 () {
        Integer<int> a = 234;
		Integer<int> c = 2;
        a >>= 2;
        CPPUNIT_ASSERT(a == c);}

	void test_right_equal_2 () {
        Integer<int> a = 2345;
		Integer<int> c = 234;
        a >>= 1;
        CPPUNIT_ASSERT(a == c);}

	void test_right_equal_3 () {
        Integer<int> a = 234567;
		Integer<int> c = 2;
        a >>= 5;
        CPPUNIT_ASSERT(a == c);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_plus_digits_1);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_plus_digits_4);
    CPPUNIT_TEST(test_minus_digits_1);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_minus_digits_4);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
    CPPUNIT_TEST(test_pow_1);
	CPPUNIT_TEST(test_plus_equal_1);
    CPPUNIT_TEST(test_plus_equal_2);
    CPPUNIT_TEST(test_plus_equal_3);
	CPPUNIT_TEST(test_minus_equal_1);
    CPPUNIT_TEST(test_minus_equal_2);
    CPPUNIT_TEST(test_minus_equal_3);
	CPPUNIT_TEST(test_times_equal_1);
    CPPUNIT_TEST(test_times_equal_2);
    CPPUNIT_TEST(test_times_equal_3);
	CPPUNIT_TEST(test_left_equal_1);
    CPPUNIT_TEST(test_left_equal_2);
    CPPUNIT_TEST(test_left_equal_3);
	CPPUNIT_TEST(test_right_equal_1);
    CPPUNIT_TEST(test_right_equal_2);
    CPPUNIT_TEST(test_right_equal_3);
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
