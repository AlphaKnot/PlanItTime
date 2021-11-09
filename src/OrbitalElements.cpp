#include"OrbitalElements.h"
#include<iostream>
#include<math.h>


OrbitalElements::OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon){
    
    m_asc_node = rev(asc_node);
    m_incl = rev(incl);
    m_arg = rev(arg);
    m_axis = rev(axis);
    m_eccen = rev(eccen);
    m_mean_anon = rev(mean_anon);

    computeCoordinates();

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
    
    m_clip_x = radius * (cos(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))-sin(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    m_clip_y = radius * (sin(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))+cos(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    m_clip_z = radius * sin(radians(true_anomaly+m_arg))*sin(radians(m_incl));


    m_long = atan2(radians(m_clip_y),radians(m_clip_x));

    m_long = degrees(m_long);
    m_long = rev(m_long);
    
    m_lat = atan2(radians(m_clip_z),radians(sqrt(pow(m_clip_x,2) + pow(m_clip_y,2))));
    m_lat = degrees(m_lat);
    m_radius = sqrt(pow(m_clip_x,2)+pow(m_clip_y,2)+pow(m_clip_z,2));

        
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
double OrbitalElements::getRad(){
    return m_radius;
}
double OrbitalElements::getClipX(){
    return m_clip_x;
}
double OrbitalElements::getClipY(){
    return m_clip_y;
}
double OrbitalElements::getClipZ(){
    return m_clip_z;
}
//setters
void OrbitalElements::setLong(double longtitude){
    m_long = longtitude;
}
void OrbitalElements::setLat(double lat){
    m_lat = lat;
}
void OrbitalElements::setRad(double rad){
    m_radius = rad;
}
void OrbitalElements::setClipX(double clip_x){
    m_clip_x = clip_x;
}
void OrbitalElements::setClipY(double clip_y){
    m_clip_y = clip_y;
}
void OrbitalElements::setClipZ(double clip_z){
    m_clip_z = clip_z;
}
// for testing
void OrbitalElements::printOrbitalElements(std::string planetName){
    std::cout << planetName << ": " <<
        m_long << " " <<
        m_lat << " " <<
        m_radius << " " << 
        "\n";
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
