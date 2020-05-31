#include "Bot.h"

Bot::Bot(GameBoard* board, Player* player){
  this->gameBoard = board;
  this->player = player;

}


Bot::~Bot(){

}


//GameBoard Bot::getGameBoard(){
//  return gameBoard;
//}
//Player Bot::getPlayer(){
//  return player;
//}

std::string Bot::botScan() {
  std::string botInput;

  std::getline(std::cin, botInput); 

  return botInput;
}