#ifndef JEUALLUMETTES_GAMEPLAY_H
#define JEUALLUMETTES_GAMEPLAY_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"
#include "informations.h"

typedef struct player {
    char name[100];
    int hits;
    int nbAllumettes;
} Player;


void play();
void playHuman(int);
void playComputer(int);

#endif
