
#include "gameplay.h"


void play() {

    srand(time(NULL));

    printf("[INFO] Vous avez choisi de jouer !\n");
    printf("[INFO] Vous allez maintenant choisir si vous souhaitez jouer contre un autre joueur ou contre l'ordinateur.\n");

    int gameMode;
    do {
        printf("[CHOIX] Mode de jeu : \n");
        printf("1 - Humain vs Humain\n");
        printf("2 - Humain vs Ordinateur\n");
        secure_scanf("%d", &gameMode);
    } while (gameMode != 1 && gameMode != 2);

    printf("Vous allez maintenant choisir le nombre d'allumettes à utiliser.\n");

    int allumetteValueChoice = 0;
    do {
        printf("[CHOIX] Nombre d'allumettes : \n");
        printf("1 - 25 allumettes\n");
        printf("2 - 30 allumettes\n");
        printf("3 - 35 allumettes\n");
        printf("4 - 40 allumettes\n");
        printf("5 - Aléatoire entre 25 et 40 allumettes\n");
        secure_scanf("%d", &allumetteValueChoice);
    } while (allumetteValueChoice != 1 && allumetteValueChoice != 2 && allumetteValueChoice != 3 && allumetteValueChoice != 4 && allumetteValueChoice != 5);

    int nbAllumettes;
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
        printf("[INFO] Vous avez choisi %d allumettes.\n", nbAllumettes);
    } else {
        printf("[INFO] Vous avez choisi un nombre aléatoire d'allumettes : %d.\n", nbAllumettes);
    }

    if (gameMode == 1) {
        playHuman(nbAllumettes);
    } else {
        playComputer(nbAllumettes);
    }
}


void playHuman(int nbAllumettes) {
    Player player1 = {"Joueur 1", 0};
    Player player2 = {"Joueur 2", 0};
    printf("[INFO] Vous avez choisi de jouer contre un autre joueur.\n");

    printf("> Veuillez entrer le nom du joueur 1 : ");

    secure_scanf("%[^\n]", player1.name);

    printf("> Veuillez entrer le nom du joueur 2 : ");
    secure_scanf("%[^\n]", player2.name);

    if (strcmp(player1.name, player2.name) == 0) {
        printf("[INFO] Oh des jumeaux ! Nous allons quand même vous différencier.\n");
        player1.name[strlen(player1.name)] = '1';
        player2.name[strlen(player2.name)] = '2';
    }

    printf("Vous allez maintenant commencer la partie !\n");

    int allumettesRestantes = nbAllumettes;
    int allumettesPrises = 0;

    while (allumettesRestantes > 0) {
        printRemainingAllumettes(allumettesRestantes);

        printf("> %s, combien d'allumettes voulez-vous prendre ? (1, 2 ou 3)\n", player1.name);
        secure_scanf("%d", &allumettesPrises);

        while (allumettesPrises < 1 || allumettesPrises > 3) {
            printf("[ERREUR] > Vous ne pouvez pas prendre %d allumettes, veuillez en prendre entre 1 et 3.\n", allumettesPrises);
            secure_scanf("%d", &allumettesPrises);
        }
        player1.nbAllumettes += allumettesPrises;
        player1.hits++;

        allumettesRestantes -= allumettesPrises;
        if (allumettesRestantes <= 0) {
            printf("[INFO] %s a gagné en %d coups !\n", player2.name, player2.hits);
            savePvPToHistory(player2.name, player1.name, player2.hits, nbAllumettes);
            break;
        }

        printRemainingAllumettes(allumettesRestantes);

        printf("> %s, combien d'allumettes voulez-vous prendre ? (1, 2 ou 3)\n", player2.name);
        secure_scanf("%d", &allumettesPrises);

        while (allumettesPrises < 1 || allumettesPrises > 3) {
            printf("[ERREUR] > Vous ne pouvez pas prendre %d allumettes, veuillez en prendre entre 1 et 3.\n", allumettesPrises);
            secure_scanf("%d", &allumettesPrises);
        }

        player2.nbAllumettes += allumettesPrises;
        player2.hits++;

        allumettesRestantes -= allumettesPrises;
        if (allumettesRestantes <= 0) {
            printf("[INFO] %s a gagné en %d coups !\n", player1.name, player1.hits);
            savePvPToHistory(player1.name, player2.name, player1.hits, nbAllumettes);
            break;
        }
    }
}


void playComputer(int nbAllumettes) {

    Player player = {"Joueur", 0, nbAllumettes};
    printf("[INFO] Vous avez choisi de jouer contre l'ordinateur.\n");
    printf("> Veuillez entrer votre nom : ");
    fgets(player.name, 100, stdin);

    int difficulty;
    do {
        printf("[CHOIX] Niveau de difficulté : \n");
        printf("1 - Facile\n");
        printf("2 - Moyen\n");
        printf("3 - Difficile\n");
        secure_scanf("%d", &difficulty);
    } while (difficulty != 1 && difficulty != 2 && difficulty != 3);

    switch (difficulty) {
        case 1:
            printf("[INFO] Vous avez choisi le niveau facile.\n");
            break;
        case 2:
            printf("[INFO] Vous avez choisi le niveau moyen.\n");
            break;
        case 3:
            printf("[INFO] Vous avez choisi le niveau difficile.\n");
            break;
        default:
            break;
    }

    printf("[INFO] Vous allez maintenant commencer la partie !\n");

    int allumettesRestantes = nbAllumettes;
    int allumettesPrises = 0;

    while (allumettesRestantes > 0) {
        printRemainingAllumettes(allumettesRestantes);
        printf("> Combien d'allumettes voulez-vous prendre ?\n");

        secure_scanf("%d", &allumettesPrises);

        while (allumettesPrises < 1 || allumettesPrises > 3) {
            printf("[ERREUR] > Vous ne pouvez pas prendre %d allumettes, veuillez en prendre entre 1 et 3.\n", allumettesPrises);
            secure_scanf("%d", &allumettesPrises);
        }

        allumettesRestantes -= allumettesPrises;

        player.nbAllumettes += allumettesPrises;
        player.hits++;

        if (allumettesRestantes <= 0) {
            printf("[INFO] FIN DE LA PARTIE : Vous avez perdu ! TROP NUL(LE) !!\n");
            savePvEToHistory(player.name, player.hits, nbAllumettes, 0);
            break;
        }

        printRemainingAllumettes(allumettesRestantes);
        printf("[INFO] L'ordinateur va maintenant jouer.\n");

        int takenAllumettes = 0;
        switch (difficulty) {
            case 1:
                takenAllumettes = rand() % 2 + 1;
                break;
            case 2:
                do {
                    takenAllumettes = rand() % 2 + 1;
                } while (allumettesRestantes - takenAllumettes <= 0);
                break;
            case 3:
                if ((allumettesRestantes + 3) % 4 != 0) {
                    takenAllumettes = (allumettesRestantes + 3) % 4;
                } else {
                    takenAllumettes = 1;
                }
                break;
            default:
                break;
        }

        sleep(rand() % 1 + 1);

        allumettesPrises = takenAllumettes;

        printf("[INFO] L'ordinateur a pris %d %s.\n", allumettesPrises, allumettesPrises > 1 ? "allumettes" : "allumette");
        allumettesRestantes -= allumettesPrises;

        if (allumettesRestantes <= 0) {
            printf("[INFO] FIN DE LA PARTIE : Vous avez gagné ! BRAVO !\n");
            savePvEToHistory(player.name, player.hits, nbAllumettes, 1);
            break;
        }
    }
}
