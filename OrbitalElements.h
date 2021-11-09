#ifndef ORBITALELEMENTS_H
#define ORBITALELEMENTS_H
#include<string>
const double PI = 3.14159265359;
class OrbitalElements{
    public:
        OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon);
        void updateEclipCoords();
        double getLong();
        double getLat();
        double getRad();
        double getEclipX();
        double getEclipY();
        double getEclipZ();
        double getMeanAnom();

        void setLong(double longtitude);
        void setLat(double lat);


    private:

        double m_long;
        double m_lat;
        double m_radius;
        double m_eclip_x;
        double m_eclip_y;
        double m_eclip_z;
        
        double m_asc_node;
        double m_incl;
        double m_arg;
        double m_axis;
        double m_eccen;
        double m_mean_anon;


        void computeCoordinates();
        void computeCoordinatesEarth();
        double computeEccentricAnomaly(int itr);

        double radians(double x);
        double rev(double x);
        double degrees(double x);
        
};


#endif // ORBITALELEMENTS_H