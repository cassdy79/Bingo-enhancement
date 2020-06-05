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
  minFill = false;
  //std::string botInput;
  
   calculateMove();
  //std::cout<<move<<std::endl;
  //std::getline(std::cin, botInput); 
  
  return move;
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

    for(int i = 0; i < 6; ++i){
      size = set[i].size();
      std::cout<< "Moves for row"<<i<<std::endl;
      for (int j = 0; j < size; ++j){
        std::cout<<set[i][j]<<std::endl;
      }
      std::cout<<size<<std::endl;
    }

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
    set.clear();
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
  int total = 0;
  std::string value = "N/A";
  std::vector<std::vector<std::string>> set2(6);
  

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
          if (j == 0){
            value += "B";
          } else {
          value += std::to_string(j);
          }
          set2[j].push_back(value);
        }

      }
        
    }

  }
  
  for (int i = 1; i < 6; ++i) {
    size = info[i].size();
    
    for (int j = 0; j < size; ++j) {
      if (info[i][j]=='.') {
        ++total;
      }
    }

    lineCount[i-1] = total;
    total = 0;
  }


set = set2;
}

int Bot::findFocus(){
  int focus = 0;
  int mindex = 6;

  for(int i = 0; i < 5; ++i) {

    if (lineCount[i] != 0) {
        if(lineCount[i] < mindex) {
          mindex = lineCount[i];
          focus = i+1;
        } 

    }
  }
  return focus;
}

std::string Bot::defaultMove() {
  int size = set[0].size();
  int index = 0;
  int min = 16;
  int factory = 0;
  char tile = '.';
  std::string input;

  for (int i = 0; i < size; ++i) {
    input = set[0][i];
    factory = (int)input[0]-'0';
    tile = char(input[2]);
    int total = 0;
    int facSize = info[factory+11].size();

    for (int j = 0; j < facSize; ++j) {
      if(info[factory+11][j]== tile){
        ++total; 
      }
    }

    if (total != 0 && total < min) {
      min = total;
      index = i;
    }

  }

  return set[0][index];
}

int Bot::findPerfect(int focus) {
  int size = info[focus].size();;
  int index = 99;
  char tile = ' ';
  int factory = 0;
  
  int empty = 0;
  int min = 5;

    for (int i = 0; i< size; ++i) {
      if(info[focus][i] == '.') {
        ++empty;
      }
    }


    size = set[focus].size();

    for (int i = 0; i < size; ++i){
 
      int total = 0;
      int full = 0;
      std::string input= set[focus][i];

      factory = (int)input[0]-'0';
      tile = char(input[2]);
      int factorySize = info[factory+11].size();
// std::cout<<set[focus][i] <<factorySize<<std::endl;
      for (int j = 0; j < factorySize; ++j) {
        if(info[factory+11][j]== tile){
          
         
        ++full; 
        }
      }

      total = (full-empty);
      
      if(!minFill) {
        if (total == 0) {
          index = i;
         // std::cout<<"check1 "<<input<<std::endl;
        } 
      } else {
        if (total < min){
          index = i;
          //std::cout<<"check2 "<<input<<std::endl;
        }

      }
      //std::cout<<total<<" <total, "<< empty<< " <empty, "<<full<< " <full"<<std::endl;

}


return index;
}

std::string Bot::calculateMove() {
  fillMoves();
  int focus = findFocus();
 //std::cout<<minFill<<std::endl;


  move = defaultMove();


  while (focus != 0) { 

    int index = findPerfect(focus);
    if (index == 99) {
      lineCount[focus-1] = 0;
      focus = findFocus();

    } else {
 
      move = set[focus][index];
      minFill = true;
      focus = 0;
    }


    
  } 

  if (minFill == false) {
    minFill = true;
    calculateMove();
  }

 return move;
}