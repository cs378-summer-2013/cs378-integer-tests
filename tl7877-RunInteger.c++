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
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
% doxygen Doxyfile
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque> // deque

#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than 15 s with valgrind
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    cout << "*** 14th Mersenne prime: 183 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(607) - 1;
    cout << "2^607 - 1 = " << n << endl << endl;
    }

    cout << "*** 3rd Mersenne prime: 2 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(5) - 1;
    cout << "2^5 - 1 = " << n << endl << endl;
    }

    cout << "*** 21st Mersenne prime: 2917 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(9689) - 1;
    cout << "2^9689 - 1 = " << n << endl << endl;
    }

    cout << "*** 7th Mersenne prime: 6 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(19) - 1;
    cout << "2^19 - 1 = " << n << endl << endl;
    }

    {
    Integer<int> n = 1;
    for( int i = 0; i < 1000; i++ ) {
       n += n;
    }
    cout << "n += n 1000 times = " << n << endl << endl; 
    }



    return 0;}
