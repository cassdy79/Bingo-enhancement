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

    //methods to help calculate best move
    char getRow(int row);
    int countRow(int row);
    bool checkRow(int row, char tile);
    bool canInsert(int row, char tile);
    void fillMoves();
    void clearTiles();
    void fillTiles(char tile);
    
    std::string calculateMove();

  private:
    std::vector<std::vector<char>> info;
    std::vector<std::string> moveset;
    char tiles[5];
    
};



#endif //BOT_H