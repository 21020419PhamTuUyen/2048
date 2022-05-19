#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <io.h>
#include <vector>

class Player{
    public:
        std::string name;
        unsigned int score;
        Player (std::string name,unsigned int score);
        
        void save();
        
};


void makelist(std::vector<Player> &list);


#endif