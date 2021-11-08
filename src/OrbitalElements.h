#ifndef ORBITALELEMENTS_H
#define ORBITALELEMENTS_H
#include<string>
class OrbitalElements{
    public:
        OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon);
        
        void printOrbitalElements(std::string planetName);
        
        double getLong();
        double getLat();
        double getRad();
        double getClipX();
        double getClipY();
        double getClipZ();

    private:

        double m_long;
        double m_lat;
        double m_radius;
        double m_clip_x;
        double m_clip_y;
        double m_clip_z;
        
        double m_asc_node;
        double m_incl;
        double m_arg;
        double m_axis;
        double m_eccen;
        double m_mean_anon;


        void computeCoordinates();
        double computeEccentricAnomaly(int itr);
        

        double radians(double x);
        double degrees(double x);
        double rev(double);
};


#endif // ORBITALELEMENTS_H