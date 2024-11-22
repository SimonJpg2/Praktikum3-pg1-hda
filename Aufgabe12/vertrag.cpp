#include "vertrag.h"

// Konstruktor
Eigenschaften::Eigenschaften
    ( // Params
        const Vertragstypen pVertragstyp,
        const int pGrundgebuehr,
        const int pInklusivMinuten,
        const float pPreisProWeitereMin
    ) // Initialization list
    :   vertragstyp(pVertragstyp),
        grundgebuehr(pGrundgebuehr),
        inklusivMinuten(pInklusivMinuten),
        preisProWeitereMin(pPreisProWeitereMin)
{ // empty body
}
