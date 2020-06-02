#ifndef BOT_H
#define BOT_H
#include <string>
#include <iostream>
#include "Player.h"
#include "PlayerBoard.h"
#include "GameBoard.h"

class Bot {

  public:
    //creates bot with player2's game board
    Bot(GameBoard* gBoard, PlayerBoard* pBoard);
    ~Bot();


    //returns botMove
    std::string botScan();
    void print();

  private:
    std::vector<std::vector<char>> info;
    
};



#endif //BOT_H