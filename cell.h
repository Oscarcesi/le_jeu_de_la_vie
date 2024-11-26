#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>


class Cell
{
    private:
        int cellSize;
        bool isAlive;
        bool nextState;
        int x;
        int y;

    public:
        Cell() : cellSize(1), isAlive(0){}
        Cell(int cellSize, bool isAlive, bool nextState = 0, int x = 0, int y = 0) : cellSize(cellSize), isAlive(isAlive){}
        ~Cell(){};

        int getCellSize();
        bool getIsAlive();
        bool getNextState();

        void setIsAlive(bool state);
        void setCoordos(int x, int y);
        void setNextState(bool state);
        void setCellSize(int cellSize);
        void changeState();
        void drawCell(sf::RenderWindow &window);
};



#endif //GRILLE_H
