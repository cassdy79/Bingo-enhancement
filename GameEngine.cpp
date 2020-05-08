#include "GameEngine.h"
#include <fstream>
#include <iostream>

GameEngine::GameEngine(){
    winner = nullptr;
    gameBoard = new GameBoard();
    player1 = new Player("Player 1");
    player2 = new Player("Player 2");
}

GameEngine::~GameEngine(){
    delete winner;
    delete gameBoard;
}

void GameEngine::createPlayers(std::string playerName1, std::string playerName2){
    player1 = new Player(playerName1);
    player2 = new Player(playerName2);
}

void GameEngine::playGame(){
    gameBoard->generateTileOrder();
    gameBoard->fillTileBag();

        std::cout << "=== Start Round ===" << std::endl;
        //fill up factories
        gameBoard->insertIntoFactory();
        while(gameBoard->factoriesEmpty()==false){

            //Round start
 
            //Player1's turn
            std::cout << "TURN FOR PLAYER: " << player1->getName() << std::endl;
            gameBoard->printFactory();
            player1->printPlayerBoard();
            std::string input;

            do{
                //do while input is invalid
                std::cout << "> turn ";
                std::cin >> input; 

            }
            while(processInput(input, gameBoard, player1)==false);
            std::cout << std::endl;

            //Player2's turn
            std::cout << "TURN FOR PLAYER: " << player2->getName() << std::endl;
            gameBoard->printFactory();
            player2->printPlayerBoard();
            std::string input2;

            do{
                //do while input is invalid
                std::cout << "> turn ";
                std::cin >> input2; 

            }
            while(processInput(input2, gameBoard, player2)==false);
            std::cout << std::endl;
        }
        std::cout << "=== END OF ROUND ===" << std::endl;
}



bool GameEngine::processInput(std::string input, GameBoard* gameBoard, Player* player){
    bool check=false;

    if(checkInput(input, gameBoard, player)){

        //breaking down the string into int, char, int
        int factory = (int)input[0]-'0';
        char tile = char(input[1]);
        int line = (int)input[2]-'0';

        //if the selected tile exists in the factory, remove same color tiles from factory
        int numTiles = gameBoard->takeTile(factory, tile);
        if(numTiles>0){
            if(factory==0 && gameBoard->checkCentre()==true){
                for(int x=0;x<numTiles;x++){
                    if(player->getPlayerBoard()->insertIntoLine(line-1, gameBoard->getBoxLid(), tile)==true){
                        check=true;
                        gameBoard->takeFirstMarker();
                        player->setFirstPlayerMark(true);
                    }
                    else{
                        check=false;
                        std::cout << "Tile exists in wall" << std::endl;
                    }
                }
            }   
            else{ 
                //std::cout <<" Number of "<< tile << " " << numTiles << std::endl; 
                for(int x=0;x<numTiles;x++){
                    if(player->getPlayerBoard()->insertIntoLine(line-1, gameBoard->getBoxLid(), tile)==true){
                        check=true;
                    }
                    else{
                        check=false;
                        std::cout << "Tile exists in wall" << std::endl;
                    }
                }
            }
        }
        else{
            std::cout << "Tile not found" << std::endl;
            check=false;
        } 
    }
    else{
        check=false;
    }
    if(check==false){
        std::cout << "Invalid input" << std::endl;
        return false;
    }
    else{
        return true;
    }
}



bool GameEngine::checkInput(std::string input, GameBoard* gameBoard, Player* player){
    //check if input string is valid (1-5, RYBLUF, and 1-5)
    if(input[0]=='0' || input[0]=='1' || input[0]=='2' || input[0]=='3' || input[0]=='4' || input[0]=='5'){
        if(input[1]=='R' || input[1]=='Y' || input[1]=='B' || input[1]=='L' || input[1]=='U' || input[1]=='F'){
            if(input[0]=='0' || input[2]=='1' || input[2]=='2' || input[2]=='3' || input[2]=='4' || input[2]=='5'){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

void GameEngine::saveGame(){
    std::string saveFileName;
    std::cout << "Please enter the name of your save game\n";
    std::cin >> saveFileName;

    std::ofstream saveFile;
    saveFile.open(saveFileName + ".txt");
    // need to add player turn indicator
    saveFile << player1->getName() << "\n" << player2->getName() << "\n" << player1->getScore() << "\n" << player2->getScore() << "\n";

    for(int i = 0; i <= 5 ; i++){
        std::string factoryOutput = gameBoard->factoryOutput(i);
        saveFile << factoryOutput << "\n";        
    }

    GameBoard player1Board = player1->getPlayerBoard;
    GameBoard player2Board = player2->getPlayerBoard;


}
