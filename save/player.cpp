#include"player.h"

Player :: Player (std::string name,unsigned int score ){
    this->name = name;
    this->score = score;
}



void Player :: save(){
    std::fstream file("save/score_list.txt");
    std::fstream fi;
    fi.open("save/t.txt",std::ios::out);
    std::string s;
    unsigned int k;
    while(!file.eof()){
        std::getline(file,s,',');
        if(s[0]<32) s.erase(0,1);
        file>>k;
        if(k<score) break;
        else {
            if(s!="") //this condition is to fix open file bug (even though there is nothing in file, but this loop still runs)
            fi<<s<<","<<k<<std::endl;     
        }
    }
    fi<<name<<","<<score<<std::endl;
    while(!file.eof()){
        fi<<s<<","<<k<<std::endl;
        std::getline(file,s,',');
        if(s[0]<32) s.erase(0,1);
        file>>k;
    }
    fi.close();
    file.close();
    int x = remove("save/score_list.txt");
    int y = rename("save/t.txt","save/score_list.txt");
}


void makelist(std::vector<Player> &list){
    std::fstream file("save/score_list.txt");
    while(!file.eof()){
        std::string name;
        unsigned int score;
        std::getline(file,name,',');
        if(name[0]<32)name.erase(0,1);
        file>>score;
        Player player(name,score);
        list.push_back(player);
    }
    file.close();
}
