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
        Console(int nbIterations) : Simulation(), nbIterations(nbIterations) {}
        ~Console(){};

        void run();
        void print();

};



#endif //CONSOLE_H
