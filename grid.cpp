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

void Grid :: setCellSize(int size)
{
    cellSize = size;
}

void Grid :: update(int i, int j)
{
    //int test;
    bool alive;
    
    for (int x = i; x < i + gridHeight/2; ++x) {
        for (int y = j; y < j + gridWidth/2; ++y) {
            int dx, dy, nx, ny, voisines = 0;
            //cout << "cellule suivant" << endl;
            //test = 0;
            for (dx = -1; dx <= 1; ++dx)
            {
                for (dy = -1; dy <= 1; ++dy)
                {
                    //test += 1;
                    nx = ((x + dx) % gridHeight + gridHeight) % gridHeight;
                    ny = ((y + dy) % gridWidth + gridWidth) % gridWidth;
                    //cout << nx << ", " << ny << endl;
                    if (not(dx == 0 && dy == 0))
                    {

                        if (grid[nx][ny].getIsAlive())
                        {
                            voisines+=1;
                        }
                        //cout << test << endl;
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
}

void Grid :: changeState(int i, int j)
{
    for (int x = i; x < i + gridHeight/2; ++x) {
        for (int y = j; y < j + gridWidth/2; ++y) {
            grid[x][y].changeState();
        }
    }
}

