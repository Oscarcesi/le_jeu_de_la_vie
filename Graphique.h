#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "Simulation.h"
#include "grid.h"
#include <SFML/Graphics.hpp>


class Graphique : public Simulation
{
    private:
    sf::RenderWindow window;

    public:
        Graphique() : Simulation(), window(sf::VideoMode(100,100), "Game of Life") {}
        ~Graphique(){};

        void print();
        void run();
};



#endif //GRAPHIQUE_H
