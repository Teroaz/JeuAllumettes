#include "main.h"

int main() {
    printMenu();

    while (1) {

        printf("\n");
        printf("[CHOIX] Que faire ?\n");
        printf("1 - Jouer\n");
        printf("2 - Voir les règles du jeu\n");
        printf("3 - Voir les crédits\n");
        printf("4 - Afficher l'historique des parties\n");
        printf("5 - Quitter\n");

        int choice;
        printf("> Votre choix :\n");
        scanf("%d", &choice);

        switch (choice) {
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
                printHistory();
                break;
            case 5:
                printf("[INFO] Merci d'avoir joué !\n");
                return 0;
            default:
                printf("[ERREUR] Choix invalide. Re-essayer !.\n");
                break;
        }
        sleep(1);
    }
}
