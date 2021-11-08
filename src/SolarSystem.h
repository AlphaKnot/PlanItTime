#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include<vector>
#include"Planets.h"
class SolarSystem{
    public:
        SolarSystem(int m_year,int m_month,int m_day,int m_hour,int m_minute);
        void updateSystem(int year,int month,int day,int hour,int minute);

    private:
        Planets planets;
        double time_scale;
        void computeTimeScale(int year, int month, int day, int hour, int minute);
};


#endif // SOALRSYSTEM_H