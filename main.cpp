#include <iostream>
#include <string>
#include <vector>

class playerBoard{
    private:
    char line1;
    std::vector<char> line2, line3, line4, line5;

    public:
    //creating char/vectors for the players wall
    playerBoard(){
        std::vector<char> line2Input(2, '.'); std::vector<char> line3Input(3, '.'); std::vector<char> line4Input(4, '.'); std::vector<char> line5Input(5, '.');
        line1 = '.';
        line2 = line2Input;
        line3 = line3Input;
        line4 = line4Input;
        line5 = line5Input;
    }
};

void azulGame(){
    std::string playerName1, playerName2;
    std::cout << "Enter a name for player 1";
    std::cin >> playerName1;
    std::cout << "Enter a name for player 2";
    std::cin >> playerName2;

}

void showCredits(){
    std::cout << 
    "---------------------------------- \n" <<
    "Name: Cass Ilangantileke \n" <<
    "Student ID: \n" <<
    "Email: \n";

    std::cout << 
    "\nName: Julian Tjiong \n" <<
    "Student ID: \n" <<
    "Email: \n";

    std::cout << 
    "\nName: Matthew Andric \n" <<
    "Student ID: S3506698   \n" <<
    "Email: S3506698@student.rmit.edu.au\n" <<
    "----------------------------------\n\n";
}

int main(){
    int userInput{ 0 };
    do{
        std::cout << 
        "Welcome to Azul! \n" <<
        "-------------------\n \n" <<
        "Menu \n" <<
        "---- \n" <<
        "1. New Game \n" <<
        "2. Load Game \n" <<
        "3. Credits (Show student information) \n" <<
        "4. Quit \n \n";

        std::cin >> userInput;
        
        switch(userInput){
            case 1: azulGame(); userInput = 0; break;
            case 2: break; userInput = 0;
            case 3: showCredits(); userInput = 0; break;
            case 4: return 0; 
            default: break;
        }

    }while(true);
}