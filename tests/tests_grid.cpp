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
    grille.getGrid()[3][4].setIsAlive(true);

    // Vérification des dimensions
    ASSERT_LT(0, grille.getGridWidth());
    ASSERT_LT(0, grille.getGridHeight());

    // Calculer la prochaine génération
    grille.update(0,0);
    grille.update(grille.getGridHeight()/2, 0);
    grille.update(0, grille.getGridWidth()/2);
    grille.update(grille.getGridHeight()/2, grille.getGridWidth()/2);
    grille.changeState(0,0);
    grille.changeState(grille.getGridHeight()/2, 0);
    grille.changeState(0, grille.getGridWidth()/2);
    grille.changeState(grille.getGridHeight()/2, grille.getGridWidth()/2);

    // Vérifier les états après application des règles
    EXPECT_FALSE(grille.getGrid()[0][0].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[0][1].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[0][2].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[0][3].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[0][4].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[1][0].getIsAlive()); // La cellule reste morte
    EXPECT_TRUE(grille.getGrid()[1][1].getIsAlive()); // La cellule (1,1) reste vivante
    EXPECT_TRUE(grille.getGrid()[1][2].getIsAlive()); // La cellule (1,2) reste vivante
    EXPECT_FALSE(grille.getGrid()[1][3].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[1][4].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[2][0].getIsAlive());  // La cellule reste morte
    EXPECT_TRUE(grille.getGrid()[2][1].getIsAlive()); // La cellule (2,1) devient vivante
    EXPECT_TRUE(grille.getGrid()[2][2].getIsAlive()); // La cellule (2,2) reste vivante
    EXPECT_TRUE(grille.getGrid()[2][3].getIsAlive()); // La cellule (2,3) reste vivante
    EXPECT_FALSE(grille.getGrid()[2][4].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[2][5].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[3][0].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[3][1].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[3][2].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[3][3].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[3][4].getIsAlive()); // La cellule (3,4) devient morte
    EXPECT_FALSE(grille.getGrid()[4][0].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[4][1].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[4][2].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[4][3].getIsAlive()); // La cellule reste morte
    EXPECT_FALSE(grille.getGrid()[4][4].getIsAlive()); // La cellule reste morte
   
    
}

TEST(GridTest, Test_Oscillateur) {
    Grid grille(7, 5, 5);
    grille.getGrid()[1][1].setIsAlive(true);
    grille.getGrid()[1][2].setIsAlive(true);
    grille.getGrid()[1][3].setIsAlive(true);

    // Calculer la prochaine génération
    grille.update(0,0);
    grille.update(grille.getGridHeight()/2, 0);
    grille.update(0, grille.getGridWidth()/2);
    grille.update(grille.getGridHeight()/2, grille.getGridWidth()/2);
    grille.changeState(0,0);
    grille.changeState(grille.getGridHeight()/2, 0);
    grille.changeState(0, grille.getGridWidth()/2);
    grille.changeState(grille.getGridHeight()/2, grille.getGridWidth()/2);
    
     // Vérifier les états après application des règles
    EXPECT_FALSE(grille.getGrid()[0][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[0][1].getIsAlive()); // La cellule est morte
    EXPECT_TRUE(grille.getGrid()[0][2].getIsAlive()); // La cellule (0,2) est vivante
    EXPECT_FALSE(grille.getGrid()[0][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[0][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[1][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[1][1].getIsAlive()); // La cellule est morte
    EXPECT_TRUE(grille.getGrid()[1][2].getIsAlive()); // La cellule (1,2) est vivante
    EXPECT_FALSE(grille.getGrid()[1][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[1][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][0].getIsAlive());  // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][1].getIsAlive()); // La cellule est morte
    EXPECT_TRUE(grille.getGrid()[2][2].getIsAlive()); // La cellule (2,2) est vivante
    EXPECT_FALSE(grille.getGrid()[2][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][5].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][1].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][2].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][1].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][2].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][4].getIsAlive()); // La cellule est morte
   
    // Calculer la prochaine génération
    grille.update(0,0);
    grille.update(grille.getGridHeight()/2, 0);
    grille.update(0, grille.getGridWidth()/2);
    grille.update(grille.getGridHeight()/2, grille.getGridWidth()/2);
    grille.changeState(0,0);
    grille.changeState(grille.getGridHeight()/2, 0);
    grille.changeState(0, grille.getGridWidth()/2);
    grille.changeState(grille.getGridHeight()/2, grille.getGridWidth()/2);
    
         // Vérifier les états après application des règles
    EXPECT_FALSE(grille.getGrid()[0][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[0][1].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[0][2].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[0][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[0][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[1][0].getIsAlive()); // La cellule est morte
    EXPECT_TRUE(grille.getGrid()[1][1].getIsAlive()); // La cellule (1,1) est vivante
    EXPECT_TRUE(grille.getGrid()[1][2].getIsAlive()); // La cellule (1,2) est vivante
    EXPECT_TRUE(grille.getGrid()[1][3].getIsAlive()); // La cellule (1,3) est vivante
    EXPECT_FALSE(grille.getGrid()[1][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][0].getIsAlive());  // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][1].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][2].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[2][5].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][1].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][2].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[3][4].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][0].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][1].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][2].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][3].getIsAlive()); // La cellule est morte
    EXPECT_FALSE(grille.getGrid()[4][4].getIsAlive()); // La cellule est morte
   
}