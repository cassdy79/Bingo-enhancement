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

    //Returns a winner
    Player* getWinner();

    //creates players to store into GameEngine
    void GameEngine::createPlayers(std::string playerName1, std::string playerName2);

    private:
    GameBoard* gameBoard;
    Player* winner;
    LinkedList* tileBag;
    Player* player1;
    Player* player2;

};

#endif //GAMEENGINE_H