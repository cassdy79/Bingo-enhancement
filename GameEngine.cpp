#include "GameEngine.h"

GameEngine::GameEngine(){
    winner = nullptr;
    gameBoard = new GameBoard();
}

GameEngine::~GameEngine(){
    delete winner;
    delete gameBoard;
}

void GameEngine::playGame(Player* player1, Player* player2){
    
}