#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include<vector>
#include"Planets.h"
class SolarSystem{
    public:
        SolarSystem(int year,int month,int day,int hour,int minute);
        ~SolarSystem();
        void initSystem(int current_day);
        void updateSystem(int year,int month,int day,int hour,int minute);

    private:
        double current_day;
        Planets* planets;
        double computeCurrentDay(int year, int month, int day, int hour, int minute);
};


#endif // SOALRSYSTEM_H