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
#include <cstring> // strcmp
#include <sstream> // ostringstream
#include <stdexcept> // invalid_argument
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

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
        const int a[] = {1};
        const int b[] = {1, 0, 0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 1, 5, x);
        CPPUNIT_ASSERT((p - x) == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_3 () {
        const int a[] = {1, 2, 3, 4, 5};
        const int b[] = {1, 2, 3, 4, 5, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 5, 1, x);
        CPPUNIT_ASSERT((p - x) == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_4 () {
        const int a[] = {1, 2, 3, 4, 5};
        const int b[] = {1, 2, 3, 4, 5};
              int x[10];
        const int* p = shift_left_digits(a, a + 5, 0, x);
        CPPUNIT_ASSERT((p - x) == 5);
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
        const int a[] = {1, 2, 3, 4};
        const int b[] = {1, 2, 3};
              int x[10];
        const int* p = shift_right_digits(a, a + 4, 1, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_3 () {
        const int a[] = {1};
        const int b[] = {0};
              int x[10];
        const int* p = shift_right_digits(a, a + 1, 1, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_4 () {
        const int a[] = {1};
        const int b[] = {1};
              int x[10];
        const int* p = shift_right_digits(a, a + 1, 0, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits () {
        const int a[] = {4, 3, 2};
        const int b[] = {7, 6, 5};
        const int c[] = {1, 0, 8};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_2 () {
        const int a[] = {3, 2, 1};
        const int b[] = {9, 7, 8};
        const int c[] = {2, 0, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {3};
        const int b[] = {9, 7};
        const int c[] = {2, 8};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_4 () {
        const int a[] = {4, 3, 2, 1};
        const int b[] = {9, 7, 8};
        const int c[] = {3, 1, 1, 2};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // ------------
    // minus_digits
    // ------------

    void test_minus_digits () {
        const int a[] = {1, 0, 8};
        const int b[] = {7, 6, 5};
        const int c[] = {4, 3, 2};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_2 () {
        const int a[] = {0, 1};
        const int b[] = {5};
        const int c[] = {5};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {0, 0, 8};
        const int b[] = {0, 2};
        const int c[] = {0, 8, 7};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_4 () {
        const int a[] = {0, 0, 0, 1};
        const int b[] = {1};
        const int c[] = {9, 9, 9};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int a[] = {4, 3, 2};
        const int b[] = {7, 6, 5};
        const int c[] = {8, 7, 6, 2, 3, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_2 () {
        const int a[] = {2};
        const int b[] = {5};
        const int c[] = {0, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_3 () {
        const int a[] = {0, 1};
        const int b[] = {0, 1};
        const int c[] = {0, 0, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_4 () {
        const int a[] = {4, 1};
        const int b[] = {4, 1};
        const int c[] = {6, 9, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // --------------
    // divides_digits
    // --------------

    void test_divides_digits () {
        const int a[] = {0, 1};
        const int b[] = {5};
        const int c[] = {2};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

   void test_divides_digits_2 () {
        const int a[] = {8, 7, 6, 2, 3, 1};
        const int b[] = {7, 6, 5};
        const int c[] = {4, 3, 2};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_3 () {
        const int a[] = {0, 1};
        const int b[] = {0, 1};
        const int c[] = {1};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_4 () {
        const int a[] = {0, 0, 1};
        const int b[] = {5};
        const int c[] = {0, 2};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 1, x);
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

    // ---
    // abs
    // ---

    void test_abs_1 () {
        try {
            Integer<int> x = -98765;
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
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------
    // equal_to
    // --------

    void test_equal_to () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = 98765;
            CPPUNIT_ASSERT( x == y);
            CPPUNIT_ASSERT( x == 98765);
            CPPUNIT_ASSERT( 98765 == x);
            CPPUNIT_ASSERT( !(x != y));
            CPPUNIT_ASSERT( !(x != 98765));
            CPPUNIT_ASSERT(!(98765 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_2 () {
        try {
            const Integer<int> x = 98764;
            const Integer<int> y = 98765;
            CPPUNIT_ASSERT( x != y);
            CPPUNIT_ASSERT( x == 98764);
            CPPUNIT_ASSERT( 98765 != x);}
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

    void test_negation_2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 98765);}
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

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int> x = 14;
            const int e = 3;
            Integer<int>& y = x.pow(e);
            CPPUNIT_ASSERT( e == 3);
            CPPUNIT_ASSERT( x == 2744);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 2;
            const int e = 4;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == 4);
            CPPUNIT_ASSERT(y == 16);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -
    // <
    // -


    void test_less_than () {
        try {
            const Integer<int> x = 2;
            const Integer<int> y = 16;
            CPPUNIT_ASSERT(x < y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

   void test_less_than_2 () {
        try {
            const Integer<int> x = 2;
            const Integer<int> y = 16;
            CPPUNIT_ASSERT(!(y < x));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_than_3 () {
        try {
            const Integer<int> x = 16;
            const Integer<int> y = 12;
            CPPUNIT_ASSERT(!(x < y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_than_4 () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16;
            CPPUNIT_ASSERT(x < y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --
    // +=
    // --

    void test_plus_equals () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16 + x;
            CPPUNIT_ASSERT(28 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equals_2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 1 + x;
            CPPUNIT_ASSERT(2 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equals_3 () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16 + x;
            CPPUNIT_ASSERT(28 != x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --
    // -=
    // --

    void test_minus_equals () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16 - x;
            CPPUNIT_ASSERT(4 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 1 + x;
            CPPUNIT_ASSERT(1 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_3 () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16 - x;
            CPPUNIT_ASSERT(4 != x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --
    // *=
    // --

    void test_multiplies_equals () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16 * x;
            CPPUNIT_ASSERT(192 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiplies_equals_2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 2 * x;
            CPPUNIT_ASSERT(1 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiplies_equals_3 () {
        try {
            const Integer<int> x = 12;
            const Integer<int> y = 16 * x;
            CPPUNIT_ASSERT(192 != x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --
    // /=
    // --

    void test_divides_equals () {
        try {
            const Integer<int> x = 4;
            const Integer<int> y = 16 / x;
            CPPUNIT_ASSERT(4 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divides_equals_2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 2 / x;
            CPPUNIT_ASSERT(1 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divides_equals_3 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = 20 / x;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            }}

    // --
    // <<=
    // --

    void test_shift_left_equals () {
        try {
            const Integer<int> x = 4;
            const Integer<int> y = x << 3;
            CPPUNIT_ASSERT(4000 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_left_equals_2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = x << 2;
            CPPUNIT_ASSERT(1 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_left_equals_3 () {
        try {
            const Integer<int> x = 11;
            const Integer<int> y = x << 0;
            CPPUNIT_ASSERT(11 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --
    // >>=
    // --

    void test_shift_right_equals () {
        try {
            const Integer<int> x = 4000;
            const Integer<int> y = x >> 3;
            CPPUNIT_ASSERT(4 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_right_equals_2 () {
        try {
            const Integer<int> x = 100;
            const Integer<int> y = x >> 2;
            CPPUNIT_ASSERT(100 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_right_equals_3 () {
        try {
            const Integer<int> x = 11;
            const Integer<int> y = x >> 0;
            CPPUNIT_ASSERT(11 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits_2);
    CPPUNIT_TEST(test_shift_left_digits_3);
    CPPUNIT_TEST(test_shift_left_digits_4);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_shift_right_digits_2);
    CPPUNIT_TEST(test_shift_right_digits_3);
    CPPUNIT_TEST(test_shift_right_digits_4);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_plus_digits_4);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_minus_digits_4);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_4);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_divides_digits_3);
    CPPUNIT_TEST(test_divides_digits_4);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_plus_equals);
    CPPUNIT_TEST(test_plus_equals_2);
    CPPUNIT_TEST(test_plus_equals_3);
    CPPUNIT_TEST(test_minus_equals);
    CPPUNIT_TEST(test_minus_equals_2);
    CPPUNIT_TEST(test_minus_equals_3);
    CPPUNIT_TEST(test_multiplies_equals);
    CPPUNIT_TEST(test_multiplies_equals_2);
    CPPUNIT_TEST(test_multiplies_equals_3);
    CPPUNIT_TEST(test_divides_equals);
    CPPUNIT_TEST(test_divides_equals_2);
    CPPUNIT_TEST(test_divides_equals_3);
    CPPUNIT_TEST(test_shift_left_equals);
    CPPUNIT_TEST(test_shift_left_equals_2);
    CPPUNIT_TEST(test_shift_left_equals_3);
    CPPUNIT_TEST(test_shift_right_equals);
    CPPUNIT_TEST(test_shift_right_equals_2);
    CPPUNIT_TEST(test_shift_right_equals_3);
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
