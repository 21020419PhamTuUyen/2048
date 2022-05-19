#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include<stdlib.h>

int get_power(int x);

int** createtab(int size);

bool checkWin(int **&tab, int size,int max);

bool checkPut(int **&tab, int size);

bool checkLose(int **&tab, int size);

bool checkToRandom(int **&tab, int **&backTab, int size);

void randomOnBoard(int **&tab, int size);

void copyTab(int **&tab1,int **&tab2, int size);


#endif