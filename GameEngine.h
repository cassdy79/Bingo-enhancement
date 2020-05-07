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
    void playGame(Player* player1, Player* player2);

    //Returns a winner
    Player* getWinner();

    private:
    GameBoard* gameBoard;
    Player* winner;
    LinkedList* tileBag;

};

#endif //GAMEENGINE_H