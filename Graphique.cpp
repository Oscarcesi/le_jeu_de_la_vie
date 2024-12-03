#include "Graphique.h"
#include "grid.h"
#include <iostream>

void Graphique :: print()
{
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(grille.getCellSize() - 1.0f, grille.getCellSize() - 1.0f));
    for (x = 0; x < grille.getGridHeight(); ++x) {
        for (y = 0; y < grille.getGridWidth(); ++y) {
            grille.getGrid()[x][y].drawCell(window);
        }
    }
    window.display();
}

void Graphique :: run()
{
    //sf::RenderWindow window(sf::VideoMode(grille.getGridWidth() * grille.getCellSize(), grille.getGridHeight() * grille.getCellSize()), "Game of Life");

    initializeGrid();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        print();
        grille.update();
    }
}