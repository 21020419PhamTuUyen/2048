#ifndef DRAW_H
#define DRAW_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<stdio.h>
#include"gameplay.h"

void DrawString(SDL_Surface *screen, int x, int y, const std::string text, SDL_Surface *charset);

// draw a single pixel
void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color);

// draw a vertical (when dx = 0, dy = 1) or horizontal (when dx = 1, dy = 0) line
void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color);

// draw a rectangle of size l by k
void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k,
                   Uint32 outlineColor, Uint32 fillColor); 

//Draw point of block in the middle of it
void DrawPoint(SDL_Surface *screen, int X, int Y, int width, const char *number, SDL_Surface *charset);


//draw board with all block and points
void DrawBoard(SDL_Surface *screen, int **tab, int size, Uint32 outlineColor, Uint32 fillColor, SDL_Surface *charset, int BOARD_WIDTH , int x,int y);

void DrawScore(SDL_Surface *screen, unsigned int score, SDL_Surface *charset, int x,int y);


#endif