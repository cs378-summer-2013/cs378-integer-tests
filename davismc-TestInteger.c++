/* UT EID : davismc2 */

/******************************************************************************
 * Program: C378 Project 3 - Integer
 * Student: Merrill Davis
 * CS Server ID: davismc
 * Class: CS 378
 * Summer 2013
 *
 * Purpose: a program to implement an arbitrary-precision integer class and
 *  to compute the 20th Mersenne prime.
 *
 *****************************************************************************/

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
#include <forward_list> // forward_list

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
        const int a[] = {0};
        const int b[] = {0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 1, 3, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_3 () {
        const int a[] = {9, 7, 6};
        const int b[] = {9, 7, 6};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 0, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_4 () {
        const int a[] = {4, 5, 6};
        const int b[] = {4, 5, 6, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 1, x);
        CPPUNIT_ASSERT((p - x) == 4);
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
        const int a[] = {5, 6, 8};
        const int b[] = {0};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 4, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_3 () {
        const int a[] = {4, 0, 0, 0, 0};
        const int b[] = {4, 0};
              int x[10];
        const int* p = shift_right_digits(a, a + 5, 3, x);
        CPPUNIT_ASSERT((p - x) == 2);
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
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int c[] = {2, 4, 6, 9, 1, 3, 5, 7, 8, 2, 4, 6, 9, 1, 3, 5, 7, 8,
		2, 4, 6, 9, 1, 3, 4};
              int x[35];
        const int* p = plus_digits(a, a + 25, b, b + 25, x);
        CPPUNIT_ASSERT(p - x == 25);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {0};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// Test carry
    void test_plus_digits_4 () {
        const int a[] = {2};
        const int b[] = {9};
        const int c[] = {1, 1};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // Tests weak iterator capability
    void test_plus_digits_5 () {
		std::forward_list<int> a = {3, 6, 2, 5};
		std::forward_list<int> b = {7, 6, 2, 1};
        const int c[] = {1, 1, 2, 4, 6};
              int x[10];
        const int* p = plus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// Test for different size lists
    void test_plus_digits_6 () {
        const int a[] = {4, 7, 9, 2, 5};
        const int b[] = {3, 2};
        const int c[] = {4, 7, 9, 5, 7};
              int x[10];
        const int* p = plus_digits(a, a + 5, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// Test for different size lists
    void test_plus_digits_7 () {
        const int a[] = {7, 7, 5};
        const int b[] = {7, 3, 8, 5, 2, 3};
        const int c[] = {7, 3, 9, 2, 9, 8};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 6, x);
        CPPUNIT_ASSERT(p - x == 6);
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
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int b[] = {1, 2, 3, 4};
        const int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 3, 3, 3, 3};
              int x[25];
        const int* p = minus_digits(a, a + 25, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 25);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int c[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0};
              int x[25];
        const int* p = minus_digits(a, a + 25, b, b + 25, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// Test weak iterator capability
    void test_minus_digits_4 () {
		std::forward_list<int> a = {9, 6, 2, 5};
		std::forward_list<int> b = {7, 8, 3, 1};
        const int c[] = {1, 7, 9, 4};
              int x[10];
        const int* p = minus_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_5 () {
        const int a[] = {8, 0, 0, 0};
        const int b[] = {2};
        const int c[] = {7, 9, 9, 8};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 4);
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

    void test_multiplies_digits_1 () {
        const int a[] = {9, 1, 4};
        const int b[] = {8, 4};
        const int c[] = {7, 6, 7, 7, 6};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_2 () {
        const int a[] = {2, 3, 4};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_3 () {
      const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int c[] = {1, 5, 2, 4, 1, 5, 7, 8, 7, 8, 0, 6, 7, 3, 6, 7, 8, 5,
		4, 6, 1, 0, 5, 7, 5, 6, 3, 0, 5, 7, 4, 6, 2, 5, 6, 5, 4, 0, 3,
		1, 4, 1, 5, 6, 7, 7, 4, 8, 9};
              int x[55];
        const int* p = multiplies_digits(a, a + 25, b, b + 25, x);
        CPPUNIT_ASSERT(p - x == 49);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	// Test weak iterator
    void test_multiplies_digits_4 () {
        std::forward_list<int> a = {5, 6, 1};
        std::forward_list<int> b = {7};
        const int c[] = {3, 9, 2, 7};
              int x[10];
        const int* p = multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), x);
        CPPUNIT_ASSERT(p - x == 4);
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
        const int a[] = {0};
        const int b[] = {6, 4, 2};
        const int c[] = {0};
              int x[10];
        const int* p = divides_digits(a, a + 1, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_3 () {
        const int a[] = {4, 8, 6, 5};
        const int b[] = {6, 4, 2};
        const int c[] = {7};
              int x[10];
        const int* p = divides_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_4 () {
        const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		1, 2, 3, 4, 5, 6, 7};
        const int b[] = {6};
        const int c[] = {2, 0, 5, 7, 6, 1, 3, 1, 5, 2, 0, 5, 7, 6, 1, 3, 1, 5,
		2, 0, 5, 7, 6, 1};
              int x[28];
        const int* p = divides_digits(a, a + 25, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 24);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_5 () {
        const int a[] = {4, 8, 6};
        const int b[] = {2};
        const int c[] = {2, 4, 3};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 1, x);
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

    void test_constructor_4 () {
        try {
            const Integer<int> x("-12");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_5 () {
        try {
            const Integer<int> x="1234567891234567891234567";}
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
            const Integer<int> x ("-1234567891234567891234567");
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == "-1234567891234567891234567");
            CPPUNIT_ASSERT(y ==  "1234567891234567891234567");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_4 () {
        try {
            const Integer<int> x = "1234567891234567891234567";
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == "1234567891234567891234567");
            CPPUNIT_ASSERT(y ==  "1234567891234567891234567");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

   void test_abs_5 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y == 0);}
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
            const Integer<int> x = "-1234567891234567891234567";
            const Integer<int> y = "-1234567891234567891234567";
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == "-1234567891234567891234567");
            CPPUNIT_ASSERT(  "-1234567891234567891234567" == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != "-1234567891234567891234567"));
            CPPUNIT_ASSERT(!("-1234567891234567891234567" != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_3 () {
        try {
            const Integer<int> x = "1234567891234567891234567";
            const Integer<int> y = "-1234567891234567891234567";
            CPPUNIT_ASSERT(     !(x == y));
            CPPUNIT_ASSERT(      x == "1234567891234567891234567");
            CPPUNIT_ASSERT(  "1234567891234567891234567" == x);
            CPPUNIT_ASSERT(     (x != y));
            CPPUNIT_ASSERT(    !(x != "1234567891234567891234567"));
            CPPUNIT_ASSERT(("1234567891234567891234567" != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_4 () {
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

	// Should ignore leading 0's in constructor
    void test_equal_to_5 () {
        try {
            const Integer<int> x = "054";
            const Integer<int> y = "54";
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == "54");
            CPPUNIT_ASSERT(  "54" == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != "54"));
            CPPUNIT_ASSERT(!("54" != y));}
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
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation_3 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation_4 () {
        try {
            const Integer<int> x = "1234567891234567891234567";
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == "-1234567891234567891234567");}
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
            const Integer<int> x = "1234567891234567891234567";
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "1234567891234567891234567");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_3 () {
        try {
            const Integer<int> x = "-1234567891234567891234567";
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-1234567891234567891234567");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 2;
            const int          e =  8;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 8);
            CPPUNIT_ASSERT( x ==    256);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 0;
            const int          e =  2;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(e ==  2);
            CPPUNIT_ASSERT(y ==     0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

     void test_pow_3 () {
        try {
            Integer<int>       x = 98;
            const int          e =  12;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 12);
            CPPUNIT_ASSERT( x == "784716723734800033386496");
   			CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

	void test_pow_4 () {
        try {
            Integer<int>       x = 1;
            const int          e =  0;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 0);
            CPPUNIT_ASSERT( y ==   "1");
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------
    // Integer multiply_equal  *=
    // ------
	void test_Integer_multiply_equal_1 () {
        Integer<int> a = "234";
        Integer<int> b = "567";
		a *= b;
        CPPUNIT_ASSERT(a == 132678);}

	void test_Integer_multiply_equal_2 () {
        Integer<int> a = "-5678";
        Integer<int> b = "789";
		a *= b;
        CPPUNIT_ASSERT(a == -4479942);}

	void test_Integer_multiply_equal_3 () {
        Integer<int> a = "9";
        Integer<int> b = "-32";
		a *= b;
        CPPUNIT_ASSERT(a == -288);}

	void test_Integer_multiply_equal_4 () {
        Integer<int> a = "8";
        Integer<int> b = "0";
		a *= b;
        CPPUNIT_ASSERT(a == 0);}

	void test_Integer_multiply_equal_5 () {
        Integer<int> a = "0";
        const Integer<int> b = "0";
		a *= b;
		Integer<int> x = "0";
        CPPUNIT_ASSERT(a == x);}

	void test_Integer_multiply_equal_6 () {
        Integer<int> a = "999999999999999999999";
        Integer<int> b = "-999999999999999999999";
		a *= b;
        CPPUNIT_ASSERT(a == "-999999999999999999998000000000000000000001");}

    // ------
    // Integer divide_equal  /=
    // ------

    void test_Integer_divide_equal_1 () {
        try {
        		  Integer<int> a = "12";
        	const Integer<int> b = "0";
			a /= b;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_Integer_divide_equal_2 () {
        try {
                  Integer<int> a = "24";
        	const Integer<int> b = "8";
			a /= b;
			CPPUNIT_ASSERT(a == 3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_3 () {
        try {
                  Integer<int> a = "0";
        	const Integer<int> b = "5";
			a /= b;
			CPPUNIT_ASSERT(a == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_4 () {
        try {
                  Integer<int> a = "10";
        	const Integer<int> b = "12";
			a /= b;
			CPPUNIT_ASSERT(a == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_5 () {
        try {
                  Integer<int> a = "56";
        	const Integer<int> b = "13";
			a /= b;
			CPPUNIT_ASSERT(a == "4");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_6 () {
        try {
                  Integer<int> a = "-30";
        	const Integer<int> b = "-10";
			a /= b;
			CPPUNIT_ASSERT(a == 3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_7 () {
        try {
                  Integer<int> a = "-120";
        	const Integer<int> b = "40";
			a /= b;
			CPPUNIT_ASSERT(a == -3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_8 () {
        try {
                  Integer<int> a = "2500";
        	const Integer<int> b = "-211";
			a /= b;
			CPPUNIT_ASSERT(a == -11);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_9 () {
        try {
                  Integer<int> a = "50";
        	const Integer<int> b = "60";
			a /= b;
			CPPUNIT_ASSERT(a == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_divide_equal_10 () {
        try {
                  Integer<int> a = "6";
        	const Integer<int> b = "6";
			a /= b;
			CPPUNIT_ASSERT(a == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------
    // Integer mod_equal  %=
    // ------

    void test_Integer_mod_equal_1 () {
        try {
        		  Integer<int> a = "12";
        	const Integer<int> b = "0";
			a %= b;
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer()"));}}

    void test_Integer_mod_equal_2 () {
        try {
                  Integer<int> a = "13";
        	const Integer<int> b = "2";
			a %= b;
			CPPUNIT_ASSERT(a == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_mod_equal_3 () {
        try {
                  Integer<int> a = "12";
        	const Integer<int> b = "6";
			a %= b;
			CPPUNIT_ASSERT(a == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_mod_equal_4 () {
        try {
                  Integer<int> a = "1";
        	const Integer<int> b = "1";
			a %= b;
			CPPUNIT_ASSERT(a == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_mod_equal_5 () {
        try {
                  Integer<int> a = "10";
        	const Integer<int> b = "6";
			a %= b;
			CPPUNIT_ASSERT(a == 4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_mod_equal_6 () {
        try {
                  Integer<int> a = 3;
        	const Integer<int> b = "1234567891234567891234567";
			a %= b;
			CPPUNIT_ASSERT(a == "3");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_Integer_mod_equal_7 () {
        try {
                  Integer<int> a = 0;
        	const Integer<int> b = "12";
			a %= b;
			CPPUNIT_ASSERT(a == "0");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // ------
    // Integer plus_equal  +=
    // ------
	void test_Integer_plus_equal_1 () {
        Integer<int> a = "234";
        Integer<int> b = "567";
		a += b;
        CPPUNIT_ASSERT(a == 801);}

	void test_Integer_plus_equal_2 () {
        Integer<int> a = "0";
        Integer<int> b = "0";
		a += b;
        CPPUNIT_ASSERT(a == 0);}

	void test_Integer_plus_equal_3 () {
        Integer<int> a = "-3";
        Integer<int> b = "3";
		a += b;
        CPPUNIT_ASSERT(a == "0");}

	void test_Integer_plus_equal_4 () {
        Integer<int> a = "30";
        Integer<int> b = "-70";
		a += b;
        CPPUNIT_ASSERT(a == "-40");}

	void test_Integer_plus_equal_5 () {
        Integer<int> a = "-130";
        Integer<int> b = "-120";
		a += b;
        CPPUNIT_ASSERT(a == -250);}

	void test_Integer_plus_equal_6 () {
        Integer<int> a = "1986";
        Integer<int> b = "-96324";
		a += b;
        CPPUNIT_ASSERT(a == -94338);}

	// ------
    // Integer minus_equal  -=
    // ------
	void test_Integer_minus_equal_1 () {
        Integer<int> a = "234";
        Integer<int> b = "567";
		a -= b;
        CPPUNIT_ASSERT(a == -333);}

	void test_Integer_minus_equal_2 () {
        Integer<int> a = "0";
        Integer<int> b = "0";
		a -= b;
        CPPUNIT_ASSERT(a == 0);}

	void test_Integer_minus_equal_3 () {
        Integer<int> a = "3";
        Integer<int> b = "3";
		a -= b;
        CPPUNIT_ASSERT(a == "0");}

	void test_Integer_minus_equal_4 () {
        Integer<int> a = "-30";
        Integer<int> b = "-70";
		a -= b;
        CPPUNIT_ASSERT(a == "40");}

	void test_Integer_minus_equal_5 () {
        Integer<int> a = "0500";
        Integer<int> b = "-120";
		a += b;
        CPPUNIT_ASSERT(a == 380);}

    // ------
    // Integer less_than <
    // ------
	void test_Integer_less_than_1 () {
        Integer<int> a = "234";
        Integer<int> b = "567";
        CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(!(b < a));}

	void test_Integer_less_than_2 () {
        Integer<int> a = "922";
        Integer<int> b = "952";
        CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(!(b < a));}

	// Single digit
	void test_Integer_less_than_3 () {
        Integer<int> a = "1";
        Integer<int> b = "2";
        CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(!(b < a));}

	// 0
	void test_Integer_less_than_4 () {
        Integer<int> a = "0";
        Integer<int> b = "0";
        CPPUNIT_ASSERT(!(a < b));
		CPPUNIT_ASSERT(!(b < a));}

	// Big int
	void test_Integer_less_than_5 () {
        Integer<int> a = "1234567891234567891234567";
        Integer<int> b = "1234567891234567891234567";
        CPPUNIT_ASSERT(!(a < b));
		CPPUNIT_ASSERT(!(b < a));}

	void test_Integer_less_than_6 () {
        Integer<int> a = "1234567891234567891234565";
        Integer<int> b = "1234567891234567891234567";
        CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(!(b < a));}

	// Negative numbers
	void test_Integer_less_than_7 () {
        Integer<int> a = "-7";
        Integer<int> b = "5";
        CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(!(b < a));}

	void test_Integer_less_than_8 () {
        Integer<int> a = "12";
        Integer<int> b = "-9";
        CPPUNIT_ASSERT(!(a < b));
		CPPUNIT_ASSERT(b < a);}

	void test_Integer_less_than_9 () {
        Integer<int> a = "-12";
        Integer<int> b = "-9";
        CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(!(b < a));}


    // ------
    // Integer greater_than >
    // ------

	void test_Integer_greater_than_1 () {
        Integer<int> a = "256";
        Integer<int> b = "255";
        CPPUNIT_ASSERT(a > b);
		CPPUNIT_ASSERT(!(b > a));}

	void test_Integer_greater_than_2 () {
        Integer<int> a = "0";
        Integer<int> b = "0";
        CPPUNIT_ASSERT(!(a > b));
		CPPUNIT_ASSERT(!(b > a));}

	void test_Integer_greater_than_3 () {
        Integer<int> a = "-3";
        Integer<int> b = "-9";
        CPPUNIT_ASSERT(a > b);
		CPPUNIT_ASSERT(!(b > a));}

    // ------
    // Integer shift_right  >>= >>
    // ------
	void test_Integer_shift_right_1 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a >>= 0;
		b = b >> 0;
        CPPUNIT_ASSERT(a == 123456789);
	    CPPUNIT_ASSERT(b == 123456789);}

	void test_Integer_shift_right_2 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a >>= 1;
		b = b >> 1;
        CPPUNIT_ASSERT(a == 12345678);
	    CPPUNIT_ASSERT(b == 12345678);}

	void test_Integer_shift_right_3 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a >>= 2;
		b = b >> 2;
        CPPUNIT_ASSERT(a == 1234567);
	    CPPUNIT_ASSERT(b == 1234567);}

	void test_Integer_shift_right_4 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a >>= 9;
		b = b >> 9;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

	void test_Integer_shift_right_5 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a >>= 10;
		b = b >> 10;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

	void test_Integer_shift_right_6 () {
        Integer<int> a = "-562";
		Integer<int> b = "-562";
		a >>= 2;
		b = b >> 2;
        CPPUNIT_ASSERT(a == -5);
	    CPPUNIT_ASSERT(b == -5);}

	void test_Integer_shift_right_7 () {
        Integer<int> a = "-562";
		Integer<int> b = "-562";
		a >>= 3;
		b = b >> 3;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

	void test_Integer_shift_right_8 () {
        Integer<int> a = "0";
		Integer<int> b = "0";
		a >>= 3;
		b = b >> 3;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

    // ------
    // Integer shift_left  <<= <<
    // ------
	void test_Integer_shift_left_1 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a <<= 0;
		b = b << 0;
        CPPUNIT_ASSERT(a == 123456789);
	    CPPUNIT_ASSERT(b == 123456789);}

	void test_Integer_shift_left_2 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a <<= 1;
		b = b << 1;
        CPPUNIT_ASSERT(a == 1234567890);
	    CPPUNIT_ASSERT(b == 1234567890);}

	void test_Integer_shift_left_3 () {
        Integer<int> a = "123456789";
		Integer<int> b = "123456789";
		a <<= 2;
		b = b << 2;
        CPPUNIT_ASSERT(a == "12345678900");
	    CPPUNIT_ASSERT(b == "12345678900");}

	void test_Integer_shift_left_4 () {
        Integer<int> a = "1";
		Integer<int> b = "1";
		a <<= 9;
		b = b << 9;
        CPPUNIT_ASSERT(a == 1000000000);
	    CPPUNIT_ASSERT(b == 1000000000);}

	void test_Integer_shift_left_5 () {
        Integer<int> a = "-1";
		Integer<int> b = "-1";
		a <<= 3;
		b = b << 3;
        CPPUNIT_ASSERT(a == -1000);
	    CPPUNIT_ASSERT(b == -1000);}

	void test_Integer_shift_left_6 () {
        Integer<int> a = "-562";
		Integer<int> b = "-562";
		a <<= 2;
		b = b << 2;
        CPPUNIT_ASSERT(a == -56200);
	    CPPUNIT_ASSERT(b == -56200);}

	void test_Integer_shift_left_7 () {
        Integer<int> a = "-562";
		Integer<int> b = "-562";
		a <<= 3;
		b = b << 3;
        CPPUNIT_ASSERT(a == -562000);
	    CPPUNIT_ASSERT(b == -562000);}

	void test_Integer_shift_left_8 () {
        Integer<int> a = "0";
		Integer<int> b = "0";
		a <<= 3;
		b = b << 3;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

    // ------
    // Integer decrement  --
    // ------
	void test_Integer_decrement_1 () {
        Integer<int> a = "5";
		Integer<int> b = "5";
		--a;
		b--;
        CPPUNIT_ASSERT(a == 4);
	    CPPUNIT_ASSERT(b == 4);}

	void test_Integer_decrement_2 () {
        Integer<int> a = "1";
		Integer<int> b = "1";
		--a;
		b--;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

	void test_Integer_decrement_3 () {
        Integer<int> a = 0;
		Integer<int> b = 0;
		--a;
		b--;
        CPPUNIT_ASSERT(a == -1);
	    CPPUNIT_ASSERT(b == -1);}

    // ------
    // Integer increment++
    // ------
	void test_Integer_increment_1 () {
        Integer<int> a = "5";
		Integer<int> b = "5";
		++a;
		b++;
        CPPUNIT_ASSERT(a == 6);
	    CPPUNIT_ASSERT(b == 6);}

	void test_Integer_increment_2 () {
        Integer<int> a = "-1";
		Integer<int> b = "-1";
		++a;
		b++;
        CPPUNIT_ASSERT(a == 0);
	    CPPUNIT_ASSERT(b == 0);}

	void test_Integer_increment_3 () {
        Integer<int> a = 0;
		Integer<int> b = 0;
		++a;
		b++;
        CPPUNIT_ASSERT(a == 1);
	    CPPUNIT_ASSERT(b == 1);}

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
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_plus_digits_4);
    CPPUNIT_TEST(test_plus_digits_5);
    CPPUNIT_TEST(test_plus_digits_6);
    CPPUNIT_TEST(test_plus_digits_7);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_minus_digits_4);
    CPPUNIT_TEST(test_minus_digits_5);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_4);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_divides_digits_3);
    CPPUNIT_TEST(test_divides_digits_4);
    CPPUNIT_TEST(test_divides_digits_5);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_abs_4);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);
    CPPUNIT_TEST(test_equal_to_4);
    CPPUNIT_TEST(test_equal_to_5);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_negation_3);
    CPPUNIT_TEST(test_negation_4);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
	CPPUNIT_TEST(test_Integer_multiply_equal_1);
	CPPUNIT_TEST(test_Integer_multiply_equal_2);
	CPPUNIT_TEST(test_Integer_multiply_equal_3);
	CPPUNIT_TEST(test_Integer_multiply_equal_4);
	CPPUNIT_TEST(test_Integer_multiply_equal_5);
	CPPUNIT_TEST(test_Integer_multiply_equal_6);
	CPPUNIT_TEST(test_Integer_plus_equal_1);
	CPPUNIT_TEST(test_Integer_plus_equal_2);
	CPPUNIT_TEST(test_Integer_plus_equal_3);
	CPPUNIT_TEST(test_Integer_plus_equal_4);
	CPPUNIT_TEST(test_Integer_plus_equal_5);
	CPPUNIT_TEST(test_Integer_plus_equal_6);
	CPPUNIT_TEST(test_Integer_minus_equal_1);
	CPPUNIT_TEST(test_Integer_minus_equal_2);
	CPPUNIT_TEST(test_Integer_minus_equal_3);
	CPPUNIT_TEST(test_Integer_minus_equal_4);
	CPPUNIT_TEST(test_Integer_minus_equal_5);
	CPPUNIT_TEST(test_Integer_divide_equal_1);
	CPPUNIT_TEST(test_Integer_divide_equal_2);
	CPPUNIT_TEST(test_Integer_divide_equal_3);
	CPPUNIT_TEST(test_Integer_divide_equal_4);
	CPPUNIT_TEST(test_Integer_divide_equal_5);
	CPPUNIT_TEST(test_Integer_divide_equal_6);
	CPPUNIT_TEST(test_Integer_divide_equal_7);
	CPPUNIT_TEST(test_Integer_divide_equal_8);
	CPPUNIT_TEST(test_Integer_divide_equal_9);
	CPPUNIT_TEST(test_Integer_divide_equal_10);  
	CPPUNIT_TEST(test_Integer_mod_equal_1);
	CPPUNIT_TEST(test_Integer_mod_equal_2);
	CPPUNIT_TEST(test_Integer_mod_equal_3);
	CPPUNIT_TEST(test_Integer_mod_equal_4);
	CPPUNIT_TEST(test_Integer_mod_equal_5);
	CPPUNIT_TEST(test_Integer_mod_equal_6);
	CPPUNIT_TEST(test_Integer_less_than_1);
	CPPUNIT_TEST(test_Integer_less_than_2);
	CPPUNIT_TEST(test_Integer_less_than_3);
	CPPUNIT_TEST(test_Integer_less_than_4);
	CPPUNIT_TEST(test_Integer_less_than_5);
	CPPUNIT_TEST(test_Integer_less_than_6);
	CPPUNIT_TEST(test_Integer_less_than_7);
	CPPUNIT_TEST(test_Integer_less_than_8);
	CPPUNIT_TEST(test_Integer_less_than_9);
	CPPUNIT_TEST(test_Integer_greater_than_1);
	CPPUNIT_TEST(test_Integer_greater_than_2);
	CPPUNIT_TEST(test_Integer_greater_than_3);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
	CPPUNIT_TEST(test_Integer_shift_right_1);
	CPPUNIT_TEST(test_Integer_shift_right_2);
	CPPUNIT_TEST(test_Integer_shift_right_3);
	CPPUNIT_TEST(test_Integer_shift_right_4);
	CPPUNIT_TEST(test_Integer_shift_right_5);
	CPPUNIT_TEST(test_Integer_shift_right_6);
	CPPUNIT_TEST(test_Integer_shift_right_7);
	CPPUNIT_TEST(test_Integer_shift_right_8);
	CPPUNIT_TEST(test_Integer_shift_left_1);
	CPPUNIT_TEST(test_Integer_shift_left_2);
	CPPUNIT_TEST(test_Integer_shift_left_3);
	CPPUNIT_TEST(test_Integer_shift_left_4);
	CPPUNIT_TEST(test_Integer_shift_left_5);
	CPPUNIT_TEST(test_Integer_shift_left_6);
	CPPUNIT_TEST(test_Integer_shift_left_7);
	CPPUNIT_TEST(test_Integer_shift_left_8);
	CPPUNIT_TEST(test_Integer_increment_1);
	CPPUNIT_TEST(test_Integer_increment_2);
	CPPUNIT_TEST(test_Integer_increment_3);
	CPPUNIT_TEST(test_Integer_decrement_1);
	CPPUNIT_TEST(test_Integer_decrement_2);
	CPPUNIT_TEST(test_Integer_decrement_3);
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
