#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include<vector>
#include"Planets.h"
#include"OrbitalElements.h"
class SolarSystem{
    public:
        SolarSystem(int year,int month,int day,int hour,int minute);
        void updateSystem(int year,int month,int day,int hour,int minute);
        std::vector<OrbitalElements> getPlanetData();

    private:
        double current_day;
        double computeCurrentDay(int year, int month, int day, int hour, int minute);
        std::vector<OrbitalElements> planetData;
};


#endif // SOALRSYSTEM_H
