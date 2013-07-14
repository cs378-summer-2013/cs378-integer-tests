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
        
    void test_shift_left_digits_1 () {
        const int a[] = {2};
        const int b[] = {2, 0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 1, 4, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    void test_shift_left_digits_2 () {
        const int a[] = {1, 0};
        const int b[] = {1, 0, 0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 2, 3, x);
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
        
    void test_shift_right_digits_1 () {
        const int a[] = {2, 3, 4, 5, 6, 7};
        const int b[] = {2, 3};
              int x[10];
        const int* p = shift_right_digits(a, a + 6, 4, x);
        CPPUNIT_ASSERT((p - x) == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}
    
    void test_shift_right_digits_2 () {
        const int a[] = {1, 0, 5, 9};
        const int b[] = {1, 0, 5};
              int x[10];
        const int* p = shift_right_digits(a, a + 4, 1, x);
        CPPUNIT_ASSERT((p - x) == 3);
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
        cout << p-x << endl;
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
    void test_plus_digits_1 () {
        const int a[] = {2, 3, 4, 0};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 9, 0, 7};
              int x[10];
        const int* p = plus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_plus_digits_2 () {
        const int a[] = {5, 0, 0};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 0, 6, 7};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
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
    
    void test_minus_digits_1 () {
        const int a[] = {8, 0, 0};
        const int b[] = {8, 0, 0};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
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
        const int a[] = {1, 0, 5, 3};
        const int b[] = {5, 0, 0};
        const int c[] = {5, 5, 3};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_minus_digits_4 () {
        const int a[] = {8, 9, 5};
        const int b[] = {3, 5, 9};
        const int c[] = {5, 3, 6};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
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
        const int a[] = {8, 0, 0};
        const int b[] = {3};
        const int c[] = {2, 4, 0, 0};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_multiplies_digits_2 () {
        const int a[] = {1, 3, 4, 0};
        const int b[] = {3, 7, 5};
        const int c[] = {5, 0, 2, 5, 0, 0};
              int x[10];
        const int* p = multiplies_digits(a, a + 4, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_3 () {
        const int a[] = {1, 0, 0, 0, 0, 0};
        const int b[] = {1, 0, 0, 0, 0, 0};
        const int c[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
              int x[15];
        const int* p = multiplies_digits(a, a + 6, b, b + 6, x);
        CPPUNIT_ASSERT(p - x == 11);
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
    
    void test_divides_digits_1 () {
        const int a[] = {0};
        const int b[] = {5, 6, 7};
        const int c[] = {0};
              int x[10];
        const int* p = divides_digits(a, a + 1, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
    void test_divides_digits_2 () {
        try {
            const int a[] = {1, 3, 2, 6, 7, 8};
            const int b[] = {0};
                  int x[10];
            const int* p = divides_digits(a, a + 6, b, b + 1, x);
            CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument& e) {
             CPPUNIT_ASSERT(strcmp(e.what(), "Divide by 0"));
        }
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
            const Integer<int> x("20000");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_3 () {
        try {
            const Integer<int> x(2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // ----------
    // left shift 
    // ----------       
            
    void test_left_shift () {
        try {
            Integer<int> x = 333;
            CPPUNIT_ASSERT( x << 0 == 333);
            CPPUNIT_ASSERT( x << 3 == 333000);
            CPPUNIT_ASSERT( x << 5 == 33300000);
            x <<= 5;
            CPPUNIT_ASSERT( x == 33300000);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_left_shift_1 () {
        try {
            Integer<int> x = 1250;
            CPPUNIT_ASSERT( x << 0 == 1250);
            CPPUNIT_ASSERT( x << 3 == 1250000);
            CPPUNIT_ASSERT( x << 4 == 12500000);
            x <<= 6;
            CPPUNIT_ASSERT( x == 1250000000);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_left_shift_2 () {
        try {
            Integer<int> x = 10135;
            CPPUNIT_ASSERT( x << 1 == 101350);
            CPPUNIT_ASSERT( x << 4 == 101350000);
            CPPUNIT_ASSERT( x << 5 == 1013500000);
            x <<= 5;
            CPPUNIT_ASSERT( x == 1013500000);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // ----------
    // right shift 
    // ----------       
            
    void test_right_shift () {
        try {
            Integer<int> x = 33333333;
            CPPUNIT_ASSERT( x >> 0 == 33333333);
            CPPUNIT_ASSERT( x >> 8 == 0);
            CPPUNIT_ASSERT( x >> 10 == 0);
            x >>= 5;
            CPPUNIT_ASSERT( x == 333);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_right_shift_1 () {
        try {
            Integer<int> x = 125006020;
            CPPUNIT_ASSERT( x >> 0 == 125006020);
            CPPUNIT_ASSERT( x >> 7 == 12);
            CPPUNIT_ASSERT( x >> 20 == 0);
            x >>= 6;
            CPPUNIT_ASSERT( x == 125);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_right_shift_2 () {
        try {
            Integer<int> x = 1013513256;
            CPPUNIT_ASSERT( x >> 6 == 1013);
            CPPUNIT_ASSERT( x >> 4 == 101351);
            CPPUNIT_ASSERT( x >> 9 == 1);
            x >>= 15;
            CPPUNIT_ASSERT( x == 0);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // -----
    // plus 
    // -----       
            
    void test_plus () {
        try {
            Integer<int> x = 479;
            Integer<int> y = 596;
            CPPUNIT_ASSERT( x + y == 1075 );
            CPPUNIT_ASSERT( y + x == 1075);
            CPPUNIT_ASSERT( x + 400 == 879);
            CPPUNIT_ASSERT( y + 500 == 1096);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_plus_1 () {
        try {
            Integer<int> x = -479;
            Integer<int> z = 0;
            Integer<int> y = 500;
            CPPUNIT_ASSERT( x + y == 21);
            CPPUNIT_ASSERT( y + x == 21);
            CPPUNIT_ASSERT( x + 400 == -79);
            CPPUNIT_ASSERT( y + -500 == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_plus_2 () {
        try {
            Integer<int> x = -500;
            Integer<int> y = -1053;
            CPPUNIT_ASSERT( x + y == -1553);
            CPPUNIT_ASSERT( y + x == -1553);
            CPPUNIT_ASSERT( x + 500 == 0);
            CPPUNIT_ASSERT( y + 1000 == -53);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    // -----
    // minus 
    // -----       
            
    void test_minus () {
        try {
            Integer<int> x = 895;
            Integer<int> y = 359;
            CPPUNIT_ASSERT( x - y == 536 );
            CPPUNIT_ASSERT( y - x == -536);
            CPPUNIT_ASSERT( x - 400 == 495);
            CPPUNIT_ASSERT( y - 235 == 124);
            CPPUNIT_ASSERT( y - 360 == -1);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_1 () {
        try {
            Integer<int> x = -479;
            Integer<int> y = 550;
            CPPUNIT_ASSERT( x - y == -1029);
            CPPUNIT_ASSERT( y - x == 1029);
            CPPUNIT_ASSERT( x - 400 == -879);
            CPPUNIT_ASSERT( y - -500 == 1050);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_minus_2 () {
        try {
            Integer<int> x = -500;
            Integer<int> y = -1053;
            CPPUNIT_ASSERT( x - y == 553);
            CPPUNIT_ASSERT( y - x == -553);
            CPPUNIT_ASSERT( x - -500 == 0);
            CPPUNIT_ASSERT( 1000 - y == 2053);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
            
    // --------
    // multiply 
    // --------       
            
    void test_multiply () {
        try {
            Integer<int> x = 1000;
            Integer<int> y = 3;
            CPPUNIT_ASSERT( x * y == 3000 );
            CPPUNIT_ASSERT( y * x == 3000);
            CPPUNIT_ASSERT( x * -43 == -43000);
            CPPUNIT_ASSERT( y * 0 == 0);
            CPPUNIT_ASSERT( x * -1000  == -1000000);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_multiply_1 () {
        try {
            Integer<int> x = -479;
            Integer<int> y = 550;
            CPPUNIT_ASSERT( x * y == -263450);
            CPPUNIT_ASSERT( y * x == -263450);
            CPPUNIT_ASSERT( x * -1 == 479);
            CPPUNIT_ASSERT( y * 0 == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_multiply_2 () {
        try {
            Integer<int> x = -500;
            Integer<int> y = (x *= 4);
            cout << "MULT2";
            CPPUNIT_ASSERT( y == -2000);
            CPPUNIT_ASSERT( x * y == 4000000);
            CPPUNIT_ASSERT( x * 233 == -466000);
            CPPUNIT_ASSERT( y * -12 == 24000);}
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
            const Integer<int> x = -3;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -3);
            CPPUNIT_ASSERT(y == 3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_abs_3 () {
        try {
            const Integer<int> x = -100000000;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -100000000);
            CPPUNIT_ASSERT(y == 100000000);}
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
    
    void test_equal_to_1 () {
        try {
            const Integer<int> x = 777;
            const Integer<int> y = -777;
            CPPUNIT_ASSERT( x != y);
            CPPUNIT_ASSERT( x == 777);
            CPPUNIT_ASSERT( 777 == x);
            CPPUNIT_ASSERT( !(x == y));
            CPPUNIT_ASSERT( !(x != 777));
            CPPUNIT_ASSERT(!(777 == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_equal_to_2 () {
        try {
            const Integer<int> x = -2654896;
            const Integer<int> y = -26548963;
            CPPUNIT_ASSERT( x != y);
            CPPUNIT_ASSERT( x == -2654896);
            CPPUNIT_ASSERT( -2654896 == x);
            CPPUNIT_ASSERT( !(x == y));
            CPPUNIT_ASSERT( !(x != -2654896));
            CPPUNIT_ASSERT(!(-2654896 == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
            
    // --------
    // less_than
    // --------           
            
    void test_less_than () {
        try {
            const Integer<int> x = 479;
            const Integer<int> y = 596;
            CPPUNIT_ASSERT( x < y);
            CPPUNIT_ASSERT( x <= 479);
            CPPUNIT_ASSERT( 596 > x);
            CPPUNIT_ASSERT( !(x >= y));
            CPPUNIT_ASSERT( !(x > 596));
            CPPUNIT_ASSERT(!(600 <= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_less_than_1 () {
        try {
            const Integer<int> x = -479;
            const Integer<int> y = 500;
            CPPUNIT_ASSERT( x < y);
            CPPUNIT_ASSERT( x <= -479);
            CPPUNIT_ASSERT( 596 > x);
            CPPUNIT_ASSERT( !(x >= y));
            CPPUNIT_ASSERT( !(x > 596));
            CPPUNIT_ASSERT(!(600 <= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_less_than_2 () {
        try {
            const Integer<int> x = 500;
            const Integer<int> y = 1053;
            CPPUNIT_ASSERT( x < y);
            CPPUNIT_ASSERT( x <= 500);
            CPPUNIT_ASSERT( 1053 > x);
            CPPUNIT_ASSERT( !(x >= y));
            CPPUNIT_ASSERT( !(x > 596));
            CPPUNIT_ASSERT(!(2000 <= y));}
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
    
    void test_negation_1 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_negation_2 () {
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
            Integer<int> x = 2;
            const int e = 5;
            Integer<int>& y = x.pow(e);
            CPPUNIT_ASSERT( e == 5);
            CPPUNIT_ASSERT( x == y);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 10;
            const int e = 9;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 10);
            CPPUNIT_ASSERT(e == 9);
            CPPUNIT_ASSERT(y == 1000000000);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
    
    void test_pow_3 () {
        try {
            Integer<int> x = 50;
            const int e = 6;
            Integer<int>& y = x.pow(e);
            CPPUNIT_ASSERT( e == 6);
            CPPUNIT_ASSERT( x == y);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits_1);
    CPPUNIT_TEST(test_shift_left_digits_2);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_shift_right_digits_1);
    CPPUNIT_TEST(test_shift_right_digits_2);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits_1);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits_1);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits_1);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_left_shift);
    CPPUNIT_TEST(test_left_shift_1);
    CPPUNIT_TEST(test_left_shift_2);
    CPPUNIT_TEST(test_right_shift);
    CPPUNIT_TEST(test_right_shift_1);
    CPPUNIT_TEST(test_right_shift_2);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_multiply);
    CPPUNIT_TEST(test_multiply_1);
    CPPUNIT_TEST(test_multiply_2);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation_1);
    CPPUNIT_TEST(test_negation_2);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
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
