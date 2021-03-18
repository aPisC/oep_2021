#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct Sik
{
    int length;
    double avg;
};

class SikEnor
{
private:
    enum Status
    {
        NORM,
        ABNORM
    };

    // Beolvasas kezeles
    Status _st;
    int _e;
    ifstream _x;
    void read();

    // Enor mukodes
    Sik _item;
    bool _end;

public:
    SikEnor(string filename)
    {
        _x.open(filename.c_str());
    }
    void first();
    void next();
    bool end() { return _end; }
    Sik current() { return _item; }
};

void SikEnor::read()
{
    _x >> _e;
    _st = _x.fail() ? ABNORM : NORM;
}

void SikEnor::next()
{
    if (_st == ABNORM)
    {
        _end = true;
        return;
    }
    int cnt = 1;
    int sum = _e;
    int prev = _e;
    read();

    while (_st != ABNORM && prev - _e < 10 && _e - prev < 10)
    {
        cnt++;
        sum += _e;
        read();
    }

    _item.length = cnt;
    _item.avg = 1.0 * sum / cnt;
}

void SikEnor::first()
{
    read(); // kezdő érték beolvasása e-be
    next();
}