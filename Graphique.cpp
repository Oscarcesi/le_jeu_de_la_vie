#include "Graphique.h"
#include "grid.h"
#include <iostream>
#include <thread>
#include <functional>

void Graphique::setupButton(sf::RectangleShape& button, sf::Text& text, const std::string& label, const sf::Font& font, float widthPercent, float heightPercent, float xPercent, float yPercent, sf::RenderWindow& window) 
{
    // Taille de la fenêtre
    sf::Vector2u windowSize = window.getSize();

    // Taille du bouton
    sf::Vector2f buttonSize(windowSize.x * widthPercent, windowSize.y * heightPercent);
    button.setSize(buttonSize);
    button.setFillColor(sf::Color::Black);

    // Position du bouton
    button.setPosition(windowSize.x * xPercent, windowSize.y * yPercent);

    // Configuration du texte
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(static_cast<unsigned int>(buttonSize.y * 0.5f)); // Taille relative au bouton
    text.setFillColor(sf::Color::White);

    // Centrer le texte dans le bouton
    sf::FloatRect buttonBounds = button.getGlobalBounds();
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(
        buttonBounds.left + (buttonBounds.width - textBounds.width) / 2,
        buttonBounds.top + (buttonBounds.height - textBounds.height) / 2
    );
}

void Graphique::setupButtonNoText(sf::RectangleShape& button, float widthPercent, float heightPercent, float xPercent, float yPercent, sf::RenderWindow& window) 
{
    // Taille de la fenêtre
    sf::Vector2u windowSize = window.getSize();

    // Taille du bouton
    sf::Vector2f buttonSize(windowSize.x * widthPercent, windowSize.y * heightPercent);
    button.setSize(buttonSize);
    button.setFillColor(sf::Color::White);

    // Position du bouton
    button.setPosition(windowSize.x * xPercent, windowSize.y * yPercent);
}


void Graphique::updateEvent(sf::Event event){
    while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (pauseButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    std::cout << "Pause button clicked!" << std::endl;
                    if (!pause){
                        pause = true;
                    }
                    else{
                        pause = false;
                    }
                }

                if (increaseSpeedButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    std::cout << "Increase speed button clicked!" << std::endl;
                    if (vitesse < 10)
                        vitesse++;
                }

                if (decreaseSpeedButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    std::cout << "Decrease speed button clicked!" << std::endl;
                    if (vitesse > 1)
                        vitesse--;
                }
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
    }
}

void Graphique::print() {
    window.clear();
    // Dessiner la grille ou d'autres éléments
    window.draw(construction);
    // Dessiner les boutons et leurs textes
    window.draw(bandeau);

    window.draw(pauseButton);
    window.draw(pauseText);

    window.draw(increaseSpeedButton);
    window.draw(increaseText);

    window.draw(decreaseSpeedButton);
    window.draw(decreaseText);

    
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

    window.create(sf::VideoMode(grille.getCellSize()*grille.getGridWidth(), grille.getCellSize()*grille.getGridHeight()/0.9), "Game of Life");

    // init button
    // Charger la police
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        throw std::runtime_error("Impossible de charger la police.");
    }

    // Initialiser les boutons
    setupButton(pauseButton, pauseText, "Pause", font, 0.1f, 0.05f, 0.02f, 0.93f, window);        // 10% largeur, 5% hauteur, 2% gauche, 93% haut
    setupButton(increaseSpeedButton, increaseText, "Speed +", font, 0.1f, 0.05f, 0.14f, 0.93f, window); // 10% largeur, 5% hauteur, 12% gauche, 93% haut
    setupButton(decreaseSpeedButton, decreaseText, "Speed -", font, 0.1f, 0.05f, 0.26f, 0.93f, window); // 10% largeur, 5% hauteur, 5% gauche, 93% haut
    setupButtonNoText(bandeau, 1.0f, 0.1f, 0.0f, 0.9f, window); // 100% largeur, 10% hauteur, 0% gauche, 90% haut
    
    //end

    construction.setPosition(-10,-10);
        

    while (window.isOpen()) {
        sf::Event event;
        std::thread upEvent{std::bind(&Graphique::updateEvent, this, event)};
        upEvent.join();

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

        

        
        print();
        
        if (!pause){
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

        
}


