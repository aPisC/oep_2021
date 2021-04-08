#pragma once
#include <string>
#include "SeasonEnor.hpp"

using namespace std;

struct ActorInfo
{
    string actor;
    int minLength;
};

class ActorEnor
{
private:
    ActorInfo _current;
    bool _end;
    SeasonEnor _x;

public:
    ActorEnor(string filename) : _x(filename)
    {
    }

    bool end() { return _end; }

    ActorInfo current() { return _current; }

    void first()
    {
        _x.first();
        next();
    }

    void next()
    {
        if (!(_end = _x.end()))
        {
            _current.actor = _x.current().actor;
            _current.minLength = _x.current().minLength;
            _x.next();
            while (!_x.end() && _x.current().actor == _current.actor)
            {
                if (_x.current().minLength < _current.minLength)
                    _current.minLength = _x.current().minLength;
                _x.next();
            }
        }
    }
};