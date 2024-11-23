#include <iostream>
#include "fraction.h"

int main() {
    // local variables!
    Fraction f1;
    Fraction f2;
    Fraction result;

    readFraction(f1);
    readFraction(f2);

    std::cout << std::endl << "Erster Bruch: ";

    printFraction(f1);
    std::cout << std::endl;

    std::cout << "Zweiter Bruch: ";

    printFraction(f2);
    std::cout << std::endl;

    // Addition
    result = add(f1, f2);
    std::cout << std::endl << "Addition: ";
    printFraction(result);
    std::cout << std::endl;

    // Substraktion
    result = subtract(f1, f2);
    std::cout << "Subtraktion: ";
    printFraction(result);
    std::cout << std::endl;

    // Multiplikation
    result = multiply(f1, f2);
    std::cout << "Multiplikation: ";
    printFraction(result);
    std::cout << std::endl;

    // Division
    result = divide(f1, f2);
    std::cout << "Division: ";
    printFraction(result);
    std::cout << std::endl;
    return 0;
}
