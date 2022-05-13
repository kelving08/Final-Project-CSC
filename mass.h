#ifndef MASS_H
#define MASS_H

class Mass
{
private:
    double val;

public:
    bool allowNegative;
    enum Unit
    {
        KGS,
        LBS
    };
    double GetMass(Unit u = KGS);
    bool SetMass(double x, Unit u);
    Mass();
    void Input();
    void Display();
};

#endif