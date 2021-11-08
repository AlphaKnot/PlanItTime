#ifndef ORBITALELEMENTS_H
#define ORBITALELEMENTS_H

class OrbitalElements{
    public:
        OrbitalElements(double asc_node, double incl, double arg, double axis, double eccen, double mean_anon);
        ~OrbitalElements();
        double getAscNode();
        double getIncl();
        double getArg();
        double getAxis();
        double getEccen();
        double getMeanAnon();
    private:
        double m_asc_node;
        double m_incl;
        double m_arg;
        double m_axis;
        double m_eccen;
        double m_mean_anon;
};


#endif // ORBITALELEMENTS_H