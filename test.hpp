#include <vector>
#include "main.h"

using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("0..m hossza 1", "[max]")
{
    vector<int> x = { 0, 0, 0 };
    int e = mostFrequented(x);
    CHECK(0==e);
}

TEST_CASE("0..m hossza 3", "[max]")
{
    vector<int> x = { 2, 0, 2, 1 };
    int e = mostFrequented(x);
    CHECK(2==e);
}

TEST_CASE("0..m eleje a max", "[max]")
{
    vector<int> x = { 0 };
    int e = mostFrequented(x);
    CHECK(0==e);
}

TEST_CASE("0..m vege a max", "[max]")
{
    vector<int> x = { 2 };
    int e = mostFrequented(x);
    CHECK(2==e);
}

TEST_CASE("egyetlen max", "[max]")
{
    vector<int> x = { 2, 0, 0 };
    int e = mostFrequented(x);
    CHECK(0==e);
}

TEST_CASE("tobb max", "[max]")
{
    vector<int> x = { 1, 0 };
    int e = mostFrequented(x);
    bool l = 0==e || 1==e;
    CHECK(l);
}

TEST_CASE("elagazas bal", "[max]")
{
    vector<int> x = { 2, 0, 0 };
    int e = mostFrequented(x);
    CHECK(0==e);
}

TEST_CASE("elagazas jobb", "[max]")
{
    vector<int> x = { 0, 0, 2 };
    int e = mostFrequented(x);
    CHECK(0==e);
}

/* *************************************** */

TEST_CASE("1..n hossza 0", "[count]")
{
    int e = 0;
    vector<int> x;
    int c = frequency(x, e);
    CHECK(0==c);
}

TEST_CASE("1..n hossza 1", "[count]")
{
    int e = 0;
    vector<int> x = { 0 };
    int c = frequency(x, e);
    CHECK(1==c);
}

TEST_CASE("1..n hossza 4", "[count]")
{
    int e = 0;
    vector<int> x = { 0, 0, 0, 0 };
    int c = frequency(x, e);
    CHECK(4==c);
}

TEST_CASE("1..n eleje es vege", "[count]")
{
    int e = 0;
    vector<int> x = { 0,  1, 0 };
    int c = frequency(x, e);
    CHECK(2==c);
}

TEST_CASE("egy sem", "[count]")
{
    int e = 1;
    vector<int> x = { 0, 0, 0, 0 };
    int c = frequency(x, e);
    CHECK(0==c);
}

TEST_CASE("n�h�ny", "[count]")
{
    int e = 0;
    vector<int> x = { 0, 1, 0, 1 };
    int c = frequency(x, e);
    CHECK(2==c);
}

TEST_CASE("�sszes", "[count]")
{
    int e = 0;
    vector<int> x = { 0, 0, 0, 0 };
    int c = frequency(x, e);
    CHECK(4==c);
}