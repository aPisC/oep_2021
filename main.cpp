#include "SeasonEnor.hpp"
#include "ActorEnor.hpp"
#include "iostream"

using namespace std;
int main()
{
    // Test enor 1
    /*
    SeasonEnor e1("input.txt");
    for (e1.first(); !e1.end(); e1.next())
    {
        SeasonInfo i = e1.current();
        cout << i.year << " " << i.actor << " " << i.minName << " " << i.minLength << endl;
    }
    */

    // Task 1
    cout << "TASK 1" << endl;
    SeasonEnor e1("input.txt");
    for (e1.first(); !e1.end(); e1.next())
    {
        SeasonInfo i = e1.current();
        if (i.year >= 2005)
            cout << i.year << " " << i.actor << " " << i.minName << " " << i.minLength << endl;
    }

    // Task 2

    cout << endl
         << endl
         << "TASK 2" << endl;
    ActorEnor e2("input.txt");
    int cnt = 0;
    for (e2.first(); !e2.end(); e2.next())
    {
        ActorInfo i = e2.current();
        //cout << i.minLength << " " << i.actor << endl;
        if (i.minLength >= 40)
            cnt++;
    }
    cout << "Szineszek szama: " << cnt << endl;
}