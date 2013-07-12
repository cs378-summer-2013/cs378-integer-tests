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

    void test_shift_left_digits_1 () {
        const int a[] = {5, 6};
        const int b[] = {5, 6, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 2, 2, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_2 () {
        const int a[] = {4, 6};
        const int b[] = {4, 6, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 2, 2, x);
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

    void test_shift_right_digits_1 () {
        const int a[] = {5, 6};
        const int b[] = {5};
              int x[10];
        const int* p = shift_right_digits(a, a + 2, 1, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_right_digits_2 () {
        const int a[] = {4, 6, 7};
        const int b[] = {4};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
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



    void test_plus_digits_2 () {
        const int a[] = {9, 9, 9};
        const int b[] = {9, 9, 9};
        const int c[] = {1, 9, 9, 8};
              int x[10];

        const int* p = plus_digits(a, a + 3, b, b + 3, x);

        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {1, 0};
        const int b[] = {1};
        const int c[] = {1, 1};
              int x[10];

        const int* p = plus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_plus_digits_4 () {
        const int a[] = {1, 9, 9};
        const int b[] = {1};
        const int c[] = {2, 0, 0};
              int x[10];

        const int* p = plus_digits(a, a + 3, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
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
        const int a[] = {9, 0, 0, 1};
        const int b[] = {5, 6};
        const int c[] = {8, 9, 4, 5};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_minus_digits_3 () {
        const int a[] = {1, 1, 9};
        const int b[] = {1, 0, 5};
        const int c[] = {1, 4};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_minus_digits_4 () {
        const int a[] = {1, 3, 1, 5, 4, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 0, 9, 7, 7};
              int x[10];
        const int* p = minus_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_minus_digits_5 () {
        const int a[] = {1, 0, 9, 9, 9, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 0, 9, 4, 3, 1};
              int x[10];
        const int* p = minus_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
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


    void test_multiplies_digits_2 () {
        const int a[] = {9, 9, 9};
        const int b[] = {9, 9, 9};
        const int c[] = {9, 9, 8, 0, 0, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_multiplies_digits_3 () {
        const int a[] = {9, 9, 9};
        const int b[] = {0};
        const int c[] = {0};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 1, x);

        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits_4 () {
        const int a[] = {6, 5, 5, 3, 6};
        const int b[] = {2};
        const int c[] = {1, 3, 1, 0 ,7, 2};
              int x[10];
        const int* p = multiplies_digits(a, a + 5, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_greater_than_digits () {
        const int a[] = {9, 9, 9};
        const int b[] = {9, 9, 8};
        CPPUNIT_ASSERT(check_greater_than_or_equal(a, a + 3, b, b + 3));
    }

        void test_greater_than_digits_2 () {
        const int a[] = {9, 9, 9};
        const int b[] = {9, 9, 9};
        CPPUNIT_ASSERT(check_greater_than_or_equal(a, a + 3, b, b + 3));
    }

            void test_greater_than_digits_3 () {
        const int a[] = {9, 9, 8};
        const int b[] = {9, 9, 9};
        CPPUNIT_ASSERT(!check_greater_than_or_equal(a, a + 3, b, b + 3));
    }


            void test_greater_than_digits_4 () {
        const int a[] = {9, 9};
        const int b[] = {9, 9, 9};
        CPPUNIT_ASSERT(!check_greater_than_or_equal(a, a + 2, b, b + 3));
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
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits_2 () {
        const int a[] = {9};
        const int b[] = {4};
        const int c[] = {2};
              int x[10];
        const int* p = divides_digits(a, a + 1, b, b + 1, x);
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

    // --------------
    // comparision
    // -------------

	void test_comparision () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = 987;
            CPPUNIT_ASSERT(      x > y);
	    CPPUNIT_ASSERT(     y < x);
	    CPPUNIT_ASSERT(     y <= x);
	    CPPUNIT_ASSERT(     x >= y); }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // plus_operator
    // -------------

	void test_plus_operator () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = 987;
            CPPUNIT_ASSERT(x + y == 99752);
	    CPPUNIT_ASSERT(y + x == 99752);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_operator_1 () {
        try {
            const Integer<int> x = 10;
            const Integer<int> y = -5;
            CPPUNIT_ASSERT(x + y == 5);
        CPPUNIT_ASSERT(y + x == 5);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_plus_operator_2 () {
        try {
            const Integer<int> x = -10;
            const Integer<int> y = -5;
            CPPUNIT_ASSERT(x + y == -15);
        CPPUNIT_ASSERT(y + x == -15);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    // --------------
    // minus_operator
    // -------------

	void test_minus_operator () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = 987;
            CPPUNIT_ASSERT(x - y == 97778);
	    CPPUNIT_ASSERT(y - x == -97778);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_operator_1 () {
        try {
            const Integer<int> x = 10;
            const Integer<int> y = 5;
            CPPUNIT_ASSERT(x - y == 5);
        CPPUNIT_ASSERT(y - x == -5);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_minus_operator_2 () {
        try {
            const Integer<int> x = -10;
            const Integer<int> y = 5;
            CPPUNIT_ASSERT(x - y == -15);
        CPPUNIT_ASSERT(y - x == 15);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // --------------
    // multiply_operator
    // -------------

	void test_multiply_operator () {
        try {
            const Integer<int> x = 100;
            const Integer<int> y = -987;
            CPPUNIT_ASSERT(x * y == -98700);
	    CPPUNIT_ASSERT(y * x == -98700);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiply_operator_1 () {
        try {
            const Integer<int> x = -100;
            const Integer<int> y = -987;
            CPPUNIT_ASSERT(x * y == 98700);
            CPPUNIT_ASSERT(y * x == 98700);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_multiply_operator_2 () {
        try {
            const Integer<int> x = -100;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(x * y == 0);
            CPPUNIT_ASSERT(y * x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // divide_operator
    // -------------

	void test_divide_operator () {
        try {
            const Integer<int> x = 100;
            const Integer<int> y = 987;
            CPPUNIT_ASSERT(x / y == 0);
	        CPPUNIT_ASSERT(y / x == 9);
        }            
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_operator_1 () {
        try {
            const Integer<int> x = 100;
            const Integer<int> y = -10;
            CPPUNIT_ASSERT(x / y == -10);
            CPPUNIT_ASSERT(y / x == 0);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_operator_2 () {
        try {
            const Integer<int> x = 100;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(x / y == -10);
            CPPUNIT_ASSERT(y / x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}
    // --------------
    // modulo_operator
    // -------------

	void test_modulo_operator () {
        try {
            const Integer<int> x = 119;
            const Integer<int> y = 21;
            CPPUNIT_ASSERT(x % y == 14);
	    CPPUNIT_ASSERT(y % x == 21);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_modulo_operator_1 () {
        try {
            const Integer<int> x = -119;
            const Integer<int> y = 21;
            CPPUNIT_ASSERT(x % y == 7);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_modulo_operator_2 () {
        try {
            const Integer<int> x = -119;
            const Integer<int> y = -1;
            CPPUNIT_ASSERT(x % y == 7);
            }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(true);}}
    // --------------
    // left_shift_operator
    // -------------

	void test_left_shift_operator () {
        try {
            const Integer<int> x = 987;
            int y = 2;
            CPPUNIT_ASSERT(x << y == 98700);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_left_shift_operator_1 () {
        try {
            const Integer<int> x = 987;
            int y = 0;
            CPPUNIT_ASSERT(x << y == 98700);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_left_shift_operator_2 () {
        try {
            const Integer<int> x = 987;
            int y = 2;
            CPPUNIT_ASSERT(x << y == 98700);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // right_shift_operator
    // -------------

	void test_right_shift_operator () {
        try {
            const Integer<int> x = 987;
            int y = 2;
            CPPUNIT_ASSERT(x >> y == 9);}
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

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 2;
            const int          e =  4422;
            Integer<int>&      y = x.pow(e);
            Integer<int>       z ("142771271114139806950781783051082004163082119322351444599623728301142200195300326937977285752769921619877256957948075148939199688528035717584873610553994395599100494238765669607141386008029504952293343127494542407867711240204511172148794176263002191945316308062038158693708440574296243094180936952087891572848008459787195382799140094299517789224295538841838587760217037143863289003133379807985379760663914277831390839192845790922218222406255781214068371245229681606405090138048044055700501688785181772862560462036823460788398573099693809648280151340130895059066462506161523222219311154438962304686886506240840836212246837237244268885077891503440426324080756533572407395144183332031128637332637893563687324615548187500585450945393131662309789397865712846902536528059838790169042166690993750451484415967956547634910655570661196678245089244364491144078141300406915648071831922972715572021876910771435638872803223929282079606664221790103211357347456545881358223520844839035048386795214904454808375226463629000421750172415814148544951364324990997193823617287138131864847424152375458587093090565344259396374311306146670684464028317192233323163286238083637830419552825264487856949660105560747897655713973127276652693533910533800884375488933050230007301069204224010612526844527396871001547861048366477375360859057765935655115528951304290304");
            CPPUNIT_ASSERT( e == 4422);
            CPPUNIT_ASSERT(&x ==   &y);
            CPPUNIT_ASSERT(x ==   z);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 2;
            const int          e =  15;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e ==  15);
            CPPUNIT_ASSERT(y ==  32768);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -----
    // suite
    // -----    CPPUNIT_TEST(test_multiplies_digits);

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits_1);
    CPPUNIT_TEST(test_shift_left_digits_2);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_shift_right_digits_1);
    CPPUNIT_TEST(test_shift_right_digits_2);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_plus_digits_4);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_minus_digits_4);
    CPPUNIT_TEST(test_minus_digits_5);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_4);
    CPPUNIT_TEST(test_greater_than_digits);
    CPPUNIT_TEST(test_greater_than_digits_2);
    CPPUNIT_TEST(test_greater_than_digits_3);
    CPPUNIT_TEST(test_greater_than_digits_4);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_comparision);
    CPPUNIT_TEST(test_plus_operator);
    CPPUNIT_TEST(test_plus_operator_1);
    CPPUNIT_TEST(test_plus_operator_2);
    CPPUNIT_TEST(test_minus_operator);
    CPPUNIT_TEST(test_minus_operator_1);
    CPPUNIT_TEST(test_minus_operator_2);
    CPPUNIT_TEST(test_multiply_operator);
    CPPUNIT_TEST(test_multiply_operator_1);
    CPPUNIT_TEST(test_multiply_operator_2);
    CPPUNIT_TEST(test_divide_operator);
    CPPUNIT_TEST(test_divide_operator_1);
    CPPUNIT_TEST(test_divide_operator_2);
    CPPUNIT_TEST(test_modulo_operator);
    CPPUNIT_TEST(test_modulo_operator_1);
    CPPUNIT_TEST(test_modulo_operator_2);
    CPPUNIT_TEST(test_left_shift_operator);
    CPPUNIT_TEST(test_right_shift_operator);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_output);

    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);

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

