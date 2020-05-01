#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "PlayerBoard.h"

class Player{
    public:
    Player();
    ~Player();

    int getScore();

    void setScore();

    std::string getName();

    private:
    PlayerBoard playerBoard;
    int playerScore;
    std::string playerName;
};

#endif // PLAYER_H