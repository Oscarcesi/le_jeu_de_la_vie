#ifndef CONSOLE_H
#define CONSOLE_H

#include "Simulation.h"
#include "grid.h"
#include <SFML/Graphics.hpp>


class Console : public Simulation
{
    private :
        int nbIterations;
        int cpt = 0;
    public:
        Console(int cellSize, int gridWidth, int gridHeight, int nbIterations) : Simulation(cellSize, gridWidth, gridHeight), nbIterations(nbIterations) {}
        ~Console(){};

        virtual void run();
        virtual void print();

};



#endif //CONSOLE_H
