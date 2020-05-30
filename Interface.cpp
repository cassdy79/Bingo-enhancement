#include "Interface.h"


//void Interface::print(std::string input, std::string colour){
 // std::cout << RED << "Hello" << END << std::endl;

//}

void Interface::printTile(char tile){
  if (tile == 'R' || tile == 'r') {
    std::cout << RED << tile << END;
  } else if (tile == 'Y' || tile == 'y') {
    std::cout << YELLOW << tile << END;
  } else if (tile == 'B' || tile == 'b') {
    std::cout << BLUE << tile << END;
  } else if (tile == 'L' || tile == 'l') {
    std::cout << CYAN << tile << END;
  } else if (tile == 'U' || tile == 'u') {
    std::cout << BLACK << tile << END;
  } else if (tile == '.' || tile == 'F') {
    std::cout << GREEN << tile << END;
  } else {
    std::cout << MAGENTA << tile << END;
  }



}


