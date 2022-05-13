#ifndef PLANET_H
#define PLANET_H

#include "mass.h"
#include "diameter.h"
#include "planetName.h"

class Planet
{
private:
    double G;
    double SurfaceArea;
    double Density;
    double Acceleration;

public:
    Mass mass;
    Diameter diameter;
    PlanetName name;
    bool SetSurfaceArea();
    bool SetDensity();
    bool SetAcceleration();
    double GetSurfaceArea();
    double GetDensity();
    double GetAcceleration();
    Planet();
    void Input();
    void Display();
};

#endif