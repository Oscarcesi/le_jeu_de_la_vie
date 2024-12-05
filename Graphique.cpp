#include "Graphique.h"
#include "grid.h"
#include <iostream>
#include <thread>


void Graphique :: print()
{
    window.clear();
    //window.draw(button1);
    window.draw(construction);
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
    bool keys[7] = {false, false, false, false, false, false, false};
    initializeGrid();

    window.create(sf::VideoMode(grille.getCellSize()*grille.getGridWidth(), grille.getCellSize()*grille.getGridHeight()), "Game of Life");

    construction.setPosition(-10,-10);
        

    while (window.isOpen()) {
        sf::Event event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) & not(keys[0])) {
            keys[0]=true;
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) & not(keys[1])) {
            keys[1]=true;
            construction.move(0, -2*grille.getCellSize());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) & not(keys[2])) {
            keys[2]=true;
            construction.move(0, 2*grille.getCellSize());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) & not(keys[3])) {
            keys[3]=true;
            construction.move(-2*grille.getCellSize(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) & not(keys[4])) {
            keys[4]=true;
            construction.move(2*grille.getCellSize(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) & not(keys[5])) {
            keys[5]=true;
            grille.getGrid()[construction.getPosition().y/grille.getCellSize()][construction.getPosition().x/grille.getCellSize()].InfectCell();
            construction.setPosition(-10,-10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) & not(keys[6])) {
            keys[6]=true;
            construction.setFillColor(sf::Color::Red);
            construction.setPosition(0, 0);
        }

        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Escape) keys[0] = false;
            if (event.key.code == sf::Keyboard::Up) keys[1] = false;
            if (event.key.code == sf::Keyboard::Down) keys[2] = false;
            if (event.key.code == sf::Keyboard::Left) keys[3] = false;
            if (event.key.code == sf::Keyboard::Right) keys[4] = false;
            if (event.key.code == sf::Keyboard::Enter) keys[5] = false;
            if (event.key.code == sf::Keyboard::Space) keys[6] = false;
        }

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
            std::cout << "L'automate n'évolue plus." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            window.close();
        }
    }
}

