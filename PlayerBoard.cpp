#include <iostream>
#include <string>

#include "PlayerBoard.h"



PlayerBoard::PlayerBoard(){


  //  void PlayerBoard::insertIntoWall(std::list<char>* boxLid){

 //   }

    
    std::vector<std::vector<char>> lines{
        {'.'},
        {'.','.'},
        {'.','.','.'},
        {'.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'}}; 

        factoryLines = lines;

    //Fills playerboard Wall with default values.
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j<5; ++j) {
            factoryWall[i][j]='.';
        } 
    }
    }

    PlayerBoard::~PlayerBoard(){
        
    }

    void PlayerBoard::printWall(int x){
        
        int size = factoryLines[x].size();

        for(int i = 0; i < size; ++i){
            std::cout<<" "<<factoryLines[x][i];
        }
        if (x!=5) {
        std::cout<<" ||";
        for(int i = 0; i < 5; ++i){
            std::cout<<" "<<factoryWall[x][i];
            }
        }
        std::cout<<std::endl;
        
    }

    void PlayerBoard::printMosaic(){
    std::cout<<"1:         ";
    printWall(0);
    std::cout<<"2:       ";
    printWall(1);
    std::cout<<"3:     ";
    printWall(2);
    std::cout<<"4:   ";
    printWall(3);
    std::cout<<"5: ";
    printWall(4);
    std::cout<<"broken:";
    printWall(5);
    std::cout<<std::endl;
}



