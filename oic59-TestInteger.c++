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
        
    void test_shift_left_digits2 () {
        const int a[] = {2, 3, 4, 5, 6};
        const int b[] = {2, 3, 4, 5, 6, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 5, 2, x);
        CPPUNIT_ASSERT((p - x) == 7);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
        
    void test_shift_left_digits3 () {
        const int a[] = {1};
        const int b[] = {1, 0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 1, 4, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits4 () {
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
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
       
    void test_shift_right_digits2 () {
        const int a[] = {2, 3, 4, 5, 6};
        const int b[] = {2, 3, 4};
              int x[10];
        const int* p = shift_right_digits(a, a + 5, 2, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
        
    void test_shift_right_digits3 () {
        const int a[] = {2, 3, 4, 5, 6};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 5, 4, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits4 () {
        const int a[] = {2, 3, 4, 5, 6, 7, 8, 9};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 8, 7, x);
        CPPUNIT_ASSERT((p - x) == 1);
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

    void test_plus_digits2 () {
        const int a[] = {2, 3, 4, 2, 3, 4};
        const int b[] = {5, 6, 7, 5, 6, 7};
        const int c[] = {8, 0, 1, 8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 6, b, b + 6, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits3 () {
        const int a[] = {1, 0};
        const int b[] = {2};
        const int c[] = {1, 2};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits4 () {
        const int a[] = {2, 3, 0, 0, 0};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 5, 6, 7};
              int x[10];
        const int* p = plus_digits(a, a + 5, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 5);
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
        
    void test_minus_digits2 () {
        const int a[] = {5, 6, 7, 5, 6, 7};
        const int b[] = {2, 3, 4, 2, 3, 4};
        const int c[] = {3, 3, 3, 3, 3, 3};
              int x[10];
        const int* p = minus_digits(a, a + 6, b, b + 6, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
    void test_minus_digits3 () {
        const int a[] = {1, 2};
        const int b[] = {2};
        const int c[] = {1,0};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
    void test_minus_digits4 () {
        const int a[] = {2, 3, 5, 6, 7};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 0, 0, 0};
              int x[10];
        const int* p = minus_digits(a, a + 5, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10] = {0};
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits2 () {
        const int a[] = {1, 2};
        const int b[] = {1, 2};
        const int c[] = {1, 4, 4};
              int x[10] = {0};
        const int* p = multiplies_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits3 () {
        const int a[] = {2, 3, 4, 2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 8, 1, 0, 6, 7, 8};
              int x[10] = {0};
        const int* p = multiplies_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 9);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits4 () {
        const int a[] = {2};
        const int b[] = {5, 1, 2};
        const int c[] = {1, 0, 2, 4};
              int x[10] = {0};
        const int* p = multiplies_digits(a, a + 1, b, b + 3, x);
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
            const Integer<int> x(-2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_5 () {
        try {
            const Integer<int> x("-200");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_6 () {
        try {
            const Integer<int> x(10);}
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
            const Integer<int> x = -1;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -1);
            CPPUNIT_ASSERT(y ==  1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}            

    void test_abs_4 () {
        try {
            const Integer<int> x = -123456789;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -123456789);
            CPPUNIT_ASSERT(y ==  123456789);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
            
    void test_abs_5 () {
        try {
            const Integer<int> x = 900;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 900);
            CPPUNIT_ASSERT(y == 900);}
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

    void test_equal_to2 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = 1;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 1);
            CPPUNIT_ASSERT(  1 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 1));
            CPPUNIT_ASSERT(!(1 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to3 () {
        try {
            const Integer<int> x = -1;
            const Integer<int> y = -1;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == -1);
            CPPUNIT_ASSERT(  -1 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != -1));
            CPPUNIT_ASSERT(!(-1 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to4 () {
        try {
            const Integer<int> x = 999;
            const Integer<int> y = 999;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 999);
            CPPUNIT_ASSERT(  999 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 999));
            CPPUNIT_ASSERT(!(999 != y));}
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

    void test_negation2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation3 () {
        try {
            const Integer<int> x = 1;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation4 () {
        try {
            const Integer<int> x = 10;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -10);}
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

    void test_output2 () {
        try {
            const Integer<int> x = 123456789;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "123456789");}
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

    void test_output4 () {
        try {
            const Integer<int> x = -1;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-1");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 12;
            const int          e =  8;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 8);
            CPPUNIT_ASSERT( x == 429981696);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 12;
            const int          e =  8;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 12);
            CPPUNIT_ASSERT(e ==  8);
            CPPUNIT_ASSERT(y == 429981696);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
            
    void test_pow_3 () {
        try {
            const Integer<int> x = 2;
            const int          e = 2;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == 2);
            CPPUNIT_ASSERT(y == 4);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}            
            
    void test_pow_4 () {
        try {
            const Integer<int> x = 2;
            const int          e =  10;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == 10);
            CPPUNIT_ASSERT(y == 1024);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}            
            
    void test_pow_5 () {
        try {
            const Integer<int> x = 12;
            const int          e =  8;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 12);
            CPPUNIT_ASSERT(e ==  8);
            CPPUNIT_ASSERT(y == 429981696);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}          
                    

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits2);
    CPPUNIT_TEST(test_shift_left_digits3);
    CPPUNIT_TEST(test_shift_left_digits4);    
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_shift_right_digits2);
    CPPUNIT_TEST(test_shift_right_digits3);
    CPPUNIT_TEST(test_shift_right_digits4);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits2);
    CPPUNIT_TEST(test_plus_digits3);
    CPPUNIT_TEST(test_plus_digits4);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits2);
    CPPUNIT_TEST(test_minus_digits3);
    CPPUNIT_TEST(test_minus_digits4);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits2);
    CPPUNIT_TEST(test_multiplies_digits3);
    CPPUNIT_TEST(test_multiplies_digits4);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);
    CPPUNIT_TEST(test_constructor_6);    
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_abs_4);
    CPPUNIT_TEST(test_abs_5);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to2);    
    CPPUNIT_TEST(test_equal_to3);    
    CPPUNIT_TEST(test_equal_to4);        
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation2);
    CPPUNIT_TEST(test_negation3);
    CPPUNIT_TEST(test_negation4);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output2);
    CPPUNIT_TEST(test_output3);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
    CPPUNIT_TEST(test_pow_5);
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
