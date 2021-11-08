#ifndef PLANETS_H
#define PLANETS_H
#include<vector>
class Planets{
    public:
        Planets();
        ~Planets();
        std::vector<unsigned short> getPlanets(void);

    private:
        std::vector<unsigned short> planetStates;
};


#endif // PLANETS_H