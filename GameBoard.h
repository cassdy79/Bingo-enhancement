#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>
#include <string>
#include <random>
#include <iostream>
#include "Types.h"
#include "LinkedList.h"

class GameBoard{
    public:
    GameBoard();
    ~GameBoard();

    //use factory number to return specific factory 0-5
    char* retrieveFactory(int factoryNumber);

    //adds tiles into factory offers from tileBag
    void insertIntoFactory();

    //generate a shuffled R,L,Y,B,U into the tileOrder string 
    void generateTileOrder();

    //fills the tile bag at the beginning of the game
    void fillTileBag();

    //fills up tilebag at the end of a round
    //fills tile bag with tiles from the box lid, may need to randomise tiles but uncertain as assignment spec says to only randomise tiles once
    void fillTileBag(LinkedList* boxLid);

    //prints out the factories
    void printFactory();

    private:
    char factory0[FACTORY_SIZE], factory1[FACTORY_SIZE], factory2[FACTORY_SIZE], factory3[FACTORY_SIZE], factory4[FACTORY_SIZE], factory5[FACTORY_SIZE];
    char factoryTiles[FACTORY_SIZE];
    LinkedList* tileBag;
    LinkedList* boxLid;
    std::string tileOrder;

};

#endif // GAMEBOARD_H