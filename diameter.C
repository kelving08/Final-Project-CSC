#include <iostream>
#include <string>
#include "diameter.h"
#include "readValue.h"
#include "readDouble.h"

using namespace std;

Diameter::Diameter()
{
    val = 0.0;
    allowNegative = false;
}

double Diameter::GetDiameter(Unit u)
{
    double rv;
    if (u == Meters)
    {
        rv = val * 1000;
    }
    else if (u == Miles)
    {
        rv = val / 1.609344;
    }
    else if (u == Kilometers)
    {
        rv = val;
    }
    return rv;
}

bool Diameter::SetDiameter(double x, Unit u)
{
    if (u == Kilometers)
    {
        val = x;
    }
    else if (u == Miles)
    {
        val = x * 1.609344;
    }
    else if (u == Meters)
    {
        val = x / 1000;
    };
    return true; // error check tbd
};

bool Diameter::SetRadius(double x)
{
    radius = x / 2;
    return true;
};

double Diameter::GetRadius(Unit u)
{
    double rv;
    if (u == Meters)
    {
        rv = radius * 1000;
    }
    else if (u == Miles)
    {
        rv = radius / 1.609344;
    }
    else if (u == Kilometers)
    {
        rv = radius;
    }
    return rv;
};

void Diameter::Input()
{
    int choice;
    double input;
    Unit u;
    cout << "1. Meters\n2. Kilometer\n3. Miles\n";
    choice = ReadValue<int>("Please, make a selection for the diameter unit: ", 1, 3);
    switch (choice)
    {
    case 1:
    {
        u = Meters;
    }
    break;
    case 2:
    {
        u = Kilometers;
    }
    break;
    case 3:
    {
        u = Miles;
    }
    break;
    }
    input = ReadDouble("Please, enter the diameter of the planet: ", allowNegative);
    SetDiameter(input, u);
    SetRadius(GetDiameter());
};

void Diameter::Display()
{
    cout.width(32);
    cout.setf(ios::left);
    cout << "Diameter: ";
    cout << GetDiameter() << "km" << endl;
}