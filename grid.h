#ifndef GRILLE_H
#define GRILLE_H

#include "cell.h"
#include <SFML/Graphics.hpp>


class Grid
{
    private:
        const int cellSize;
        const int gridWidth;
        const int gridHeight;
        
    public:
        std::vector<std::vector<Cell>> grid;

        Grid(int cellSize, int gridWidth, int gridHeight) : cellSize(cellSize), gridWidth(gridWidth), gridHeight(gridHeight), grid(gridWidth, std::vector<Cell>(gridHeight)) {}
        ~Grid(){};

        int getCellSize();
        int getGridWidth();
        int getGridHeight();

        void initializeGrid();
        void renderGrid(sf::RenderWindow &window);
        void update();
};



#endif //GRILLE_H
