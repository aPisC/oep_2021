
#include <iostream>
#include <sstream>
#include <string>
#include "./library/stringstreamenumerator.hpp"
#include "./library/seqinfileenumerator.hpp"
#include "./library/maxsearch.hpp"

using namespace std;

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

class MinSeason : public MaxSearch<Season, int, Less<int>>
{

protected:
    virtual int func(const Season &e) const override
    {
        return e.minEpisode.length;
    }

    virtual bool cond(const Season &e) const override { return e.year >= 2005; }
};

int main()
{
    string filename = "input.txt";
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