#include <iostream>
#include <string>
#include <string.h>
#include "PlayerBoard.h"
#include "Player.h"
#include "GameBoard.h"
#include "GameEngine.h"

//for processing file input
class Args{   
public:
  std::string operation;

};

void printMenu();
void showCredits();
void azulGame(std::string randomSeed);


int main(int argc, char** argv){
    int userInput = 0 ;
    std::string randomSeed = "0";
        std::cout << 
    "Welcome to Azul! \n" <<
    "-------------------\n \n"; 

    for(int i = 0; i < argc; i++){
        if(std::string(argv[i]) == "-s"){
            if(i + 1 < argc){
                i++;
                randomSeed = argv[i];
                std::cout << "Random seed set as: " << randomSeed << std::endl;
            }
        }
    }

    while (userInput != 4 ){
        printMenu();

        std::cin >> userInput;
   
        if (userInput == 1) {
            azulGame(randomSeed);

        } else if (userInput == 2) {
            GameEngine* engine = new GameEngine();
            engine->loadGame();
            engine->playGame(randomSeed);
            
        } else if (userInput == 3) {
            showCredits();

        } else if (userInput == 4) {
            std::cout<<"Thanks for playing"<<std::endl;

        } 
        
        //test input for playerboard testing
        else if (userInput == 23) {
            Player* player = new Player("Bob");
            player->printPlayerBoard();
            delete player;
            

        }

        //test for inputting tiles and adding to wall
            else if (userInput == 24) {
            Player* player = new Player("Bob");
            player->printPlayerBoard();

            LinkedList* boxLid = new LinkedList();

            player->getPlayerBoard()->insertIntoLine(1, boxLid, 'R');
            player->getPlayerBoard()->insertIntoLine(1, boxLid, 'R');

            player->getPlayerBoard()->insertIntoLine(2, boxLid, 'Y');
            player->getPlayerBoard()->insertIntoLine(2, boxLid, 'Y');
            player->getPlayerBoard()->insertIntoLine(2, boxLid, 'Y');
            player->getPlayerBoard()->insertIntoLine(2, boxLid, 'Y');
            player->getPlayerBoard()->insertIntoLine(2, boxLid, 'F');


            std::cout<<"Inserting to player line"<<std::endl;
            player->printPlayerBoard();
            player->getPlayerBoard()->insertIntoWall(boxLid);
            std::cout<<"Inserting to player Wall if line is full"<<std::endl;
            player->printPlayerBoard();

        }

        else if (userInput == 25) {
            GameEngine saveTest;

            saveTest.saveGame();
        }

        else if (userInput == 26) {
            GameEngine saveTest;

            saveTest.loadGame();
            saveTest.saveGame();
        }

        else if (userInput == 88) {
            GameBoard* a = new GameBoard();
            a->fillTileBag('50');
            a->getBoxLid()->addBack('R');
            a->getBoxLid()->addBack('L');
            a->getBoxLid()->addBack('Y');
            a->getBoxLid()->addBack('Y');
            a->printTileBag();
            std::cout<<"0: "<<a->getBoxLid()->getValue(0)<<std::endl;
            std::cout<<"1: "<<a->getBoxLid()->getValue(1)<<std::endl;
            std::cout<<"2: "<<a->getBoxLid()->getValue(2)<<std::endl;
            std::cout<<"boxlid size: "<<a->getBoxLid()->size()<<std::endl;

            std::cout<<"after refilling:"<<std::endl;
             
            a->fillTileBagFromBoxLid();
            a->printTileBag();
            std::cout<<"boxlid size: "<<a->getBoxLid()->size()<<std::endl;
        }

        else {
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

void azulGame(std::string randomSeed){
    std::string playerName1, playerName2;
    GameEngine* engine = new GameEngine();
    std::cout << "Enter a name for player 1" << std::endl << ">";
    std::cin >> playerName1;
    std::cout << "Enter a name for player 2" << std::endl << ">";
    std::cin >> playerName2;

    std::cout << std::endl << "Let's Play!" << std::endl << std::endl;

    engine->createPlayers(playerName1, playerName2);
    std::cin.ignore(100000, '\n');
    engine->playGame(randomSeed);
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