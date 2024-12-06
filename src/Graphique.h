#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "Simulation.h"
#include "grid.h"
#include <SFML/Graphics.hpp>

class Graphique : public Simulation
{
    private:
    sf::RenderWindow window;
    int vitesse;
    sf::RectangleShape pauseButton, increaseSpeedButton, decreaseSpeedButton, bandeau, boutonFin;
    sf::Text pauseText, increaseText, decreaseText, textFin;
    sf::Font font;
    bool pause = false;
    sf::RectangleShape construction;
    bool keys[7] = {false, false, false, false, false, false, false};


    public:
        Graphique() : Simulation(), vitesse(8), construction(sf::Vector2f(grille.getCellSize(), grille.getCellSize())){}
        ~Graphique(){};

        void setupButton(sf::RectangleShape& button, sf::Text& text, const std::string& label, const sf::Font& font, float widthPercent, float heightPercent, float xPercent, float yPercent, sf::RenderWindow& window);
        void setupButtonNoText(sf::RectangleShape& button, float widthPercent, float heightPercent, float xPercent, float yPercent, sf::RenderWindow& window);
        void updateEvent(sf::Event event);
        void print();
        void run();
        void interactions();
};



#endif //GRAPHIQUE_H
