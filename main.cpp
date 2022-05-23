#include<iostream>
#include"game/botton.h"
#include"game/mouse.h"
#include"game/draw.h"
#include"game/move.h"
#include"save/player.h"
#include"game/LoadImage.h"
#include"game/sound.h"



#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int i=0;
int Size[3] = {4,5,6};
int BOARD_WIDTH[3] ={300,350,400};
int BOARD_X[3]= {200,150,130};
int BOARD_Y[3] ={90,70,50};
int max[3] = {2048,4096,8192};

SDL_Window* window;
SDL_Surface* screen,*charset;
SDL_Renderer* renderer;
SDL_Texture *scrtex;

unsigned int score,backscore;
std::string name;
Player player(name,score);
int** tab,**backtab;

void load_on_screen(){
        SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
        SDL_RenderPresent(renderer);
}

void close(){
    SDL_FreeSurface(screen);
    SDL_FreeSurface(charset);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(scrtex);
    SDL_DestroyWindow(window);
}

int main(int argc, char **argv){
    //sounds
    sound Sound;
    Sound.load();

   //screen
    int rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,0,&window,&renderer);
    SDL_SetWindowTitle(window,"2048");

    screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH, SCREEN_HEIGHT);

    const int black = SDL_MapRGB(screen->format,0,0,0);
    const int white = SDL_MapRGB(screen->format,225,225,225);
    const int lightblue = SDL_MapRGB(screen->format,135,132,227);
    const int puple = SDL_MapRGB(screen->format,128,0,128);
    const int whitepink = SDL_MapRGB(screen->format,255,153,255);

    //text
	charset = SDL_LoadBMP("image/32.bmp");
    SDL_SetColorKey(charset, true, 0x00);
    std::string text;

    //title image
    SDL_Surface *image = load_image(screen,"image/2048.png");
    SDL_Rect rect = make_rect(100,30,400,200);

    //sound image
    SDL_Surface *s_on = load_image(screen,"image/sound_on.png");
    SDL_Surface *s_off = load_image(screen,"image/sound_off.png");
    SDL_Rect Rect = make_rect(500,0,70,70);
    bool sound_on = true;

    bool running = 1;
    int status = 1;
    while(running)
    {
    
    SDL_Event event;
    //menu
    while(status == 1){
        SDL_FillRect(screen,NULL,black);
        while(SDL_PollEvent(&event)){
           //load the title image
            SDL_BlitScaled(image,NULL,screen,&rect);
            //load sound image
            SDL_BlitScaled(( sound_on? s_on:s_off ),NULL,screen,&Rect);
           //new game botton
            botton new_game(SCREEN_WIDTH/2-110,SCREEN_HEIGHT/2-50,200,50,screen,charset,"NEW GAME",white,black);
            new_game.draw_botton();
            //score botton
            botton Score(SCREEN_WIDTH/2-80,SCREEN_HEIGHT/2+10,130,50,screen,charset,"SCORE",white,black);
            Score.draw_botton();
            //sound botton
            botton sound(500,0,70,70,screen,charset,"",black,black);
            load_on_screen();
            if(event.type == SDL_MOUSEMOTION ){
                if(mouse_in_botton(new_game)){
                    if(mouse_touch_botton(new_game)){
                        Mix_PlayChannel(-1,Sound.motion,0);
                    }
                    new_game.fill_color = puple;
                    new_game.draw_botton();
                    load_on_screen();
                    
                }
                   
                if(mouse_in_botton(Score)){
                    if(mouse_touch_botton(Score)){
                    Mix_PlayChannel(-1,Sound.motion,0);
                    }
                    Score.fill_color = puple;
                    Score.draw_botton();
                    load_on_screen();
                }
                
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN){
                if(mouse_in_botton(new_game)){
                    score=0;
                    backscore=0;
                    name="";
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 2;
                }
                else if(mouse_in_botton(Score)){
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 5;
                }
                else if(mouse_in_botton(sound)){
                    if(!sound_on) {
                        Sound.load();
                        sound_on = true;
                    }
                    else if(sound_on){
                         Sound.off();
                         sound_on = false;
                    }
                }
            }
            else if(event.type == SDL_QUIT){
                close();
                status = 0;
            }
            
       }
    }

    botton back(0,0,180,50,screen,charset,"<-BACK",black,black);
    botton enter(450,0,180,50,screen,charset,"ENTER->",black,black);
    while(status == 2){
        SDL_FillRect(screen,NULL,black);
        back.draw_botton();
        enter.draw_botton();
        DrawString(screen,30,200,"enter your name: ",charset);
        DrawString(screen,400,200,name,charset);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_BACKSPACE && name.length()!=0)
                    name.pop_back();
                else if(event.key.keysym.sym == SDLK_RETURN){
                    if(name=="") name = "player";
                    player.name = name;
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 3;
                }            
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN){
                if(mouse_in_botton(back)){
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 1;
                }
                else if(mouse_in_botton(enter)){
                    if(name=="") name = "player";
                    player.name = name;
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 3;
                }
            }
            else if(event.type == SDL_QUIT){
                status = 0;

            }
            else if(event.type == SDL_TEXTINPUT){
                name+=event.text.text;
            }

        }  
        load_on_screen();
    }
    
    char level[3];
    while(status == 3){
        SDL_FillRect(screen,NULL,black);
        back.draw_botton();
        enter.draw_botton();
        DrawString(screen,30,200,"chose board's size:",charset);
        sprintf(level,"<- %d ->",Size[i]);
        DrawString(screen,230,250,level,charset);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                status = 0;
            }
            else if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_RETURN){
                    status = 4;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                    Mix_PlayChannel(-1,Sound.click,0);
                     i++;
                     if(i==3) i=2;
                }
                else if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                    Mix_PlayChannel(-1,Sound.click,0);
                     i--;
                    if(i==-1) i=0;
                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN){
                if(mouse_in_botton(back)){
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 1;
                }
                else if(mouse_in_botton(enter)){
                    tab = createtab(Size[i]);
                    backtab = createtab(Size[i]);
                    copyTab(tab,backtab,Size[i]);
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 4;
                }
            }
        }
        load_on_screen();
    }

    //game start

    while(status == 4){
        if(!checkLose(tab,Size[i])  && !checkWin(tab,Size[i],max[i])){

        SDL_FillRect(screen, NULL, black);
        DrawString(screen,400,450,"u-remove",charset);

        back.draw_botton();
        DrawBoard(screen, tab, Size[i], black, lightblue, charset,BOARD_WIDTH[i],BOARD_Y[i],BOARD_X[i]);
		DrawScore(screen, score, charset,300,0);

        while(SDL_PollEvent(&event)){
            switch(event.type) {
				case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d
                        || event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN)
                            move(event, tab, Size[i], backtab, score, backscore,Sound.Move);

                    else if (event.key.keysym.sym == SDLK_u) { 
							copyTab(tab, backtab, Size[i]); 
							score = backscore;
					}

                    break;
                case SDL_MOUSEBUTTONDOWN:  
                    if(mouse_in_botton(back)){
                        player.score = score;
                        player.save();
                        Mix_PlayChannel(-1,Sound.click,0);
                        status = 1;    
                    }
                    break;
                case SDL_QUIT:
                    player.score = score;
                    player.save();
                    status = 0;
                    close();
                    break;
            
            }
            load_on_screen();
        }
        }
        else{
            SDL_FillRect(screen,NULL,black);
            if(checkWin(tab,Size[i],max[i]))  DrawString(screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2-50,"YOU WIN",charset);
            else if(checkLose(tab,Size[i])) DrawString(screen,SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2-50,"YOU LOSE",charset);  
            char k[1000000];
            sprintf(k,"%d",score);
            text = "YOUR SCORE: ";
            text+=k;
            DrawString(screen,SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2,text,charset);
            DrawString(screen,400,450,"n-new game",charset);
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT ){
                    player.save();
                    status = 0;
                }
                else if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_n){
                        player.save();
                        status = 1;
                    }
                }
            }
            load_on_screen();
        }
    }
    while(status == 5){
        SDL_FillRect(screen,NULL,black);
        DrawString(screen,170,100,"Highest score",charset);
        back.draw_botton();
        std::vector<Player> list; 
        makelist(list);
        int lines = list.size();
        int x1=100,y1=180,x2=450,y2=180;
        for(int i=0;i<lines;i++){
            DrawString(screen,x1,y1,list[i].name,charset);
            char k[1000000];
            sprintf(k,"%d",list[i].score); 
            DrawString(screen,x2,y2,k,charset);
            y1+=24;y2+=24;
            if(i==9) break;
        }
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                status = 0;
                break;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN){
                if(mouse_in_botton(back)){
                    Mix_PlayChannel(-1,Sound.click,0);
                    status = 1;
                }
            }
        }
         load_on_screen();
    }

    if(status==0)
        running = false;
    }
    close();
    return 0;
}