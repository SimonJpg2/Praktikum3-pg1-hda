#include "fraction.h"
#include <iostream>

void printFraction(Fraction& f)
{
    std::cout << f.numerator << "/" << f.denominator;
}

void readFraction(Fraction& f) // Eingabe des Bruchs
{
    int numerator = 0, denominator = 0;

    std::cout << "Zaehler: ";
    std::cin >> numerator;

    do {
        std::cout << "Nenner: ";
        std::cin >> denominator;

        if (denominator == 0)
            std::cout << "Nenner darf nicht null sein!" << std::endl;
    } while (denominator == 0);
    f.denominator = denominator;
    f.numerator = numerator;
    format(f);
}

int gcd(int p, int q) // Berechnung ggT(p, q) mit Euklidischem Algorithmus
{
    while (q != 0)
    {
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
}

void cancel(Fraction& fRef) // Kürzen des Bruchs
{
    int gcdNumDenom = gcd(fRef.numerator, fRef.denominator);
    fRef.numerator /= gcdNumDenom;
    fRef.denominator /= gcdNumDenom;
}

void format(Fraction& fRef) // Bruch formatieren (Aufruf am Ende der vier Grundrechenarten und von readFraction)
{
    cancel(fRef);
    if (fRef.denominator < 0) {
        fRef.numerator = -fRef.numerator;
        fRef.denominator = -fRef.denominator;
    } else if (fRef.denominator == 0) {
        std::cout << "Nenner darf nicht Null sein!" << std::endl;
    }
}

Fraction add(Fraction& f1Ref, Fraction& f2Ref) // Addition zweier Brüche
{
    Fraction result;
    result.numerator = f1Ref.numerator * f2Ref.denominator + f2Ref.numerator * f1Ref.denominator;
    result.denominator = f1Ref.denominator * f2Ref.denominator;

    format(result);
    return result;
}

Fraction subtract(Fraction& f1Ref, Fraction& f2Ref) // Subtraktion zweier Brüche
{
    Fraction result;
    result.numerator = f1Ref.numerator * f2Ref.denominator - f2Ref.numerator * f1Ref.denominator;
    result.denominator = f1Ref.denominator * f2Ref.denominator;

    format(result);
    return result;
}

Fraction multiply(Fraction& f1Ref, Fraction& f2Ref) // Multiplikation zweier Brüche
{
    Fraction result;
    result.numerator = f1Ref.numerator * f2Ref.numerator;
    result.denominator = f1Ref.denominator * f2Ref.denominator;

    format(result);
    return result;
}

Fraction divide(Fraction& f1Ref, Fraction& f2Ref) // Divison zweier Brüche
{
    Fraction result;
    result.numerator = f1Ref.numerator * f2Ref.denominator;
    result.denominator = f1Ref.denominator * f2Ref.numerator;

    format(result);
    return result;
}
