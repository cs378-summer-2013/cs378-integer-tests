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
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits () {
        const int a[] = {9, 9, 9, 9, 9, 9};
        const int b[] = {1};
        const int c[] = {1,0,0,0,0,0,0};
              int x[10];
        const int* p = plus_digits(a, a + 6, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 7);
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


    void test_minus_digits1 () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7, 0, 0};
        const int c[] = {7, 5, 9, 7, 8};
              int x[10];
        const int* p = minus_digits(a, a + 6, b, b + 5, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits2 () {
        const int a[] = {8, 0, 1};
        const int b[] = {8, 0, 1};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits3 () {
        const int b[] = {8, 0, 1};
        const int a[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // ------------
    // compare
    // ------------

    void compare1 () {
        const int a[] = {8, 0, 1};
        const int b[] = {8, 0, 1};
        const int p = compare(a, a + 3, b, b + 3);
        CPPUNIT_ASSERT(p == 2);}
    void compare2 () {
        const int a[] = {1, 0, 0, 1};
        const int b[] = {5, 6, 7};
        const int p = compare(a, a + 4, b, b + 3);
        CPPUNIT_ASSERT(p == 1);}
    void compare3 () {
        const int a[] = {8, 0, 1};
        const int b[] = {1, 0, 6, 7};
        const int p = compare(a, a + 3, b, b + 4);
        CPPUNIT_ASSERT(p == 0);}


    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits_1 () {
        const int a[] = {2,3,4,2,3,4,2,3,4};
        const int b[] = {5,6,5,6,7,8,6,7,8};
        const int c[] = {1,3,2,5,0,1,3,1,1,8,3,1,4,6,2,6,5,2};
              int x[20];
        const int* p = multiplies_digits(a, a + 9, b, b + 9, x);
        CPPUNIT_ASSERT(p - x == 18);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_multiplies_digits_2 () {
        const int a[] = {2};
        const int b[] = {1, 0};
        const int c[] = {2, 0};
              int x[4];
        const int* p = multiplies_digits(a, a + 1, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_multiplies_digits_3 () {
        const int a[] = {1, 0};
        const int b[] = {2};
        const int c[] = {2, 0};
              int x[4];
        const int* p = multiplies_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_multiplies_digits_4 () {
        const int a[] = {1, 0};
        const int b[] = {0};
        const int c[] = {0};
              int x[4];
        const int* p = multiplies_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


        void test_multiplies_digits_5 () {
        const int a[] = {0};
        const int b[] = {1, 0};
        const int c[] = {0};
              int x[4];
        const int* p = multiplies_digits(a, a + 1, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_multiplies_digits_6 () {
        const int a[] = {9, 9};
        const int b[] = {9, 9};
        const int c[] = {9, 8, 0, 1};
              int x[4];
        const int* p = multiplies_digits(a, a + 2, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    
    void test_multiplies_digits_7 () {
        const int a[] = {9, 9};
        const int b[] = {9};
        const int c[] = {8, 9, 1};
              int x[4];
        const int* p = multiplies_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
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

    void test_divides_digits1() {
        const int a[] = {1, 3, 2, 6, 7, 7};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 3};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits2 () {
        const int b[] = {1, 3, 2, 6, 7, 8};
        const int a[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 6, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits3 () {
        const int a[] = {5, 6, 7};
        const int b[] = {5, 6, 7};
        const int c[] = {1};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits4 () {
        const int a[] = {1, 3, 2, 6, 7, 9};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits5 () {
        const int a[] = {1, 3, 3, 2, 4, 6};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 5};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------
    // %=
    // -----------

    void test_module1 () {
        const Integer<int> a(133248);;
        const Integer<int> b(567);
        const Integer<int> c(3);
        CPPUNIT_ASSERT(c == a % b);}


    void test_module2 () {
        const Integer<int> a(567);;
        const Integer<int> b(567);
        const Integer<int> c(0);
        CPPUNIT_ASSERT(c == a % b);}

    void test_module3 () {
        const Integer<int> a(567001);;
        const Integer<int> b(567);
        const Integer<int> c(1);
        CPPUNIT_ASSERT(c == a % b);}
    void test_module4 () {
        const Integer<int> a(566);;
        const Integer<int> b(567);
        const Integer<int> c(566);
        CPPUNIT_ASSERT(c == a % b);}

    void test_module5 () {
        const Integer<int> a(567);;
        const Integer<int> b(1);
        const Integer<int> c(0);
        CPPUNIT_ASSERT(c == a % b);}
    // -----------
    // constructor
    // -----------

    void test_constructor_1 () {
        try {
            const Integer<int> x("abc");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer::Integer()")==0);}}

    void test_constructor_2 () {
        try {
            const Integer<int> x("2");}
        catch (std::invalid_argument& e) {
            std::cout << e.what() << " this is what" << std::endl;
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
            CPPUNIT_ASSERT(y ==  98765);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_3 () {
        try {
            const Integer<int> x = 98765;
	    
            const Integer<int> y = abs(x);
	    
            CPPUNIT_ASSERT(x == 98765);
            CPPUNIT_ASSERT(y ==  98765);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_4 () {
        try {
            const Integer<int> x = 0;
	    
            const Integer<int> y = abs(x);
	    
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y == 0);
	}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_5 () {
        try {
            const Integer<int> x = -9876;
	    
            const Integer<int> y = abs(x);
	    
            CPPUNIT_ASSERT(x == -9876);
            CPPUNIT_ASSERT(y ==  9876);
	}
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

    void test_equal_to1 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(x == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to2 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(x == y);}
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

    void test_output () {
        try {
            const Integer<int> x = 98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output1 () {
        try {
            const Integer<int> x = 0;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "0");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output2 () {
        try {
            const Integer<int> x = -1;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-1");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output3 () {
        try {
            const Integer<int> x = 987;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "987");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 12;
            const int          e =  2;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( x ==    144);
            CPPUNIT_ASSERT( y ==    144);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 7;
            const int          e =  11;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 7);
            CPPUNIT_ASSERT(y ==  1977326743);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            Integer<int>       x = 12;
            const int          e =  1;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( x ==    12);
            CPPUNIT_ASSERT( y ==    12);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
 
   void test_pow_4 () {
        try {
            Integer<int>       x = 1;
            const int          e =  12;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( x ==    1);
            CPPUNIT_ASSERT( y ==    1);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    // can x be negative?
    void test_pow_5 () {
        try {
            Integer<int>       x = 10;
            const int          e =  2;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( x ==    100);
            CPPUNIT_ASSERT( y ==    100);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
            
            
    void test_pow_6 () {
        try {
            Integer<int>       x = 10;
            const int          e =  0;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer::pow()")==0);}}
            
            
    void test_pow_7 () {
        try {
            Integer<int>       x = 10;
            const int          e =  -1;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Integer::pow()")==0);}}

    // -----
    // suite
    // -----
  
    CPPUNIT_TEST_SUITE(TestInteger);
    
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits1);
    CPPUNIT_TEST(test_minus_digits2);
    CPPUNIT_TEST(test_minus_digits3);
    CPPUNIT_TEST(compare1);
    CPPUNIT_TEST(compare2);
    CPPUNIT_TEST(compare3);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_4);    
    CPPUNIT_TEST(test_multiplies_digits_5);
    CPPUNIT_TEST(test_multiplies_digits_6); 
    CPPUNIT_TEST(test_multiplies_digits_7);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits1);
    CPPUNIT_TEST(test_divides_digits2);
    CPPUNIT_TEST(test_divides_digits3);
    CPPUNIT_TEST(test_divides_digits4);
    CPPUNIT_TEST(test_divides_digits5);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to1);
    CPPUNIT_TEST(test_equal_to2);
    CPPUNIT_TEST(test_module1);
    CPPUNIT_TEST(test_module2);
    CPPUNIT_TEST(test_module3);
    CPPUNIT_TEST(test_module4);
    CPPUNIT_TEST(test_module5);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_abs_4);
    CPPUNIT_TEST(test_abs_5);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output1);
    CPPUNIT_TEST(test_output2);
    CPPUNIT_TEST(test_output3);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
    CPPUNIT_TEST(test_pow_5);
    CPPUNIT_TEST(test_pow_6);
    CPPUNIT_TEST(test_pow_7);
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