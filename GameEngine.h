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
    void playGame(std::string seed);

    //Returns the number of colors found in the factory
    bool processInput(std::string input, GameBoard* gameBoard, Player* player);
    
    bool intoMozaic(std::string input, Player* player, int sameColorTiles);

    bool checkInput(std::string input, GameBoard* gameBoard, Player* player);

    //creates player to store into game engine
    void createPlayers(std::string playerName1, std::string playerName2);

    //Returns a winner
    Player* getWinner();

    //returns values for save game functionality
    bool returnPlayerTurn();
    int returnRandomSeed();

    //functions for restoring game from save file
    void loadPlayerTurn(std::string loadInput);
    void loadRandomSeed(std::string loadInput);

    //save/load game functionality
    void saveGame();
    void loadGame();

    //function to produce test case output with overloaded function for initial board state
    void testCase(int turnCounter, std::string playerInput);
    void testCase();

    private:
    GameBoard* gameBoard;
    Player* winner;
    LinkedList* tileBag;
    Player* player1;
    Player* player2;
    int randomSeed;
    bool player1Turn;
    bool gameLoaded;

};

#endif //GAMEENGINE_H