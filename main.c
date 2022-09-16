#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printInfo();
int promptForMenuChoice();
void printRules();
void printCredits();
void play();
void playHuman();
void playComputer();
void printRemainingAllumettes(int);

typedef struct player {
    char name[100];
    int hits;
    int nbAllumettes;
} Player;

int nbAllumettes = 30;

int main() {
    printInfo();

    while (1) {
        printf("\n");
        printf("\tQue faire ?\n");
        printf("1 - Jouer\n");
        printf("2 - Voir les règles du jeu\n");
        printf("3 - Voir les crédits\n");
        printf("4 - Quitter\n");

        switch (promptForMenuChoice()) {
            case 1:
                play();
                printf("Fin de la partie, voulez-vous rejouer ? (o/n)\n");
                break;
            case 2:
                printRules();
                break;
            case 3:
                printCredits();
                break;
            case 4:
                printf("Merci d'avoir joué !\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

void printCredits() {
    printf("Ce jeu a été développé par : \n");
    printf(" - Raphael\n");
    printf(" - Philippe\n");
}

void printInfo() {

    printf("Bonjour et bienvenue dans le jeu des allumettes !\n");
    printf("Vous allez avoir 3 menus.\n");
    printf("Vous choisirez d'abord si vous voulez voir les règles du jeu ou non, puis le nombre d'allumettes à utiliser, et enfin le nombre de joueurs\n");
}

void printRules() {
    printf("Le but du jeu est simple : \n");
    printf("Ce jeu se joue à deux. Vous avez un nombre n d'allumettes.\n");
    printf("A tour de role, chacun des deux joueurs enleve entre 1 et 3 allumettes selon ce qu'il souhaite. Le perdant est celui qui doit enlever la derniere allumette.\n");
    printf("\n");

    printf("Attention, il existe 3 niveaux de difficulté en version humain vs ordi.\n");
    printf("Le 1er est plutôt simple à battre, donc pour les débutant. Mais le dernier.....\n");
}

int promptForMenuChoice() {
    int choice;
    printf("Votre choix : ");
    scanf("%d", &choice);
    return choice;
}

void play() {

    srand(time(NULL));
    int gameMode;

    printf("Vous avez choisi de jouer !\n");
    printf("Vous allez maintenant choisir si vous souhaitez jouer contre un autre joueur ou contre l'ordinateur.\n");

    do {
        printf("\tVotre choix : \n");
        printf("1 - Humain vs Humain\n");
        printf("2 - Humain vs Ordinateur\n");
        scanf("%d", &gameMode);
    } while (gameMode != 1 && gameMode != 2);

    printf("Vous allez maintenant choisir le nombre d'allumettes à utiliser.\n");

    int allumetteValueChoice = 0;
    do {
        printf("\tVotre choix : \n");
        printf("1 - 25 allumettes\n");
        printf("2 - 30 allumettes\n");
        printf("3 - 35 allumettes\n");
        printf("4 - 40 allumettes\n");
        printf("5 - Aléatoire entre 25 et 40 allumettes\n");
        scanf("%d", &allumetteValueChoice);
    } while (allumetteValueChoice != 1 && allumetteValueChoice != 2 && allumetteValueChoice != 3 && allumetteValueChoice != 4 && allumetteValueChoice != 5);

    switch (allumetteValueChoice) {
        case 1:
            nbAllumettes = 25;
            break;
        case 2:
            nbAllumettes = 30;
            break;
        case 3:
            nbAllumettes = 35;
            break;
        case 4:
            nbAllumettes = 40;
            break;
        case 5:
            nbAllumettes = rand() % 15 + 25;
            break;
        default:
            break;
    }

    if (allumetteValueChoice != 5) {
        printf("Vous avez choisi %d allumettes.\n", nbAllumettes);
    } else {
        printf("Vous avez choisi un nombre aléatoire d'allumettes : %d.\n", nbAllumettes);
    }

    if (gameMode == 1) {
        playHuman();
    } else {
        playComputer();
    }
}

void playHuman() {
    Player player1 = {"Joueur 1", 0, nbAllumettes};
    Player player2 = {"Joueur 2", 0, nbAllumettes};
    printf("Vous avez choisi de jouer contre un autre joueur.\n");
    printf("Veuillez entrer le nom du joueur 1 : ");
    scanf("%s", player1.name);
    printf("Veuillez entrer le nom du joueur 2 : ");
    scanf("%s", player2.name);

    printf("Vous allez maintenant commencer la partie !\n");

    int allumettesRestantes = nbAllumettes;
    int allumettesPrises = 0;

    while (allumettesRestantes > 0) {
        printRemainingAllumettes(allumettesRestantes);

        printf("> %s, combien d'allumettes voulez-vous prendre ? (1, 2 ou 3)\n", player1.name);
        scanf("%d", &allumettesPrises);

        while (allumettesPrises < 1 || allumettesPrises > 3) {
            printf("Vous ne pouvez pas prendre %d allumettes, veuillez en prendre entre 1 et 3.\n", allumettesPrises);
            scanf("%d", &allumettesPrises);
        }
        player1.nbAllumettes += allumettesPrises;
        player1.hits++;

        allumettesRestantes -= allumettesPrises;
        if (allumettesRestantes <= 0) {
            printf("%s a gagné en %d coups !\n", player2.name, player2.hits);
            break;
        }

        printRemainingAllumettes(allumettesRestantes);

        printf("> %s, combien d'allumettes voulez-vous prendre ? (1, 2 ou 3)\n", player2.name);
        scanf("%d", &allumettesPrises);

        while (allumettesPrises < 1 || allumettesPrises > 3) {
            printf("Vous ne pouvez pas prendre %d allumettes, veuillez en prendre entre 1 et 3.\n", allumettesPrises);
            scanf("%d", &allumettesPrises);
        }

        player2.nbAllumettes += allumettesPrises;
        player2.hits++;
        allumettesRestantes -= allumettesPrises;
        if (allumettesRestantes <= 0) {
            printf("%s a gagné en %d coups !\n", player1.name, player1.hits);
            break;
        }
    }
}

void playComputer() {
    Player player = {"Joueur", 0, nbAllumettes};
    printf("Vous avez choisi de jouer contre l'ordinateur.\n");
    printf("> Veuillez entrer votre nom : ");
    scanf("%s", player.name);

    int difficulty;
    do {
        printf("\tVotre choix : \n");
        printf("1 - Facile\n");
        printf("2 - Moyen\n");
        printf("3 - Difficile\n");
        scanf("%d", &difficulty);
    } while (difficulty != 1 && difficulty != 2 && difficulty != 3);

    switch (difficulty) {
        case 1:
            printf("Vous avez choisi le niveau facile.\n");
            break;
        case 2:
            printf("Vous avez choisi le niveau moyen.\n");
            break;
        case 3:
            printf("Vous avez choisi le niveau difficile.\n");
            break;
        default:
            break;
    }

    printf("Vous allez maintenant commencer la partie !\n");

    int allumettesRestantes = nbAllumettes;
    int allumettesPrises = 0;

    while (allumettesRestantes > 0) {
        printRemainingAllumettes(allumettesRestantes);
        printf("Combien d'allumettes voulez-vous prendre ?\n");

        scanf("%d", &allumettesPrises);

        while (allumettesPrises < 1 || allumettesPrises > 3) {
            printf("Vous ne pouvez pas prendre %d allumettes, veuillez en prendre entre 1 et 3.\n", allumettesPrises);
            scanf("%d", &allumettesPrises);
        }

        allumettesRestantes -= allumettesPrises;

        player.nbAllumettes += allumettesPrises;
        player.hits++;

        if (allumettesRestantes <= 0) {
            printf("Vous avez perdu !\n");
            break;
        }

        printRemainingAllumettes(allumettesRestantes);
        printf("L'ordinateur va maintenant jouer.\n");

        switch (difficulty) {
            case 1:
                allumettesPrises = rand() % 3 + 1;
                break;
            case 2:
                allumettesPrises = rand() % 2 + 1;
                break;
            case 3:
                allumettesPrises = 4 - allumettesPrises;
                break;
            default:
                break;
        }

        printf("L'ordinateur a pris %d allumettes.\n", allumettesPrises);
        allumettesRestantes -= allumettesPrises;

        if (allumettesRestantes <= 0) {
            printf("Vous avez gagné !\n");
            break;
        }
    }
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