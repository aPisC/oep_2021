#include <iostream>
#include "HorpadEnor.hpp"

using namespace std;

int main()
{
    HorpadEnor t("input.txt");

    bool l = false;
    Item max;

    t.first();
    while (!t.end())
    {
        if (t.current().isHorpadas() && (!l || max.a < t.current().a))
        {
            l = true;
            max = t.current();
        }
        t.next();
    }

    if (!l)
        cout << "Nem talaltam horpadast" << endl;
    else
        cout << "Legmagasabb horpadas: " << max.a << endl;
}
