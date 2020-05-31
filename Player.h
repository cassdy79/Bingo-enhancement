#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "PlayerBoard.h"

class Player{
    public:
        Player(std::string playerName, bool bot);
        ~Player();
        int getScore();
        void setScore();
        PlayerBoard* getPlayerBoard();
        std::string getName();
        void printPlayerBoard();
        void setFirstPlayerMark(bool set);
        bool firstPlayer();
        bool botCheck();

        //loads data from save into player variables
        bool loadPlayerName(std::string loadInput);
        bool loadPlayerScore(std::string loadInput);
        bool loadPlayerBot(std::string loadInput);

    private:
        PlayerBoard* playerBoard;
        int playerScore;
        std::string playerName;
        bool firstPlayerMark;
        bool bot;
};

#endif // PLAYER_H