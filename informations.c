#include "informations.h"


void printMenu() {
    printf("###############      MENU       ###############\n");
    printf("Bonjour et bienvenue dans le jeu des allumettes !\n");
    printf("Vous allez avoir 3 menus.\n");
    printf("Vous choisirez d'abord si vous voulez voir les règles du jeu ou non, puis le nombre d'allumettes à utiliser, et enfin le nombre de joueurs\n");
}


void printRules() {
    printf("###############     RÈGLES      ###############\n");
    printf("Le but du jeu est simple : \n");
    printf("Ce jeu se joue à deux. Vous avez un nombre n d'allumettes.\n");
    printf("A tour de role, chacun des deux joueurs enleve entre 1 et 3 allumettes selon ce qu'il souhaite. Le perdant est celui qui doit enlever la derniere allumette.\n");
    printf("\n");

    printf("Attention, il existe 3 niveaux de difficulté en version humain vs ordi.\n");
    printf("Le 1er est plutôt simple à battre, donc pour les débutant. Mais le dernier.....\n");
}


void printCredits() {
    printf("###############     CREDITS     ###############\n");
    printf("> Développé par Raphael BARRIET & Philippe SARAFIAN\n");
    printf("> Module : Programmation C et C++\n");
    printf("> Année : 2022-2023\n");
}


void printRemainingAllumettes (int allumettesRestantes) {
    for (int i = 0; i < 40; i++) {
        if (i < allumettesRestantes) {
            printf("|");
        } else {
            printf(" ");
        }
    }

    printf("Il reste %d %s.\n", allumettesRestantes, allumettesRestantes > 1 ? "allumettes" : "allumette");
}
