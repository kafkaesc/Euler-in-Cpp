//  main.cpp
//  Euler in C++
//
//  Created by Jared Hettinger on 11/25/15.

#include <iostream>
#include "BasicSolution.h"

int main(int argc, const char * argv[]) {
    bool continueAnswering = true;
    while(continueAnswering) {
        std::cout << "Which Project Euler solution do you want to run? ";
        int command = 0;
        std::cin >> command;
        std::cout << std::endl << std::endl;
        while(command < 1 || command > 10) {
            std::cout << "Please enter a number in range: ";
            std::cin >> command;
            std::cout << std::endl << std::endl;
        }
        switch(command) {
            case 1: std::cout << BasicSolution::problem1(); break;
            case 2: std::cout << BasicSolution::problem2(); break;
            case 3: std::cout << BasicSolution::problem3(); break;
            case 4: std::cout << BasicSolution::problem4(); break;
            case 5: std::cout << BasicSolution::problem5(); break;
            case 6: std::cout << BasicSolution::problem6(); break;
            case 7: std::cout << BasicSolution::problem7(); break;
        }
        std::cout << std::endl << std::endl;
        std::cout << "Do you want to continue? (Y/N): ";
        std::string s;
        std::cin >> s;
        if(s[0] == 'N' || s[0] == 'n')
            continueAnswering = false;
    }
    return 0;
}
