#include "GameEngine.h"
#include <fstream>
#include <iostream>

GameEngine::GameEngine(){
    winner = nullptr;
    gameBoard = new GameBoard();
    player1 = new Player("Player 1");
    player2 = new Player("Player 2");
    player1Turn = true;
    randomSeed = 0;
    gameLoaded = false;
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
    if(!gameLoaded){
        gameBoard->generateTileOrder();
        gameBoard->fillTileBag();
        gameBoard->insertIntoFactory();
    }

    int turnCounter = 0;

        std::cout << "=== Start Round ===" << std::endl;
        //fill up factories

        testCase();

        while(gameBoard->factoriesEmpty()==false){

            //Round start
            turnCounter++;

            //Player1's turn
            if(player1Turn){

                std::cout << "TURN FOR PLAYER: " << player1->getName() << std::endl;
                gameBoard->printFactory();
                player1->printPlayerBoard();
                std::string input;
                do{
                    //do while input is invalid
                    std::cout << "> turn ";
                    std::getline(std::cin, input); 
                    if(input == "save"){
                        saveGame();
                        gameLoaded = false;
                        return;
                    }
                }
                while(processInput(input, gameBoard, player1)==false);
                testCase(turnCounter, input);
                player1Turn = !player1Turn;
                std::cout << std::endl;
            }

            //Player2's turn
            if(!player1Turn){

                std::cout << "TURN FOR PLAYER: " << player2->getName() << std::endl;
                gameBoard->printFactory();
                player2->printPlayerBoard();
                std::string input2;
               
                do{
                    //do while input is invalid
                    std::cout << "> turn ";
                    std::getline(std::cin, input2); 
                    if(input2 == "save"){
                        saveGame();
                        gameLoaded = false;
                        return;
                    }
                }
                while(processInput(input2, gameBoard, player2)==false);
                testCase(turnCounter, input2);
                player1Turn = !player1Turn;
                std::cout << std::endl;   
            }
            
        }
        std::cout << "=== END OF ROUND ===" << std::endl;
}



bool GameEngine::processInput(std::string input, GameBoard* gameBoard, Player* player){
    bool check=false;
    if(checkInput(input, gameBoard, player)){
        //breaking down the string into int, char, int
        int factory = (int)input[0]-'0';
        char tile = char(input[2]);
        int line = (int)input[4]-'0';

        //checks if colour exists in the line
        if(player->getPlayerBoard()->checkLine(line-1, tile)==true){

            //if the selected tile exists in the factory, remove same color tiles from factory
            int numTiles = gameBoard->takeTile(factory, tile);
            if(numTiles>0){
                //If user is taking tiles from centre factory:
                if(factory==0 && gameBoard->checkCentre()==true){
                    player->getPlayerBoard()->insertIntoLine(line-1, gameBoard->getBoxLid(), 'F');
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
                //If user isn't taking tiles from centre factory:
                else{ 
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
    }
    else{
        check=false;
    }
    if(check==false){
        std::cout << "Invalid Input" << std::endl;
        return false;
    }
    else{
        return true;
    }
}



bool GameEngine::checkInput(std::string input, GameBoard* gameBoard, Player* player){
    //check if input string is valid (1-5, RYBLUF, and 1-5)
    if(input[0]=='0' || input[0]=='1' || input[0]=='2' || input[0]=='3' || input[0]=='4' || input[0]=='5'){
        if(input[2]=='R' || input[2]=='Y' || input[2]=='B' || input[2]=='L' || input[2]=='U'){
            if(input[4]=='0' || input[4]=='1' || input[4]=='2' || input[4]=='3' || input[4]=='4' || input[4]=='5'){
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

bool GameEngine::returnPlayerTurn(){
    return player1Turn;
}

int GameEngine::returnRandomSeed(){
    return randomSeed;
}

void GameEngine::loadPlayerTurn(std::string loadInput){
    player1Turn = std::stoi(loadInput);
}

void GameEngine::loadRandomSeed(std::string loadInput){
    randomSeed = std::stoi(loadInput);
}

void GameEngine::saveGame(){
    std::string saveFileName;
    std::cout << "Please enter the name of your save game\n";
    std::cin >> saveFileName;

    std::ofstream saveFile;
    saveFile.open(saveFileName + ".txt");
    
    saveFile << player1->getName() << "\n" << player2->getName() << "\n" << player1->getScore() << "\n" << player2->getScore() << "\n" << player1Turn << "\n";

    for(int i = 0; i <= 5 ; i++){
        saveFile << gameBoard->factoryOutput(i) << "\n";        
    }

    PlayerBoard* player1Board = player1->getPlayerBoard();
    PlayerBoard* player2Board = player2->getPlayerBoard();

    for(int i = 0; i < 5; i++){
        saveFile << player1Board->playerMosaicString(i) << "\n";
    }
    for(int i = 0; i < 5; i++){
        saveFile << player2Board->playerMosaicString(i) << "\n";
    }

    for(int i = 0; i < 5; i++){
        saveFile << player1Board->playerLineString(i) << "\n";
    }
    for(int i = 0; i < 5; i++){
        saveFile << player2Board->playerLineString(i) << "\n";
    }

    saveFile << player1Board->brokenTileString() << "\n";
    saveFile << player2Board->brokenTileString() << "\n";

    saveFile << gameBoard->boxLidString() << "\n";

    saveFile << gameBoard->tileBagString() << "\n";

    saveFile << randomSeed;
}

void GameEngine::loadGame(){
    std::string saveName = {};
    std::cout << "Please enter the name of your save game (not including .txt): \n";
    std::cin >> saveName;
    std::ifstream saveFile(saveName + ".txt");

    std::string parseInput = {};

    std::getline(saveFile, parseInput, '\n');
    player1->loadPlayerName(parseInput);
    std::getline(saveFile, parseInput, '\n');
    player2->loadPlayerName(parseInput);

    std::getline(saveFile, parseInput, '\n');
    player1->loadPlayerScore(parseInput);
    std::getline(saveFile, parseInput, '\n');
    player2->loadPlayerScore(parseInput);

    std::getline(saveFile, parseInput, '\n');
    loadPlayerTurn(parseInput);

    for(int i = 0; i <= 5; i++){
        std::getline(saveFile, parseInput, '\n');
        gameBoard->loadFactory(parseInput, i);
    }

    PlayerBoard* loadBoard = new PlayerBoard();

    loadBoard = player1->getPlayerBoard();
    for(int i = 0; i < 5; i++){
        std::getline(saveFile, parseInput, '\n');
        loadBoard->loadFactoryWall(parseInput, i);
    }
    loadBoard = player2->getPlayerBoard();
    for(int i = 0; i < 5; i++){
        std::getline(saveFile, parseInput, '\n');
        loadBoard->loadFactoryWall(parseInput, i);
    }

    loadBoard = player1->getPlayerBoard(); 
    for(int i = 0; i < 5; i++){
        std::getline(saveFile, parseInput, '\n');
        loadBoard->loadMosaicLines(parseInput, i);
    }
    loadBoard = player2->getPlayerBoard(); 
    for(int i = 0; i < 5; i++){
        std::getline(saveFile, parseInput, '\n');
        loadBoard->loadMosaicLines(parseInput, i);
    }

    loadBoard = player1->getPlayerBoard();
    std::getline(saveFile, parseInput, '\n');
    loadBoard->loadBrokenTiles(parseInput);

    loadBoard = player2->getPlayerBoard();
    std::getline(saveFile, parseInput, '\n');
    loadBoard->loadBrokenTiles(parseInput);

    std::getline(saveFile, parseInput, '\n');
    gameBoard->loadBoxLid(parseInput);
    std::getline(saveFile, parseInput, '\n');
    gameBoard->loadTileBag(parseInput);

    std::getline(saveFile, parseInput, '\n');
    loadRandomSeed(parseInput);

    gameLoaded = true;
}

void GameEngine::testCase(int turnCounter, std::string playerInput){

    std::ofstream saveFile;
    saveFile.open("TestCase.txt", std::ofstream::app);

    if(player1Turn){
        saveFile << "Turn " << turnCounter << " Player 1s turn\n";
    } else if (!player1Turn){
        saveFile << "Turn " << turnCounter << " Player 2s turn\n";
    }

    saveFile << "Player Input: " << playerInput << "\n";

    saveFile << player1->getName() << "\n" << player2->getName() << "\n" << player1->getScore() << "\n" << player2->getScore() << "\n" << player1Turn << "\n";

    for(int i = 0; i <= 5 ; i++){
        saveFile << gameBoard->factoryOutput(i) << "\n";        
    }

    PlayerBoard* player1Board = player1->getPlayerBoard();
    PlayerBoard* player2Board = player2->getPlayerBoard();

    for(int i = 0; i < 5; i++){
        saveFile << player1Board->playerMosaicString(i) << "\n";
    }
    for(int i = 0; i < 5; i++){
        saveFile << player2Board->playerMosaicString(i) << "\n";
    }

    for(int i = 0; i < 5; i++){
        saveFile << player1Board->playerLineString(i) << "\n";
    }
    for(int i = 0; i < 5; i++){
        saveFile << player2Board->playerLineString(i) << "\n";
    }

    saveFile << player1Board->brokenTileString() << "\n";
    saveFile << player2Board->brokenTileString() << "\n";

    saveFile << gameBoard->boxLidString() << "\n";

    saveFile << gameBoard->tileBagString() << "\n";

    saveFile << randomSeed << "\n";

    saveFile << "======================\n";
}

void GameEngine::testCase(){

    std::ofstream saveFile;
    saveFile.open("TestCase.txt", std::ofstream::app);

    saveFile << "Initial board state: \n";

    saveFile << player1->getName() << "\n" << player2->getName() << "\n" << player1->getScore() << "\n" << player2->getScore() << "\n" << player1Turn << "\n";

    for(int i = 0; i <= 5 ; i++){
        saveFile << gameBoard->factoryOutput(i) << "\n";        
    }

    PlayerBoard* player1Board = player1->getPlayerBoard();
    PlayerBoard* player2Board = player2->getPlayerBoard();

    for(int i = 0; i < 5; i++){
        saveFile << player1Board->playerMosaicString(i) << "\n";
    }
    for(int i = 0; i < 5; i++){
        saveFile << player2Board->playerMosaicString(i) << "\n";
    }

    for(int i = 0; i < 5; i++){
        saveFile << player1Board->playerLineString(i) << "\n";
    }
    for(int i = 0; i < 5; i++){
        saveFile << player2Board->playerLineString(i) << "\n";
    }

    saveFile << player1Board->brokenTileString() << "\n";
    saveFile << player2Board->brokenTileString() << "\n";

    saveFile << gameBoard->boxLidString() << "\n";

    saveFile << gameBoard->tileBagString() << "\n";

    saveFile << randomSeed << "\n";

    saveFile << "======================\n";
}