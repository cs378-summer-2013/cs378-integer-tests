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
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	
	void test_plus_digits1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {8, 0, 0};
        const int c[] = {1, 0, 3, 4};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
    void test_plus_digits2 () {
        const int a[] = {9, 9, 9};
        const int b[] = {8, 8, 8};
        const int c[] = {1, 8, 8, 7};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_plus_digits3 () {
        const int a[] = {1, 2};
        const int b[] = {7};
        const int c[] = {1, 9};
              int x[10];
        const int* p = plus_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_plus_digits4 () {
        const int a[] = {8};
        const int b[] = {1, 7};
        const int c[] = {2, 5};
              int x[10];
        const int* p = plus_digits(a, a + 1, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
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
        const int a[] = {1, 1, 1};
        const int b[] = {9, 9};
        const int c[] = {1, 2};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

	void test_minus_digits2 () {
        const int a[] = {1, 1, 1};
        const int b[] = {1, 1, 0};
        const int c[] = {1};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
    void test_minus_digits3 () {
        const int a[] = {5, 5, 5};
        const int b[] = {5, 5, 5};
        const int c[] = {0};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
    
     void test_minus_digits4 () {
        const int a[] = {1, 0, 0, 0};
        const int b[] = {2};
        const int c[] = {9, 9 ,8};
              int x[10];
        const int* p = minus_digits(a, a + 4, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
    // -----------------
    // addToDeque
    // -----------------
       
    void test_addTodeque() {
		std::deque<int> a = {1, 2, 3};
		std::deque<int> b = {2, 3, 4};
		addToDeque(a, b);
	}
        
    void test_addTodeque2() {
		std::deque<int> a;
		std::deque<int> b = {2, 3, 4};
		addToDeque(a, b);
	}
	
	void test_addTodeque3() {
		std::deque<int> a;
		std::deque<int> b = {2, 3, 4};
		addToDeque(b, a);
	}
	
	
   
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


	 void test_multiplies_digits1 () {
        const int a[] = {2, 3};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 0, 4, 1};
              int x[10];
        const int* p = multiplies_digits(a, a + 2, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
        
    void test_multiplies_digits2 () {
        const int a[] = {5};
        const int b[] = {1,0};
        const int c[] = {5,0};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}
        
        
        
    void test_multiplies_digits3 () {
        const int a[] = {1};
        const int b[] = {1,2};
        const int c[] = {1,2};
              int x[10];
        const int* p = multiplies_digits(a, a + 1, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}    
            
     void test_multiplies_digits4 () {
        const int a[] = {1,5};
        const int b[] = {1};
        const int c[] = {1,5};
              int x[10];
        const int* p = multiplies_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
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

	void test_equal_to1 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = 98765;
            CPPUNIT_ASSERT(!(x==y));}
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
            Integer<int>       x = 98765;
            const int          e =  9867;
            Integer<int>&      y = x.pow(e);
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
            const Integer<int> x = 4;
            const int          e =  2;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 4);
            CPPUNIT_ASSERT(e ==  2);
            CPPUNIT_ASSERT(y ==  16);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
            
     void test_pow_4 () {
        try {
            const Integer<int> x = 55;
            const int          e =  5;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 55);
            CPPUNIT_ASSERT(e ==  5);
            CPPUNIT_ASSERT(y ==  503284375);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

	void test_pow_5 () {
        try {
            const Integer<int> x = 2;
            const int          e =  27;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 55);
            CPPUNIT_ASSERT(e ==  5);
            CPPUNIT_ASSERT(y ==  134217728);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	
	
	// -----
    // operator *
    // -----
	void test_mult_operator () {
		const Integer<int> x = 5;
		const Integer<int> y = 4;
		const Integer<int> z = x*y;
		const Integer<int> w = 20;
		
		CPPUNIT_ASSERT(z == w);
	}
	
	void test_mult_operator2() {
		const Integer<int> x = 111;
		const Integer<int> y = 5;
		const Integer<int> a = 555;
		const Integer<int> z = x*y;
		CPPUNIT_ASSERT(z == a);
	}
	
	void test_mult_operator3 () {
		const Integer<int> x = 55;
		const Integer<int> y = 1;
		const Integer<int> z = x*y;
		const Integer<int> w = 55;
		CPPUNIT_ASSERT(z == w);
	}
	
	void test_mult_operator4 () {
		const Integer<int> x = 1;
		const Integer<int> y = 44;
		const Integer<int> z = x*y;
		const Integer<int> w = 44;
		CPPUNIT_ASSERT(z == w); 
	}

	void test_mult_operator5 () {
		const Integer<int> x = 6225;
		const Integer<int> y = 3654;
		const Integer<int> z = x*y;
		const Integer<int> w = 22746150;
		CPPUNIT_ASSERT(z == w); 
	}


	
	// -----
    // operator -
    // -----
	void test_minus_operator () {
		const Integer<int> x = 6225;
		const Integer<int> y = 3654;
		const Integer<int> z = x-y;
		const Integer<int> w = 2571;
		CPPUNIT_ASSERT(z == w); 
	}
	
	void test_minus_operator1 () {
		const Integer<int> x = 62255555151;
		const Integer<int> y = 1;
		const Integer<int> z = x-y;
		const Integer<int> w = 62255555150;
		CPPUNIT_ASSERT(z == w); 
	}
	
	void test_minus_operator2 () {
		const Integer<int> x = 10000000000;
		const Integer<int> y = 1;
		const Integer<int> z = x-y;	
		const Integer<int> w = 		9999999999;
		CPPUNIT_ASSERT(z == w); 
	}

	void test_minus_operator3 () {
		const Integer<int> x = 1;
		const Integer<int> y = 1;
		const Integer<int> z = x-y;	
		const Integer<int> w = 0;
		CPPUNIT_ASSERT(z == w); 
	}
	
	void test_less_than_operator () {
		const Integer<int> x = 6225;
		const Integer<int> y = 3654;
		CPPUNIT_ASSERT(y < x);
	}
		
	void test_less_than_operator1 () {
		const Integer<int> x = 6225;
		const Integer<int> y = -x;
		CPPUNIT_ASSERT(y < x);
		CPPUNIT_ASSERT(!(x < y)); 
	}
	
	void test_equal_operator () {
		const Integer<int> x = 6225;
		const Integer<int> y = 6225;
		const Integer<int> z = 622;

		CPPUNIT_ASSERT(y == x);
		CPPUNIT_ASSERT(!(x == z)); 
	}
	
	void test_equal_operator1 () {
		const Integer<int> x = 6225;
		const Integer<int> y = -x;
		CPPUNIT_ASSERT(!(x == y)); 
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_plus_digits1);
    CPPUNIT_TEST(test_plus_digits2);
    CPPUNIT_TEST(test_plus_digits3);
    CPPUNIT_TEST(test_plus_digits4);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_minus_digits1);
    CPPUNIT_TEST(test_minus_digits2);
    CPPUNIT_TEST(test_minus_digits3);
    CPPUNIT_TEST(test_minus_digits4);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_multiplies_digits1);
    CPPUNIT_TEST(test_multiplies_digits2);
    CPPUNIT_TEST(test_multiplies_digits3);
    CPPUNIT_TEST(test_multiplies_digits4);
    CPPUNIT_TEST(test_mult_operator);
    CPPUNIT_TEST(test_mult_operator2);
    CPPUNIT_TEST(test_mult_operator3);
    CPPUNIT_TEST(test_mult_operator4);
    CPPUNIT_TEST(test_mult_operator5);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_equal_to1);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_output);
   // CPPUNIT_TEST(test_pow_1);
    //CPPUNIT_TEST(test_pow_2);
    CPPUNIT_TEST(test_pow_3);
    CPPUNIT_TEST(test_addTodeque); 
    CPPUNIT_TEST(test_addTodeque2); 
    CPPUNIT_TEST(test_addTodeque3); 
    CPPUNIT_TEST(test_minus_operator);
    CPPUNIT_TEST(test_minus_operator1);
    CPPUNIT_TEST(test_minus_operator2);
    CPPUNIT_TEST(test_minus_operator3);
	CPPUNIT_TEST(test_less_than_operator);
	CPPUNIT_TEST(test_less_than_operator1);
	CPPUNIT_TEST(test_equal_operator);
	CPPUNIT_TEST(test_equal_operator1);

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
