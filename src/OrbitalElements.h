#ifndef ORBITALELEMENTS_H
#define ORBITALELEMENTS_H
#include<string>
const double PI = 3.14159265359;
class OrbitalElements{
    public:
        OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon);
        double getLong();
        double getLat();
        double getRad();
        double getClipX();
        double getClipY();
        double getClipZ();

        double getMeanAnom();

        void setLong(double longtitude);
        void setLat(double lat);
        void setRad(double rad);
        void setClipX(double clipx);
        void setClipY(double clipy);
        void setClipZ(double clipz);


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
        double rev(double x);
        double degrees(double x);
        
};


#endif // ORBITALELEMENTS_H