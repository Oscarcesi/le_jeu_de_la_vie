#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "grid.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
    Grid grille(5, 100, 100);
    sf::RenderWindow window(sf::VideoMode(grille.getGridWidth() * grille.getCellSize(), grille.getGridHeight() * grille.getCellSize()), "Game of Life");

    grille.initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        grille.renderGrid(window);
        cout << "ta mère" << endl;
        grille.update();
        cout << "la pute" << endl;
    }

    return 0;
}
