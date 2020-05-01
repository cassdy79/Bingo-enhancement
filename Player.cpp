#include "Player.h"

Player::Player(std::string playerName) :
    playerScore(0)
{
    this->playerName =  playerName;
    playerBoard = new PlayerBoard();
}

Player::~Player(){
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