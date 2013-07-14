// -------------------------------
// projects/integer/RunInteger.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------------
// Modified by Zachary Lozano
// and Eli Miller
// July 2013
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

//--------
//includes
//--------

#include <iostream> // cout, endl
#include <vector>   // vector
#include <deque>    // deque
#include <time.h>     //time

#include "Integer.h"

//----
//main
//----

int main () {
	using namespace std;
	time_t timer_begin;
	time_t timer_end;
	cout << "RunInteger.c++" << endl;
	cout << "Running on cherry-sour.cs.utexas.edu" << endl << endl;
	Integer<int> x(10);
	Integer<int> y(100);
	y / x;


	//less than 300 ms without valgrind
	//less than  15  s with    valgrind
	cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;
	{
		time(&timer_begin);
		const Integer<int> n = Integer<int>(2).pow(4423) - 1;
		cout << "2^4423 - 1 = " << n << endl << endl;
		time(&timer_end);
		cout << "Performed in " << (timer_end - timer_begin) << " seconds." << endl << endl;
	}



	{
		time(&timer_begin);
		const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
		cout << "2^4423 - 1 = " << n << endl << endl;
		time(&timer_end);
		cout << "Performed in " << (timer_end - timer_begin) << " seconds." << endl << endl;
	}
	//--------------------------
	//extra credit (5 bonus pts)
	//--------------------------

	//less than 4 min without valgrind
	//don't run with valgrind
	cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

	{
		time(&timer_begin);
		const Integer<int> n = Integer<int>(2).pow(132049) - 1;
		cout << "2^132049 - 1 = " << n << endl << endl;
		time(&timer_end);
		cout << "Performed in " << (timer_end - timer_begin) << " seconds." << endl << endl;
	}
	cout << "Done." << endl;
	return 0; }
