#include"Planets.h"
#include<math.h>
#include<iostream>
// a planet moves a certain number of degrees in a certain ammount of time
// obviously a planet closer to the sun will move more in a given time than a planet further away
// so it's really just a list of values with a transition function

Planets::Planets(int year, int month, int day, int hour, int minute){
    day = computeCurrentDay(year,month,day,hour,minute);
    computePositions(day);

}
void Planets::updatePlanets(int year, int month, int day, int hour, int minute){
    day = computeCurrentDay(year,month,day,hour,minute);
    computePositions(day);

}
void Planets::computePositions(double day){
    OrbitalElements mercuryOE = computeMercuryOE(day);
    OrbitalElements venusOE = computeVenusOE(day);
    OrbitalElements marsOE = computeMarsOE(day);
    OrbitalElements jupiterOE = computeJupiterOE(day);
    OrbitalElements saturnOE = computeSaturnOE(day);
    OrbitalElements uranusOE = computeUranusOE(day);
    OrbitalElements neptuneOE = computeNeptuneOE(day);

    std::cout << "Mercury: " <<
        mercuryOE.getAscNode() << " " <<
        mercuryOE.getIncl() << " " <<
        mercuryOE.getArg() << " " <<
        mercuryOE.getAxis() << " " <<
        mercuryOE.getEccen() << " " <<
        mercuryOE.getMeanAnon() << 
        "\n";
    
    std::cout <<  "Venus: " <<
        venusOE.getAscNode() << " " <<
        venusOE.getIncl() << " " <<
        venusOE.getArg() << " " <<
        venusOE.getAxis() << " " <<
        venusOE.getEccen() << " " <<
        venusOE.getMeanAnon() << 
        "\n";

    std::cout << "Mars: " <<
        marsOE.getAscNode() << " " <<
        marsOE.getIncl() << " " <<
        marsOE.getArg() << " " <<
        marsOE.getAxis() << " " <<
        marsOE.getEccen() << " " <<
        marsOE.getMeanAnon() << 
        "\n";
    
    std::cout << "Jupiter: " <<
        jupiterOE.getAscNode() << " " <<
        jupiterOE.getIncl() << " " <<
        jupiterOE.getArg() << " " <<
        jupiterOE.getAxis() << " " <<
        jupiterOE.getEccen() << " " <<
        jupiterOE.getMeanAnon() << 
        "\n";

    std::cout <<  "Saturn: " <<
        saturnOE.getAscNode() << " " <<
        saturnOE.getIncl() << " " <<
        saturnOE.getArg() << " " <<
        saturnOE.getAxis() << " " <<
        saturnOE.getEccen() << " " <<
        saturnOE.getMeanAnon() << 
        "\n";

    std::cout << "Uranus: " <<
        uranusOE.getAscNode() << " " <<
        uranusOE.getIncl() << " " <<
        uranusOE.getArg() << " " <<
        uranusOE.getAxis() << " " <<
        uranusOE.getEccen() << " " <<
        uranusOE.getMeanAnon() << 
        "\n";
    
    std::cout << "Neptune: " <<
        neptuneOE.getAscNode() << " " <<
        neptuneOE.getIncl() << " " <<
        neptuneOE.getArg() << " " <<
        neptuneOE.getAxis() << " " <<
        neptuneOE.getEccen() << " " <<
        neptuneOE.getMeanAnon() << 
        "\n";
}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements 
 * Mercury:

    N =  48.3313_deg + 3.24587E-5_deg   * d    (Long of asc. node)
    i =   7.0047_deg + 5.00E-8_deg      * d    (Inclination)
    w =  29.1241_deg + 1.01444E-5_deg   * d    (Argument of perihelion)
    a = 0.387098                               (Semi-major axis)
    e = 0.205635     + 5.59E-10         * d    (Eccentricity)
    M = 168.6562_deg + 4.0923344368_deg * d    (Mean anonaly)
 */
OrbitalElements Planets::computeMercuryOE(double day){
    double asc_node = 48.3313 + (3.24587E-5*day);
    double incl = 7.0047 + (5.00E-8*day);
    double arg = 29.1241 + (1.01444E-5*day);
    double axis = 0.387098;
    double eccen = 0.205635 + (5.59E-10*day);
    double mean_anon = 168.6562+(4.0923344368*day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));

}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements
 * Venus:

    N =  76.6799_deg + 2.46590E-5_deg   * d
    i =   3.3946_deg + 2.75E-8_deg      * d
    w =  54.8910_deg + 1.38374E-5_deg   * d
    a = 0.723330
    e = 0.006773     - 1.302E-9         * d
    M =  48.0052_deg + 1.6021302244_deg * d 
 */
OrbitalElements Planets::computeVenusOE(double day){
    double asc_node = 76.6799 + (2.46590E-5*day);
    double incl = 3.3946 + (2.75E-8*day);
    double arg = 54.8910 + (1.38374E-5*day);
    double axis = 0.723330;
    double eccen = 0.006773 - (1.302E-9*day);
    double mean_anon = 48.0052+(1.6021302244*day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));
}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements 
 * Mars:

    N =  49.5574_deg + 2.11081E-5_deg   * d
    i =   1.8497_deg - 1.78E-8_deg      * d
    w = 286.5016_deg + 2.92961E-5_deg   * d
    a = 1.523688
    e = 0.093405     + 2.516E-9         * d
    M =  18.6021_deg + 0.5240207766_deg * d
 */
OrbitalElements Planets::computeMarsOE(double day){
    double asc_node = 49.5574 + (2.11081E-5*day);
    double incl = 1.8497 - (1.78E-8*day);
    double arg = 286.5016 + (2.92961E-5*day);
    double axis = 1.523688;
    double eccen = 0.093405 + (2.516E-9 * day);
    double mean_anon = 18.6021 + (0.5240207766 * day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));

}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements 
 * Jupiter:

    N = 100.4542_deg + 2.76854E-5_deg   * d
    i =   1.3030_deg - 1.557E-7_deg     * d
    w = 273.8777_deg + 1.64505E-5_deg   * d
    a = 5.20256
    e = 0.048498     + 4.469E-9         * d
    M =  19.8950_deg + 0.0830853001_deg * d

 */
OrbitalElements Planets::computeJupiterOE(double day){
    double asc_node = 100.4542 + (2.76854E-5*day);
    double incl = 1.3030 - (1.557E-7*day);
    double arg = 273.8777 + (1.64505E-5*day);
    double axis = 5.20256;
    double eccen = 0.048498 + (4.469E-9 * day);
    double mean_anon = 19.8950 + (0.0830853001 * day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));

}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements 
 * Saturn:

    N = 113.6634_deg + 2.38980E-5_deg   * d
    i =   2.4886_deg - 1.081E-7_deg     * d
    w = 339.3939_deg + 2.97661E-5_deg   * d
    a = 9.55475
    e = 0.055546     - 9.499E-9         * d
    M = 316.9670_deg + 0.0334442282_deg * d
 */
OrbitalElements Planets::computeSaturnOE(double day){
    double asc_node = 113.6634 + (2.38980E-5*day);
    double incl = 2.4886 - (1.081E-7*day);
    double arg = 339.3939 + (2.97661E-5*day);
    double axis = 9.55475;
    double eccen = 0.055546 - (9.499E-9 * day);
    double mean_anon = 316.9670 + (0.0334442282 * day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));
}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements 
 * Uranus:

    N =  74.0005_deg + 1.3978E-5_deg    * d
    i =   0.7733_deg + 1.9E-8_deg       * d
    w =  96.6612_deg + 3.0565E-5_deg    * d
    a = 19.18171     - 1.55E-8          * d
    e = 0.047318     + 7.45E-9          * d
    M = 142.5905_deg + 0.011725806_deg  * d
 */
OrbitalElements Planets::computeUranusOE(double day){
    double asc_node = 74.0005 + (1.3978E-5*day);
    double incl = 0.7733 + (1.9E-8*day);
    double arg = 96.6612 + (3.0565E-5*day);
    double axis = 19.18171 - (1.55E-8*day);
    double eccen = 0.047318 + (7.45E-9 * day);
    double mean_anon = 142.5905 + (0.011725806 * day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));

}
/**
 * @brief 
 * 
 * @param day 
 * @return OrbitalElements 
 * Neptune:

    N = 131.7806_deg + 3.0173E-5_deg    * d
    i =   1.7700_deg - 2.55E-7_deg      * d
    w = 272.8461_deg - 6.027E-6_deg     * d
    a = 30.05826     + 3.313E-8         * d
    e = 0.008606     + 2.15E-9          * d
    M = 260.2471_deg + 0.005995147_deg  * d
 */
OrbitalElements Planets::computeNeptuneOE(double day){
    double asc_node = 131.7806 + (3.0173E-5*day);
    double incl = 1.7700 - (2.55E-7*day);
    double arg = 272.8461 - (6.027E-6*day);
    double axis = 30.05826 + (3.313E-8*day);
    double eccen = 0.008606 + (2.15E-9 * day);
    double mean_anon = 260.2471 + (0.005995147 * day);

    return OrbitalElements(rev(asc_node),rev(incl),rev(arg),rev(axis),rev(eccen),rev(mean_anon));
}
double Planets::rev(double value){
    return value - floor(value/360.0)*360.0;
}
double Planets::computeCurrentDay (int year, int month, int day, int hour, int minute){
    return 367*year - 7 * ( year + (month+9)/12 ) / 4 - 3 * ( (year + (month-9)/7 ) / 100 + 1 ) / 4 + 275*month/9 + day - 730515;
}
int main(int argc, char const *argv[]){
    Planets p = Planets(1990,4,19,0,0);
    
    return 0;
}

