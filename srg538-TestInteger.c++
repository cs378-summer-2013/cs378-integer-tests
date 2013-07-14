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
        const int a[] = {4, 3, 2};
        const int b[] = {0, 0, 4, 3, 2};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_2(){
        const int a[] = {0};
        const int b[] = {0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a+1, 3, x);
        CPPUNIT_ASSERT((p-x)== 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
        
    }
    void test_shift_left_digits_3(){
        const int a[] = {0, 1, 2, 3};
        const int b[] = {0, 1, 2, 3};
              int x[10];
        const int* p = shift_left_digits(a, a+4, 0, x);
        CPPUNIT_ASSERT((p-x)== 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
        
    }

    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {4};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_2 () {
        const int a[] = {1, 2};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 2, 1, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}


    void test_shift_right_digits_3 () {
        const int a[] = {1, 0, 0, 0, 0};
        const int b[] = {1, 0, 0, 0, 0};
              int x[10];
        const int* p = shift_right_digits(a, a + 5, 0, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    //Altered Test to Match Our implementation of plus_digits
    void test_plus_digits () {
        const int a[] = {4, 3, 2};
        const int b[] = {2};
        const int c[] = {6, 3, 2};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_plus_digits_2 () {
        const int a[] = {0};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {9, 9, 9};
        const int b[] = {1};
        const int c[] = {0, 0, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 1, x);
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
        const int a[] = {9, 8};
        const int b[] = {8, 8};
        const int c[] = {1, 0};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {0, 0, 0, 1};
        const int b[] = {1};
        const int c[] = {9, 9, 9};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_4 () {
        const int a[] = {1};
        const int b[] = {1};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int b[] = {4, 3, 2};
        const int a[] = {7, 6, 5};
        const int c[] = {8, 7, 6, 2, 3, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);

        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}



    void test_multiplies_digits_2 () {
        const int b[] = {0, 1};
        const int a[] = {0, 1};
        const int c[] = {0, 0, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 2, b, b + 2, x);

        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_3 () {
        const int b[] = {5};
        const int a[] = {1};
        const int c[] = {5};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 1, x);

        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_4 () {
        const int b[] = {1};
        const int a[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 1, x);

        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // --------------
    // divides_digits
    // --------------

    void test_divides_digits () {
        const int a[] = {8, 7, 6, 2, 3, 1};
        const int b[] = {7, 6, 5};
        const int c[] = {4, 3, 2};
              int x[10];
        std::vector<int> a1 = {1, 3, 2, 6, 7, 8};
        std::vector<int> a2 = {5, 6, 7};
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits_2 () {
        const int a[] = {0, 1};
        const int b[] = {1};
        const int c[] = {0, 1};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_3 () {
        const int a[] = {0, 0, 1};
        const int b[] = {0, 1};
        const int c[] = {0, 1};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_4 () {
        const int a[] = {1, 1};
        const int b[] = {0, 1};
        const int c[] = {1};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 2, x);
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
            Integer<int> x = 98765;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT(x == 98765);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_abs_3 () {
        try {
            Integer<int> x = -89;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT(x == 89);
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

    void test_output_2 () {
        try {
            const Integer<int> x = 0;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "0");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_3 () {
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
            Integer<int>       x = 2;
            const int          e =  10;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 10);
            CPPUNIT_ASSERT( x == 1024);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 10;
            const int          e =  3;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e ==  3);
            CPPUNIT_ASSERT(y == 1000);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            const Integer<int> x = 5;
            const int          e = 0;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e ==  0);
            CPPUNIT_ASSERT(y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_4 () {
        try {
            const Integer<int> x = 2;
            const int          e = 10;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == 10);
            CPPUNIT_ASSERT(y == 1024);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    


    // ------
    // Plus 
    // ------

    void test_plus () {
        try {
            Integer<int> x = 15;
            Integer<int> e = 5;
            CPPUNIT_ASSERT(x == 15);
            CPPUNIT_ASSERT(e == 5);
            Integer<int> y(x + e);
            CPPUNIT_ASSERT(y == 20);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_2 () {
        try {
            Integer<int> x = 5;
            Integer<int> e = -5;
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e == -5);
            Integer<int> y(x + e);
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_3 () {
        try {
            Integer<int> x = 15;
            Integer<int> e = -5;
            CPPUNIT_ASSERT(x == 15);
            CPPUNIT_ASSERT(e == -5);
            Integer<int> y(x + e);
            CPPUNIT_ASSERT(y == 10);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // -----------
    // Plus Equals
    // -----------            

    void test_plus_equals () {
        try {
            Integer<int> x = 2;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == -2);
                         x += e;
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_plus_equals_2 () {
        try {
            Integer<int> x = 10;
            Integer<int> e = 15;
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == 15);
                         x += e;
            CPPUNIT_ASSERT(x == 25);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_equals_3 () {
        try {
            Integer<int> x = 3;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 3);
            CPPUNIT_ASSERT(e == -2);
                         x += e;
            CPPUNIT_ASSERT(x == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}  


    // -----------
    // Minus
    // -----------    


    void test_minus () {
    try {
        Integer<int> x = 2;
        Integer<int> e = -2;
        CPPUNIT_ASSERT(x == 2);
        CPPUNIT_ASSERT(e == -2);
        Integer<int> y(x - e);
        CPPUNIT_ASSERT(y == 4);}
    catch (std::invalid_argument& e) {
        CPPUNIT_ASSERT(false);}}   

    void test_minus_2 () {
    try {
        Integer<int> x = -2;
        Integer<int> e = -2;
        CPPUNIT_ASSERT(x == -2);
        CPPUNIT_ASSERT(e == -2);
        Integer<int> y(x - e);
        CPPUNIT_ASSERT(y == 0);}
    catch (std::invalid_argument& e) {
        CPPUNIT_ASSERT(false);}}   

    void test_minus_3 () {
    try {
        Integer<int> x = 10;
        Integer<int> e = 2;
        CPPUNIT_ASSERT(x == 10);
        CPPUNIT_ASSERT(e == 2);
        Integer<int> y(x - e);
        CPPUNIT_ASSERT(y == 8);}
    catch (std::invalid_argument& e) {
        CPPUNIT_ASSERT(false);}}   

    // -----------
    // Minus Equals
    // -----------

    void test_minus_equals () {
        try {
            Integer<int> x = 2;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == -2);
                         x -= e;
            CPPUNIT_ASSERT(x == 4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_minus_equals_2 () {
        try {
            Integer<int> x = 0;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(e == -2);
                         x -= e;
            CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_equals_3 () {
        try {
            Integer<int> x = 210;
            Integer<int> e = 100;
            CPPUNIT_ASSERT(x == 210);
            CPPUNIT_ASSERT(e == 100);
                         x -= e;
            CPPUNIT_ASSERT(x == 110);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}   

    // -----------
    // Multiply
    // -----------

    void test_multiply () {
        try {
            Integer<int> x = 2;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == -2);
            Integer<int> y(x * e);
            CPPUNIT_ASSERT(y == -4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiply_2 () {
        try {
            Integer<int> x = 10;
            Integer<int> e = 0;
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == 0);
            Integer<int> y(x * e);
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiply_3 () {
        try {
            Integer<int> x = 30;
            Integer<int> e = 10;
            CPPUNIT_ASSERT(x == 30);
            CPPUNIT_ASSERT(e == 10);
            Integer<int> y(x * e);
            CPPUNIT_ASSERT(y == 300);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // Multiply Equals
    // ---------------


    void test_multiply_equals () {
        try {
            Integer<int> x = 2;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == -2);
                         x *= e;
            CPPUNIT_ASSERT(x == -4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiply_equals_2 () {
        try {
            Integer<int> x = 5;
            Integer<int> e = 5;
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e == 5);
                         x *= e;
            CPPUNIT_ASSERT(x == 25);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiply_equals_3 () {
        try {
            Integer<int> x = 21;
            Integer<int> e = 0;
            CPPUNIT_ASSERT(x == 21);
            CPPUNIT_ASSERT(e == 0);
                         x *= e;
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // Divide
    // ---------------

    void test_divide () {
        try {
            Integer<int> x = 10;
            Integer<int> e = 5;
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == 5);
            Integer<int> y(x / e);
            CPPUNIT_ASSERT(y == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_divide_2 () {
        try {
            Integer<int> x = 11;
            Integer<int> e = 5;
            CPPUNIT_ASSERT(x == 11);
            CPPUNIT_ASSERT(e == 5);
            Integer<int> y(x / e);
            CPPUNIT_ASSERT(y == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_3 () {
        try {
            Integer<int> x = 10;
            Integer<int> e = -5;
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == -5);
            Integer<int> y(x / e);
            CPPUNIT_ASSERT(y == -2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // Divide Equals
    // ---------------

    void test_divide_equals () {
        try {
            Integer<int> x = 20;
            Integer<int> e = 2;
            CPPUNIT_ASSERT(x == 20);
            CPPUNIT_ASSERT(e == 2);
                         x /= e;
            CPPUNIT_ASSERT( x == 10);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}    


    void test_divide_equals_2 () {
        try {
            Integer<int> x = 20;
            Integer<int> e = 2;
            CPPUNIT_ASSERT(x == 20);
            CPPUNIT_ASSERT(e == 2);
                         x /= e;
            CPPUNIT_ASSERT( x == 10);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_equals_3 () {
        try {
            Integer<int> x = 21;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 21);
            CPPUNIT_ASSERT(e == -2);
                         x /= e;
            CPPUNIT_ASSERT( x == -10);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}    

    // ---------------
    // Mod
    // ---------------

    void test_mod () {
        try {
            Integer<int> x = 5;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e == -2);
            Integer<int> y(x % e);
            CPPUNIT_ASSERT(y == -1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_mod_2 () {
        try {
            Integer<int> x = 10;
            Integer<int> e = 3;
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == 3);
            Integer<int> y(x % e);
            CPPUNIT_ASSERT(y == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_mod_3 () {
        try {
            Integer<int> x = -32;
            Integer<int> e = 7;
            CPPUNIT_ASSERT(x == -32);
            CPPUNIT_ASSERT(e == 7);
            Integer<int> y(x % e);
            CPPUNIT_ASSERT(y == 3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // Mod Equals
    // ---------------

    void test_mod_equals () {
        try {
            Integer<int> x = 5;
            Integer<int> e = -2;
            CPPUNIT_ASSERT(x == 5);
            CPPUNIT_ASSERT(e == -2);
                         x %= e;
            CPPUNIT_ASSERT(x == -1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_mod_equals_2 () {
        try {
            Integer<int> x = 23;
            Integer<int> e = 7;
            CPPUNIT_ASSERT(x == 23);
            CPPUNIT_ASSERT(e == 7);
                         x %= e;
            CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_mod_equals_3 () {
        try {
            Integer<int> x = 10;
            Integer<int> e = 5;
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == 5);
                         x %= e;
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // Shift Left Equal
    // ---------------

    void test_lshift_equals () {
        try {
            Integer<int> x = 223;
            CPPUNIT_ASSERT(x == 223);
                         x <<= 1;
            //std::cout << "x" << x << std::endl;
            CPPUNIT_ASSERT(x == 2230);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_lshift_equals_2 () {
        try {
            Integer<int> x = 1;
            CPPUNIT_ASSERT(x == 1);
                         x <<= 2;
            CPPUNIT_ASSERT(x == 100);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_lshift_equals_3 () {
        try {
            Integer<int> x = 100;
            CPPUNIT_ASSERT(x == 100);
                         x <<= 5;
            //std::cout << "x" << x << std::endl;
            CPPUNIT_ASSERT((x == 10000000));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------------
    // Shift Right Equal
    // ---------------


    void test_rshift_equals () {
        try {
            Integer<int> x = 223;
            CPPUNIT_ASSERT(x == 223);
                         x >>= 1;
            //std::cout << "x" << x << std::endl;
            CPPUNIT_ASSERT(x  == 22);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}  

    void test_rshift_equals_2 () {
        try {
            Integer<int> x = 100;
            CPPUNIT_ASSERT(x == 100);
                         x >>= 1;
            //std::cout << "x" << x << std::endl;
            CPPUNIT_ASSERT( x == 10);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}  

    void test_rshift_equals_3 () {
        try {
            Integer<int> x = 1000;
            CPPUNIT_ASSERT(x == 1000);
                         x >>= 3;
            //std::cout << "x" << x << std::endl;
            CPPUNIT_ASSERT( x == 1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}  

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
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_equals);
    CPPUNIT_TEST(test_plus_equals_2);
    CPPUNIT_TEST(test_plus_equals_3);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_equals);
    CPPUNIT_TEST(test_minus_equals_2);
    CPPUNIT_TEST(test_minus_equals_3);
    CPPUNIT_TEST(test_multiply);
    CPPUNIT_TEST(test_multiply_2);
    CPPUNIT_TEST(test_multiply_3);
    CPPUNIT_TEST(test_multiply_equals);
    CPPUNIT_TEST(test_multiply_equals_2);
    CPPUNIT_TEST(test_multiply_equals_3);
    CPPUNIT_TEST(test_divide);
    CPPUNIT_TEST(test_divide_2);
    CPPUNIT_TEST(test_divide_3);
    CPPUNIT_TEST(test_divide_equals);
    CPPUNIT_TEST(test_divide_equals_2);
    CPPUNIT_TEST(test_divide_equals_3);
    CPPUNIT_TEST(test_mod);
    CPPUNIT_TEST(test_mod_2);
    CPPUNIT_TEST(test_mod_3);
    CPPUNIT_TEST(test_mod_equals);
    CPPUNIT_TEST(test_mod_equals_2);
    CPPUNIT_TEST(test_mod_equals_3);
    CPPUNIT_TEST(test_lshift_equals);
    CPPUNIT_TEST(test_lshift_equals_2);
    CPPUNIT_TEST(test_lshift_equals_3);
    CPPUNIT_TEST(test_rshift_equals);
    CPPUNIT_TEST(test_rshift_equals_2);
    CPPUNIT_TEST(test_rshift_equals_3);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
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
