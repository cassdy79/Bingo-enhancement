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


    //methods to help calculate best move
    //counts tiles in specified row
    int countRow(int row);

    //checks if tile is already inserted into the mosaic row
    bool checkRow(int row, char tile);

    //checks if tile can be inserted to row
    bool canInsert(int row, char tile);

    //fills all possible moves into vector ser
    void fillMoves();

    //clears tiles in vector or tile array if false
    void clearTiles(bool vect);

    //fills tiles array with valid tiles for moves
    void fillTiles(char tile);

    //sets default move which adds least number of tiles to broken line
    std::string defaultMove();

    //calculates best move for Bot and replaces default move if found
    std::string calculateMove();

    //finds best row to insert a tile which helps find best move
    int findFocus();

    //finds best move to fill a tile perfectly, if not, finds next best move if available
    int findPerfect(int focus);

  private:
    std::vector<std::vector<char>> info;
    std::vector<std::vector<std::string>> set;
    char tiles[5];
    int lineCount[5];
    bool minFill;
    std::string move;
    
};



#endif //BOT_H