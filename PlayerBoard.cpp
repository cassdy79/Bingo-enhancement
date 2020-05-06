
#include "PlayerBoard.h"
#include "GameBoard.h"


PlayerBoard::PlayerBoard(){

    red = 'r';
    empty = '.';
    yellow = 'y';
    dblue = 'b';
    lblue = 'l';
    black = 'u';

    this->r = &red;
    this->e = &empty;
    this->y = &yellow;
    this->b = &dblue;
    this->l = &lblue;
    this->u = &black;

    //fills in the lines with default empty value '.'
    std::vector<std::vector<char*>> lines{
        {e},
        {e,e},
        {e,e,e},
        {e,e,e,e},
        {e,e,e,e,e}
    }; 

    mosaicLines = lines;



    //Fills broken tiles with default empty values.
    for (int i = 0; i < 5; ++i) {
        broken[i] = e; 
    }


        //fills factoryWall with default factory Wall pattern

    factoryWall[0][0] = b;
    factoryWall[0][1] = y;
    factoryWall[0][2] = r;
    factoryWall[0][3] = u;
    factoryWall[0][4] = l;

    for (int i = 1; i < 5; ++i){
        for (int j = 1; j < 6; ++j){
            if (j ==5){
                factoryWall[i][0] = factoryWall[i-1][j-1];
            } else {
             factoryWall[i][j] = factoryWall[i-1][j-1];
            }

        }


    }

}

PlayerBoard::~PlayerBoard(){

}

void PlayerBoard::findTile(char* x, int wall){
    
    char tile = ' ';

        if (*x == 'R'){
            tile = 'r';
        } else if (*x == 'Y') {
            tile = 'y';
        } else if (*x == 'B') {
            tile = 'b';
        } else if (*x == 'L') {
            tile = 'l';
        } else if (*x == 'U') {
            tile = 'u';
        }

    for (int i = 0; i < 5; ++i) {

        if (tile == *(factoryWall[wall][i]) ) {
            factoryWall[wall][i] = x;
        }
    }


}

void PlayerBoard::insertIntoWall(std::list<char*> boxLid){

    for (int i = 0; i <5; ++i){
        int lineSize = mosaicLines[i].size();
        int filled = 0;
            for (int j = 0; j<lineSize;++j) {
                if (mosaicLines[i][j] != e) {
                    ++filled;
                }
            }

        if (filled == lineSize){
            for (int j = 0; j < lineSize; ++j){
                if (j != 0) {
                    boxLid.push_back(mosaicLines[i][j]);

                    mosaicLines[i][j] = e;
                }

            }

            findTile(mosaicLines[i][0], i);
            mosaicLines[i][0] = e;
        }

    }

}

void PlayerBoard::insertIntoLine(int mosaicLineNumber, std::list<char*> boxLid, char* factoryTiles) {

    int lineSize = mosaicLines[mosaicLineNumber].size();
    bool inserted = false;

    for (int i = 0; i < lineSize && !inserted; i++) {
            //looks for earliest index that is empty and fills factory tile.
        if (mosaicLines[mosaicLineNumber][i] == e){
            mosaicLines[mosaicLineNumber][i] = factoryTiles;
            //bool check to break out of loop once inserted
            inserted = true;

        }

    }

    if(!inserted){
        for (int i = 0; i < 5 && !inserted; i++) {
            //looks for earliest index in broken tiles that is empty and fills factory tile.
            if (broken[i] == e){
                broken[i] = factoryTiles;
                //bool check to break out of loop once inserted
                inserted = true;

            }
        }
    }
            //if broken tiles line is full, send it to box lid.
    if(!inserted){
        
        boxLid.push_back(factoryTiles);

    }

}
            
    

    //void PlayerBoard::insertIntoLine(int factoryLineNumber, std::list<char*> boxLid, std::list<char>* discardTiles) {



   // }


void PlayerBoard::printWall(int x){
        
    int size = mosaicLines[x].size();
        if (x!=5) {
            for(int i = size-1; i >= 0; --i){
                std::cout<<" "<<*(mosaicLines[x][i]);
            }
        
            std::cout<<" ||";
            for(int i = 0; i < 5; ++i){
                std::cout<<" "<<*(factoryWall[x][i]);
            }
            std::cout<<std::endl;

        } else {

            for(int i = 0; i < 5; ++i){
                std::cout<<" "<<*(broken[i]);
            }
            std::cout<<std::endl;
        }
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



