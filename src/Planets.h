#ifndef PLANETS_H
#define PLANETS_H
#include<vector>
class Planets{
    public:
        Planets();
        ~Planets();
        std::vector<double> getPlanets(void);
        void setPlanet(double value);

    private:
        std::vector<double> planets;
};


#endif // PLANETS_H