#include "Bot.h"

Bot::Bot(GameBoard* gBoard, PlayerBoard* pBoard){
  char e = '.';

  std::vector<std::vector<char>> infoTemp{

    //broken line 0 
    {e,e,e,e,e,e,e},

    //player lines 1 - 5
    {e},
    {e,e},
    {e,e,e},
    {e,e,e,e},
    {e,e,e,e,e},

    //player Wall 6 - 10
    {e,e,e,e,e},
    {e,e,e,e,e},
    {e,e,e,e,e},
    {e,e,e,e,e},
    {e,e,e,e,e},

    //center factory 11
    {e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e},

    //factories 12 - 16
    {e,e,e,e},
    {e,e,e,e},
    {e,e,e,e},
    {e,e,e,e},
    {e,e,e,e}
  }; 

  info = infoTemp;

    int size = 0;
    char* temp = nullptr;
      for (int i = 0; i <11; ++i){
        temp = pBoard->getBot(i);
        size = info[i].size();
        for (int j = 0; j < size; ++j) {
          info[i][j] = temp[j];
        }
      }

    for (int i = 11; i < 17; ++i){
       temp = gBoard->getFactory(i);
      size = info[i].size();
      for (int j = 0; j < size; ++j) {
        info[i][j] = temp[j];
      }
    }
  
}


Bot::~Bot(){
}


std::string Bot::botScan() {
  std::string botInput;

  std::getline(std::cin, botInput); 

  return botInput;
}

void Bot::print() {
int size = 0;
std::cout<<std::endl;
  for (int i = 0; i< 17; ++i){
    size = info[i].size();
    for (int j = 0; j < size; ++j){
      std::cout<<info[i][j];
    }
    std::cout<<std::endl;
  }

}
