#include"sound.h"

void sound :: load(){
    int au = Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, 2, 1024);
    this->motion = Mix_LoadWAV("sound/motion.wav");
    this->click = Mix_LoadWAV("sound/click.wav");
    this->Move = Mix_LoadWAV("sound/move.wav");
}

void sound::off(){
    this->motion = NULL;
    this->click = NULL;
    this->Move = NULL;
}