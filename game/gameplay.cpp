#include"gameplay.h"

//get the color of the pixel that contain this number(x)
int get_power(int x) {
	int n = 0;
	while (x != 0) {
		x = x/2;
		n++;
	}

	return n;
}

int** createtab(int size) {
	int **tab;
	tab = new int *[size];
	for (int i = 0; i < size; ++i) tab[i] = new int[size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tab[i][j] = 0;
		}
	}
	int X = rand() % size;
	int Y = rand() % size;
	tab[X][Y] = 2;
	X = rand() % size;
	Y = rand() % size;
	tab[X][Y] = 2;

	return tab;
}

bool checkWin(int **&tab, int size,int max) {
	bool win = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (tab[i][j] == max) win = 1;
		}
	}

	return win;
}

bool checkPut(int **&tab, int size) {
	bool put = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (tab[i][j] == 0) put = 1;
		}
	}

	return put;
}

bool checkLose(int **&tab, int size) {
	bool lose = 1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (tab[i][j] == tab[i][j + 1]) lose = 0;
		}
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size; j++) {
			if (tab[i][j] == tab[i + 1][j]) lose = 0;
		}
	}

	if (checkPut(tab, size)) lose = 0;

	return lose;
}

bool checkToRandom(int **&tab, int **&backTab, int size) {
	int can_put = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (tab[i][j] != backTab[i][j]) can_put = 1;
		}
	}
	return can_put;
}

void randomOnBoard(int **&tab, int size) {

	if (checkPut(tab, size)) {
		int values[10] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
		int value = values[rand() % 10];

		int X = rand() % size;
		int Y = rand() % size;
		if (tab[X][Y] == 0) tab[X][Y] = 2;
		else {
			while (tab[X][Y] != 0) {
				X = rand() % size;
				Y = rand() % size;
			}
			tab[X][Y] = value;
		}
	}
}
//to remove
void copyTab(int **&tab1,int **&tab2, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) tab1[i][j] = tab2[i][j];
	}
}