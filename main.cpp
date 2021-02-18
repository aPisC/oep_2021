#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"

using namespace std;

bool search(const Circle &cir, const vector<Point> &t, unsigned int &ind);
void FillInFromFile(const string &str, Circle &c, vector<Point> &t);

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    Circle cir;
    vector<Point> t;
    FillInFromFile("input.txt", cir, t);

    unsigned int ind;
    if (search(cir, t, ind))
        cout << "A " << t[ind] << " koordinataju pont a " << cir << " korbe esik\n";
    else
        cout << "Egyik pont sincs a korben\n";

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Test cases of linear search

TEST_CASE("empty sequence", "[search]")
{
    ifstream f("input0.txt");
    REQUIRE(!f.fail());
    Circle cir;
    vector<Point> t;
    FillInFromFile("input0.txt", cir, t);

    unsigned int ind;
    bool l = search(cir, t, ind);
    CHECK(!l);
}

TEST_CASE("one inner point", "[search]")
{
    ifstream f("input1.txt");
    REQUIRE(!f.fail());
    Circle cir;
    vector<Point> t;
    FillInFromFile("input1.txt", cir, t);

    unsigned int ind;
    bool l = search(cir, t, ind);
    CHECK(l);
    CHECK(ind == 0);
}

TEST_CASE("one outer point", "[search]")
{
    ifstream f("input2.txt");
    REQUIRE(!f.fail());
    Circle cir;
    vector<Point> t;
    FillInFromFile("input2.txt", cir, t);

    unsigned int ind;
    bool l = search(cir, t, ind);
    CHECK(!l);
}

TEST_CASE("last inner point", "[search]")
{
    ifstream f("input3.txt");
    REQUIRE(!f.fail());
    Circle cir;
    vector<Point> t;
    FillInFromFile("input3.txt", cir, t);

    unsigned int ind;
    bool l = search(cir, t, ind);
    CHECK(l);
    CHECK(ind == 2);
}

// Test cases of class Point

TEST_CASE("distance", "[point]")
{
    Point p1(0.0, 1.0);
    Point p2(1.0, 0.0);

    CHECK(p1.distance(p2) == sqrt(2));
}

// Test cases of class Circle

TEST_CASE("contains", "[circle]")
{
    Circle c(Point(0.0, 0.0), 0.0);

    CHECK(c.contains(Point(0.0, 0.0)));
}

#endif

bool search(const Circle &cir, const vector<Point> &t, unsigned int &ind)
{
    bool l = false;
    for (unsigned int i = 0; !l && i < t.size(); ++i)
    {
        l = cir.contains(t[i]);
        ind = i;
    }
    return l;
}

void FillInFromFile(const string &str, Circle &cir, vector<Point> &t)
{
    ifstream f(str.c_str());
    if (f.fail())
        cout << "Hibas fajl nev!\n";

    double c;
    Point p;
    f >> p >> c;
    Circle x(p, c);
    cir = x;

    while (f >> p)
    {
        t.push_back(p);
    }
}
