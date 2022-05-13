#include <iostream>
#include <string>
#include "readValue.h"
#include "readDouble.h"
#include "mass.h"

using namespace std;

Mass::Mass()
{
    val = 0.0;
    allowNegative = false;
}

double Mass::GetMass(Unit u)
{
    double rv;
    if (u == LBS)
    {
        rv = val / 0.45359237;
    }
    else if (u == KGS)
    {
        rv = val;
    }
    return rv;
}

bool Mass::SetMass(double x, Unit u)
{
    if (u == KGS)
    {
        val = x;
    }
    else if (u == LBS)
    {
        val = x * 0.45359237;
    };
    return true; // error check tbd
};

void Mass::Input()
{
    int choice;
    double input;
    Unit u;
    cout << "1. KGS\n2. LBS\n";
    choice = ReadValue<int>("Please, make a selection for the mass unit: ", 1, 2);
    u = (choice == 1) ? KGS : LBS;

    input = ReadDouble("Please, enter the mass of the planet: ", allowNegative);
    SetMass(input, u);
};

void Mass::Display()
{
    cout.width(32);
    cout.setf(ios::left);
    cout << "Mass: ";
    cout << GetMass() << "kgs" << endl;
}