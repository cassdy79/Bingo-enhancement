#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "PlayerBoard.h"

class Player{
    public:
        Player(std::string playerName);
        ~Player();
        int getScore();
        void setScore(int score);
        PlayerBoard* getPlayerBoard();
        std::string getName();
        void printPlayerBoard();

    private:
        PlayerBoard* playerBoard;
        int playerScore;
        std::string playerName;
};

#endif // PLAYER_H