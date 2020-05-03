#include "GameBoard.h"

GameBoard::GameBoard(){
    this->factory0={"", "", ""};

}

GameBoard::~GameBoard(){

}

char* GameBoard::retrieveFactory(int factoryNumber){
    if(factoryNumber==0){
        return factory0;
    }
    else if(factoryNumber==1){
        return factory1;
    }
    else if(factoryNumber==2){
        return factory2;
    }
    else if(factoryNumber==3){
        return factory3;
    }
    else if(factoryNumber==4){
        return factory4;
    }
    else{
        return factory5;
    }
}

void GameBoard::insertIntoFactory(int factoryNumber, char tile1, char tile2, char tile3, char tile4){
    this->retrieveFactory(factoryNumber)[0] =  tile1;
    this->retrieveFactory(factoryNumber)[1] =  tile2;
    this->retrieveFactory(factoryNumber)[2] =  tile3;
    this->retrieveFactory(factoryNumber)[3] =  tile4;
}

