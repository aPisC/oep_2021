#include <iostream>
#include "SikEnor.hpp"

using namespace std;

int main()
{
    SikEnor t("input.txt");
    t.first();

    while (!t.end())
    {
        cout << t.current().avg << endl;
        t.next();
    }
}
