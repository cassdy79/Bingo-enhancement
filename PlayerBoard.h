#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include <vector>
#include <list>
#include <iostream>
#include <string>

#include "Types.h"
#include "LinkedList.h"

class PlayerBoard{

  public:
    //creating char/vectors for the players wall
    PlayerBoard();
    ~PlayerBoard();

    //will move tiles from the factory lines into the wall, passing through boxLid to add extra tiles into the lid
    void insertIntoWall(LinkedList* boxLid);

    //specifies the line to move the tiles into out of the players lines, adds extra tiles to the boxLid
    bool insertIntoLine(int factoryLineNumber, LinkedList* boxLid, char factoryTiles);

    //overloaded function for when pulling from discard tiles as opposed to factory offers
    //void insertIntoLine(int factoryLineNumber, LinkedList* boxLid, std::list<char> discardTiles);

    //checks if a wall line contains the given tile
    bool checkWall(int wallLine, char tile);

    //function to print current status of player board
    void printMosaic();

    //helps print a line of the wall for the mosaic
    void printWall(int x);

    //helps find tile to replace in wall
    void findTile(char x, int wall);

    //checks newly added tile in factory wall and sets score accordingly
    void calculateScore(int row, int col);

    //checks if given tile is empty or not
    bool empty(char x);

    //retrieve score
    int getScore();

  private:
    char r;
    char e;
    char y;
    char b;
    char l;
    char u;
    
    int score;
    std::vector<std::vector<char>> mosaicLines;
    char factoryWall[5][5];
    char broken[7];
    
};




#endif //PLAYERBOARD_H