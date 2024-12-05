#include "cell.h"
#include <iostream>
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

bool Cell :: isInfected()
{
    return infected;
}

void Cell :: setIsAlive(bool state)
{
    isAlive = state;
    //std::cout << "dans cell" << getIsAlive() << std::endl;
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

void Cell :: InfectCell()
{
    infected = true;
    isAlive = true;
}

void Cell :: changeState()
{
    if (!infected)
    {
        isAlive = nextState;
    }
}

void Cell :: drawCell(sf::RenderWindow &window)
{
    sf::RectangleShape cellule(sf::Vector2f(cellSize, cellSize));
    
    if (isAlive) {
        cellule.setPosition(y * cellSize, x * cellSize);
        window.draw(cellule);
    }
}

