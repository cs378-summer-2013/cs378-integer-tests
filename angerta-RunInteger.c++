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

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "Integer.h"
#include <time.h>

// ----
// main
// ----

int main () {
    using namespace std;
    clock_t t1,t2, t3, t4;
    
    //code goes here
   
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than 15 s with valgrind
    t1 = clock();
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;
   
    {
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cout<<"Time For 20th Mersenne using Vector =  " << seconds << " seconds "<<endl;
    cout << endl;

    //system ("pause");
    t2=clock();
    {
    const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    t3=clock();
    float diff2 ((float)t3-(float)t2);
    float seconds2 = diff2 / CLOCKS_PER_SEC;
    cout<<"Time For 20th Mersenne using deque =  " << seconds2 << " seconds "<<endl;
    cout << endl;



    cout << "*** 25th Mersenne prime: 6,533 digits ***" << endl << endl;
   t1 = clock();
    {
    const Integer<int> n = Integer<int>(2).pow(21701) - 1;
    cout << "2^21701 - 1 = " << n << endl << endl;
    }
    
    t2=clock();
    float diff4 ((float)t2-(float)t1);
    float seconds4 = diff4 / CLOCKS_PER_SEC;
    cout<<"Time For 25th Mersenne using Vector =  " << seconds4 << " seconds "<<endl;
    cout << endl;


    cout << "*** 26th Mersenne prime: 6,987 digits ***" << endl << endl;
   t1 = clock();
    {
    const Integer<int> n = Integer<int>(2).pow(23209) - 1;
    cout << "2^23209 - 1 = " << n << endl << endl;
    }
    
    t2=clock();
    float diff5 ((float)t2-(float)t1);
    float seconds5 = diff5 / CLOCKS_PER_SEC;
    cout<<"Time For 26th Mersenne using Vector =  " << seconds5 << " seconds "<<endl;
    cout << endl;



    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min without valgrind
    // don't run with valgrind

    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;
    t3=clock();
    {
    const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    cout << "2^132049 - 1 = " << n << endl << endl;
    }

    t4=clock();
    float diff3 ((float)t4-(float)t3);
    float seconds3 = diff3 / CLOCKS_PER_SEC;
    cout<<"Bonus: Time For 30th Mersenne using Vector =  " << seconds3 << " seconds "<<endl;




    cout << "Done." << endl;

    return 0;}


