#include <iostream>
#include "SikEnor.hpp"

using namespace std;

// Leghosszabb sík keresése, milyen magas ez a sík?
//  Síknak tekintjük azt az egybefüggő szakaszt,
//  ahol az egymást követő magasságok eltérése 10nél kisebb

int main()
{
    bool l = false;
    Sik max;

    SikEnor t("input.txt");
    t.first();

    while (!t.end())
    {
        cout << "Vizsgalt sik: " << t.current().length << " " << t.current().avg << endl;
        if (!l || t.current().length > max.length)
        {
            l = true;
            max = t.current();
        }
        t.next();
    }

    if (!l)
        cout << "Nem volt sik" << endl;
    else
        cout << "Leghosszabb sik " << max.length << " hosszu es magassaga: " << max.avg << endl;
}
