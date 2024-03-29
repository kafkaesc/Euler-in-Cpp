//  BasicSolution.cpp
//  Euler in C++
//
//  Created by Jared Hettinger on 11/25/15.
//  Copyright © 2015 Openquote Design. All rights reserved.

#include <stdio.h>
#include "BasicSolution.h"
#include "Helper.h"


/* Project Euler, problem #1
 *
 * If we list all the natural numbers below 10 that
 * are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

 int BasicSolution::problem1() {
    int sum = 0;
    for(int i = 0; i < 1000; i++)
        if(i % 3 == 0 || i % 5 == 0)
            sum+= i;
    return sum;
}

/* Project Euler, problem #2
 *
 * Each new term in the Fibonacci sequence is generated by
 * adding the previous two terms. By starting with 1 and 2,
 * the first 10 terms will be:
 *                 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values
 * do not exceed four million, find the sum of the even-valued terms.
 */
int BasicSolution::problem2() {
    int fib_1 = 1;
    int fib_2 = 2;
    int fib_current = 3;
    int sum = 2;
    
    while(fib_current < 4000000) {
        if(fib_current % 2 == 0)
            sum += fib_current;
        
        fib_1 = fib_2;
        fib_2 = fib_current;
        fib_current = fib_1 + fib_2;
    }
    return sum;
}

/* Project Euler, problem #3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 */
int BasicSolution::problem3() {
    long given = 600851475143;
    return Helper::findLargestPrimeFactor(given);
}

/* Project Euler, problem #4
 *
 * A palindromic number reads the same both ways. The largest
 * palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
int BasicSolution::problem4() {
    int largest_palindrome = 0;
    // Nested loops are an eyesore, BUT, these loops
    // are constant and therefore the Big O for the
    // function is still O(1)
    for(int i = 999; i > 99; i--) {
        for(int j = 999; j > 99; j--) {
            int temp = i * j;
            if(Helper::isPalindrome(temp) && temp > largest_palindrome)
                largest_palindrome = temp;
        }
    }
    return largest_palindrome;
}

/* Project Euler, problem #5
 *
 * 2520 is the smallest number that can be divided
 * by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly
 * divisible by all of the numbers from 1 to 20?
 */
int BasicSolution::problem5() {
    int i =   20;
    bool found = false;
    while(!found) {
        if(Helper::checkFactorsWithinRange(i, 1, 20)) {
            found = true;
            return i;
        }
        // skip odd numbers
        i += 2;
    }
    // returning -1 implies the method
    // failed to find a solution
    return -1;
}

/* Project Euler, problem #6
 *
 * The sum of the squares of the first ten natural numbers is,
 *     1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 *     (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of
 * the first ten natural numbers and the square of the sum is
 * 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the
 * first one hundred natural numbers and the square of the sum.
 */
int BasicSolution::problem6() {
    return Helper::squareOfSums(1, 100) - Helper::sumOfSquares(1, 100);
}

int BasicSolution::problem7() {
    Helper::eliminateRedundantDivisors(1, 20);
    return -1;
}