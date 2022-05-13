#include <iostream>
#include <string>
#include <cmath>
#include "planet.h"

Planet::Planet()
{
    G = 6.6742E-11;
};

bool Planet::SetSurfaceArea()
{
    SurfaceArea = 4.0 * M_PI * pow(diameter.GetRadius(Diameter::Kilometers), 2.0);
    return true;
};

bool Planet::SetDensity()
{
    double volume = (4.0 / 3.0) * M_PI * pow(diameter.GetRadius(Diameter::Meters), 3.0);
    Density = (mass.GetMass(Mass::KGS) / volume) / 1000;
    return true;
};

bool Planet::SetAcceleration()
{
    Acceleration = (G * mass.GetMass(Mass::KGS)) / pow(diameter.GetRadius(Diameter::Meters), 2.0);
    return true;
};

double Planet::GetSurfaceArea()
{
    return SurfaceArea;
};

double Planet::GetDensity()
{
    return Density;
};

double Planet::GetAcceleration()
{
    return Acceleration;
};

void Planet::Input()
{
    name.Input();
    mass.Input();
    diameter.Input();
};

void Planet::Display()
{
    cout << endl;
    name.Display();
    mass.Display();
    diameter.Display();
    cout.width(32);
    cout.setf(ios::left);
    cout << "Surface Area: ";
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);
    cout << GetSurfaceArea() << "km^2" << endl;
    cout.width(32);
    cout.setf(ios::left);
    cout << "Density: ";
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);
    cout << GetDensity() << "g/cm^3" << endl;
    cout.width(32);
    cout.setf(ios::left);
    cout << "Acceleration due to gravity: ";
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    cout << GetAcceleration() << "m/s^2\n\n";
    for (int i = 0; i < 50; i++)
    {
        cout << "-";
    };
    cout << endl;
};