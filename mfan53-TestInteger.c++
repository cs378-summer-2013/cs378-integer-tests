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
#include <ctime>

// -----------
// TestInteger
// -----------

struct TestInteger : CppUnit::TestFixture {
    // -----------------
    // shift_left_digits
    // -----------------

    void test_shift_left_digits () {
        //a is 234, b is 23400
        const int a[] = {4, 3, 2};
        const int b[] = {0, 0, 4, 3, 2};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits2 () {
        //a is 0, b is 000
        const int a[] = {0};
        const int b[] = {0, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 1, 2, x);
        CPPUNIT_ASSERT((p - x) == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    void test_shift_left_digits3 () {
        //a is 2, b is 5000
        const int a[] = {5};
        const int b[] = {0, 0, 0, 5};
              int x[10];
        const int* p = shift_left_digits(a, a + 1, 3, x);
        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits () {
        //a is 234, b is 2
        const int a[] = {4, 3, 2};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
       //  std::cout << "digits 1 test: p - x " << p - x << std::endl;
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

     void test_shift_right_digits2 () {
        //a is 5, b is 0
        const int a[] = {5};
        const int b[] = {0};
              int x[10];
        const int* p = shift_right_digits(a, a + 1, 1, x);
        //std::cout << "length of p - x is " << p - x << std::endl;
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

     void test_shift_right_digits3 () {
        //a is 92, b is 0
        const int a[] = {2, 9};
        const int b[] = {0};
              int x[10];
        const int* p = shift_right_digits(a, a + 2, 8, x);
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

    void test_plus_digits2 () {
        const int a[] = {0, 0, 1};
        const int b[] = {0, 1};
        const int c[] = {0, 1, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits3 () {
        const int a[] = {0, 1};
        const int b[] = {0, 0, 1};
        const int c[] = {0, 1, 1};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_plus_digits4 () {
       //std::cout << "TEST PLUS 4" << std::endl;
        const int a[] = {2, 9, 2, 7, 9};
        const int b[] = {0, 9, 6, 9, 2, 7};
        const int c[] = {2, 8, 9, 6, 2, 8};
              int x[10];
        const int* p = plus_digits(a, a + 5, b, b + 6, x);
        CPPUNIT_ASSERT(p - x == 6);
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

    void test_minus_digits2 () {
        const int a[] = {0, 0, 1};
        const int b[] = {0, 1};
        const int c[] = {0, 9, 0};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 2, x);
        //std::cout << "p - x = " << p-x << std::endl;       
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_minus_digits3 () {
        const int a[] = {1, 0, 9};
        const int b[] = {3, 5, 2};
        const int c[] = {8, 4, 6};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        //std::cout << "TEST MULTIPLIES 1" << std::endl;
        const int a[] = {4, 3, 2};
        const int b[] = {7, 6, 5};
        const int c[] = {8, 7, 6, 2, 3, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits2 () {
        const int a[] = {3, 2, 3, 4, 2};
        const int b[] = {4, 3, 1, 4, 3};
        const int c[] = {2, 8, 2, 1, 4, 2, 0, 3, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 5, b, b + 5, x);
        CPPUNIT_ASSERT(p - x == 9);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_multiplies_digits3 () {
        //std::cout << "TEST MULTIPLIES 2" << std::endl;
        const int a[] = {6, 5, 2};
        const int b[] = {6, 5, 2};
        const int c[] = {6, 3, 5, 5, 6};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 5);
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
            const Integer<int> x("-2");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_3 () {
        try {
            const Integer<int> x(-2);}
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
            const Integer<int> x = 0;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y ==  0);}
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
            const Integer<int> x = 56783;
            const Integer<int> y = 56781;
            CPPUNIT_ASSERT(!(x == y));
            CPPUNIT_ASSERT(x == 56783);
            CPPUNIT_ASSERT(56783 == x);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(56781 != y));
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_equal_to3 () {
        try {
            const Integer<int> x = -23;
            const Integer<int> y = 23;
            CPPUNIT_ASSERT(!(x == y));
            CPPUNIT_ASSERT(x == -23);
            CPPUNIT_ASSERT(-23 == x);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(23 != y));
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------
    // negation
    // --------

    void test_negation () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -x;
            //std::cout << "negation of x is " << y << std::endl;
            CPPUNIT_ASSERT(y == -98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation2 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            //std::cout << "negation of 0 is " << y << std::endl;
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation3 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
             //std::cout << "negation of x is " << y << std::endl;
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_negation4 () {
        try {
            const Integer<int> x = -77;
            const Integer<int> y = -x;
             //std::cout << "negation of x is " << y << std::endl;
            CPPUNIT_ASSERT(y == 77);}
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
            const Integer<int> x = -543;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-543");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_output3 () {
        try {
            const Integer<int> x = 7;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "7");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            //std::clock_t start;
            //double duration;
            //start = std::clock();
            Integer<int>       x = 98765;
            const int          e =  9867;
            Integer<int>&      y = x.pow(e);
            //duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            //std::cout<<"TEST POW 1 DURATION: "<< duration <<std::endl;
            CPPUNIT_ASSERT( e == 9867);
            CPPUNIT_ASSERT( x ==    0);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 98765;
            const int          e =  9867;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 98765);
            CPPUNIT_ASSERT(e ==  9867);
            CPPUNIT_ASSERT(y ==     0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_3 () {
        try {
            const Integer<int> x = 0;
            const int          e =  0;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "pow"));}}

    void test_pow_4 () {
        try {
            const Integer<int> x = 1;
            const int          e =  -1;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "pow"));}}

    void test_pow_5 () {
        try {
            Integer<int> x = 2;
            const int e = 4;
            x.pow(e);
            CPPUNIT_ASSERT(x == 16);
        }
          catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "pow"));}
    }

    void test_pow_6 () {
        try {
            Integer<int> x = -2;
            const int e = 4;
            x.pow(e);
            CPPUNIT_ASSERT(x == 16);
        }
          catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "pow"));}
    }

    void test_pow_7 () {
        try {
            Integer<int> x = -2;
            const int e = 3;
            x.pow(e);
            CPPUNIT_ASSERT(x == -8);
        }
          catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "pow"));}
    }

    void test_pow_8 () {
        try {
            //std::clock_t start;
            //double duration;
           // start = std::clock();
            Integer<int> x = 50;
            const int e = 4;
            x.pow(e);
            //duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            //std::cout<<"printf: "<< duration <<std::endl;
            CPPUNIT_ASSERT(x == 6250000);
        }
          catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "pow"));}
    }

    void test_divide_operator_1 () {
        try {
            const Integer<int> x = 10;
            const Integer<int> y = 0;
            const Integer<int> r = x / y;
            CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "divide"));
        }
    }

    void test_modulus_operator_1 () {
        try {
            const Integer<int> x = 10;
            const Integer<int> y = -10;
            const Integer<int> r = x % y;
            CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "modulus"));
        }
    }

    void test_shift_left_1 () {
        try {
            const Integer<int> x = 10;
            const int y = -10;
            const Integer<int> r = x << y;
            CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "shift left"));
        }
    }

    void test_shift_right_1 () {
        try {
            const Integer<int> x = 10;
            const int y = -10;
            const Integer<int> r = x >> y;
            CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "shift right"));
        }
    }

    // ----------
    // operator <
    // ----------

    void test_less_than () {
        const Integer<int> x = 15;
        const Integer<int> y = 53;
        const bool r = x < y;
        CPPUNIT_ASSERT(r);
    }

    void test_less_than2 () {
        const Integer<int> x = 98;
        const Integer<int> y = 89;
        const bool r = x < y;
        CPPUNIT_ASSERT(!r);
    }

    void test_less_than3 () {
        const Integer<int> x = -80;
        const Integer<int> y = -20;
        const bool r = x < y;
        CPPUNIT_ASSERT(r);
    }

     void test_less_than4 () {
        const Integer<int> x = -10;
        const Integer<int> y = 25;
        const bool r = x < y;
        CPPUNIT_ASSERT(r);
    }

    // ------------
    // operator <<=
    // ------------

    void test_left_shift_equal () {
        try {
            Integer<int> x = 234;
            x <<= 2;           
            CPPUNIT_ASSERT(x == 23400);
        }
         catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_left_shift_equal2 () {
        try {
            Integer<int> x = 5;
            x <<= 3;           
            CPPUNIT_ASSERT(x == 5000);
        }
         catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_left_shift_equal3 () {
        try {
            Integer<int> x = -17;
            x <<= 1;           
            CPPUNIT_ASSERT(x == -170);
        }
         catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    // ------------
    // operator >>=
    // ------------

    void test_right_shift_equal () {
        try {
            Integer<int> x = 234;
            x >>= 2;
            CPPUNIT_ASSERT(x == 2);
        }
         catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_right_shift_equal2 () {
        try {
            Integer<int> x = 5;
            x >>= 1;
            CPPUNIT_ASSERT(x == 0);
        }
         catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_right_shift_equal3 () {
        try {
            Integer<int> x = 23;
            x >>= 2;
            //cout <<  "x is " << x << endl;
            CPPUNIT_ASSERT(x == 0);
        }
         catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }
    // -----------
    // operator +=
    // -----------

    void test_plus_equals () {
        try {
            Integer<int> x = 10;
            Integer<int> y = 5;
            x += y;
            //std::cout << "10 += 5 is " << x << std::endl;
            CPPUNIT_ASSERT(x == 15);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_plus_equals2 () {
        try {
            Integer<int> x = -550;
            Integer<int> y = -75;
            x += y;
            //std::cout << "10 += 5 is " << x << std::endl;
            CPPUNIT_ASSERT(x == -625);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_plus_equals3 () {
        try {
            Integer<int> x = 1;
            Integer<int> y = 222;
            x += y;
            CPPUNIT_ASSERT(x == 223);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    // -----------
    // operator -=
    // -----------

    void test_minus_equals () {
        try {
            Integer<int> x = 801;
            Integer<int> y = 567;
            x -= y;
            CPPUNIT_ASSERT(x == 234);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_minus_equals2 () {
        try {
            Integer<int> x = 100;
            Integer<int> y = 10;
            x -= y;
            CPPUNIT_ASSERT(x == 90);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_minus_equals3 () {
        try {
            Integer<int> x = 901;
            Integer<int> y = 253;
            x -= y;
            CPPUNIT_ASSERT(x == 648);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    // -----------
    // operator *=
    // -----------

    void test_multiplies_equals () {
        try {
            Integer<int> x = 234;
            Integer<int> y = 567;
            x *= y;
            CPPUNIT_ASSERT(x == 132678);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_multiplies_equals2 () {
        try {
            Integer<int> x = 1;
            Integer<int> y = -436328;
            x *= y;
            CPPUNIT_ASSERT(x == -436328);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_multiplies_equals3 () {
        try {
            Integer<int> x = -5;
            Integer<int> y = 6;
            x *= y;
            CPPUNIT_ASSERT(x == -30);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    void test_multiplies_equals4 () {
        try {
            Integer<int> x = -5;
            Integer<int> y = -6;
            x *= y;
           //std::cout << "-5 * -6 is " << x << std::endl;
            CPPUNIT_ASSERT(x == 30);
        }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_left_digits2);
    CPPUNIT_TEST(test_shift_left_digits3);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_shift_right_digits2);
    CPPUNIT_TEST(test_shift_right_digits3);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits2);
    CPPUNIT_TEST(test_plus_digits3);
    CPPUNIT_TEST(test_plus_digits4);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits2);
    CPPUNIT_TEST(test_minus_digits3);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits2);
    CPPUNIT_TEST(test_multiplies_digits3);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_negation2);
    CPPUNIT_TEST(test_negation3);
    CPPUNIT_TEST(test_negation4);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_output2);
    CPPUNIT_TEST(test_output3);
    //CPPUNIT_TEST(test_pow_1);
    //CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_pow_4);
    CPPUNIT_TEST(test_pow_5);
    CPPUNIT_TEST(test_pow_6);
    CPPUNIT_TEST(test_pow_7);
    CPPUNIT_TEST(test_pow_8);
    CPPUNIT_TEST(test_divide_operator_1);
    CPPUNIT_TEST(test_modulus_operator_1);
    CPPUNIT_TEST(test_shift_left_1);
    CPPUNIT_TEST(test_shift_right_1);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_less_than3);
    CPPUNIT_TEST(test_less_than4);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to2);
    CPPUNIT_TEST(test_equal_to3);
    CPPUNIT_TEST(test_left_shift_equal);
    CPPUNIT_TEST(test_left_shift_equal2);
    CPPUNIT_TEST(test_left_shift_equal3);
    CPPUNIT_TEST(test_right_shift_equal);
    CPPUNIT_TEST(test_right_shift_equal2);
    CPPUNIT_TEST(test_right_shift_equal3);
    CPPUNIT_TEST(test_plus_equals);
    CPPUNIT_TEST(test_plus_equals2);
    CPPUNIT_TEST(test_plus_equals3);
    CPPUNIT_TEST(test_minus_equals);
    CPPUNIT_TEST(test_minus_equals2);
    CPPUNIT_TEST(test_minus_equals3);
    CPPUNIT_TEST(test_multiplies_equals);
    CPPUNIT_TEST(test_multiplies_equals2);
    CPPUNIT_TEST(test_multiplies_equals3);
    CPPUNIT_TEST(test_multiplies_equals4);
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

