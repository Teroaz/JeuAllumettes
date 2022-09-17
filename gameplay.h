#ifndef JEUALLUMETTES_GAMEPLAY_H
#define JEUALLUMETTES_GAMEPLAY_H

#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#include <unistd.h>

typedef struct player {
    char name[100];
    int hits;
    int nbAllumettes;
} Player;



void play();
void playHuman(int);
void playComputer(int);
int promptForMenuChoice();

#endif
