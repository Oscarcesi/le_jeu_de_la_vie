# Jeu de la Vie

## Description
Ce projet implémente le **Jeu de la Vie** de John Conway en utilisant la **programmation orientée objet (POO)** en **C++** et la bibliothèque graphique **SFML**.  

Le Jeu de la Vie est un automate cellulaire où une grille de cellules vivantes et mortes évolue selon des règles simples. Ce projet permet également à l'utilisateur de placer des constructions préprogrammées sur la grille grâce au clavier.

## Fonctionnalités
- Initialisation d'une grille avec des cellules vivantes ou mortes.
- Placement interactif de constructions prédéfinies (structures célèbres comme le *glider*, le *block*, etc.).
- Simulation de l'évolution de la grille selon les règles classiques du Jeu de la Vie :
  - Une cellule vivante avec moins de 2 voisins meurt (sous-population).
  - Une cellule vivante avec 2 ou 3 voisins survit.
  - Une cellule vivante avec plus de 3 voisins meurt (surpopulation).
  - Une cellule morte avec exactement 3 voisins devient vivante (reproduction).
- Affichage graphique avec SFML pour une meilleure visualisation.
- Tests unitaires avec **Google Test** pour assurer la fiabilité du code.

## Technologies utilisées
- **Langage** : C++
- **Framework graphique** : SFML
- **Environnement de développement** : WSL Ubuntu
- **Compilateur** : g++
- **Tests unitaires** : Google Test

## Installation et utilisation
### Prérequis
- C++17 ou plus récent
- SFML installé
- Google Test (pour les tests unitaires)

### Instructions
1. **Cloner le projet**  
   ```bash
   git clone https://github.com/Oscarcesi/le_jeu_de_la_vie
   cd le_jeu_de_la_vie
   ```

2. **Compiler le projet**  
   ```bash
   cd src/ && make
   ```

3. **Lancer l'application**  
   ```bash
   ./main
   ```

4. **Exécuter les tests unitaires**  
   Si les tests unitaires sont dans un fichier séparé (par exemple, `tests.cpp`), compilez et exécutez-les comme suit :  
   ```bash
   g++ ../src/cell.cpp ../src/grid.cpp tests_grid.cpp -o tests.exe -lgtest -lgtest_main -pthread
   ./tests
   ```

## Améliorations possibles
- Ajout de nouvelles règles personnalisables.
- Amélioration de l'interface utilisateur graphique.

## Auteurs
Projet réalisé dans le cadre de la deuxième année à **CESI**.  
**OSCAR** - Étudiant en développement logiciel.
