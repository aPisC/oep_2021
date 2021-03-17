#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct Item
{
    int e;
    int a;
    int k;

    bool isHorpadas()
    {
        return e > a && a < k;
    }
};

class HorpadEnor
{
private:
    Item _item;
    ifstream _f;

public:
    HorpadEnor(string filename)
    {
        _f.open(filename.c_str());
    }
    void first();
    void next();
    bool end() { return _f.fail(); }
    Item current() { return _item; }
};

void HorpadEnor::next()
{
    _item.e = _item.a;
    _item.a = _item.k;
    _f >> _item.k;
}

void HorpadEnor::first()
{
    _f >> _item.e >> _item.a >> _item.k;
}