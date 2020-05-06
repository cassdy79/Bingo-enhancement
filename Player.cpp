#include "Player.h"

Player::Player(std::string playerName) :
    playerScore(0)
{
    this->playerName =  playerName;
    playerBoard = new PlayerBoard();
}

Player::~Player(){
    delete playerBoard;
}

void Player::printPlayerBoard(){
std::cout<<"Mosaic for "<< playerName<<std::endl;
playerBoard->printMosaic();
}

std::string Player::getName(){
    return playerName;
}

void Player::setScore(int score){
    playerScore = score;
}

int Player::getScore(){
    return playerScore;
}

PlayerBoard* Player::getPlayerBoard(){
    return playerBoard;
}