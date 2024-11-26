#include "cell.h"

#include <SFML/Graphics.hpp>


int Cell :: getCellSize()
{
    return cellSize;
}

bool Cell :: getIsAlive()
{
    return isAlive;
}

bool Cell :: getNextState()
{
    return nextState;
}

void Cell :: setIsAlive(bool state)
{
    isAlive = state;
}

void Cell :: setNextState(bool state)
{
    nextState = state;
}

void Cell :: setCoordos(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Cell :: setCellSize(int cellSize)
{
    this->cellSize = cellSize;
}

void Cell :: changeState()
{
    isAlive = nextState;
}

void Cell :: drawCell(sf::RenderWindow &window)
{
    sf::RectangleShape cellule(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    
    if (isAlive) {
        cellule.setPosition(x * cellSize, y * cellSize);
        window.draw(cellule);
    }
}

