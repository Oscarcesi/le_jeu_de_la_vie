#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Simulation.h"


void Simulation :: initializeGrid()
{
    int hauteur, largeur;
    std::string chemin = "./fichiers/entree.txt";

    //std::cin >> chemin;

    std::ifstream fichier(chemin);

    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier.");
    }

    fichier >> hauteur >> largeur;

    std::cout << hauteur << std::endl;
    std::cout << largeur << std::endl;

    grille.setGrid(largeur, hauteur);
    
    fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::srand(std::time(0));

    std::string ligne;
    for (int x = 0; x < grille.getGridHeight(); ++x) {
        std::getline(fichier, ligne);
        ligne.erase(std::remove(ligne.begin(), ligne.end(), ' '), ligne.end());
        std::cout << "ligne " << ligne << std::endl;
        for (int y = 0; y < grille.getGridWidth();) {
            //std::cout << "dans init " << ligne[y] << std::endl;
            
            //std::cout << "dans init " << ligne[y] << std::endl;
            grille.getGrid()[x][y].setCellSize(grille.getCellSize());
            grille.getGrid()[x][y].setCoordos(x, y);
            grille.getGrid()[x][y].setIsAlive((ligne[y] == '1'));
            ++y;
            //std::cout << "y : " << y << std::endl;
        
           
        }
     
    }
    //std::cout << "dans init" << grille.getGrid()[0][0].getIsAlive() << std::endl;
}