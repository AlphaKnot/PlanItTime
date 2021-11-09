#include"SolarSystem.h"
#include<iostream>

using namespace std;
SolarSystem::SolarSystem(int year, int month, int day, int hour, int minute){
    current_day = computeCurrentDay(year,month,day,hour,minute);
    planetData = Planets(current_day).getPlanets();
}
void SolarSystem::updateSystem(int year, int month, int day, int hour, int minute){
    current_day = computeCurrentDay(year,month,day,hour,minute);
    planetData = Planets(current_day).getPlanets();
}
double SolarSystem::computeCurrentDay (int year, int month, int day, int hour, int minute){
    return 367*year - 7 * ( year + (month+9)/12 ) / 4 - 3 * ( (year + (month-9)/7 ) / 100 + 1 ) / 4 + 275*month/9 + day - 730515;
}

                                       
