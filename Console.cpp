#include "Console.h"
#include "grid.h"
#include <iostream>


void Console :: run()
{
    int cpt = 0;
    grille.initializeGrid();

    while (cpt<nbIterations) {
        print();
        grille.update();
        ++cpt;
    }
}



void Console :: print()
{
    int x, y;

    std::cout << "Itération n° : " << nbIterations << std::endl;

    for (x = 0; x < grille.getGridWidth(); ++x) {
        for (y = 0; y < grille.getGridHeight(); ++y) {
            if (grille.getGrid()[x][y].getIsAlive())
            {
                std::cout << "0 ";
            }
            else
            {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }
}