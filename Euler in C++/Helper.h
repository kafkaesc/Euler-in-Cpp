// Helper.h
// Euler in C++
//
// Created by Jared Hettinger on 11/25/15.
// Copyright © 2015 Openquote Design. All rights reserved.

#ifndef Helper_h
#define Helper_h 

#include <iostream>
#include <Math.h>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>

class Helper {
public:
    // Mathematical calculations
    static int findLargestPrimeFactor(long n);
    static int squareOfSums(int a, int b);
    static int sumOfSquares(int a, int b);
    
    // Testing attributes, bool functions
    static bool checkFactorsWithinRange(int n, int a, int b);
    static bool checkPrimality(long n);
    static bool isPalindrome(long n);
    
    // Array and set manipulation
    static std::vector<int> eliminateRedundantDivisors(int a, int b);
};

#endif /* Helper_h */
