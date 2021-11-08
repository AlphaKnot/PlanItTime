#include"OrbitalElements.h"
#include<iostream>

OrbitalElements::OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon){
    m_asc_node = asc_node;
    m_incl = incl;
    m_arg = arg;
    m_axis = axis;
    m_eccen = eccen;
    m_mean_anon = mean_anon;
}
OrbitalElements::~OrbitalElements(){
    //pass
}
double OrbitalElements::getAscNode(){
    return m_asc_node;
}
double OrbitalElements::getIncl(){
    return m_incl;
}
double OrbitalElements::getArg(){
    return m_arg;
}
double OrbitalElements::getAxis(){
    return m_axis;
}
double OrbitalElements::getEccen(){
    return m_eccen;
}
double OrbitalElements::getMeanAnon(){
    return m_mean_anon;
}
// for testing
void OrbitalElements::printOrbitalElements(std::string planetName){
    std::cout << planetName << ": " <<
        getAscNode() << " " <<
        getIncl() << " " <<
        getArg() << " " <<
        getAxis() << " " <<
        getEccen() << " " <<
        getMeanAnon() << 
        "\n";
}