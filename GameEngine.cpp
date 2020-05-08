#include "GameEngine.h"

GameEngine::GameEngine(){
    winner = nullptr;
    gameBoard = new GameBoard();
    player1 = new Player("Player 1");
    player2 = new Player("Player 2");
}

GameEngine::~GameEngine(){
    delete winner;
    delete gameBoard;
}

void GameEngine::playGame(){
    gameBoard->generateTileOrder();
    gameBoard->fillTileBag();
    gameBoard->insertIntoFactory();
    gameBoard->printFactory();
}

void GameEngine::createPlayers(std::string playerName1, std::string playerName2){
    player1 = new Player(playerName1);
    player2 = new Player(playerName2);
}