#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include <vector>
#include <list>
#include <iostream>
#include <string>

#include "Types.h"


class PlayerBoard{

  public:
    //creating char/vectors for the players wall
    PlayerBoard();
    ~PlayerBoard();

    //will move tiles from the factory lines into the wall, passing through boxLid to add extra tiles into the lid
    void insertIntoWall(std::list<char>* boxLid);

    //specifies the line to move the tiles into out of the players lines, adds extra tiles to the boxLid
    void insertIntoLine(int factoryLineNumber, std::list<char>* boxLid, char* factoryTiles);

    //overloaded function for when pulling from discard tiles as opposed to factory offers
    void insertIntoLine(int factoryLineNumber, std::list<char>* boxLid, std::list<char>* discardTiles);

    //function to print current status of player board
    void printMosaic();

    //helps print a line of the wall for the mosaic
    void printWall(int x);

  private:
    std::vector<std::vector<char>> mosaicLines;
    char factoryWall[5][5];
    
};




#endif //PLAYERBOARD_H