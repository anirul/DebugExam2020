# ExamDebug920

## Exercice 1 (Points: 20)
Faites un petit programme dans le but est de prendre en entrée console le rayon d’un cercle,
puis de calculer la surface et le périmètre.

La sortie console de votre programme devrait ressembler à cela:
```
Welcome! Set the radius for a circle
56
The area is: 9852.03
The perimeter is: 351.858
```
## Exercice 2 (Points: 30)
Faites un programme qui prend en entrée console cinq nombres entiers et en calcule la
moyenne.
Le programme doit contenir une fonction pour calculer la moyenne depuis un std::vector.
La sortie console de votre programme devrait ressembler à cela:
```
Insert 5 numbers:
4
6
13
78
3
The average is: 20.8
```
## Exercice 3 (Points: 50)
Faites un petit jeu inspiré par Rogue où le joueur incarne un petit héros dont le but est de
rejoindre sa copine sans toucher de fantôme.

À chaque mouvement du héros, les fantômes bougent également de manière aléatoire.

Voici les classes principales:
* GameObject: N’importe quel personnage sur la scène (sans compter le sol), contient
la sprite affichée et la position courante sur le grid.
* Hero: Contrôle le personnage joueur, il peut se déplacer dans les quatre directions
tant qu’il ne sort pas de l’écran, appelle la méthode Step du GameManager pour faire
bouger les fantômes
* RogueMonster: Contrôle les fantômes, bouge aléatoirement lorsque Step est appelé.
* GameManager: Point central du jeu, contenant tous les éléments du jeu, ainsi que la
boucle principale du jeu.
* GridMap: Une simple class pour afficher le sol derrière les personnages
Globals.h contient la plupart des constantes importantes dans le jeu.

Le jeu quitte lorsque:
* Le joueur appuie sur la croix en haut
* Le héros touche un fantôme (Un message de game over est affiché sur la console)
* Le héros touche la fille (Un message de victoire est affiché sur la console)

![image](https://drive.google.com/uc?export=view&id=1eCTJLqtNhLgvbjjwZK-51ITFcjGwVPSn)
