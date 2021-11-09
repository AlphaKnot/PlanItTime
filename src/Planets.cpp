#include"Planets.h"
#include<math.h>
#include<iostream>
#include<string>


Planets::Planets(int day){
    computePositions(day);
}
std::vector<OrbitalElements> Planets::getPlanets(){
    return planets;
}
void Planets::computePositions(double day){


    OrbitalElements mercuryOE = computeMercuryOE(day);
    OrbitalElements venusOE = computeVenusOE(day);
    OrbitalElements marsOE = computeMarsOE(day);
    OrbitalElements jupiterOE = computeJupiterOE(day);
    OrbitalElements saturnOE = computeSaturnOE(day);
    OrbitalElements uranusOE = computeUranusOE(day);
    OrbitalElements neptuneOE = computeNeptuneOE(day);

  
    jupiterPertubations(jupiterOE,saturnOE);

    // testing
    mercuryOE.printOrbitalElements("Mercury");
    venusOE.printOrbitalElements("Venus");
    marsOE.printOrbitalElements("Mars");
    jupiterOE.printOrbitalElements("Jupiter");
    saturnOE.printOrbitalElements("Saturn");
    uranusOE.printOrbitalElements("Uranus");
    neptuneOE.printOrbitalElements("Neptune");

    planets.push_back(mercuryOE);
    planets.push_back(venusOE);
    planets.push_back(marsOE);
    planets.push_back(jupiterOE);
    planets.push_back(saturnOE);
    planets.push_back(uranusOE);
    planets.push_back(neptuneOE);

}
void Planets::jupiterPertubations(OrbitalElements jupiterOE, OrbitalElements saturnOE){


    double added_long = 0;

    double Mj = jupiterOE.getMeanAnom();
    double Ms = saturnOE.getMeanAnom();
    
    added_long += -0.332 * sin(radians(2*Mj - 5*Ms - 67.6));
    added_long += -0.056 * sin(radians(2*Mj - 2*Ms + 21));
    added_long += +0.042 * sin(radians(3*Mj - 5*Ms + 21));
    added_long += -0.036 * sin(radians(Mj - 2*Ms));
    added_long += +0.022 * cos(radians(Mj - Ms));
    added_long += +0.023 * sin(radians(2*Mj - 3*Ms + 52));
    added_long += -0.016 * sin(radians(Mj - 5*Ms - 69));
    
    jupiterOE.setLong(jupiterOE.getLong() + added_long);


}
void Planets::saturnPertubations(){

}
void Planets::uranusPertubations(){

} 
OrbitalElements Planets::computeMercuryOE(double day){
    double asc_node = 48.3313 + (3.24587E-5*day);
    double incl = 7.0047 + (5.00E-8*day);
    double arg = 29.1241 + (1.01444E-5*day);
    double axis = 0.387098;
    double eccen = 0.205635 + (5.59E-10*day);
    double mean_anon = 168.6562+(4.0923344368*day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);

}
OrbitalElements Planets::computeVenusOE(double day){
    double asc_node = 76.6799 + (2.46590E-5*day);
    double incl = 3.3946 + (2.75E-8*day);
    double arg = 54.8910 + (1.38374E-5*day);
    double axis = 0.723330;
    double eccen = 0.006773 - (1.302E-9*day);
    double mean_anon = 48.0052+(1.6021302244*day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);
}
OrbitalElements Planets::computeMarsOE(double day){
    double asc_node = 49.5574 + (2.11081E-5*day);
    double incl = 1.8497 - (1.78E-8*day);
    double arg = 286.5016 + (2.92961E-5*day);
    double axis = 1.523688;
    double eccen = 0.093405 + (2.516E-9 * day);
    double mean_anon = 18.6021 + (0.5240207766 * day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);

}
OrbitalElements Planets::computeJupiterOE(double day){
    double asc_node = 100.4542 + (2.76854E-5*day);
    double incl = 1.3030 - (1.557E-7*day);
    double arg = 273.8777 + (1.64505E-5*day);
    double axis = 5.20256;
    double eccen = 0.048498 + (4.469E-9 * day);
    double mean_anon = 19.8950 + (0.0830853001 * day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);

}
OrbitalElements Planets::computeSaturnOE(double day){
    double asc_node = 113.6634 + (2.38980E-5*day);
    double incl = 2.4886 - (1.081E-7*day);
    double arg = 339.3939 + (2.97661E-5*day);
    double axis = 9.55475;
    double eccen = 0.055546 - (9.499E-9 * day);
    double mean_anon = 316.9670 + (0.0334442282 * day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);
}
OrbitalElements Planets::computeUranusOE(double day){
    double asc_node = 74.0005 + (1.3978E-5*day);
    double incl = 0.7733 + (1.9E-8*day);
    double arg = 96.6612 + (3.0565E-5*day);
    double axis = 19.18171 - (1.55E-8*day);
    double eccen = 0.047318 + (7.45E-9 * day);
    double mean_anon = 142.5905 + (0.011725806 * day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);

}
OrbitalElements Planets::computeNeptuneOE(double day){
    double asc_node = 131.7806 + (3.0173E-5*day);
    double incl = 1.7700 - (2.55E-7*day);
    double arg = 272.8461 - (6.027E-6*day);
    double axis = 30.05826 + (3.313E-8*day);
    double eccen = 0.008606 + (2.15E-9 * day);
    double mean_anon = 260.2471 + (0.005995147 * day);

    return OrbitalElements(asc_node,incl,arg,axis,eccen,mean_anon);
}
double Planets::radians(double x){
    return x*PI/180;
}

