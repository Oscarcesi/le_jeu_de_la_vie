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
        std::vector<std::vector<Cell>> grid;
        
    public:
        

        Grid(int cellSize, int gridWidth, int gridHeight) : cellSize(cellSize), gridWidth(gridWidth), gridHeight(gridHeight), grid(gridWidth, std::vector<Cell>(gridHeight)) {}
        ~Grid(){};

        int getCellSize();
        int getGridWidth();
        int getGridHeight();
        std::vector<std::vector<Cell>> getGrid();

        void initializeGrid();
        void update();
};



#endif //GRILLE_H
