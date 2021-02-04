#pragma once
#include <vector>

using namespace std;

// vissza adja, hogy hányszor fordul elő a vektorban a keresett elem
int frequency(const vector<int> &x, int e);

//  maximum keresést végez az adatokon az előbbi függvényt használva
int mostFrequented( int m, const vector<int> &x);