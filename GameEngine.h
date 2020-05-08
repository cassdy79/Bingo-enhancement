#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Types.h"
#include "Player.h"
#include "PlayerBoard.h"
#include "GameBoard.h"
#include "LinkedList.h"

class GameEngine{
    public:
    GameEngine();
    ~GameEngine();

    //The gameplay method
    void playGame();

    //Returns the number of colors found in the factory
    bool processInput(std::string input, GameBoard* gameBoard, Player* player);
    
    bool intoMozaic(std::string input, Player* player, int sameColorTiles);

    bool checkInput(std::string input, GameBoard* gameBoard, Player* player);

    //creates player to store into game engine
    void createPlayers(std::string playerName1, std::string playerName2);

    //Returns a winner
    Player* getWinner();

    //saves game to text file
    void saveGame();

    private:
    GameBoard* gameBoard;
    Player* winner;
    LinkedList* tileBag;
    Player* player1;
    Player* player2;

};

#endif //GAMEENGINE_H