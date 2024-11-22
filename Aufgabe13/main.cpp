#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
void insertValue(std::vector<T>& vec, const T& input) {
    std::cout << "Das Element wurde dem Vektor hinzugefügt." << std::endl;
    vec.push_back(input);
}

template<typename T>
void printValue(const std::vector<T>& vec) {
    if (vec.empty()) {
        std::cout << "Es wurden keine Werte eingegeben." << std::endl;
        return;
    }
    std::cout << "Folgende Werte sind Bestandteil des Vektors:" << std::endl;

    for (const auto& value : vec)
        std::cout << value << std::endl;
}

template<typename T>
void searchValue(const std::vector<T>& vec, const T& element) {
    if (vec.empty()) {
        std::cout << "Der Vektor hat keine Elemente und demnach ist das Element auch nicht enthalten."
                  << std::endl;
        return;
    }

    std::cout
        <<
        (
            std::find(vec.begin(), vec.end(), element) != vec.end()
            ? "Element befindet sich im Vektor"
            : "Element befindet sich nicht im Vektor."
        )
    << std::endl;
}

template<typename T>
bool isSorted(const std::vector<T>& vec) {
    // Alternativ auch mit return std::is_sorted(vec.begin(), vec.end());
    for (std::size_t i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1])
            return false;
    return true;
}

int main() {
    char input = ' ';
    char input_datatype = ' ';

    std::string input_s = " ";
    int input_i = 0;
    float input_f = 0.0;

    std::string searchElement_s = " ";
    int searchElement_i = 0;
    float searchElement_f = 0.0;

    std::vector<std::string> vec_s;
    std::vector<int> vec_i;
    std::vector<float> vec_f;

    do {
        std::cout << "Werte verwalten- Auswahl" << std::endl;
        std::cout
            << "    (1) Werte eingeben\n"
            << "    (2) Werte ausgeben\n"
            << "    (3) Wert suchen\n"
            << "    (4) Auf Sortierung pruefen\n"
            << "    (x) Ende\n"
            << std::endl;

        std::cin >> input;

        switch(input) {
            case '1':
                std::cout << "Soll ein String (s), integer (i) oder float (f) eingeben werden? ";
                std::cin >> input_datatype;

                if (input_datatype == 's') {
                    std::cout << "Nachfolgend den String eingeben: " ;
                    std::cin >> input_s;
                    insertValue(vec_s, input_s);
                } else if (input_datatype == 'i') {
                    std::cout << "Nachfolgend den integer eingeben: ";
                    std::cin >> input_i;
                    insertValue(vec_i, input_i);
                } else if(input_datatype == 'f') {
                    std::cout << "Nachfolgend den float eingeben: ";
                    std::cin >> input_f;
                    insertValue(vec_f, input_f);
                } else {
                    std::cout << "Eingabe wird nicht zugelassen." << std::endl;
                }
                break;

            case '2':
                switch (input_datatype) {
                    case 's': printValue(vec_s); break;
                    case 'i': printValue(vec_i); break;
                    case 'f': printValue(vec_f); break;
                    default: std::cout << "Zuerst einen Wert eingeben." << std::endl;
                }
                break;

            case '3':
                switch (input_datatype) {
                    case 's':
                        std::cout << "String für die Suche eingeben: ";
                        std::cin >> searchElement_s;
                        searchValue(vec_s, searchElement_s); break;
                    case 'i':
                            std::cout << "Integer für die Suche eingeben: ";
                            std::cin >> searchElement_i;
                            searchValue(vec_i, searchElement_i); break;
                    case 'f':
                            std::cout << "Float für die Suche eingeben: ";
                            std::cin >> searchElement_f;
                            searchValue(vec_f, searchElement_f); break;
                    default: std::cout << "Zuerst einen Wert eingeben." << std::endl;
                }
                break;

            case '4':
                switch (input_datatype) {
                    case 's': std::cout << (isSorted(vec_s) ? "String Vektor ist sortiert" : "String Vektor ist nicht sortiert") << std::endl; break;
                    case 'i': std::cout << (isSorted(vec_i) ? "Integer Vektor ist sortiert" : "String Vektor ist nicht sortiert") << std::endl; break;
                    case 'f': std::cout << (isSorted(vec_f) ? "Float Vektor ist sortiert" : "String Vektor ist nicht sortiert") << std::endl; break;
                    default: std::cout << "Zuerst einen Wert eingeben." << std::endl;
                }
                break;

            case 'x': std::cout << "Programm beendet." << std::endl; break;
            default: std::cout << "Falsche Eingabe!" << std::endl;
        }
    } while (input != 'x');
    return 0;
}
