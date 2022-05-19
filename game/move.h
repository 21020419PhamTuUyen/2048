#ifndef MOVE_H
#define MOVE_H

#include<SDL2/SDL.h>
#include"gameplay.h"
#include<SDL2/SDL_mixer.h>

//move points in any direction
void rushTop(int **&tab, int size);
void moveTop(int **&tab, int size, unsigned int &score);

void rushBot(int **&tab, int size) ;
void moveBot(int **&tab, int size, unsigned int &score) ;

void rushRight(int **&tab, int size);
void moveRight(int **&tab,int size, unsigned int &score) ;

void rushLeft(int **&tab, int size);
void moveLeft(int **&tab, int size, unsigned int &score) ;

void move(SDL_Event event, int **&tab, int size, int **&backtab, unsigned int &score, unsigned int &backScore,Mix_Chunk *chuck);
	
#endif