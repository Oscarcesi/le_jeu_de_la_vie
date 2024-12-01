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
        Graphique(int cellSize, int gridWidth, int gridHeight) : Simulation(cellSize, gridWidth, gridHeight), window(sf::VideoMode(grille.getGridWidth() * grille.getCellSize(), grille.getGridHeight() * grille.getCellSize()), "Game of Life") {}
        ~Graphique(){};

        virtual void print();
        virtual void run();
};



#endif //GRAPHIQUE_H
