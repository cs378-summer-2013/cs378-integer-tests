// -------------------------------
// projects/integer/RunInteger.c++
// Copyright (C) 2013
// Glenn P. Downing
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

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than  15  s with    valgrind
    
        
    {
    cout << "First Test Case: 4th Mersenne prime, 3 digits" << endl << endl;
    const Integer<int> n = Integer<int>(2).pow(7) - 1;
    cout << "2^7 - 1 = " << n << endl << endl;
    }
    
    {
    cout << "Second Test Case: 9th Mersenne prime, 19 digits" << endl << endl;
    const Integer<int> n = Integer<int>(2).pow(61) - 1;
    cout << "2^61 - 1 = " << n << endl << endl;
    }
    
    {
    cout << "Third Test Case: 12th Mersenne prime, 39 digits" << endl << endl;
    const Integer<int> n = Integer<int>(2).pow(127) - 1;
    cout << "2^127 - 1 = " << n << endl << endl;
    }
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

    
    {
    cout << "First calculation." << endl << endl;
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    }

    {
    cout << "Second calculation." << endl << endl;
    const Integer< int, std::vector<int> > n = Integer< int, std::vector<int> >(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min without valgrind
    // don't run with valgrind
    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    cout << "2^132049 - 1 = " << n << endl << endl;
    }

    cout << "Done." << endl;

    return 0;}
