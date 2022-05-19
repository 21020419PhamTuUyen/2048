#ifndef BOTTON_H
#define BOTTON_H

#include<iostream>
#include<string>
#include"draw.h"



class botton{
    public:
    int x,y,w,h;
    SDL_Surface *screen,*charset;
    std::string text;
    int outline_color;
    int fill_color;
    
    botton(int x,int y,int w,int h,SDL_Surface*screen , SDL_Surface*charset,const std:: string text,int outline_color,int fill_color);
    void draw_botton();
    void bdrawstring();

};

 

#endif