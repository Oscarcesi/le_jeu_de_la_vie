#ifndef SIMULATION_H
#define SIMULATION_H

#include "grid.h"
#include <SFML/Graphics.hpp>


class Simulation
{
    protected:
        Grid grille;
        
    public:
        

        Simulation(int cellSize, int gridWidth, int gridHeight) : grille(cellSize, gridWidth, gridHeight) {}
        ~Simulation(){};

        virtual void run() = 0;
        virtual void print() = 0;
};



#endif //SIMULATION_H
