/* UT EID : davismc2 */

/******************************************************************************
 * Program: C378 Project 3 - Integer
 * Student: Merrill Davis
 * CS Server ID: davismc
 * Class: CS 378
 * Summer 2013
 *
 * Purpose: a program to implement an arbitrary-precision integer class and
 *  to compute the 20th Mersenne prime.
 *
 *****************************************************************************/

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
#include <string>	// string

#include "Integer.h"

bool op_read (std::istream& r, Integer<int>& lhs, Integer<int>& rhs, std::string& op, Integer<int>& ans) {
    std::string lhs_t;
	std::string rhs_t;
	std::string ans_t;
	r >> lhs_t;
	lhs = lhs_t.c_str();
    if (!r)
        return false;
    r >> rhs_t;
	rhs = rhs_t.c_str();
	if (!r)
		return false;
	r >> op;
	if (!r)
		return false;
	r >> ans_t;
	ans = ans_t.c_str();
	if (!r)
		return false;
    return true;}

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than  15  s with    valgrind
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;

    {
    	const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    	cout << "2^4423 - 1 = " << n << endl << endl;
    }

    {
    	const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
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

    //cout << "Done." << endl;

    // --------------------------
    // Acceptance Tests
    // --------------------------
	int test_num = 0;
	int pass = 0;
	int fail = 0;
	const int MAX_TESTS = 5000;
	std::cout << "***************** GENERATING RANDOM TESTS *****************" << std::endl;
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 99999 - (rand() % 99999);
		long long right = rand() % 99999 - (rand() % 99999);
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs + rhs;
		Integer<int> other_result = (left + right);
		std::cout << "Test #" << test_num << ": " << lhs << " + " << rhs << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " + " << right << " = " << left+right;
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	}

	// Subtraction
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 99999 - (rand() % 99999);
		long long right = rand() % 99999 - (rand() % 99999);
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs - rhs;
		Integer<int> other_result = (left - right);
		std::cout << "Test #" << test_num << ": " << lhs << " - " << rhs << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " - " << right << " = " << left - right;
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	}

	// Multiplication
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 9999 - (rand() % 9999);
		long long right = rand() % 9999 - (rand() % 9999);
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs * rhs;
		Integer<int> other_result = (left * right);
		std::cout << "Test #" << test_num << ": " << lhs << " * " << rhs << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " * " << right << " = " << left*right;
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	}

	// Division
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 99999 - (rand() % 99999);
		long long right = rand() % 99999 - (rand() % 99999);
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs / rhs;
		Integer<int> other_result = (left / right);
		std::cout << "Test #" << test_num << ": " << lhs << " / " << rhs << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " / " << right << " = " << left / right;
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	} 

	// Mod
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 99999 - (rand() % 99999);
		long long right = rand() % 99999 - (rand() % 99999);
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs % rhs;
		Integer<int> other_result = (left % right);
		std::cout << "Test #" << test_num << ": " << lhs << " % " << rhs << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " % " << right << " = " << left % right;
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	} 

	// Shift Right
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 99999 - (rand() % 99999);
		long long right = rand() % 20;
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs >> right;
		Integer<int> other_result = (left / (std::pow(10, right)));
		std::cout << "Test #" << test_num << ": " << lhs << " >> " << right << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " >> " << right << " = " << (long) (left / (std::pow(10, right)));
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	} 

	// Shift Left
	for (int i = 0; i < MAX_TESTS; ++i){
		long long left = rand() % 9999 - (rand() % 9999);
		long long right = rand() % 5;
		Integer<int> lhs = left;
		Integer<int> rhs = right;
		Integer<int> result = lhs << right;
		Integer<int> other_result = (left * (std::pow(10, right)));
		std::cout << "Test #" << test_num << ": " << lhs << " << " << right << " = ";
		std::cout << result << " Calculated with Base Types: " << left << " << " << right << " = " << (long) (left * (std::pow(10, right))) << " " << other_result;
		if (other_result == result){
			std::cout << "  PASS" << std::endl;
			++pass;
		}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	} 

	std::cout << std::endl << "***************** LOADING BIG INTEGER TESTS FROM FILE *****************" << std::endl;
	std::cout << "**** Expects input from console.  Use 'RunInteger < RunInteger.in > RunInteger.out'";

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

	Integer<int> lhs;
	Integer<int> rhs;
	std::string op;
	Integer<int> ans;
	bool passed;
	while (op_read(cin, lhs, rhs, op, ans)) {
		if (op == "+"){
			Integer<int> result = lhs + rhs;
			std::cout << "Test #" << test_num << ": " << lhs << " + " << rhs << " = ";
			std::cout << result << " Calculated with Java BigInt: " << lhs << " + " << rhs << " = " << ans;
			passed = (result == ans);
		}
		else if (op == "-"){
			Integer<int> result = lhs - rhs;
			std::cout << "Test #" << test_num << ": " << lhs << " - " << rhs << " = ";
			std::cout << result << " Calculated with Java BigInt: " << lhs << " - " << rhs << " = " << ans;
			passed = (result == ans);
		}
		else if (op == "/"){
			Integer<int> result = lhs / rhs;
			std::cout << "Test #" << test_num << ": " << lhs << " / " << rhs << " = ";
			std::cout << result << " Calculated with Java BigInt: " << lhs << " / " << rhs << " = " << ans;
			passed = (result == ans);
		}
		else if (op == "*"){
			Integer<int> result = lhs * rhs;
			std::cout << "Test #" << test_num << ": " << lhs << " * " << rhs << " = ";
			std::cout << result << " Calculated with Java BigInt: " << lhs << " * " << rhs << " = " << ans;
			passed = (result == ans);
		}
		else if (op == "%"){
			Integer<int> result = lhs % rhs;
			std::cout << "Test #" << test_num << ": " << lhs << " % " << rhs << " = ";
			std::cout << result << " Calculated with Java BigInt: " << lhs << " % " << rhs << " = " << ans;
			passed = (result == ans);
		}

		if (passed){
				std::cout << "  PASS" << std::endl;
				++pass;
			}
		else {
			std::cout << "  FAIL" << std::endl;
			++fail;
		}
		++test_num;
	}


	std::cout << std::endl << "TOTAL TESTS PASSED: " << pass << std::endl;
	std::cout << "TOTAL TESTS FAILED: " << fail << std::endl;

    return 0;}
