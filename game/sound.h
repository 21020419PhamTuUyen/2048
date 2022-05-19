#ifndef SOUND_H
#define SOUND_H

#include<SDL2/SDL_mixer.h>

class sound{
    public:
        Mix_Chunk *motion,*click,*Move;
        void load();
        void off();
};

#endif