#include"botton.h"

botton::botton(int x,int y,int w,int h,SDL_Surface*screen , SDL_Surface*charset,const std::string text,int outline_color,int fill_color){
    this -> x = x;
    this -> y = y;
    this -> w = w;
    this -> h = h;
    this -> screen = screen;
    this -> charset = charset;
    this -> text = text;
    this -> outline_color = outline_color;
    this -> fill_color = fill_color;
}

void botton::draw_botton(){
    DrawRectangle(screen,x,y,w,h,outline_color,fill_color);
    DrawString(screen, x+6, y+10, text, charset);
}
