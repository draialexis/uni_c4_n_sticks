#include <stdio.h>
#include <stdlib.h>

#include "puissance4.h"

#define INIT_BAT_NB 20
#define LIN 6
#define COL 7

//TODO put functions in .h files to make the main file leaner and easier to use

/*
 * v v v   fonctions liées au jeu des bâtonnets   v v v
 */

//TODO inmplement CPU-player

int takeBatCheck(int currentBatNb) {

    char input[16];
    int value;
    fgets(input, 15, stdin);
    value = (int) strtol(input, NULL, 10);

    if (value >= 1 && value <= 3 && value < currentBatNb) {
        printf("vous avez choisi : %d batonnet(s).\nil en reste %d\n", value, currentBatNb - value);
        return currentBatNb - value;
    } else {
        printf("l'input est invalide\nvous devez choisir d'enlever entre 1 et 3 batonnets,"
               " et moins que le nombre de batonnets restant\n");
        return takeBatCheck(currentBatNb);
    }
}

int batonnets() {
    int currentPlayer = 1;
    int currentBatNb = INIT_BAT_NB;
    printf("jeu des batonnets :\nil y a 20 batonnets. veuillez choisir le nombre de batonnets a retirer.\n"
           "(le nombre initial est %d, et vous pouvez retirer 1, 2, ou 3 batonnets)\n", INIT_BAT_NB);

    while (currentBatNb > 1) {
        if (currentPlayer == 1) {
            printf("joueur 1 : ");
            currentPlayer = 2;
        } else {
            printf("joueur 2 : ");
            currentPlayer = 1;
        }
        currentBatNb = takeBatCheck(currentBatNb);
    }
    printf("========== joueur %d -- acceptez votre defaite ==========\n", currentPlayer);
    return currentPlayer == 2 ? 1 : 2; // le joueur actuel est celui qui n'a pas pu jouer son dernier coup ( => défaite)
    // -> "joueur actuel est #2? si oui, return 1 -- sinon, return 2"
}

/*
 * ^ ^ ^   fonctions liées au jeu des bâtonnets   ^ ^ ^
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//TODO

int main() {
    int gameNb = 0;
    int winner = 0;
    while (gameNb != 1 && gameNb != 2) {
        printf("choisissez un jeu :\n 1 -- batonnets\n 2 -- puissance4\n\n-1 -- quitter le menu\n");

        char input[16];

        fgets(input, 15, stdin);
        gameNb = (int) strtol(input, NULL, 10);

        if (gameNb == -1) {
            return 0;
        }
    }

    if (gameNb == 1) {
        winner = batonnets();
    } else {
        winner = puissance4();
    }

    if (winner) {
        printf("le vainqueur est : joueur %d\n", winner);
    }

    return 0;
}