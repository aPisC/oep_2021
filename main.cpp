#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"

using namespace std;

/*
  Feladat:
    Leggyakoribb elem keresése, számlálásba ágyazott megszámolással
    feltehető, hogy legalább 1 eleme van az adatoknak
*/

#define NORMAL_MODE
#ifdef NORMAL_MODE
    int main()
    {
        // file megnyitása, hiba esetén kilépés
        ifstream f( "input.txt" );
        if(f.fail()){
            cout << "Wrong file name!\n";
            return 1;
        }

        // adatok beolvasása vector-ba 
        vector<int> x;
        int e;
        while(f >> e) {
            x.push_back(e);
        }

        // leggyakoribb elem megkerestetése
        if(x.size()==0) cout << "Üres input\n";
        else cout << "Leggyakoribb elem: " << mostFrequented(x) << endl;

        return 0;
    }
#else
    #include "test.hpp"
#endif

int frequency(const vector<int> &x, int e){
    int cnt = 0;
    for(unsigned int i = 0; i < x.size(); i++){
        if(x[i] == e) cnt++;
    }
    return cnt;
}

int mostFrequented(const vector<int> &x){
    unsigned int mfi = 0;
    int mfc = frequency(x, x[0]);

    for(unsigned int i = 1; i < x.size(); i++){
        int c = frequency(x, x[i]);
        if(c > mfc) {
            mfi = i;
            mfc = c;
        }
    }
    return x[mfi];
}