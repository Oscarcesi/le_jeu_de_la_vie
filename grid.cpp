#include "grid.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

int Grid :: getCellSize()
{
    return cellSize;
}

int Grid :: getGridWidth()
{
    return gridWidth;
}

int Grid :: getGridHeight()
{
    return gridHeight;
}

std::vector<std::vector<Cell>> Grid :: getGrid()
{
    return grid;
}


void Grid :: initializeGrid()
{
    
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y].setCellSize(cellSize);
            grid[x][y].setCoordos(x, y);
            grid[x][y].setIsAlive(std::rand() % 2);  // Randomly initialize cells as alive or dead
        }
    }
}

void Grid :: update()
{
    int x, y;
    bool alive;
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            int dx, dy, nx, ny, voisines = 0;
            for (dx = -1; dx <= 1; ++dx)
            {
                for (dy = -1; dy <= 1; ++dy)
                {
                    nx = x + dx;
                    ny = y + dy;
                    if (nx >= 0 && nx < gridWidth && ny >= 0 && ny < gridHeight && not(dx == 0 && dy == 0))
                    {
                        if (grid[nx][ny].getIsAlive())
                        {
                            voisines+=1;
                        }
                    }
                }
            }
            alive = grid[x][y].getIsAlive();
            if ((voisines == 3 && not(alive)) || ((voisines == 3 || voisines == 2) && alive))
            {
                grid[x][y].setNextState(true);
            }
            else
            {
                grid[x][y].setNextState(false);
            }
            
        }
    }
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            grid[x][y].changeState();
        }
    }
}

