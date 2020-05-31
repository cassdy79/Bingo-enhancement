#ifndef BOT_H
#define BOT_H
#include <string>
#include <iostream>
#include "Player.h"
#include "GameBoard.h"

class Bot {

  public:
    //creates bot with player2's game board
    Bot(GameBoard* board, Player* player);
    ~Bot();

    //returns bot gameboard
   // GameBoard getGameBoard();
   // Player getPlayer();

    //returns botMove
    std::string botScan();


  private:
  GameBoard* gameBoard;
  Player* player;
};



#endif //BOT_H