#include "Graphique.h"
#include "grid.h"
#include <iostream>
#include <thread>


void Graphique :: print()
{
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(grille.getCellSize() - 1.0f, grille.getCellSize() - 1.0f));
    for (int x = 0; x < grille.getGridHeight(); ++x) {
        for (int y = 0; y < grille.getGridWidth(); ++y) {
            
            grille.getGrid()[x][y].drawCell(window);
        }
    }
    window.display();
}

void Graphique :: run()
{
    int x, y;
    
    initializeGrid();

    // On adapte la fenêtre à la taille de l'écran
    if (sf::VideoMode::getDesktopMode().width / grille.getGridWidth() < sf::VideoMode::getDesktopMode().height / grille.getGridHeight())
    {
        grille.setCellSize(sf::VideoMode::getDesktopMode().width / grille.getGridWidth());
    }
    else
    {
        grille.setCellSize(sf::VideoMode::getDesktopMode().height / grille.getGridHeight());
    }

    // On adapte la taille des cellules pour s'adapter avec la taille de l'écran
    for (x = 0; x < grille.getGridHeight(); ++x) {
        for (y = 0; y < grille.getGridWidth(); ++y) {
            
            grille.getGrid()[x][y].setCellSize(grille.getCellSize());
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //std::cout << "ta mère" << std::endl;
        print();
        //std::cout << "la pute" << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(3));

        std::thread th1{&Grid::update, &grille, 0, 0};
        std::thread th2{&Grid::update, &grille, grille.getGridHeight()/2, 0};
        std::thread th3{&Grid::update, &grille, 0, grille.getGridWidth()/2 + grille.getGridWidth()%2};
        std::thread th4{&Grid::update, &grille, grille.getGridHeight()/2 + grille.getGridHeight()%2, grille.getGridWidth()/2};

        th1.join();
        th2.join();
        th3.join();
        th4.join();
        //std::cout << "la grosse pute" << std::endl;
        std::thread th5{&Grid::changeState, &grille, 0, 0};
        std::thread th6{&Grid::changeState, &grille, grille.getGridHeight()/2, 0};
        std::thread th7{&Grid::changeState, &grille, 0, grille.getGridWidth()/2 + grille.getGridWidth()%2};
        std::thread th8{&Grid::changeState, &grille, grille.getGridHeight()/2 + grille.getGridHeight()%2, grille.getGridWidth()/2};

        th5.join();
        th6.join();
        th7.join();
        th8.join();
    }
}