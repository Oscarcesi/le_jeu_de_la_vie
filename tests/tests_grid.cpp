#include <gtest/gtest.h>
#include "../src/grid.h" // Ta classe Grid

TEST(GridTest, Initialization) {
    Grid grille(7, 5, 5); // Crée une grille 5x5
    EXPECT_EQ(grille.getGridWidth(), 5); // Vérifie que la largeur est correcte
    EXPECT_EQ(grille.getGridHeight(), 5); // Vérifie que la hauteur est correcte
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            EXPECT_FALSE(grille.getGrid()[x][y].getIsAlive()); // Vérifie que toutes les cellules sont mortes au début
        }
    }
}

TEST(GridTest, RulesOfLife) {
    Grid grille(7, 5, 5);
    grille.getGrid()[1][1].setIsAlive(true);
    grille.getGrid()[1][2].setIsAlive(true);
    grille.getGrid()[2][2].setIsAlive(true);

    // Calculer la prochaine génération
    grille.update(0,0);
    grille.update(grille.getGridHeight()/2, 0);
    grille.update(0, grille.getGridWidth()/2 + grille.getGridWidth()%2);
    grille.update(grille.getGridHeight()/2 + grille.getGridHeight()%2, grille.getGridWidth()/2);
    grille.changeState(0,0);
    grille.changeState(grille.getGridHeight()/2, 0);
    grille.changeState(0, grille.getGridWidth()/2 + grille.getGridWidth()%2);
    grille.changeState(grille.getGridHeight()/2 + grille.getGridHeight()%2, grille.getGridWidth()/2);

    std::cout << "ici : " << grille.getGrid()[2][1].getIsAlive() << std::endl;
    // Vérifier les états après application des règles
    EXPECT_TRUE(grille.getGrid()[1][2].getIsAlive()); // La cellule (1,2) reste vivante
    EXPECT_TRUE(grille.getGrid()[2][2].getIsAlive()); // La cellule (2,2) reste vivante
    EXPECT_TRUE(grille.getGrid()[2][1].getIsAlive()); // La cellule (2,1) devient vivante
    EXPECT_TRUE(grille.getGrid()[1][1].getIsAlive()); // La cellule (1,1) reste vivante
}
