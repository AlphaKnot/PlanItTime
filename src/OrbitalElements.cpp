#include"OrbitalElements.h"
#include<iostream>
#include<math.h>

const double PI = 3.14159265359;
OrbitalElements::OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon){
    m_asc_node = rev(asc_node);
    m_incl = rev(incl);
    m_arg = rev(arg);
    m_axis = rev(axis);
    m_eccen = rev(eccen);
    m_mean_anon = rev(mean_anon);
    computeCoordinates();

}
OrbitalElements::~OrbitalElements(){
    //pass
}
void OrbitalElements::computeCoordinates(){
    
    double eccentric_anomaly_0 = m_mean_anon + (180/PI) * m_eccen * sin(radians(m_mean_anon)) * (1+m_eccen*cos(radians(m_mean_anon)));
    double eccentric_anomaly_1 = eccentric_anomaly_0 - 
        (eccentric_anomaly_0 - (180/PI) 
        * m_eccen * sin(radians(eccentric_anomaly_0))-m_mean_anon)
        /(1-m_eccen * cos(radians(eccentric_anomaly_0)));



    std::cout << "Eccentric Anom: " << eccentric_anomaly_1 << "\n"; 

    double rect_x = m_axis*(cos(radians(eccentric_anomaly_1))-m_eccen);
    double rect_y = m_axis*sqrt(1-m_eccen*m_eccen)*sin(radians(eccentric_anomaly_1));



    std::cout << "Rect x: "<< rect_x << "\n";
    std::cout << "Rect y: "<< rect_y << "\n";

    double radius = sqrt(pow(rect_x,2)+pow(rect_y,2));
    double true_anomaly = atan2(radians(rect_y),radians(rect_x));

    true_anomaly = degrees(true_anomaly);
    

    std::cout << "Radius:" << radius << "\n" << "V: " << true_anomaly << "\n";

    double clip_x = radius * (cos(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))-sin(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    double clip_y = radius * (sin(radians(m_asc_node)) * cos(radians(true_anomaly+m_arg))+cos(radians(m_asc_node))*sin(radians(true_anomaly+m_arg)) *cos(radians(m_incl)));
    double clip_z = radius * sin(radians(true_anomaly+m_arg))*sin(radians(m_incl));

    std::cout << "x: " << clip_x << " y: " << clip_y << " z: " << clip_z << "\n";


    // our actual return values?
    m_long = atan2(radians(clip_y),radians(clip_x));
    m_long = degrees(m_long);
    m_lat = atan2(radians(clip_z),radians(sqrt(pow(clip_x,2) + pow(clip_y,2))));
    m_lat = rev(degrees(m_lat));
    m_radius = sqrt(pow(clip_x,2)+pow(clip_y,2)+pow(clip_z,2));

        
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
    return x * 180/PI;
}