#include "grid.h"
#include "cell.h"
#include <iostream>
#include <fstream>
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

std::vector<std::vector<Cell>>& Grid :: getGrid()
{
    return grid;
}

void Grid :: setGrid(int Width, int Height)
{
    grid.resize(Height, std::vector<Cell>(Width));
    gridWidth = Width;
    gridHeight = Height;
}

void Grid :: update()
{
    int x, y;
    bool alive;
    
    for (x = 0; x < gridHeight; ++x) {
        for (y = 0; y < gridWidth; ++y) {
            int dx, dy, nx, ny, voisines = 0;
            for (dx = -1; dx <= 1; ++dx)
            {
                for (dy = -1; dy <= 1; ++dy)
                {
                    nx = x + dx;
                    ny = y + dy;
                    if (nx >= 0 && nx < gridHeight && ny >= 0 && ny < gridWidth && not(dx == 0 && dy == 0))
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
    
    for (x = 0; x < gridHeight; ++x) {
        for (y = 0; y < gridWidth; ++y) {
            grid[x][y].changeState();
        }
    }
}

