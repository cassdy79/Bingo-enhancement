
#include "PlayerBoard.h"
#include "GameBoard.h"


PlayerBoard::PlayerBoard(){

    std::vector<std::vector<char>> lines{
        {'.'},
        {'.','.'},
        {'.','.','.'},
        {'.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'}}; 

        mosaicLines = lines;

    //Fills playerboard Wall with default values.
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j<5; ++j) {
            factoryWall[i][j]='.';
        } 
    }
    }

    PlayerBoard::~PlayerBoard(){

    }


    void PlayerBoard::insertIntoWall(std::list<char>* boxLid){


    }

    void PlayerBoard::insertIntoLine(int mosaicLineNumber, std::list<char>* boxLid, char* factoryTiles) {

        int lineSize = mosaicLines[mosaicLineNumber].size();
        bool inserted = false;

        for (int i = 0; i < lineSize && !inserted; i++) {
            //looks for earliest index that is empty and fills factory tile.
            if (mosaicLines[mosaicLineNumber][i] == '.'){
                mosaicLines[mosaicLineNumber][i] = *factoryTiles;
                //bool check to break out of loop once inserted
                inserted = true;

            }

        }

        if(!inserted){
            for (int i = 0; i < 5 && !inserted; i++) {
            //looks for earliest index in broken tiles that is empty and fills factory tile.
            if (mosaicLines[5][i] == '.'){
                mosaicLines[5][i] = *factoryTiles;
                //bool check to break out of loop once inserted
                inserted = true;

            }
        }

        //if broken tiles line is full, send it to box lid.
        if(!inserted){

            boxLid->push_back(*factoryTiles);

        }

        }
            
    }

    void PlayerBoard::insertIntoLine(int factoryLineNumber, std::list<char>* boxLid, std::list<char>* discardTiles) {



    }


    void PlayerBoard::printWall(int x){
        
        int size = mosaicLines[x].size();

        for(int i = 0; i < size; ++i){
            std::cout<<" "<<mosaicLines[x][i];
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



