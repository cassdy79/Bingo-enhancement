#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include <vector>

#include "Types.h"


class PlayerBoard{

  public:
    //creating char/vectors for the players wall
    PlayerBoard();
    ~PlayerBoard();


  private:
    std::vector<std::vector<char>> factoryLines;
      
};




#endif //PLAYERBOARD_H