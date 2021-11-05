#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include<vector>
#include"Planets.h"
class SolarSystem{
    public:
        SolarSystem(int year,int month,int day,int hour,int minute);
        void updateSystem(int year,int month,int day,int hour,int minute);
    private:
        Planets planets;
        unsigned short planetStates[];
};


#endif // SOALRSYSTEM_H