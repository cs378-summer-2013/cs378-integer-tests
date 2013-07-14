// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2013
// Glenn P. Downing
// Dalton Schmidt and Enam Ayivi
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


    //shifts left 2 digits
    void test_shift_left_digits_1 () 
  {
        const int a[] = {2, 3, 4};
        const int b[] = {0, 0, 2, 3, 4};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);

        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}



    //shifts left 4 digits
    void test_shift_left_digits_2 () 
	{
        const int a[] = {2,3};
        const int b[] = {0,0,0,0,2,3};
              int x[10];
        const int* p = shift_left_digits(a, a + 2, 4, x);

        CPPUNIT_ASSERT((p - x) == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}


    //shifts left 0 digits
    void test_shift_left_digits_3 () 
	{
        const int a[] = {2,3,4,5};
        const int b[] = {2,3,4,5};
              int x[10];
        const int* p = shift_left_digits(a, a + 4, 0, x);

        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
	}

    void test_shift_left_digits_4 () 
    {
        const int a[] = {3,2,1};
        const int b[] = {0,3,2,1};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 1, x);

        CPPUNIT_ASSERT((p - x) == 4);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));
    }

// -----------------
// shift_left_equal  <<=
// -----------------

    void test_shift_left_equal_1  () {      
        try {
            Integer<int> x = 123;
            int y = 1;
            x<<=y;

            CPPUNIT_ASSERT(x == 1230);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_left_equal_2  () {      
        try {
            Integer<int> x = 0;
            int y = 0;
            x<<=y;

            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_left_equal_3  () {      
        try {
            Integer<int> x = 23;
            int y = 0;
            x<<=y;

            CPPUNIT_ASSERT(x == 23);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_left_equal_4  () {      
        try {
            Integer<int> x = 1250;
            int y = 0;
            x<<=y; 
            CPPUNIT_ASSERT(x == 1250);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // ------------------
    // shift_right_digits
    // ------------------


    //Shft Right 2 digits
    void test_shift_right_digits_1 () {
        const int a[] = {2, 3, 4};
        const int b[] = {4};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}



    //shift right 5 digits
    void test_shift_right_digits_2 () {
        const int a[] = {2, 3, 4, 6, 7, 8, 9};
        const int b[] = {8, 9};
              int x[10];
        const int* p = shift_right_digits(a, a + 7, 5, x);
        CPPUNIT_ASSERT((p - x) == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}



    //Shift equal 4 digits.  resulting in zero
    void test_shift_right_digits_3 () {
        const int a[] = {2, 3, 4};
        const int b[] = {0};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 4, x);
//        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}


// -----------------
// shift_right_equal  >>=
// -----------------

    void test_shift_right_equal_1  () {      
        try {
            Integer<int> x = 123;
            int y = 1;
            x>>=y;
            CPPUNIT_ASSERT(x == 12);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_right_equal_2  () {      
        try {
            Integer<int> x = 0;
            int y = 0;
            x>>=y;
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_right_equal_3  () {      
        try {
            Integer<int> x = 23;
            int y = 0;
            x>>=y;

            CPPUNIT_ASSERT(x == 23);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_shift_right_equal_4  () {      
        try {
            Integer<int> x = 1250;
            int y = 4;
            x>>=y;
            CPPUNIT_ASSERT(x == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    // -----------
    // plus_digits
    // -----------

    ///Dr Downing's default test
    void test_plus_digits_1 () {
        // const int a[] = {2, 3, 4};
        // const int b[] = {5, 6, 7};
        // const int c[] = {8, 0, 1};
        const int a[] = {4, 3, 2};
        const int b[] = {7, 6, 5};
        const int c[] = {1, 0, 8};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
	
//	std::cout << "\n" << p - x << "\n";
         CPPUNIT_ASSERT(p - x == 3);
         CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));


    }

    //test a carry to an extra digit
    void test_plus_digits_2 () {
        const int a[] = {9,9,9};
        const int b[] = {1,0,0};
        const int c[] = {0,0,0,1};


              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
         CPPUNIT_ASSERT(p - x == 3);//unsure if this should be 3
         CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));


    }



        //Test a negative plus a positive
        void test_plus_digits_3 () {
        const int a[] = {9,9,9};
        const int b[] = {1,0,0};
        const int c[] = {0,0,0,1};


              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);


         CPPUNIT_ASSERT(p - x == 3);//unsure if this should be 3
         CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));


   	 }
	




    // -----------
    // plus_equal
    // -----------

    //+= of 2 positive numbers
    void test_plus_equal_1  () {
        try {
            Integer<int> x = 4567;
            const Integer<int> y = 123;
            x+=y;
  //          const Integer<int> z = 4690;
            CPPUNIT_ASSERT(x == 4690);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




    //+= of a negative and a positive
    void test_plus_equal_2  () {
        try {
            Integer<int> x = 4567;
            const Integer<int> y = -123;
            x+=y;
  //          const Integer<int> z = 4690;
            CPPUNIT_ASSERT(x == 4444);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




    //+= of a negative and a negative
    void test_plus_equal_3  () {
        try {
            Integer<int> x = -4567;
            const Integer<int> y = 123;
            x+=y;
  //          const Integer<int> z = 4690;
            CPPUNIT_ASSERT(x == -4444);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    // -----------
    // minus_equal
    // -----------


    //-= of 2 positive numbers
    void test_minus_equal_1  () {
        try {
             Integer<int> x = 4567;
            const Integer<int> y = 123;
            x-=y;


            CPPUNIT_ASSERT(x == 4444);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    //-= of 2 negative numbers
    void test_minus_equal_2  () {
        try {
             Integer<int> x = -4567;
            const Integer<int> y = -123;
            x-=y;


            CPPUNIT_ASSERT(x == -4444);} //IS == DEFINED FOR NEGATIVES?
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //-= of 2 opposite signed numbers
    void test_minus_equal_3  () {
        try {
             Integer<int> x = -4567;
            const Integer<int> y = 123;
            x-=y;


            CPPUNIT_ASSERT(x == -4690);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    //-= of 2 opposite signed numbers
    void test_minus_equal_4  () {
        try {
             Integer<int> x = 4567;
            const Integer<int> y = -123;
            x-=y;


            CPPUNIT_ASSERT(x == 4690);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------------
    // divide_equal
    // ------------

    void test_divide_equal_1  () {
        try {
            Integer<int> x = 160;
            const Integer<int> y = 20;
            x/=y;
          //  cout << x;
            CPPUNIT_ASSERT(x == 8);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_equal_2  () {
        try {
            Integer<int> x = 16;
            const Integer<int> y = 3;
            x/=y;
          //  cout << x;
            CPPUNIT_ASSERT(x == 5);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_divide_equal_3  () {
        try {
            Integer<int> x = 16;
            const Integer<int> y = 1;
            x/=y;

            CPPUNIT_ASSERT(x == 16);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




// -----------------
// modulo_equal  %=
// -----------------

    void test_modulo_equal_1  () {      
        try {
            Integer<int> x = 12;
            int y = 5;
            x%=y;
            CPPUNIT_ASSERT(x == 2);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    void test_modulo_equal_2  () {      
        try {
            Integer<int> x = 153;
            int y = 10;
            x%=y;
//		std::cout << x;
            CPPUNIT_ASSERT(x == 3);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // ------------
    // minus_digits
    // ------------


    //Default, tests subtraction of 2 numbers
    void test_minus_digits_1 () {
        const int a[] = {1, 0, 8};
        const int b[] = {7, 6, 5};
        const int c[] = {4, 3, 2};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    //Subraction of 2 positive numbers of different sizes resulting in negative
    void test_minus_digits_2 () {
        const int a[] = {8, 4, 0, 3, 1};
        const int b[] = {7, 3, 3, 1};
        const int c[] = {1, 1, 7, 1, 1};  //UNSURE ABOUT ZERO @ END
              int x[10];
        const int* p = minus_digits(a, a + 5, b, b + 4, x);

        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}



    //Subraction of 2 negative numbers of different sizes resulting in a positive
    void test_minus_digits_3 () {
        const int a[] = {1, 9, 6, 4, 2, 1, 2};
        const int b[] = {5, 7, 6, 4, 1};
        const int c[] = {6, 1, 0, 0, 1, 1, 2};  //UNSURE ABOUT ZERO @ END
              int x[10];
        const int* p = minus_digits(a, a + 7, b, b + 5, x);

        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
	  }




    // -------------------
    //  compare_magnitudes
    // -------------------


    //Compares the magnitudes a neg and a pos
    void compare_magnitudes_1()
    {
	Integer<int> x = -4324;
	const Integer<int> y = 4124;
	int res = compare_magnitudes(x, y);
	CPPUNIT_ASSERT(res == -1);


    }


    //Compares the magnitudes a neg and a neg
    void compare_magnitudes_2()
    {
	Integer<int> x = -4324;
	const Integer<int> y = -412434;
	int res = compare_magnitudes(x, y);
	CPPUNIT_ASSERT(res == 1);


    }


    //Compares the magnitudes a neg and a pos, but equal mag
    void compare_magnitudes_3()
    {
	Integer<int> x = -324;
	const Integer<int> y = 324;
	int res = compare_magnitudes(x, y);
	CPPUNIT_ASSERT(res == 0);


    }



    // -------------------
    //  greater_or_equal
    // -------------------

    void digits_greater_or_equal_1() {
        const int a[] = {2};
        const int b[] = {5,5};
        bool answer = digits_greater_or_equal(a, a+1, b, b+2);
        CPPUNIT_ASSERT(!answer);
    }

    void digits_greater_or_equal_2() {
        const int a[] = {5};
        const int b[] = {2};
        bool answer = digits_greater_or_equal(a, a+1, b, b+1);
        CPPUNIT_ASSERT(answer);
    }

    void digits_greater_or_equal_3() {
        const int a[] = {2};
        const int b[] = {5};
        bool answer = digits_greater_or_equal(a, a+1, b, b+1);
        CPPUNIT_ASSERT(!answer);
    }

    void digits_greater_or_equal_4() {
        const int a[] = {5};
        const int b[] = {5,6};
        bool answer = digits_greater_or_equal(a, a+1, b, b+2);
        CPPUNIT_ASSERT(!answer);
    }


    void digits_greater_or_equal_5() {
        const int a[] = {0,2};
        const int b[] = {5};
        bool answer = digits_greater_or_equal(a, a+2, b, b+1);
        CPPUNIT_ASSERT(answer);
    }

    void digits_greater_or_equal_6() {
        const int a[] = {9};
        const int b[] = {2};
        bool answer = digits_greater_or_equal(a, a+1, b, b+1);
        CPPUNIT_ASSERT(answer);
    }
    // -----------------
    // multiplies_digits
    // -----------------


    //multiplies a 3 digit number by 2
    void test_multiplies_digits_1 () {
        const int a[] = {3, 2, 1};
        const int b[] = {2};
        const int c[] = {6, 4, 2};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 1, x);
//        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));
}

/// mult flag

    //multiplies a 3 digit number by 2
    void test_multiplies_digits_2 () {
        const int a[] = {3, 2, 1};
        const int b[] = {2, 1};
        const int c[] = {6, 7, 4, 1};
              int x[10];
	x[0] = 0; x[1] = 0; x[2] = 0; x[3] = 0; x[4] = 0; x[5] = 0;
        const int* p = multiplies_digits(a, a + 3, b, b + 2, x);
//        CPPUNIT_ASSERT(p - x == 6);


	CPPUNIT_ASSERT(x[0] == 6); 
	CPPUNIT_ASSERT(x[1] == 7);
	CPPUNIT_ASSERT(x[2] == 4);
	CPPUNIT_ASSERT(x[3] == 1);



        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    //multiplies a 3 digit number by 2
    void test_multiplies_digits_3 () {
        const int a[] = {9, 5, 7};
        const int b[] = {7, 4};
        const int c[] = {3, 7, 6, 5, 3};
              int x[10];
	x[0] = 0; x[1] = 0; x[2] = 0; x[3] = 0; x[4] = 0; x[5] = 0; x[6] = 0;
        const int* p = multiplies_digits(a, a + 3, b, b + 2, x);
//        CPPUNIT_ASSERT(p - x == 6);


	CPPUNIT_ASSERT(x[0] == 3); 
	CPPUNIT_ASSERT(x[1] == 7);
	CPPUNIT_ASSERT(x[2] == 6);
	CPPUNIT_ASSERT(x[3] == 5);
	CPPUNIT_ASSERT(x[4] == 3);



        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}




    void test_times_equal_1 () {
            Integer<int> x = 343143;
            const Integer<int> y = 2313151;
	
		x *= y;	
		
	    Integer<int> z = x * y;
	 

	//	std::cout << x << " " << z;


    }


    // --------------
    // divides_digit, const Integer& rhs) {   |            CPPUNIT_ASSERT(!(y != -12345));}                                                          
    //   assert( getSign(rhs) == 0 ); //div by zero = end of world     
    // --------------

    //sample division Dr.Downing gave us
    void test_divides_digits_1 () {
        const int a[] = {7};
        const int b[] = {2};
        const int c[] = {3};
              int x[10];
        const int* p = divides_digits(a, a + 1, b, b + 1, x);
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

    //100 / 10 = 10
    void test_divides_digits_3 () {
        const int a[] = {0, 0, 1};
        const int b[] = {0, 1};
        const int c[] = {0, 1};
              int x[10];
        const int* p = divides_digits(a, a + 3, b, b + 2, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    //sample division Dr.Downing gave us
    void test_divides_digits_4 () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {1};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


    void test_divides_digits_5 () {
        const int a[] = {7, 2};
        const int b[] = {4};
        const int c[] = {6};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}


  
    void test_divides_digits_6 () {
        const int a[] = {7,2};
        const int b[] = {2};
        const int c[] = {3,1};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 1, x);
        CPPUNIT_ASSERT(p - x == 2);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    void test_divides_digits_7 () {
        const int a[] = {6,1};
        const int b[] = {2};
        const int c[] = {8};
              int x[10];
        const int* p = divides_digits(a, a + 2, b, b + 1, x);
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

    //gets the abs of a negative number
    void test_abs_1 () {
        try {
            Integer<int>  x = -98765;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 98765);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //abs of a positive is still positive
    void test_abs_2 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x ==  98765);
            CPPUNIT_ASSERT(y ==  98765);
	    CPPUNIT_ASSERT(x == y);
	    }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //makes sure the abs of zero is still zero
    void test_abs_3 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == 0);
            CPPUNIT_ASSERT(y == 0);
	    CPPUNIT_ASSERT(x == y);
	    CPPUNIT_ASSERT(getSign(x) == 0); 
	    CPPUNIT_ASSERT(getSign(y) == 0); 
	    }  
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




    // --------
    // equal_to
    // --------

    void test_equal_to_1 () {
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


    // Makes sure a negative does not equal a positive
    void test_equal_to_2 () {
        try {
            const Integer<int> x = 12345;
            const Integer<int> y = -12345;
            CPPUNIT_ASSERT(      x != y);
            CPPUNIT_ASSERT(      x == 12345);
            CPPUNIT_ASSERT(  12345 == x);
            CPPUNIT_ASSERT(    !(x == y));
            CPPUNIT_ASSERT(    !(x == -12345));
            CPPUNIT_ASSERT(!(-12345 != y));
            CPPUNIT_ASSERT(!(y != -12345));}

        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //Tests equality of 2 zero numbers
    void test_equal_to_3 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 0);
            CPPUNIT_ASSERT(      0 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 0));
            CPPUNIT_ASSERT(    !(0 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}







    // --------
    // less_than
    // --------

    //Dr. Downing's default test: negative < 0
    void test_less_than_1 () {
        try {
            const Integer<int> x = -10;
            const Integer<int> y = 0;
            CPPUNIT_ASSERT(      x < y);
      }
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //Tests less than of two positive integers
    void test_less_than_2 () {
        try {
            const Integer<int> x = 456;
            const Integer<int> y = 457;
            CPPUNIT_ASSERT(      x < y);
            CPPUNIT_ASSERT(    !(y < x));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //Tests less than of two negative integers
    void test_less_than_3 () {
        try {
            const Integer<int> x = -456;
            const Integer<int> y = -457;
            CPPUNIT_ASSERT(      y < x);
	    CPPUNIT_ASSERT(      x < 100);	
	    CPPUNIT_ASSERT(      y < 100);
            CPPUNIT_ASSERT(    !(x < y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




    // --------
    // negation
    // --------

    //Takes negation of a positive
    void test_negation_1 () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // --------
    // negation
    // --------


    //Takes negation of a negative
    void test_negation_2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




    // --------
    // negation
    // --------

    //Takes negation of a zero'th number
    void test_negation_3 () {
        try {
            const Integer<int> x = 0;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == 0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}








    // ------
    // output
    // ------


    //output a positive Integer
    void test_output_1 () {
        try {
            const Integer<int> x = 98765;
            std::ostringstream out;
            out << x;

            CPPUNIT_ASSERT(out.str() == "98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}




    //output a negative Integer
    void test_output_2 () {
        try {
            const Integer<int> x = -98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "-98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    //output an Integer with zero
    void test_output_3 () {
        try {
            const Integer<int> x = 0;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "0");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}


    // ---
    // pow
    // ---

    void test_pow_1 () {


	Integer<int> x = 2;


/*
	std::cout << "POWER!!!:  ";
	x *= 2;
	std::cout << x << " ";
	x *= 2;
	std::cout << x << " ";
	x *= 2;
	std::cout << x << " ";
	x *= 2;
	std::cout << x << " ";
	x *= 2;
	std::cout << x << "\n ";

*/

	const int e = 5;

	const Integer<int> y = pow(x,e);

	CPPUNIT_ASSERT(y == 32);


/*        try {
            Integer<int>       x = 98765;
            const int          e =  9867;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 9867);
            CPPUNIT_ASSERT( x ==    0);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}
*/

	
	}

    void test_pow_2 () {
        try {
            const Integer<int> x = 52;
            const int          e =  5;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 52);
            CPPUNIT_ASSERT(e ==  5);
            CPPUNIT_ASSERT(y ==  380204032);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}



    //Basic tests of get/set mutator/accessor
    void test_get_set_sign_1 () {
	
        Integer<int> x = -98765;
        CPPUNIT_ASSERT(getSign(x) == -1);
	setSign(x, 1);
        CPPUNIT_ASSERT(getSign(x) == 1);

    }



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);


     CPPUNIT_TEST(test_less_than_1);
     CPPUNIT_TEST(test_less_than_2);
     CPPUNIT_TEST(test_less_than_3);


     CPPUNIT_TEST(test_shift_left_digits_1);
     CPPUNIT_TEST(test_shift_left_digits_2);
     CPPUNIT_TEST(test_shift_left_digits_3);

     CPPUNIT_TEST(test_shift_left_equal_1);
     CPPUNIT_TEST(test_shift_left_equal_2);
     CPPUNIT_TEST(test_shift_left_equal_3);
     CPPUNIT_TEST(test_shift_left_equal_4);


     CPPUNIT_TEST(test_shift_right_digits_1);
     CPPUNIT_TEST(test_shift_right_digits_2);
     CPPUNIT_TEST(test_shift_right_digits_3);

     CPPUNIT_TEST(test_shift_right_equal_1);
     CPPUNIT_TEST(test_shift_right_equal_2);
     CPPUNIT_TEST(test_shift_right_equal_3);
     CPPUNIT_TEST(test_shift_right_equal_4);

     CPPUNIT_TEST(test_plus_digits_1);
     CPPUNIT_TEST(test_plus_digits_2);
     CPPUNIT_TEST(test_plus_digits_3); 

     CPPUNIT_TEST(test_plus_equal_1);
     CPPUNIT_TEST(test_plus_equal_2);  //Needs to work with negatives
     CPPUNIT_TEST(test_plus_equal_3);  //needs to work with negatives

     CPPUNIT_TEST(test_divide_equal_1);
     CPPUNIT_TEST(test_divide_equal_2);
     CPPUNIT_TEST(test_divide_equal_3);

     CPPUNIT_TEST(test_minus_equal_1);
     CPPUNIT_TEST(test_minus_equal_2);
     CPPUNIT_TEST(test_minus_equal_3);
     CPPUNIT_TEST(test_minus_equal_4);


     CPPUNIT_TEST(test_minus_digits_1);
     CPPUNIT_TEST(test_minus_digits_2);  //Negative
     CPPUNIT_TEST(test_minus_digits_3);  // 2 negative


     CPPUNIT_TEST(test_multiplies_digits_1);
     CPPUNIT_TEST(test_multiplies_digits_2);
     CPPUNIT_TEST(test_multiplies_digits_3);


     CPPUNIT_TEST(test_times_equal_1);

    CPPUNIT_TEST(test_divides_digits_1);
    CPPUNIT_TEST(test_divides_digits_2);
    CPPUNIT_TEST(test_divides_digits_3);
    CPPUNIT_TEST(test_divides_digits_4);
    CPPUNIT_TEST(test_divides_digits_5);
    CPPUNIT_TEST(test_divides_digits_6);
    CPPUNIT_TEST(test_divides_digits_7);




    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);


    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_abs_3);

    CPPUNIT_TEST(compare_magnitudes_1);
    CPPUNIT_TEST(compare_magnitudes_2);
    CPPUNIT_TEST(compare_magnitudes_3);

    CPPUNIT_TEST(digits_greater_or_equal_1);
    CPPUNIT_TEST(digits_greater_or_equal_2);
    CPPUNIT_TEST(digits_greater_or_equal_3);
    CPPUNIT_TEST(digits_greater_or_equal_4);
    CPPUNIT_TEST(digits_greater_or_equal_5);
    CPPUNIT_TEST(digits_greater_or_equal_6);

    CPPUNIT_TEST(test_equal_to_1);
    CPPUNIT_TEST(test_equal_to_2);
    CPPUNIT_TEST(test_equal_to_3);

    CPPUNIT_TEST(test_get_set_sign_1);


     CPPUNIT_TEST(test_negation_2);
     CPPUNIT_TEST(test_negation_3);


    CPPUNIT_TEST(test_output_1);
    CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);

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
