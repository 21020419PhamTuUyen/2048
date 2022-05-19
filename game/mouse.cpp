#include"mouse.h"

bool mouse_in_botton (botton botton){
    int x,y;
    SDL_GetMouseState(&x,&y);
    if((x>=botton.x && x<=botton.x + botton.w) && (y>=botton.y && y<=botton.y + botton.h)){
        return true;
    }
    else return false;
}

bool mouse_touch_botton(botton botton){
    int x,y;
    SDL_GetMouseState(&x,&y);
    if((x>=botton.x && x<=(botton.x +botton.w) && y==botton.y) ||
        (x>=botton.x && x<=(botton.x +botton.w) && y==(botton.y + botton.h)) ||
        (x==botton.x && y>=botton.y && y<=(botton.y + botton.h)) ||
        (x==(botton.x + botton.w) && y>=botton.y && y<=(botton.y + botton.h) ))
            return true;
    else return false;
}
