#include <iostream>
#include <string>
#include <cctype>
#include "readValue.h"
#include "planetName.h"

using namespace std;

PlanetName::PlanetName()
{
    name = "";
};

string PlanetName::Normalize(string input)
{
    string nameChecked;
    nameChecked += toupper(input[0]);
    for (int i = 1; i < input.length(); i++)
    {
        nameChecked += tolower(input[i]);
    };
    return nameChecked;
};

string PlanetName::GetPlanetName()
{
    return name;
};

bool PlanetName::SetPlanetName(string input)
{
    name = Normalize(input);
    return true; // Error check tbd
};

void PlanetName::Input()
{
    SetPlanetName(ReadValue<string>("Please, enter the name of the planet: "));
};

void PlanetName::Display()
{
    cout.width(33);
    cout.setf(ios::left);
    cout << "\nPlanet Name: ";
    cout << GetPlanetName() << endl;
};