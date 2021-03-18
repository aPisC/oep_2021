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

public:
    SikEnor(string filename)
    {
        _x.open(filename.c_str());
    }
    void first();
    void next();
    bool end();
    Sik current() { return _item; }
};

void SikEnor::read()
{
}

void SikEnor::next()
{
}

void SikEnor::first()
{
}