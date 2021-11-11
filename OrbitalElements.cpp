#include"OrbitalElements.h"
#include<iostream>
#include<math.h>


OrbitalElements::OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon, double radius){

    m_asc_node = rev(asc_node);
    m_incl = rev(incl);
    m_arg = rev(arg);
    m_axis = rev(axis);
    m_eccen = rev(eccen);
    m_mean_anon = rev(mean_anon);
    m_radius = radius;

    if (asc_node != 0){
        computeCoordinates();
    } else {
        computeCoordinatesEarth();
    }


}
void OrbitalElements::computeCoordinates(){


    double eccentric_anomaly = computeEccentricAnomaly(10);

    eccentric_anomaly = rev(eccentric_anomaly);

    double rect_x = m_axis*(cos(radians(eccentric_anomaly))-m_eccen);
    double rect_y = m_axis*sqrt(1-m_eccen*m_eccen)*sin(radians(eccentric_anomaly));

    double radius = sqrt(pow(rect_x,2)+pow(rect_y,2));
    double true_anomaly = atan2(radians(rect_y),radians(rect_x));

    true_anomaly = degrees(true_anomaly);
    true_anomaly = rev(true_anomaly);

    m_eclip_x = radius * (cos(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))-sin(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    m_eclip_y = radius * (sin(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))+cos(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    m_eclip_z = radius * sin(radians(true_anomaly+m_arg))*sin(radians(m_incl));


    m_long = atan2(radians(m_eclip_y),radians(m_eclip_x));
    m_long = degrees(m_long);
    m_long = rev(m_long);

    m_lat = atan2(radians(m_eclip_z),radians(sqrt(pow(m_eclip_x,2) + pow(m_eclip_y,2))));
    m_lat = degrees(m_lat);

    m_eclip_x = m_radius*cos(radians(m_long))*cos(radians(m_lat));
    m_eclip_y = m_radius*sin(radians(m_long))*cos(radians(m_lat));



}
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

    m_eclip_x = m_radius*cos(radians(m_long));
    m_eclip_y = m_radius*sin(radians(m_long));
    m_eclip_z = 0;

    m_lat = 0;


}
double OrbitalElements::computeEccentricAnomaly(int itr){

    double previous = m_mean_anon + (180/PI) * m_eccen * sin(radians(m_mean_anon)) * (1+m_eccen*cos(radians(m_mean_anon)));
    double current = previous - (previous - (180/PI) * m_eccen * sin(radians(previous))-m_mean_anon)/(1-m_eccen * cos(radians(previous)));

    int count = 0;
    while (abs(current - previous) < 0.005 && count < itr){
        previous = current;
        current = previous - (previous - (180/PI) * m_eccen * sin(radians(previous))-m_mean_anon)/(1-m_eccen * cos(radians(previous)));

        count++;
    }
    return current;
}
void OrbitalElements::updateEclipCoords(){
    double lat = radians(m_lat);
    double lon = radians(m_long);

    m_eclip_x = m_radius*cos(lon)*cos(lat);
    m_eclip_y = m_radius*sin(lon)*cos(lat);
    m_eclip_z = m_radius*sin(m_lat);


}
// getters
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
double OrbitalElements::rev(double value){
    return value - floor(value/360.0)*360.0;
}
double OrbitalElements::radians(double x){
    return x*PI/180;
}
double OrbitalElements::degrees(double x){
    return x*180/PI;
}
