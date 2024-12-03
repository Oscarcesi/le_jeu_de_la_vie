#include "Console.h"
#include "grid.h"
#include <iostream>


void Console :: run()
{
    initializeGrid();
    
    //std::cout << "dans run" << grille.getGrid()[0][0].getIsAlive() << std::endl;

    while (cpt<nbIterations) {
        cpt = cpt + 1;
        print();
        
        grille.update();
    }
}



void Console :: print()
{
    //std::cout << "dans print" << grille.getGrid()[0][0].getIsAlive() << std::endl;
    int x, y;

    std::cout << "Itération n° : " << cpt << std::endl;

    for (x = 0; x < grille.getGridHeight(); ++x) {
        for (y = 0; y < grille.getGridWidth(); ++y) {
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