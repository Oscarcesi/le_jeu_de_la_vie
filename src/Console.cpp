#include "Console.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <thread>

void Console :: run()
{
    initializeGrid();
    
    
    //std::cout << "dans run" << grille.getGrid()[0][0].getIsAlive() << std::endl;
    initializeGrid();
    
    
    //std::cout << "dans run" << grille.getGrid()[0][0].getIsAlive() << std::endl;

    while (cpt<=nbIterations) {
        
        print();
        
        grille.setChangesFalse();

        //std::cout << "Avant update, changes = " << grille.getChanges() << std::endl;
        std::thread th1{&Grid::update, &grille, 0, 0};
        std::thread th2{&Grid::update, &grille, grille.getGridHeight()/2, 0};
        std::thread th3{&Grid::update, &grille, 0, grille.getGridWidth()/2};
        std::thread th4{&Grid::update, &grille, grille.getGridHeight()/2, grille.getGridWidth()/2};

        th1.join();
        th2.join();
        th3.join();
        th4.join();

        //std::cout << "Après update, changes = " << grille.getChanges() << std::endl;

        std::thread th5{&Grid::changeState, &grille, 0, 0};
        std::thread th6{&Grid::changeState, &grille, grille.getGridHeight()/2, 0};
        std::thread th7{&Grid::changeState, &grille, 0, grille.getGridWidth()/2};
        std::thread th8{&Grid::changeState, &grille, grille.getGridHeight()/2, grille.getGridWidth()/2};

        th5.join();
        th6.join();
        th7.join();
        th8.join();
        
        cpt = cpt + 1;

        if (grille.getChanges() == false)
        {
            std::cout << "L'automate n'évolue plus." << std::endl;
            cpt = nbIterations+1;
        }
    }
}



void Console :: print()
{
    //std::cout << "dans print" << grille.getGrid()[0][0].getIsAlive() << std::endl;
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