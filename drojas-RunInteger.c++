// -------------------------------
// projects/integer/RunInteger.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Integer.h RunInteger.c++ -o RunInteger
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
// includesgit 
// --------

#include <iostream> // cout, endl
#include <deque>    // deque
#include <ctime>
#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    // Acceptance Tests
    // Subtraction
    {
        const Integer<int> n = Integer<int>(1) - 1;
        cout << "1 - 1 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(300) - 5;
        cout << "300 - 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(300) - 20;
        cout << "300 - 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(230) - -5;
        cout << "230 - -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(230) - -20;
        cout << "230 - -20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-530) - 5;
        cout << "-530 - 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-530) - 20;
        cout << "-530 - 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-730) - -30;
        cout << "-730 - -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-730) - -5;
        cout << "-730 - -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-190) - -20;
        cout << "-190 - -20 = " << n << endl;
    }
    std::cout << std::endl;
    // Addition
    {
        const Integer<int> n = Integer<int>(888) + 310;
        cout << "888 + 310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + 15;
        cout << "888 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + 210;
        cout << "888 + 210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + -510;
        cout << "888 + -510 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + -120;
        cout << "888 + -120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + 15;
        cout << "-888 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + 1120;
        cout << "-888 + 1120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + -1130;
        cout << "-888 + -1130 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + -15;
        cout << "-888 + -15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + -2110;
        cout << "-888 + -2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + 3110;
        cout << "888 + 3110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + 115;
        cout << "888 + 115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + 2110;
        cout << "888 + 2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + -5110;
        cout << "888 + -5110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(888) + -1210;
        cout << "888 + -1210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + 115;
        cout << "-888 + 115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + 11120;
        cout << "-888 + 11120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + -11310;
        cout << "-888 + -11310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + -115;
        cout << "-888 + -115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-888) + -21101;
        cout << "-888 + -21101 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + 310;
        cout << "555 + 310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + 15;
        cout << "555 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + 210;
        cout << "555 + 210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + -510;
        cout << "555 + -510 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + -120;
        cout << "555 + -120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + 15;
        cout << "-555 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + 1120;
        cout << "-555 + 1120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + -1130;
        cout << "-555 + -1130 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + -15;
        cout << "-555 + -15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + -2110;
        cout << "-555 + -2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + 3110;
        cout << "555 + 3110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + 115;
        cout << "555 + 115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + 2110;
        cout << "555 + 2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + -5110;
        cout << "555 + -5110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(555) + -1210;
        cout << "555 + -1210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + 115;
        cout << "-555 + 115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + 11120;
        cout << "-555 + 11120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + -11310;
        cout << "-555 + -11310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + -115;
        cout << "-555 + -115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-555) + -21101;
        cout << "-555 + -21101 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + 310;
        cout << "333 + 310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + 15;
        cout << "333 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + 210;
        cout << "333 + 210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + -510;
        cout << "333 + -510 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + -120;
        cout << "333 + -120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + 15;
        cout << "-333 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + 1120;
        cout << "-333 + 1120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + -1130;
        cout << "-333 + -1130 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + -15;
        cout << "-333 + -15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + -2110;
        cout << "-333 + -2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + 3110;
        cout << "333 + 3110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + 115;
        cout << "333 + 115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + 2110;
        cout << "333 + 2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + -5110;
        cout << "333 + -5110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(333) + -1210;
        cout << "333 + -1210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + 115;
        cout << "-333 + 115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + 11120;
        cout << "-333 + 11120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + -11310;
        cout << "-333 + -11310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + -115;
        cout << "-333 + -115 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-333) + -21101;
        cout << "-333 + -21101 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) + 310;
        cout << "23456789 + 310 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) + 15;
        cout << "23456789 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) + 210;
        cout << "23456789 + 210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) + -510;
        cout << "23456789 + -510 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) + -120;
        cout << "23456789 + -120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) + 15;
        cout << "-23456789 + 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) + 1120;
        cout << "-23456789 + 1120 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) + -1130;
        cout << "-23456789 + -1130 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) + -15;
        cout << "-23456789 + -15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) + -2110;
        cout << "-23456789 + -2110 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(9930) + 30;
        cout << "9930 + 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(9930) + 5;
        cout << "9930 + 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(300) + 20;
        cout << "300 + 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(30) + -50;
        cout << "30 + -50 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(190) + -20;
        cout << "190 + -20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-190) + 5;
        cout << "-190 + 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-300) + 20;
        cout << "-300 + 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-300) + -30;
        cout << "-300 + -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-300) + -5;
        cout << "-300 + -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-300) + -20;
        cout << "-300 + -20 = " << n << endl;
    }
    std::cout << std::endl;
    // Multiplication
    {
        const Integer<int> n = Integer<int>(180) * 30;
        cout << "180 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(180) * 5;
        cout << "180 * 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(180) * 20;
        cout << "180 * 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(630) * -5;
        cout << "630 * -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(630) * -20;
        cout << "630 * -20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) * 56;
        cout << "-30 * 56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) * 206;
        cout << "-30 * 206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) * -306;
        cout << "-30 * -306 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) * -56;
        cout << "-30 * -56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) * -206;
        cout << "-30 * -206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1810) * 30;
        cout << "1810 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1810) * 5;
        cout << "1810 * 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1810) * 20;
        cout << "1810 * 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(6310) * -5;
        cout << "6310 * -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(6310) * -20;
        cout << "6310 * -20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * 56;
        cout << "-310 * 56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * 206;
        cout << "-310 * 206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * -306;
        cout << "-310 * -306 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * -56;
        cout << "-310 * -56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * -206;
        cout << "-310 * -206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1180) * 30;
        cout << "1180 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1180) * 5;
        cout << "1180 * 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(183) * 20;
        cout << "183 * 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(633) * -5;
        cout << "633 * -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(633) * -20;
        cout << "633 * -20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-330) * 56;
        cout << "-330 * 56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-330) * 206;
        cout << "-330 * 206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-330) * -306;
        cout << "-330 * -306 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-330) * -56;
        cout << "-330 * -56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-330) * -206;
        cout << "-330 * -206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1830) * 30;
        cout << "1830 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(183) * 5;
        cout << "183 * 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(180) * 210;
        cout << "180 * 210 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(630) * -51;
        cout << "630 * -51 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(630) * -201;
        cout << "630 * -201 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) * 561;
        cout << "-30 * 561 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-301) * 206;
        cout << "-301 * 206 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-301) * -306;
        cout << "-301 * -306 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * -56;
        cout << "-310 * -56 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-310) * -206;
        cout << "-310 * -206 = " << n << endl;
    }
    std::cout << std::endl;
    // Multiplication - Reverse
    {
        const Integer<int> n = Integer<int>(303) * 30;
        cout << "303 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(53) * 30;
        cout << "53 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(203) * 30;
        cout << "203 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-5) * 30;
        cout << "-5 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-20) * 30;
        cout << "-20 * 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(53) * -30;
        cout << "53 * -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(203) * -30;
        cout << "203 * -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-303) * -30;
        cout << "-303 * -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-53) * -30;
        cout << "-53 * -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-230) * -30;
        cout << "-230 * -30 = " << n << endl;
    }
    std::cout << std::endl;
    // Division
    {
        const Integer<int> n = Integer<int>(5) / 5;
        cout << "5 / 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(300) / 5;
        cout << "300 / 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(300) / 20;
        cout << "300 / 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(30) / -5;
        cout << "30 / -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(300) / -20;
        cout << "300 / -20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-300) / 5;
        cout << "-300 / 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-300) / 20;
        cout << "-300 / 20 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) / -30;
        cout << "-30 / -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) / -5;
        cout << "-30 / -5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) / -20;
        cout << "-30 / -20 = " << n << endl;
    }
    std::cout << std::endl;
    // Division - Reverse
    {
        const Integer<int> n = Integer<int>(30) / 30;
        cout << "30 / 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(5) / 30;
        cout << "5 / 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(20) / 30;
        cout << "20 / 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-5) / 30;
        cout << "-5 / 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-20) / 30;
        cout << "-20 / 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(5) / -30;
        cout << "5 / -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(20) / -30;
        cout << "20 / -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-30) / -30;
        cout << "-30 / -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-5) / -30;
        cout << "-5 / -30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-20) / -30;
        cout << "-20 / -30 = " << n << endl;
    }
    std::cout << std::endl;
    // Power - One
    {
        const Integer<int> n = Integer<int>(1).pow(5);
        cout << "1 ^ 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(1);
        cout << "1 ^ 1 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(2);
        cout << "1 ^ 2 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(3);
        cout << "1 ^ 3 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(4);
        cout << "1 ^ 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(5);
        cout << "1 ^ 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(6);
        cout << "1 ^ 6 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(7);
        cout << "1 ^ 7 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(8);
        cout << "1 ^ 8 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(9);
        cout << "1 ^ 9 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(1).pow(30);
        cout << "1 ^ 30 = " << n << endl;
    }
    std::cout << std::endl;
    // Power - Two
    {
        const Integer<int> n = Integer<int>(2).pow(12);
        cout << "2 ^ 12 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(1);
        cout << "2 ^ 1 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(2);
        cout << "2 ^ 2 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(3);
        cout << "2 ^ 3 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(4);
        cout << "2 ^ 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(5);
        cout << "2 ^ 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(6);
        cout << "2 ^ 6 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(7);
        cout << "2 ^ 7 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(8);
        cout << "2 ^ 8 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(9);
        cout << "2 ^ 9 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(30);
        cout << "2 ^ 30 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(10);
        cout << "2 ^ 10 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(11);
        cout << "2 ^ 11 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(21);
        cout << "2 ^ 21 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(31);
        cout << "2 ^ 31 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(14);
        cout << "2 ^ 14 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(15);
        cout << "2 ^ 15 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(16);
        cout << "2 ^ 16 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(17);
        cout << "2 ^ 17 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(18);
        cout << "2 ^ 18 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(2).pow(19);
        cout << "2 ^ 19 = " << n << endl;
    }
    std::cout << std::endl;
    // Power - 147
    {
        const Integer<int> n = Integer<int>(147).pow(2);
        cout << "147 ^ 2 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(1);
        cout << "147 ^ 1 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(2);
        cout << "147 ^ 2 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(3);
        cout << "147 ^ 3 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(4);
        cout << "147 ^ 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(5);
        cout << "147 ^ 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(6);
        cout << "147 ^ 6 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(7);
        cout << "147 ^ 7 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(8);
        cout << "147 ^ 8 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(9);
        cout << "147 ^ 9 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(147).pow(30);
        cout << "147 ^ 30 = " << n << endl;
    }
    std::cout << std::endl;
    // Misc
    {
        const Integer<int> n = Integer<int>(23456789) << 4;
        cout << "23456789 << 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) << 0;
        cout << "23456789 << 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(0) << 4;
        cout << "0 << 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(0) << 0;
        cout << "0 << 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) >> 4;
        cout << "23456789 >> 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789) >> 0;
        cout << "23456789 >> 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(111110) >> 4;
        cout << "111110 >> 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(0) >> 0;
        cout << "0 >> 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) << 4;
        cout << "-23456789 << 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) << 0;
        cout << "-23456789 << 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) >> 4;
        cout << "-23456789 >> 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) >> 5;
        cout << "-23456789 >> 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789) >> 2;
        cout << "-23456789 >> 2 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789);
        cout << "abs(23456789) = " << abs(n) << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789);
        cout << "abs(-23456789) = " << abs(n) << endl;
    }
    {
        const Integer<int> n = Integer<int>(0);
        cout << "abs(0) = " << abs(n) << endl;
    }
    {
        const Integer<int> n = Integer<int>(0) >> 0;
        cout << "0 >> 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-234567896) << 4;
        cout << "-234567896 << 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-234567896) << 0;
        cout << "-234567896 << 0 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-234567896) >> 4;
        cout << "-234567896 >> 4 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-234567896) >> 5;
        cout << "-234567896 >> 5 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-234567896) >> 2;
        cout << "-234567896 >> 2 = " << n << endl;
    }
    {
        const Integer<int> n = Integer<int>(234567896);
        cout << "abs(234567896) = " << abs(n) << endl;
    }
    {
        const Integer<int> n = Integer<int>(-234567896);
        cout << "abs(-234567896) = " << abs(n) << endl;
    }
    {
        const Integer<int> n = Integer<int>(0);
        cout << "abs(0) = " << abs(n) << endl;
    }
    {
        const Integer<int> n = Integer<int>(23456789);
        cout << "negative(23456789) = " << -n << endl;
    }
    {
        const Integer<int> n = Integer<int>(-23456789);
        cout << "negative(-23456789) = " << -n << endl;
    }
    {
        const Integer<int> n = Integer<int>(0);
        cout << "negative(0) = " << -n << endl;
    }
    std::cout << std::endl; 
    cout << "RunInteger.c++" << endl << endl;

    // less than 300 ms without valgrind
    // less than 15 s with valgrind
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

    cout << "Done." << endl;

    return 0;}