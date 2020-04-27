#include <iostream>
#include <string>

//for processing file input
class Args{   
public:
  std::string operation;

};

void printMenu();
void showCredits();
void azulGame();


int main(int argc, char** argv){
    int userInput = 0 ;
        std::cout << 
    "Welcome to Azul! \n" <<
    "-------------------\n \n"; 

    while (userInput != 4 ){
        printMenu();

        std::cin >> userInput;

        if (userInput == 1) {
            azulGame();

        } else if (userInput == 2) {
            //load/save implement

        } else if (userInput == 3) {
            showCredits();

        } else if (userInput == 4) {
            std::cout<<"Thanks for playing"<<std::endl;

        } else {
            std::cout<<"Invalid Input"<<std::endl;
            userInput = 0;
        }
    }
    return EXIT_SUCCESS;
}


void printMenu(){
    std::cout << 
    "Menu \n" <<
    "---- \n" <<
    "1. New Game \n" <<
    "2. Load Game \n" <<
    "3. Credits (Show student information) \n" <<
    "4. Quit \n \n";
}

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
    "Student ID: s3742928\n" <<
    "Email: S3742928@student.rmit.edu.au\n";

    std::cout << 
    "\nName: Julian Tjiong \n" <<
    "Student ID: S3786866 \n" <<
    "Email: S3786866@student.rmit.edu.au \n";

    std::cout << 
    "\nName: Matthew Andric \n" <<
    "Student ID: S3506698   \n" <<
    "Email: S3506698@student.rmit.edu.au\n" <<
    "----------------------------------\n\n";
}