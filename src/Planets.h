#ifndef PLANETS_H
#define PLANETS_H
#include<vector>
#include"OrbitalElements.h"

class Planets{
    public:
        Planets(int day);
        ~Planets();
        std::vector<OrbitalElements*> getPlanets();

    private:
        void computePositions(double);

        void jupiterPertubations();
        void saturnPertubations();
        void uranusPertubations();

        void computeMoonOE(double);
        void computeMercuryOE(double);
        void computeVenusOE(double);
        void computeMarsOE(double);
        void computeJupiterOE(double);
        void computeSaturnOE(double);
        void computeUranusOE(double);
        void computeNeptuneOE(double);

        OrbitalElements *mercuryOE;
        OrbitalElements *venusOE;
        OrbitalElements *marsOE;
        OrbitalElements *jupiterOE;
        OrbitalElements *saturnOE;
        OrbitalElements *uranusOE;
        OrbitalElements *neptuneOE;

        std::vector<OrbitalElements*> planets;

        double radians(double x);
        double rev(double x);
        double degrees(double x);




};


#endif // PLANETS_H
