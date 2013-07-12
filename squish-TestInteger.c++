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

#include <algorithm>  // equal
#include <cstring>    // strcmp
#include <sstream>    // ostringstream
#include <stdexcept>  // invalid_argument
#include <string>     // ==
#include <time.h> // timing

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Integer.h"

// #include <jni.h>

//REMOVE REMOVE REMOVE
#define private public

// -----------
// TestInteger
// -----------

struct TestInteger : CppUnit::TestFixture {

    void test_less_than_1 () {
        const int a[] = {1};
        const int b[] = {1};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(!result);
    }

    void test_less_than_2 () {
        const int a[] = {1};
        const int b[] = {2};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(result);
    }

    void test_less_than_3 () {
        const int a[] = {1, 1};
        const int b[] = {1};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(!result);
    }

    void test_less_than_4 () {
        const int a[] = {1};
        const int b[] = {1, 1};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(result);
    }

    void test_less_than_5 () {
        const int a[] = {1, 0};
        const int b[] = {1, 1};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(result);
    }

    void test_less_than_6 () {
        const int a[] = {1, 0, 0, 0, 0};
        const int b[] = {1, 1};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(!result);
    }

    void test_less_than_7 () {
        const int a[] = {1, 1};
        const int b[] = {1, 0, 0, 0, 0};
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        bool result = less_than(a, a + a_sz, b, b + b_sz);
        CPPUNIT_ASSERT(result);
    }

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
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 0, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits_2 () {
        std::deque<int> a;
        for(int i=0; i != 5; ++i)
            a.push_back(i);
        std::deque<int> b = {0, 1, 2, 3, 4, 0};
        std::deque<int> x;
        shift_left_digits(a.begin(), a.end(), 1, std::back_inserter(x));
        CPPUNIT_ASSERT(std::equal(x.begin(), x.end(), b.begin()));
    }

    /*
    In place shift
    void test_shift_left_digits_3 () {
        std::deque<int> a;
        for(int i=0; i != 5; ++i)
            a.push_back(i);
        std::deque<int> b = {0, 1, 2, 3, 4, 0};
        std::deque<int> x;
        shift_left_digits(a.begin(), a.end(), 1, std::inserter(a, a.begin()));
        CPPUNIT_ASSERT(std::equal(a.begin(), a.end(), b.begin()));
    }
    */

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
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_1 () {
        const int a[] = {   5};
        const int b[] = {   7};
        const int c[] = {1, 2};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_2 () {
        const int a[] = {0};
        const int b[] = {7};
        const int c[] = {7};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_3 () {
        const int a[] = {4};
        const int b[] = {5};
        const int c[] = {9};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_4 () {
        const int a[] = {1, 2, 3};
        const int b[] = {   4, 5};
        const int c[] = {1, 6, 8};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_5 () {
        const int a[] = {   4, 5};
        const int b[] = {1, 2, 3};
        const int c[] = {1, 6, 8};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_6 () {
        const int a[] = {1, 2, 3};
        const int b[] = {  -1, -1};
        const int c[] = {1, 1, 2};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_7 () {
        const int a[] = {   9, 9, 9};
        const int b[] = {         1};
        const int c[] = {1, 0, 0, 0};
              int x[10];
        const int a_sz = sizeof(a) / sizeof(int) ;
        const int b_sz = sizeof(b) / sizeof(int) ;
        const int* p = plus_digits(a, a + a_sz, b, b + b_sz, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits_8 () {
        const int a[] = {0, 0};
        const int b[] = {   2};
        const int c[] = {2};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
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
        const int a[] = {1, 1};
        const int b[] = {   7};
        const int c[] = {   4};
              int x[10];
        const int* p = minus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_2 () {
        const int a[] = {1, 0, 0, 0};
        const int b[] = {         1};
        const int c[] = {   9, 9, 9};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_3 () {
        const int a[] = {1};
        const int b[] = {1};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_4 () {
        const int a[] = {1, 0, 0, 0};
        const int b[] = {1, 0, 0, 0};
        const int c[] = {         0};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 4, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits_5 () {
        const int a[] = {1};
        const int b[] = {0};
        const int c[] = {1};
              int x[10];
        const int* p = minus_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
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
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
    }

    void test_multiplies_digits_1 () {
        const int a[] = {3};
        const int b[] = {2};
        const int c[] = {6};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
    }

    void test_multiplies_digits_2 () {
        const int a[] = {   3};
        const int b[] = {   5};
        const int c[] = {1, 5};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
        // std::cout << p - x << std::endl;
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
    }

    void test_multiplies_digits_3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10];
        // const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        const int* p = multiplies_digits(a, a + a_sz, b, b + b_sz, x);

        CPPUNIT_ASSERT(p - x == a_sz + b_sz);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
    }

    void test_multiplies_digits_4 ()
    {
        std::deque<int> a = {2, 3, 4};
        std::deque<int> b = {5, 6, 7};
        std::deque<int> c = {1, 3, 2, 6, 7, 8};
        std::deque<int> x;
        multiplies_digits(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(x));
        CPPUNIT_ASSERT(x.size() == 6);
        CPPUNIT_ASSERT(std::equal(x.begin(), x.end(), c.begin()));
    }

    void test_multiplies_digits_5 () {
        const int a[] = {1, 0, 0, 0};
        const int b[] = {1};
        const int c[] = {1, 0, 0, 0};
              int x[10];
        const int* p = multiplies_digits(a, a + sizeof a / sizeof(int), b, b + sizeof b / sizeof(int), x);

        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
    }

    void test_multiplies_digits_6 () {
        int a[] = {2, 3, 4};
        int b[] = {5, 6, 7};
        int c[] = {1, 3, 2, 6, 7, 8};
        int x[10];
        // const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        const int* p = multiplies_digits(a, a + a_sz, b, b + b_sz, x);

        CPPUNIT_ASSERT(p - x == a_sz + b_sz);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
    }

    // --------------
    // divides_digits
    // --------------

    void test_divides_digits () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        const int* p = divides_digits(a, a + a_sz, b, b + b_sz, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_1 () {
        const int a[] = {8};
        const int b[] = {2};
        const int c[] = {4};
              int x[10];
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        const int* p = divides_digits(a, a + a_sz, b, b + b_sz, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_2 () {
        const int a[] = {9, 9, 9, 9, 9, 9};
        const int b[] = {1, 1, 1, 1, 1, 1};
        const int c[] = {9};
              int x[10];
        const int a_sz = sizeof a / sizeof(int);
        const int b_sz = sizeof b / sizeof(int);
        const int* p = divides_digits(a, a + a_sz, b, b + b_sz, x);
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
            const Integer<int> x(2222);
            CPPUNIT_ASSERT(x == 2222);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_5 () {
        try {
            const Integer<int> x("2222");
            CPPUNIT_ASSERT(x == 2222);
        }
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

    void test_negation_1 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -98765;
            CPPUNIT_ASSERT(y == x);}
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
            CPPUNIT_ASSERT(out.str() == "98765");
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output_1 () {
        try {
            const Integer<int> x = -98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-98765");
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 111;
            const int          e =   1;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e ==     1);
            CPPUNIT_ASSERT( x ==   111);
            CPPUNIT_ASSERT(&x ==   &y);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 123;
            const int          e =  5;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x ==    123);
            CPPUNIT_ASSERT(e ==      5);
            std::ostringstream out;
            out << y;
            CPPUNIT_ASSERT(out.str() == "28153056843");
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            const Integer<int> x = 2;
            const int          e = 3;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(e == 3);
            CPPUNIT_ASSERT(y == 8);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_4 () {
        try {
            const Integer<int> x = 3;
            const int          e = 3;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 3);
            CPPUNIT_ASSERT(e == 3);
            CPPUNIT_ASSERT(y == 27);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_5 () {
        try {
            Integer<int>       x = 3;
            const int          e = 3;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e ==   3);
            CPPUNIT_ASSERT( x ==  27);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_6 () {
        try {
            Integer<int>       x = 3;
            const int          e = 50;
            Integer<int>&      y = x.pow(e);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "717897987691852588770249");
            CPPUNIT_ASSERT( e ==   50);
            CPPUNIT_ASSERT(&x == &y);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_less_than_op_1 () {
        Integer<int> x = 1;
        Integer<int> y = 1;
        CPPUNIT_ASSERT(!(x < y));
    }

    void test_less_than_op_2 () {
        Integer<int> x = 1;
        Integer<int> y = 2;
        CPPUNIT_ASSERT(x < y);
    }

    void test_less_than_op_3 () {
        const Integer<int> x("12345678891011121314151617");
        const Integer<int> y("12345678891011121314151618");
        CPPUNIT_ASSERT(x < y);
    }

    void test_plus_equals_1 () {
        try {
            Integer<int> x(1);
            x += 1;
            CPPUNIT_ASSERT(x == 2);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_plus_equals_2 () {
        try {
            Integer<int> x(1);
            Integer<int> y(1);
            x += y;
            CPPUNIT_ASSERT(x == 2);
            CPPUNIT_ASSERT(y == 1);
            CPPUNIT_ASSERT(&x != &y);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_plus_equals_3 () {
        try {
            Integer<int> x(1111);
            x += 1234;
            CPPUNIT_ASSERT(x == 2345);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_plus_equals_4 () {
        try {
            Integer<int> x(1);
            x += -1;
            CPPUNIT_ASSERT(x == 0);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_plus_equals_5 () {
        try {
            Integer<int> x(1);
            x += -2;
            CPPUNIT_ASSERT(x == -1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }


    void test_minus_equals_1 () {
        try {
            Integer<int> x(1);
            x -= 1;
            CPPUNIT_ASSERT(x == 0);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_minus_equals_2 () {
        try {
            Integer<int> x(1001);
            x -= 1000;
            CPPUNIT_ASSERT(x == 1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mult_equals_1 () {
        try {
            Integer<int> x(1);
            x *= 1;
            CPPUNIT_ASSERT(x == 1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mult_equals_2 () {
        try {
            Integer<int> x(1);
            x *= -1;
            CPPUNIT_ASSERT(x == -1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mult_equals_3 () {
        try {
            Integer<int> x(-1);
            x *= 1;
            CPPUNIT_ASSERT(x == -1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mult_equals_4 () {
        try {
            Integer<int> x(-1);
            x *= -1;
            CPPUNIT_ASSERT(x == 1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mult_equals_5 () {
        Integer<int> a(234);
        const Integer<int> b(567);
        const Integer<int> c(132678);
        a *= b;
        CPPUNIT_ASSERT(a == c);
        CPPUNIT_ASSERT(b == 567);
    }

    void test_div_equals_1 () {
        try {
            Integer<int> x(1);
            x /= 1;
            CPPUNIT_ASSERT(x == 1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_div_equals_2 () {
        try {
            Integer<int> x(1);
            x /= -1;
            CPPUNIT_ASSERT(x == -1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_div_equals_3 () {
        try {
            Integer<int> x(-1);
            x /= 1;
            CPPUNIT_ASSERT(x == -1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_div_equals_4 () {
        try {
            Integer<int> x(-1);
            x /= -1;
            CPPUNIT_ASSERT(x == 1);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_div_equals_5 () {
        Integer<int> a(132678);
        const Integer<int> b(567);
        const Integer<int> c(234);
        a /= b;
        CPPUNIT_ASSERT(a == c);
        CPPUNIT_ASSERT(b == 567);
    }

    void test_mod_equals_1 () {
        try {
            Integer<int> i(1);
            i %= 2;
            CPPUNIT_ASSERT(i == 1);
        }
        catch (std::invalid_argument& e){
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mod_equals_2 () {
        try {
            Integer<int> i(2);
            i %= 2;
            CPPUNIT_ASSERT(i == 0);
        }
        catch (std::invalid_argument& e){
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mod_equals_3 () {
        try {
            Integer<int> i(1001);
            Integer<int> j(2);
            i %= j;
            CPPUNIT_ASSERT(i == 1);
        }
        catch (std::invalid_argument& e){
            CPPUNIT_ASSERT(false);
        }
    }

    void test_mod_equals_5 () {
        try {
            Integer<int> i(1001);
            Integer<int> j(2);
            i %= j;
            CPPUNIT_ASSERT(i == 1);
        }
        catch (std::invalid_argument& e){
            CPPUNIT_ASSERT(false);
        }
    }

    void test_shift_l_equals_1 () {
        try {
            Integer<int> i(1);
            i <<= 1;
            CPPUNIT_ASSERT(i == 10);
        }
        catch (std::invalid_argument& e){
            CPPUNIT_ASSERT(false);
        }
    }

    void test_shift_r_equals_1 () {
        try {
            Integer<int> i(10);
            i >>= 1;
            CPPUNIT_ASSERT(i == 1);
        }
        catch (std::invalid_argument& e){
            CPPUNIT_ASSERT(false);
        }
    }

    void test_minus_1 () {
        const Integer<int> n = Integer<int>(2) -1;
        CPPUNIT_ASSERT(n == 1);
    }

    void test_karatsuba_1 () {
        std::vector<int> a = {2, 3, 4};
        std::vector<int> b = {5, 6, 7};
        const std::vector<int> c = {1, 3, 2, 6, 7, 8};
        std::vector<int> x = karatsuba(a.begin(), a.end(), b.begin(), b.end());
        CPPUNIT_ASSERT(equal(x.begin(), x.end(), c.begin()));
    }

    void test_karatsuba_2 () {
        std::vector<int> a = {1, 2, 3, 4};
        std::vector<int> b = {5, 6, 7, 8};
        const std::vector<int> c = {7,0,0,6,6,5,2};
        std::vector<int> x = karatsuba(a.begin(), a.end(), b.begin(), b.end());
        CPPUNIT_ASSERT(equal(x.begin(), x.end(), c.begin()));
    }

    void test_mersenne_20th () {
        timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);

        // Minus not working
        const Integer<int> n = Integer<int>(2).pow(4423) -1;
        // const Integer<int> n = Integer<int>(2).pow(4423);

        clock_gettime(CLOCK_REALTIME, &end);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
        cout << endl << "elapsed(ms) " << (elapsed / 1000000L) << endl;
        // long valgrind =  15000000000L;
        // long no_valgrind = 300000000L;
        // CPPUNIT_ASSERT(elapsed < valgrind);
        // CPPUNIT_ASSERT(elapsed < no_valgrind);
        std::ostringstream out;
        out << n;
        CPPUNIT_ASSERT(out.str() == "285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580607"); //Note last digit should be 7
    }

    void test_mersenne_20th_1 () {
        timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);

        //General idea below, numbers conveniently chosen
        //Need to compute   2**4423 -1
        //Compute instead   2**4000 * 2*423 -1
        //Compute instead   4**2000 * 2*423 -1
        //Compute instead  16**1000 * 2*423 -1
        //Compute instead 256** 500 * 2*423 -1
        //Can't evaluate 256^2, so need to stop there.
        //Could also eval 2*423 as  2**400 * 2*23
        //                          4**200 * 2*23
        //                         16**100 * 2*23
        //                        256**50  * 2*23
        const Integer<int> a = Integer<int>(256).pow(500);
        const Integer<int> b = Integer<int>(2).pow(423);
        const Integer<int> n = a * b -1;
        // const Integer<int> n = Integer<int>(2).pow(4423);

        clock_gettime(CLOCK_REALTIME, &end);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
        cout << endl << "elapsed(ms) " << (elapsed / 1000000L) << endl;
        // long valgrind =  15000000000L;
        // long no_valgrind = 300000000L;
        // CPPUNIT_ASSERT(elapsed < valgrind);
        // CPPUNIT_ASSERT(elapsed < no_valgrind);
        std::ostringstream out;
        out << n;
        CPPUNIT_ASSERT(out.str() == "285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580607"); //Note last digit should be 7
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);

    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits_1);
    CPPUNIT_TEST(test_shift_left_digits_2);

    // In place shift
    // CPPUNIT_TEST(test_shift_left_digits_3);

    CPPUNIT_TEST(test_shift_right_digits);

    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits_1);
    CPPUNIT_TEST(test_plus_digits_2);
    CPPUNIT_TEST(test_plus_digits_3);
    CPPUNIT_TEST(test_plus_digits_4);
    CPPUNIT_TEST(test_plus_digits_5);
    CPPUNIT_TEST(test_plus_digits_6);
    CPPUNIT_TEST(test_plus_digits_7);
    CPPUNIT_TEST(test_plus_digits_8);

    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits_1);
    CPPUNIT_TEST(test_minus_digits_2);
    CPPUNIT_TEST(test_minus_digits_3);
    CPPUNIT_TEST(test_minus_digits_4);
    CPPUNIT_TEST(test_minus_digits_5);

    CPPUNIT_TEST(test_multiplies_digits);

    CPPUNIT_TEST(test_multiplies_digits_1);
    CPPUNIT_TEST(test_multiplies_digits_2);
    CPPUNIT_TEST(test_multiplies_digits_3);
    CPPUNIT_TEST(test_multiplies_digits_4);
    CPPUNIT_TEST(test_multiplies_digits_5);
    CPPUNIT_TEST(test_multiplies_digits_6);

    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_divides_digits_1);
    CPPUNIT_TEST(test_divides_digits_2);

    CPPUNIT_TEST(test_constructor_1); //Tests invalid input. Need info on valid().
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);

    CPPUNIT_TEST(test_equal_to);

    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation_1);

    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);

    CPPUNIT_TEST(test_output);


    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
    CPPUNIT_TEST(test_pow_5);
    // CPPUNIT_TEST(test_pow_6);




    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output_1);

    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_less_than_5);
    CPPUNIT_TEST(test_less_than_6);
    CPPUNIT_TEST(test_less_than_7);
    CPPUNIT_TEST(test_less_than_op_1);
    CPPUNIT_TEST(test_less_than_op_2);
    CPPUNIT_TEST(test_less_than_op_3);
    CPPUNIT_TEST(test_plus_equals_1);
    CPPUNIT_TEST(test_plus_equals_2);
    CPPUNIT_TEST(test_plus_equals_3);

    // Handling negative numbers
    // CPPUNIT_TEST(test_plus_equals_4);
    // CPPUNIT_TEST(test_plus_equals_5);

    CPPUNIT_TEST(test_minus_equals_1);
    CPPUNIT_TEST(test_minus_equals_2);

    CPPUNIT_TEST(test_mult_equals_1);
    CPPUNIT_TEST(test_mult_equals_2);
    CPPUNIT_TEST(test_mult_equals_3);
    CPPUNIT_TEST(test_mult_equals_4);
    CPPUNIT_TEST(test_mult_equals_5);

    CPPUNIT_TEST(test_div_equals_1);
    CPPUNIT_TEST(test_div_equals_2);
    CPPUNIT_TEST(test_div_equals_3);
    CPPUNIT_TEST(test_div_equals_4);
    CPPUNIT_TEST(test_div_equals_5);

    CPPUNIT_TEST(test_mod_equals_1);
    CPPUNIT_TEST(test_mod_equals_2);
    CPPUNIT_TEST(test_mod_equals_3);


    CPPUNIT_TEST(test_shift_l_equals_1);

    CPPUNIT_TEST(test_shift_r_equals_1);

    CPPUNIT_TEST(test_minus_1);

    CPPUNIT_TEST(test_karatsuba_1);
    CPPUNIT_TEST(test_karatsuba_2);


    CPPUNIT_TEST(test_mersenne_20th);
    CPPUNIT_TEST(test_mersenne_20th_1);


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
