// -------------------------------
// cs378-integer/src/RunInteger.c++
// Copyright (C) 2013
// CS w378 C++ STL w/ Dr. Downing
// Summer 2013
// Kevin Tran
// -------------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Integer.c++ RunInteger.c++ -o RunInteger
    % valgrind RunInteger > RunInteger.out

To configure Doxygen:
    % doxygen -g
That creates the file "Doxyfile".
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque>    // deque

#include "Integer.h"
#include <ctime>


// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;

    const int a[] = {1, 3, 2, 6, 7, 8};
    const int b[] = {5, 6, 7};
    const int c[] = {2, 3, 4};
    int x[10];
    const int* p = divides_digits(a, a + 6, b, b + 3, x);

    // less than 300 ms without valgrind
    // less than  15  s with    valgrind

    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

	clock_t start = clock();
    {
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }
	clock_t finish = clock();
	cout << "Time: " << ((finish - start) / (double) CLOCKS_PER_SEC) << endl;



//    {
//    const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
//    std::cout << "2^4423 - 1 = " << n << std::endl << std::endl;
//    }

    cout << "*** 10th Mersenne prime: 27 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(89) - 1;
    cout << "2^89 - 1 = " << n << endl << endl;
    }

    cout << "*** 4th Mersenne prime: 3 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(7) - 1;
    cout << "2^7 - 1 = " << n << endl << endl;
    }

    cout << "*** 25th Mersenne prime: 6533 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(21701) - 1;
    cout << "2^21701 - 1 = " << n << endl << endl;
    }





    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min without valgrind
    // don't run with valgrind

    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

	start = clock();
    {
    const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    cout << "2^132049 - 1 = " << n << endl << endl;
    }
	finish = clock();
	cout << "Time: " << ((finish - start) / (double) CLOCKS_PER_SEC) << endl;

    cout << "Done." << endl;

    return 0;}
