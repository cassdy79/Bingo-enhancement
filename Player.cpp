#include "Player.h"

Player::Player(std::string playerName) :
    playerScore(0)
{
    this->playerName =  playerName;
    playerBoard = new PlayerBoard();
    this->firstPlayerMark = false;
}

Player::~Player(){
    delete playerBoard;
}

void Player::printPlayerBoard(){
    std::cout<<"Mosaic for "<< playerName<<std::endl;
    playerBoard->printMosaic();
    //std::cout<<"Current Score " << getScore() <<std::endl<<std::endl;
}

std::string Player::getName(){
    return playerName;
}


int Player::getScore(){
    return playerBoard->getScore();;
}

PlayerBoard* Player::getPlayerBoard(){
    return playerBoard;
}

void Player::setFirstPlayerMark(bool set){
    firstPlayerMark=set;
}

bool Player::firstPlayer(){
    return firstPlayerMark;
}