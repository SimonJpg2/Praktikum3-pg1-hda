#pragma once

typedef struct {
    int numerator;
    int denominator;
} Fraction;

void printFraction(Fraction& f); // Ausgabe des Bruchs
void readFraction(Fraction& f); // Eingabe des Bruchs
int gcd(int p, int q); // Berechnung größter gemeinsamer Teiler
void cancel(Fraction& fRef); // Kürzen des Bruchs
void format(Fraction& fRef); // Formatieren des Bruchs (kein Minus im Nenner)
Fraction add(Fraction& f1Ref, Fraction& f2Ref); // Addition zweier Brüche
Fraction subtract(Fraction& f1Ref, Fraction& f2Ref); // Subtraktion zweier Brüche
Fraction multiply(Fraction& f1Ref, Fraction& f2Ref); // Multiplikation zweier Brüche
Fraction divide(Fraction& f1Ref, Fraction& f2Ref); // Divison zweier Brüche
