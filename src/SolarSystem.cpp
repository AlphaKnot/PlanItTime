#include"SolarSystem.h"

using namespace std;
SolarSystem::SolarSystem(int year, int month, int day, int hour, int minute){
    double current_day = computeCurrentDay(year,month,day,hour,minute);
    planets = Planets(current_day);
}
double SolarSystem::computeCurrentDay (int year, int month, int day, int hour, int minute){
    return 367*year - 7 * ( year + (month+9)/12 ) / 4 - 3 * ( (year + (month-9)/7 ) / 100 + 1 ) / 4 + 275*month/9 + day - 730515;
}
int main(int argc, char const *argv[]){
    SolarSystem s = SolarSystem(1990,4,19,0,0);
    
    return 0;
}

                                       
