#include"LoadImage.h"

SDL_Surface *load_image(SDL_Surface *screen, const char* path){
    int imgFlags = IMG_INIT_PNG;
    SDL_Surface *load_image, *optimized;
    load_image = IMG_Load(path);
    optimized = SDL_ConvertSurface(load_image,screen->format,0);
    SDL_FreeSurface(load_image);
    return optimized;
    SDL_Rect image;
}
SDL_Rect make_rect(int x,int y,int w,int h){
    SDL_Rect image;
    image.x=x;
    image.y=y;
    image.w=w;
    image.h=h;
    return image;
}