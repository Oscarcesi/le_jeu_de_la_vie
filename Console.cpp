#include "Console.h"
#include "grid.h"
#include <iostream>


void Console :: run()
{
    grille.initializeGrid();

    while (cpt<nbIterations) {
        cpt = cpt + 1;
        print();
        grille.update();
    }
}



void Console :: print()
{
    int x, y;

    std::cout << "Itération n° : " << cpt << std::endl;

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