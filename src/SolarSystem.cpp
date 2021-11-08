#include"SolarSystem.h"

using namespace std;
// a - mean distance or semi major axis

// e - eccentricity

// T - time at perihelion

// q - perihelion distance = a *(1-e)

// i - inclination, i.e tilt of the orbit relative to the eliptic if > 180 degrees the body moves backwards

// N - longitude of ascending node, angle along the eliptic from the vernal point to the ascending node

// w - the angle from the ascending node tot he perihelion


// PRIMARY ORBITAL ELEMENTS

// q = a*(1-e)

// Q = a*(1+e)

// P (orbital period) = 365.256898326 * a**1.5/sqrt(1+m) days, where m = the mass 
// of the planet in solar masses (0 for comets and asteroids)

// n (daily motion) = 360_deg/P degrees/day

// t some epoch as a day count

// t -T time since perihelion in days

// M - Mean anomaly = n*(t-T) = (t-T)*360_deg/P

// L - Mean longitude = M + w + N

// E - eccentric anomaly M = E - e * sin(E)

// v - true anomaly

// r Heliocentric distance

// x,y,z rectangular coordinates. used when a heliocentric positions hould be converted

// this relation is a valid elliptic orbit:

// r * cos(v) = a * (cos(E) - e)
// r * sin(v) = a * sqrt(1-e*e) * sin(E)
                                       
