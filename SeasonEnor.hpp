#pragma once
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct SeasonInfo
{
    int year;
    string actor;
    int minLength;
    string minName;
};

class SeasonEnor
{
private:
    SeasonInfo _current;
    bool _end;
    ifstream _x;

public:
    SeasonEnor(string filename)
    {
        _x.open(filename);
    }

    bool end() { return _end; }

    SeasonInfo current() { return _current; }

    void first()
    {
        next();
    }

    void next()
    {
        string line;
        getline(_x, line);
        if (!(_end = _x.fail()))
        {
            istringstream is(line);
            int l;
            string n;
            is >> _current.year >> _current.actor >> _current.minName >> _current.minLength;
            is >> n >> l;
            while (!is.fail())
            {
                if (_current.minLength > l)
                {
                    _current.minLength = l;
                    _current.minName = n;
                }
                is >> n >> l;
            }
        }
    }
};