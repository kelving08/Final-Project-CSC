#ifndef PLANETNAME_H
#define PLANETNAME_H
#include <string>

using namespace std;

class PlanetName
{
private:
    string name;
    string Normalize(string input);

public:
    bool SetPlanetName(string name);
    string GetPlanetName();
    PlanetName();
    void Input();
    void Display();
};

#endif