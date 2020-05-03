#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>
#include <string>

class GameBoard{
    public:
    GameBoard();
    ~GameBoard();

    //use factory number to return specific factory 0-5
    char* retrieveFactory(int factoryNumber);

    //adds tiles into factory offers from tileBag
    void insertIntoFactory(int factoryNumber, char tile1, char tile2, char tile3, char tile4);

    //randomises tile order in tileBag
    void generateTileOrder();

    //fills tile bag with tiles from the box lid, may need to randomise tiles but uncertain as assignment spec says to only randomise tiles once
    void fillTileBag();

    private:
    char factory0[3], factory1[4], factory2[4], factory3[4], factory4[4], factory5[4];
    std::list<char> tileBag;
    std::list<char> boxLid;
    std::list<char> discardTiles;

};

#endif // GAMEBOARD_H