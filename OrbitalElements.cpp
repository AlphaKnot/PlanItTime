/**
 *@author Nathan Halsey
 *@brief data store for orbital elements.
 * Used within planets to separate some of the computation and logic
*/

#include"OrbitalElements.h"
#include<iostream>
#include<math.h>

/**
 * @brief  Constructor for obrital elements.
 *
 *  Sets up the Orbital elements for a planet and calls compute coordinates to create the x and y coordinates of the planet
 *
 * @param asc_node the value of this Planets ascending node
 * @param incl the value of this Planet's inclination
 * @param arg the argument of this planet
 * @param axis the major axis of this planet
 * @param eccen the eccentricity of this planet
 * @param mean_anon the mean anomaly for this planet
 * @param radius the radius of this planet from the sun
 */
OrbitalElements::OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon, double radius){

    m_asc_node = rev(asc_node);
    m_incl = rev(incl);
    m_arg = rev(arg);
    m_axis = rev(axis);
    m_eccen = rev(eccen);
    m_mean_anon = rev(mean_anon);
    m_radius = radius;

    if (asc_node != 0){ // then this is not earth
        computeCoordinates();
    } else {
        computeCoordinatesEarth(); // decidely earth, use earth computing method
    }


}
/**
 * @brief Computes x and y coordinate of a planet.
 * Given a radius that we choose, we compute the x and y coordinates of the planet.
 * Basically some crazy hardcoded math follows.
 */
void OrbitalElements::computeCoordinates(){


    double eccentric_anomaly = computeEccentricAnomaly(10); // we compute the eccentric_anomaly

    eccentric_anomaly = rev(eccentric_anomaly); // rev normalizes the value to being within 0,360

    double rect_x = m_axis*(cos(radians(eccentric_anomaly))-m_eccen);
    double rect_y = m_axis*sqrt(1-m_eccen*m_eccen)*sin(radians(eccentric_anomaly));

    double radius = sqrt(pow(rect_x,2)+pow(rect_y,2));
    double true_anomaly = atan2(radians(rect_y),radians(rect_x));

    true_anomaly = degrees(true_anomaly);
    true_anomaly = rev(true_anomaly);

    m_eclip_x = radius * (cos(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))-sin(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    m_eclip_y = radius * (sin(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))+cos(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    m_eclip_z = radius * sin(radians(true_anomaly+m_arg))*sin(radians(m_incl));


    // long is some angle between 0 and 360 degrees, which here represents the angle from the sun as origin
    m_long = atan2(radians(m_eclip_y),radians(m_eclip_x));
    m_long = degrees(m_long);
    m_long = rev(m_long);


    // lat is the upward angle
    m_lat = atan2(radians(m_eclip_z),radians(sqrt(pow(m_eclip_x,2) + pow(m_eclip_y,2))));
    m_lat = degrees(m_lat);


    // as you can see, we never change m_radius, so we use it to find the new x and y coordinates
    m_eclip_x = m_radius*cos(radians(m_long))*cos(radians(m_lat));
    m_eclip_y = m_radius*sin(radians(m_long))*cos(radians(m_lat));



}
/**
 * @brief Computes earth's coordinates.
 * Earth and the other planets are different, this is because I couldn't find the orbital elements of earth
 * that met what I needed to do the same calculations as the other planets.
 * The answer? Calculate the position of the sun wrt earth, then flip everything so that we have the position of the earth
 * with respect to the sun
 */
void OrbitalElements::computeCoordinatesEarth(){

    double eccentric_anomaly = computeEccentricAnomaly(10);

    eccentric_anomaly = rev(eccentric_anomaly);

    double rect_x = m_axis*(cos(radians(eccentric_anomaly))-m_eccen);
    double rect_y = m_axis*sqrt(1-m_eccen*m_eccen)*sin(radians(eccentric_anomaly));

    double true_anomaly = atan2(radians(rect_y),radians(rect_x));

    true_anomaly = degrees(true_anomaly);
    true_anomaly = rev(true_anomaly);

    m_long = true_anomaly+m_arg;

    m_long = rev(m_long-180);

    // m_radius unchanged, so we just setthis manually and compute new x,y coords
    m_eclip_x = m_radius*cos(radians(m_long));
    m_eclip_y = m_radius*sin(radians(m_long));
    m_eclip_z = 0;

    m_lat = 0;


}
/**
 * @brief Computes the eccentric anomaly.
 * @param itr Number of iterations to perform
 * @return the eccentric anomaly
 */
double OrbitalElements::computeEccentricAnomaly(int itr){


    double previous = m_mean_anon + (180/PI) * m_eccen * sin(radians(m_mean_anon)) * (1+m_eccen*cos(radians(m_mean_anon)));
    double current = previous - (previous - (180/PI) * m_eccen * sin(radians(previous))-m_mean_anon)/(1-m_eccen * cos(radians(previous)));
    // at this point, 1 iteration is already done

    int count = 0;
    while (abs(current - previous) < 0.005 && count < itr){ // we set a threshold on the left, and a number of itrs on the right
        // just do it again
        previous = current;
        current = previous - (previous - (180/PI) * m_eccen * sin(radians(previous))-m_mean_anon)/(1-m_eccen * cos(radians(previous)));

        count++;
    }
    return current; // return current, above has been met.
}
/**
 * @brief Update Eliptical coords.
 * This is used to do pertubations in Planets.cpp
 */
void OrbitalElements::updateEclipCoords(){
    double lat = radians(m_lat);
    double lon = radians(m_long);

    m_eclip_x = m_radius*cos(lon)*cos(lat);
    m_eclip_y = m_radius*sin(lon)*cos(lat);
    m_eclip_z = m_radius*sin(m_lat);


}
/**
 * @brief Getters and setters follow.
 *
 */
double OrbitalElements::getMeanAnom(){
    return m_mean_anon;
}
double OrbitalElements::getLong(){
    return m_long;
}
double OrbitalElements::getLat(){
    return m_lat;
}
double OrbitalElements::getEclipX(){
    return m_eclip_x;
}
double OrbitalElements::getEclipY(){
    return m_eclip_y;
}
//setters
void OrbitalElements::setLong(double longtitude){
    m_long = longtitude;
    updateEclipCoords();
}
void OrbitalElements::setLat(double lat){
    m_lat = lat;
    updateEclipCoords();
}
/**
 * @brief Normalise a value to 360 degrees
 * @param value the value to normalise
 * @return the normalised value
 */
double OrbitalElements::rev(double value){
    return value - floor(value/360.0)*360.0;
}
/**
 * @brief Convert from degrees to radians.
 * @param x A value in degrees
 * @return a value in radians
 */
double OrbitalElements::radians(double x){
    return x*PI/180;
}
/**
 * @brief Convert from radians to degrees.
 * @param x A value in radians
 * @return a value in degrees
 */
double OrbitalElements::degrees(double x){
    return x*180/PI;
}
