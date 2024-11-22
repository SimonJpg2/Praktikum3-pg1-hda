#include "vertrag.h"
#include <iomanip>
#include <iostream>

float calcKosten(const Eigenschaften& pEigenschaften, const int minute) {
    /*
    * Berechnet die Kosten y, die nach x Minuten entstehen in Bezug auf den jeweiligen Vertrag z.
    *
    * Wenn das Ergebnis negativ ist, bedeutet das, dass keine Kosten enstehen. In diesem Fall wird 0 zurückgegeben,
    * um die späteren Berechnungen nicht zu verfälschen.
    */

    float y = pEigenschaften.grundgebuehr
              + pEigenschaften.preisProWeitereMin * (minute - pEigenschaften.inklusivMinuten);
    return (y < 0 ? 0 : y);
}

int main() {
    // Gegebenen Werte aus der Aufgabe in Array speichern.
    Eigenschaften vertrag[5] =
    {
        // Vertrag 1
        {
            ohneBindung, // Vertrag
            0,           // Grundgebühr
            0,           // Inklusiv-Minuten
            0.1          // Preis je weitere Minute
        },

        // Vertrag 2
        {
            super30,
            5,
            30,
            0.1
        },

        // Vertrag 3
        {
            super50,
            6,
            50,
            0.09
        },

        // Vertrag 4
        {
            super100,
            10,
            100,
            0.08
        },

        // Vertrag 5
        {
            super200,
            15,
            200,
            0.07
        },
    };

    // Ausgabe der Tabelle
    const int n = 15; // Wert für den Abstand => Generierung der Tabelle

    // Ausgabe Vertragsnummer
    std::cout << "Vertrag:" << std::setw(19) << " ";

    for (int i = 0; i < 5; i++)
        std::cout << std::setw(n) << (i+1);
    std::cout << std::endl;

    // Ausgabe der Namen der Verträge
    std::cout
        << std::setw(49)
        << "Ohne Bindung"
        << std::setw(13)
        << "super 30"
        << std::setw(14)
        << "super 50"
        << std::setw(15)
        << "super 100"
        << std::setw(16)
        << "super 200"
        << std::endl;

    /*
    * Die Ausgabe der Grundgebühr, Inklusivminuten, Preis je weitere Minute und die
    * Berechnung der Monatlichen Kosten + dessen Ausgabe erfolgen über Schleifen und
    * den Zugriff auf das C-Array, um die Werte des jeweiligen Vertrags zu verwenden.
    */

    // Ausgabe der Grundgebühr der Verträge
    std::cout << "Grundgebuehr" << std::setw(15) << " ";

    for (int i = 0; i < 5; i++)
        std::cout << std::setw(n) << vertrag[i].grundgebuehr;
    std::cout << std::endl;

    // Ausgabe der Inklusivminuten der Verträge
    std::cout << "Inklusivminuten" << std::setw(12) << " ";

    for (int i = 0; i < 5; i++)
        std::cout << std::setw(n) << vertrag[i].inklusivMinuten;
    std::cout << std::endl;

    // Ausgabe des Preises je weitere Minute
    std::cout << "Preis je weitere Minute" << std::setw(4) << " ";

    for (int i = 0; i < 5; i++)
        std::cout << std::setw(n) << vertrag[i].grundgebuehr;
    std::cout << std::endl << std::endl;

    // Ausgabe der monatlichen Kosten
    for (int i = 10; i <= 250; i+=10) {
        std::cout << "Monatliche Kosten bei " << i << "min";

        for (int j = 0; j < 5; j++)
            std::cout << std::setw(n) << calcKosten(vertrag[j], i);
        std::cout << std::endl;
    }

    return 0;
}
