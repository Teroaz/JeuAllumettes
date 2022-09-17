#include "main.h"

int main() {
    printMenu();

    while (1) {

        printf("\n");
        printf("[CHOIX] Que faire ?\n");
        printf("1 - Jouer\n");
        printf("2 - Voir les règles du jeu\n");
        printf("3 - Voir les crédits\n");
        printf("4 - Quitter\n");

        switch (promptForMenuChoice()) {
            case 1:
                play();
                break;
            case 2:
                printRules();
                break;
            case 3:
                printCredits();
                break;
            case 4:
                printf("[INFO] Merci d'avoir joué !\n");
                return 0;
            default:
                printf("[ERREUR] Choix invalide. Re-essayer !.\n");
                break;
        }
        sleep(1);
    }
}
