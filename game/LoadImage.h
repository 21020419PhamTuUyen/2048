#ifndef LOADIMAGE_H
#define LOADIMAGE_H

#include<SDL2/SDL_image.h>

SDL_Surface *load_image(SDL_Surface *screen,const char* path);
SDL_Rect make_rect(int x,int y,int w,int h);

#endif