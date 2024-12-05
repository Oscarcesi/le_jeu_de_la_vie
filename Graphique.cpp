#include "Graphique.h"
#include "grid.h"
#include <iostream>
#include <thread>


void Graphique :: print()
{
    window.clear();
    window.draw(button1);
    //sf::RectangleShape cell(sf::Vector2f(grille.getCellSize() - 1.0f, grille.getCellSize() - 1.0f));
    for (int x = 0; x < grille.getGridHeight(); ++x) {
        for (int y = 0; y < grille.getGridWidth(); ++y) {
            
            grille.getGrid()[x][y].drawCell(window);
        }
    }
    window.display();
}

void Graphique :: run()
{   
    initializeGrid();

    window.create(sf::VideoMode(grille.getCellSize()*grille.getGridWidth(), grille.getCellSize()*grille.getGridHeight()), "Game of Life");

    
    button1.setFillColor(sf::Color::Blue);
    //button1.setPosition(window.getSize().x-200, window.getSize().y-50);
    button1.setPosition(0, 0);
    window.draw(button1);

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        print();
        
        grille.setChangesFalse();

        std::this_thread::sleep_for(std::chrono::seconds((10/vitesse)-1));

        std::thread th1{&Grid::update, &grille, 0, 0};
        std::thread th2{&Grid::update, &grille, grille.getGridHeight()/2, 0};
        std::thread th3{&Grid::update, &grille, 0, grille.getGridWidth()/2 + grille.getGridWidth()%2};
        std::thread th4{&Grid::update, &grille, grille.getGridHeight()/2 + grille.getGridHeight()%2, grille.getGridWidth()/2};

        th1.join();
        th2.join();
        th3.join();
        th4.join();
        
        std::thread th5{&Grid::changeState, &grille, 0, 0};
        std::thread th6{&Grid::changeState, &grille, grille.getGridHeight()/2, 0};
        std::thread th7{&Grid::changeState, &grille, 0, grille.getGridWidth()/2 + grille.getGridWidth()%2};
        std::thread th8{&Grid::changeState, &grille, grille.getGridHeight()/2 + grille.getGridHeight()%2, grille.getGridWidth()/2};

        th5.join();
        th6.join();
        th7.join();
        th8.join();

        if (grille.getChanges() == false)
        {
            std::cout << "L'automate n'évolue plus.";
            window.close();
        }
    }
}


