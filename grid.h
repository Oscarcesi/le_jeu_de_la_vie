#ifndef GRILLE_H
#define GRILLE_H

#include "cell.h"
#include <SFML/Graphics.hpp>


class Grid
{
    private:
        int cellSize;
        int gridWidth;
        int gridHeight;
        std::vector<std::vector<Cell>> grid;
        
    public:
        
        Grid() : cellSize(5), gridWidth(0), gridHeight(0), grid(gridWidth, std::vector<Cell>(gridHeight)){};
        Grid() : cellSize(5), gridWidth(0), gridHeight(0), grid(gridWidth, std::vector<Cell>(gridHeight)){};
        Grid(int cellSize, int gridWidth, int gridHeight) : cellSize(cellSize), gridWidth(gridWidth), gridHeight(gridHeight), grid(gridWidth, std::vector<Cell>(gridHeight)) {}
        ~Grid(){};

        int getCellSize();
        int getGridWidth();
        int getGridHeight();
        std::vector<std::vector<Cell>>& getGrid();

        void setGrid(int Width, int Height);
        void setCellSize(int size);

        //void initializeGrid(bool state);
        void update(int i, int j);
        void changeState(int i, int j);
};



#endif //GRILLE_H
