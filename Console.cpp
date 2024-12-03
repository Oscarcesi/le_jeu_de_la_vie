#include "Console.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

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

    std::string dossier = chemin + "_out/";

    if (!std::filesystem::exists(dossier)) {
        std::filesystem::create_directory(dossier);
    }

    std::string filename = dossier + "Itération_" + std::to_string(cpt) + ".txt";

    std::ofstream fichier(filename);

    std::cout << "Itération n° : " << cpt << std::endl;

    for (x = 0; x < grille.getGridHeight(); ++x) {
        for (y = 0; y < grille.getGridWidth(); ++y) {
            if (grille.getGrid()[x][y].getIsAlive())
            {
                fichier << "0 ";
            }
            else
            {
                fichier << "- ";
            }
        }
        fichier << "\n";
    }
    fichier.close();
}