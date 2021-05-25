
#include <iostream>
#include <sstream>
#include <string>
#include "./library/stringstreamenumerator.hpp"
#include "./library/seqinfileenumerator.hpp"
#include "./library/maxsearch.hpp"
#include "./library/summation.hpp"
#include "./library/enumerator.hpp"
#include "./library/counting.hpp"

using namespace std;

// Base classes
struct Episode
{
    string name;
    int length;
};

istream &operator>>(istream &is, Episode &e)
{
    is >> e.name >> e.length;
}

class MinEpisode : public MaxSearch<Episode, int, Less<int>>
{
protected:
    virtual int func(const Episode &e) const override
    {
        return e.length;
    }
};

struct Season
{
    int year;
    string actor;
    Episode minEpisode;
};

istream &operator>>(istream &is, Season &s)
{
    string line;
    if (getline(is, line))
    {
        stringstream ss(line);

        ss >> s.year >> s.actor;

        StringStreamEnumerator<Episode> enor(ss);
        MinEpisode pr;

        pr.addEnumerator(&enor);
        pr.run();
        if (!pr.found())
            s.minEpisode.length = 0;
        else
            s.minEpisode = pr.optElem();
    }
    return is;
}

// Task1 classes

class MinSeason : public MaxSearch<Season, int, Less<int>>
{

protected:
    virtual int func(const Season &e) const override
    {
        return e.minEpisode.length;
    }

    virtual bool cond(const Season &e) const override { return e.year >= 2005; }
};

// Task 2 classes

struct Actor
{
    string name;
    bool goodActor;
};

class GoodActorSum : public Summation<Season, bool>
{
private:
    string _name;

public:
    GoodActorSum(string name) : _name(name) {}

protected:
    virtual bool func(const Season &e) const override
    {
        return e.minEpisode.length >= 40;
    }
    virtual bool neutral() const override
    {
        return true;
    }
    virtual bool add(const bool &a, const bool &b) const override
    {
        return a && b;
    }
    virtual void first() override {}
    virtual bool whileCond(const Season &current) const override
    {
        return current.actor == _name;
    }
};

class ActorEnor : public Enumerator<Actor>
{
private:
    SeqInFileEnumerator<Season> _t;
    bool _end;
    Actor _current;

public:
    ActorEnor(string &fn) : _t(fn) {}
    virtual void first() override
    {
        _t.first();
        next();
    }
    virtual void next() override
    {
        if (!(_end = _t.end()))
        {
            _current.name = _t.current().actor;
            GoodActorSum pr(_current.name);
            pr.addEnumerator(&_t);
            pr.run();
            _current.goodActor = pr.result();
        }
    }
    virtual bool end() const override
    {
        return _end;
    }
    virtual Actor current() const override
    {
        return _current;
    }
};

class GoodActorCount : public Counting<Actor>
{
protected:
    virtual bool cond(const Actor &e) const { return e.goodActor; }
};

int main()
{
    string filename = "input.txt";
    {
        SeqInFileEnumerator<Season> enor(filename);

        /*
    // Season enor test
    for (enor.first(); !enor.end(); enor.next())
    {
        cout << enor.current().minEpisode.name << " "
             << enor.current().minEpisode.length << " "
             << enor.current().year << endl;
    }*/

        MinSeason pr1;
        pr1.addEnumerator(&enor);
        pr1.run();

        if (pr1.found())
            cout << pr1.optElem().minEpisode.name << " "
                 << pr1.optElem().minEpisode.length << " "
                 << pr1.optElem().year << endl;
        else
            cout << "nem volt megfelelő elem" << endl;
    }
    {
        ActorEnor enor(filename);

        /*
        //test ActorEnor
        for (enor.first(); !enor.end(); enor.next())
        {
            cout << enor.current().name << " "
                 << (enor.current().goodActor
                         ? 1
                         : 0)
                 << endl;
        }*/

        GoodActorCount pr;
        pr.addEnumerator(&enor);
        pr.run();

        cout << "Szineszek szama: " << pr.result() << endl;
    }
}