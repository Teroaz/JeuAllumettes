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

void printHistory() {
    printf("###############    HISTORIQUE   ###############\n");
    FILE *file = fopen("history.txt", "r");
    if (file == NULL) {
        printf("[INFO] Aucune partie n'a été jouée.\n");
        return;
    }

    char line[256];
    int i = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("Partie #%d - %s", i, line);
    }

    fclose(file);
}

void savePvPToHistory(char *winnerName, char *loserName, int hits, int nbAllumettes) {
    FILE *file = fopen("history.txt", "a");
    if (file == NULL) {
        return;
    }

    printf("[INFO] Sauvegarde de la partie dans l'historique...\n");

    fprintf(file, "%s a gagné la partie contre %s en %d coups avec %d allumettes.\n", winnerName, loserName, hits, nbAllumettes);
    fclose(file);
}

void savePvEToHistory(char *winnerName, int hits, int nbAllumettes, int hasLose) {
    FILE *file = fopen("history.txt", "a");
    if (file == NULL) {
        return;
    }


    printf("[INFO] Sauvegarde de la partie dans l'historique...\n");
    if (hasLose) {
        fprintf(file, "%s a gagné la partie contre l'ordinateur en %d coups avec %d allumettes.\n", winnerName, hits, nbAllumettes);
    } else {
        fprintf(file, "%s a perdu la partie contre l'ordinateur avec %d allumettes.\n", winnerName, nbAllumettes);
    }

    fclose(file);
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
