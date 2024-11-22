#pragma once

enum Vertragstypen { ohneBindung, super30, super50, super100, super200 };

struct Eigenschaften {
    // Attribute
    const Vertragstypen vertragstyp;
    const int grundgebuehr;
    const int inklusivMinuten;
    const float preisProWeitereMin;

    // Konstruktor
    Eigenschaften(
        const Vertragstypen pVertragstyp = ohneBindung,
        const int pGrundgebuehr = 0,
        const int pInklusivMinuten = 0,
        const float pPreisProWeitereMin = 0.1
    );
};
