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
    char line1;
    std::vector<char> line2, line3, line4, line5;
      
};




#endif //PLAYERBOARD_H