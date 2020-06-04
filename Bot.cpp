#include "Bot.h"

Bot::Bot(GameBoard* gBoard, PlayerBoard* pBoard){
  char e = '.';
  clearTiles(false);

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
        if(temp[j]!= 'F' && temp[j]!= ' '){
          info[i][j] = temp[j];
        }
      }
    }
  
}


Bot::~Bot(){
}


std::string Bot::botScan() {
  clearTiles(true);
  std::string botInput;
  std::string botInput2;
  fillMoves();
  botInput2 = calculateMove();
  std::cout<<botInput2<<std::endl;
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
    std::cout<<std::endl;

    size = moveset.size();
    for (int j = 0; j < size; ++j){
      std::cout<<moveset[j]<<std::endl;
    }
    std::cout<<size<<std::endl;
    size = brokenset.size();
    for (int j = 0; j < size; ++j){
      std::cout<<brokenset[j]<<std::endl;
    }
    std::cout<<size<<std::endl;

}

char Bot::getRow(int row){
  return info[row][0];
}

int Bot::countRow(int row) {
  int count = 0;
  
    for (int i = 0; i<row; ++i) {
      if (info[row][i] != '.' ) {
          ++count;
      }
    }

  return count;
}

bool Bot::checkRow(int row, char tile) {
  bool check = true;
  if(tile == '.'){
    check = false;
  }

  for (int i = 0; i<5; i++){
    if (info[row+5][i] == tile) {
      check = false;
    }
  }

  if (check && info[row][0] != '.'){
    if (info[row][0] != tile){
    check = false;
    }
  }
  
  return check;
}

bool Bot::canInsert(int row, char tile) {
  bool check = false;
  if (row == 0 ){
    if (tile != '.'){
    check = true;
    }
  }
  if (row != 0 && countRow(row) != row) {
      if (checkRow(row, tile)){
        check = true;
      } 
  }

return check;
}

void Bot::clearTiles(bool vect) {
  if (vect) {
    moveset.clear();
  }
  else {
    for (int i = 0; i <5; ++i){
      tiles[i] = '.';
    } 
  }
}

void Bot::fillTiles(char tile) {
  bool contains = false;
  int empty = 5;
    
    for(int i = 0; i < 5; ++i) {
      if (tiles[i] == tile){
        contains = true;
       
      }

      if (tiles[i] == '.') {
        --empty;
      }
    }

  if (!contains){
    tiles[empty] = tile;
  }

}


void Bot::fillMoves() {
  char temp = ' ';
  int facRow = 0;
  int size = 0;
  std::string value = "N/A";

  for(int i = 11; i<17; ++i) {
    size = info[i].size();
    facRow = i-11;
    clearTiles(false);
    for(int j = 0; j < size; ++j) {
      
      if (info[i][j]!= '.'){
        fillTiles(info[i][j]);
      }
    }

    for(int j = 0; j < 6; ++j) {
      for(int k = 0; k < 5; ++k) {
        temp = tiles[k]; 

        if(canInsert((j), temp)) {

          value = std::to_string(facRow);
          value += " "; 
          value += temp; 
          value += " "; 
          if (j == 0) {
          value += "B";
          brokenset.push_back(value);
          } else {
          value += std::to_string(j);
          moveset.push_back(value);
          }

        
        }

      }

    }

  }




}

std::string Bot::defaultMove() {
  int size = brokenset.size();
  




return "hello";
}

std::string Bot::calculateMove() {
  std::string move = defaultMove();

 return move;
}