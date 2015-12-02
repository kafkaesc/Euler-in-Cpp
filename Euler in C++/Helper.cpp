//  Helper.cpp
//  Euler in C++
//
//  Created by Jared Hettinger on 11/25/15.
//  Copyright © 2015 Openquote Design. All rights reserved.

#include "Helper.h"

// Caches vars for eliminatedRedundantDivisors method
static int eliminateRD_aCache = 0;
static int eliminateRD_bCache = 0;
static std::vector<int> eliminateRD_cache;


/* This function checks a range [a, b] and returns true if
 * all integers in that range are factors of n.
 */
bool Helper::checkFactorsWithinRange(int n, int a, int b) {
    if (b / 2 + 1 > a)
        a = b / 2 + 1;
    for(int i = a; i < b; i++)
        if(n % i != 0)
            return false;
    return true;
}

/* Return true if n is prime, false otherwise. */
bool Helper::checkPrimality(long n) {
    // check if even
    if(n % 2 == 0)
        return false;
    
    // check against odds
    for(int i = 3; i*i < n; i += 2)
        if(n % i == 0)
            return false;
    
    return true;
}

/* Not actually useful, here for map, vector, and static var ref */
std::vector<int> Helper::eliminateRedundantDivisors(int a, int b) {
    if(eliminateRD_aCache == a && eliminateRD_bCache == b)
        return eliminateRD_cache;
    
    std::map<int, bool> sieve;
    for(int i = a; i < b + 1; i++)
        sieve[i] = false;
    std::vector<int> output;
    for(int i = a; i < b + 1; i++) {
        if(i == 1)
            i++;
        
        int j = i;
        bool quit = false;
        while(!quit) {
            if(j + i > b) {
                sieve[j] = true;
                quit = true;
            }
            j = j + i;
        }
    }
    for (const auto& pair : sieve) {
        if(pair.second) {
            std::cout << pair.first << ", ";
            output.push_back(pair.first);
        }
    }
    std::cout << std::endl;
    eliminateRD_aCache = a;
    eliminateRD_bCache = b;
    eliminateRD_cache = output;
    return output;
}

/* Returns the largest prime factor of n. */
int Helper::findLargestPrimeFactor(long n) {
    long divisor = sqrt(n);
    std::cout << n << "passed in" << std::endl;
    std::cout << divisor << " sqrt" << std::endl;
    while(divisor > 2) {
        if(n % divisor == 0 && checkPrimality(divisor)) {
            return (int)divisor;
        }
        
        // skip even numbers
        if(divisor % 2 == 0) divisor--;
        else divisor -= 2;
    }
    // returning -1 implies no
    // prime factors could be found
    return -1;
}

/* Returns true if the number is a palindrome. */
bool Helper::isPalindrome(long n) {
    std::string s = std::to_string(n);
    int i = 0;
    int j = (int)s.length() - 1;
    while(i < j && i != j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

/* Summate all numbers in range [a, b], 
 * then return the square of that sum 
 */
int Helper::squareOfSums(int a, int b) {
    int sum = 0;
    for(int i = a; i < b + 1; i++) {
        sum += i;
    }
    return sum * sum;
}
/* Summate and return the squares of the 
 * numbers in range [a, b] 
 */
int Helper::sumOfSquares(int a, int b) {
    int sum = 0;
    for(int i = a; i < b + 1; i++)
        sum += i * i;
    return sum;
}
