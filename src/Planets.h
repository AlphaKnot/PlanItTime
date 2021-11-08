#ifndef PLANETS_H
#define PLANETS_H
#include<vector>
#include"OrbitalElements.h"
class Planets{
    public:
        Planets(int day);

    private:
        void computePositions(double);
        OrbitalElements computeMoonOE(double);
        OrbitalElements computeMercuryOE(double);
        OrbitalElements computeVenusOE(double);
        OrbitalElements computeMarsOE(double);
        OrbitalElements computeJupiterOE(double);
        OrbitalElements computeSaturnOE(double);
        OrbitalElements computeUranusOE(double);
        OrbitalElements computeNeptuneOE(double);

};


#endif // PLANETS_H
