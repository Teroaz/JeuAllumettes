#ifndef JEUALLUMETTES_INFORMATIONS_H
#define JEUALLUMETTES_INFORMATIONS_H

#include <stdio.h>

void printMenu();
void printRules();
void printCredits();
void printRemainingAllumettes(int);
void printHistory();
void savePvPToHistory(char *, char *, int, int);
void savePvEToHistory(char *, int, int, int);

#endif
