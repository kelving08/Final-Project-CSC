#ifndef DIAMETER_H
#define DIAMETER_H

class Diameter
{
private:
    double val;
    double radius;

public:
    bool allowNegative;
    enum Unit
    {
        Kilometers,
        Miles,
        Meters
    };
    double GetRadius(Unit u = Kilometers);
    bool SetRadius(double x);
    double GetDiameter(Unit u = Kilometers);
    bool SetDiameter(double x, Unit u);
    Diameter();
    void Input();
    void Display();
};

#endif