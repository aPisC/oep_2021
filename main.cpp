#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"

using namespace std;

bool search(const Circle& cir, const vector<Point> &t, unsigned int &ind);

int main()
{
    ifstream f("input.txt");
    if(f.fail()) cout << "Hibas fajl nev!\n";

    double a, b, c;
    f >> a >> b >> c;
    Circle cir(Point(a,b),c);

    vector<Point> t;
    while(f >> a >> b){
        t.push_back(Point(a,b));
    }

    unsigned int ind;
        if(search(cir, t, ind))
        cout << "A (" << t[ind]._x << "," << t[ind]._y << ") koordinataju pont a korbe esik\n";
    else cout << "Egyik pont sincs a korben\n";

    return 0;
}

bool search(const Circle& cir, const vector<Point> &t, unsigned int &ind)
{
    bool l = false;
    for(unsigned int i=0; !l && i<t.size(); ++i)
    {
        l = cir.contains(t[i]);
        ind = i;
    }
    return l;
}
