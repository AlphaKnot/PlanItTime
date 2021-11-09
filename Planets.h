#ifndef PLANETS_H
#define PLANETS_H
#include<vector>
#include"OrbitalElements.h"

class Planets{
    public:
        Planets(int day);
        std::vector<OrbitalElements> getPlanets();

    private:
        void computePositions(double);

        void pertubations(OrbitalElements* jupiterOE, OrbitalElements* saturnOE, OrbitalElements* uranusOE);


        OrbitalElements computeMercuryOE(double);
        OrbitalElements computeVenusOE(double);
        OrbitalElements computeEarthOE(double);
        OrbitalElements computeMarsOE(double);
        OrbitalElements computeJupiterOE(double);
        OrbitalElements computeSaturnOE(double);
        OrbitalElements computeUranusOE(double);
        OrbitalElements computeNeptuneOE(double);


        std::vector<OrbitalElements> planets;

        double radians(double x);
        double rev(double x);
        double degrees(double x);




};


#endif // PLANETS_H
