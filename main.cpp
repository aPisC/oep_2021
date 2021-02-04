#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"

using namespace std;

/*
  Feladat:
    Leggyakoribb elem keresése, számlálásba ágyazott megszámolással
    feltehető, hogy legalább 1 eleme van az adatoknak

    Branch-ek:
        - intro: c++ emlékeztető
        - master: alapfeladat (megoldás: m1)
        - f2: kiegészített feladatok (értékek 0 és m között) (megoldás: m2) 
*/

//#define NORMAL_MODE
#ifdef NORMAL_MODE
    int main()
    {
        // file megnyitása, hiba esetén kilépés

        // adatok beolvasása vector-ba

        // leggyakoribb elem megkerestetése
    }
#else
    #include "test.hpp"
#endif

int frequency(const vector<int> &x, int e){
    return 0;
}

int mostFrequented(const vector<int> &x){
    return 0;
}