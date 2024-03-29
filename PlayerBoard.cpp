#include <vector>
#include <algorithm>
#include "PlayerBoard.h"
#include "GameBoard.h"


PlayerBoard::PlayerBoard(){
    colour = new Interface();
    score = 0;
    r = 'r';
    e = '.';
    y = 'y';
    b = 'b';
    l = 'l';
    u = 'u';

    //fills in the lines with default empty value '.'
    std::vector<std::vector<char>> lines{
        {e},
        {e,e},
        {e,e,e},
        {e,e,e,e},
        {e,e,e,e,e}
    }; 

    mosaicLines = lines;



    //Fills broken tiles with default empty values.
    for (int i = 0; i < 7; ++i) {
        broken[i] = ' '; 
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
    delete colour;
}

void PlayerBoard::findTile(char x, int wall){
    
    char tile = ' ';

        if (x == 'R'){
            tile = 'r';
        } else if (x == 'Y') {
            tile = 'y';
        } else if (x == 'B') {
            tile = 'b';
        } else if (x == 'L') {
            tile = 'l';
        } else if (x == 'U') {
            tile = 'u';
        }

    for (int i = 0; i < 5; ++i) {

        if (tile == factoryWall[wall][i] ) {
            factoryWall[wall][i] = x;
            calculateScore(wall, i);
        }
    }


}

void PlayerBoard::insertIntoWall(LinkedList* boxLid){

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
                    boxLid->addBack(mosaicLines[i][j]);

                    mosaicLines[i][j] = e;
                }

            }

            findTile(mosaicLines[i][0], i);
            mosaicLines[i][0] = e;
        }

    }

    //counts broken tiles and sets negative score.
            int deduction = 0;
        for( int i = 0; i<7 && broken[i]!=' '; ++i ) {
            if(i < 2) {
                deduction = -1;
                score += deduction;
                broken[i] = ' ';

            } else if (i >= 2 && i <5) {
                deduction = -2;
                score += deduction;
                broken[i] = ' ';
            } else {
                deduction = -3;
                score += deduction;
                broken[i] = ' ';
            }

        }

}

bool PlayerBoard::insertIntoLine(int mosaicLineNumber, LinkedList* boxLid, char factoryTiles) {
    bool inserted = false;
    bool brokenLine = false;
   
    
    if(mosaicLineNumber == 5){
        brokenLine = true;
    } 

    if(brokenLine){
                    for (int i = 0; i < 7 && !inserted; i++) {
                //looks for earliest index in broken tiles that is empty and fills factory tile.
                if (broken[i] == ' ' ){
                   // if(broken[i] == 'F' && factoryTiles == 'F'){
                     //   inserted = true;
                   // } else {
                    broken[i] = factoryTiles;
                    
                    //bool check to break out of loop once inserted
                        inserted = true;
                //    }

                }
            }

        if(!inserted){
            
            boxLid->addBack(factoryTiles);

        }


        return true;
    }




    if(checkWall(mosaicLineNumber, factoryTiles)==false){
        int lineSize = mosaicLines[mosaicLineNumber].size();
        
    
        if ( factoryTiles == 'F'){


            for (int i = 0; i < 7 && !inserted; i++) {
                //looks for earliest index in broken tiles that is empty and fills factory tile.
                if (broken[i] == ' '){
                    broken[i] = factoryTiles;
                    
                    //bool check to break out of loop once inserted
                    inserted = true;

                }
            }
        }

        for (int i = 0; i < lineSize && !inserted; i++) {
                //looks for earliest index that is empty and fills factory tile.
            if (mosaicLines[mosaicLineNumber][i] == e){
                mosaicLines[mosaicLineNumber][i] = factoryTiles;
                //bool check to break out of loop once inserted
                inserted = true;

            }

        }

        if(!inserted){
            for (int i = 0; i < 7 && !inserted; i++) {
                //looks for earliest index in broken tiles that is empty and fills factory tile.
                if (broken[i] == ' '){
                    broken[i] = factoryTiles;
                    //bool check to break out of loop once inserted
                    inserted = true;

                }
            }
        }
                //if broken tiles line is full, send it to box lid.
        if(!inserted){
            
            boxLid->addBack(factoryTiles);

        }
        return true;
    }
    else{
        return false;
    }

}

            
    

  //  void PlayerBoard::insertIntoLine(int factoryLineNumber, LinkedList* boxLid, std::list<char> discardTiles) {



   // }

bool PlayerBoard::checkWall(int wallLine, char tile){
    bool check=false;
    for(int i=0;i<5;i++){
        if(factoryWall[wallLine][i]==tile){
            check=true;
        }
    }
    return check;
}

bool PlayerBoard::checkLine(int line, char tile){
    bool check=false;

   // std::cout<<mosaicLines[line][0]<<std::endl;
   if (line == 5){
       check = true;
   }
   else{
    if(mosaicLines[line][0]!='.'){
        if(mosaicLines[line][0]==tile){
            check=true;
        }
        else{
            check=false;
        }
    }
    else{
        check=true;
    }
   }
    
    return check;
}

int PlayerBoard::getScore(){

    return score;
}


void PlayerBoard::printWall(int x){
        
    int size = mosaicLines[x].size();
        if (x!=5) {
            for(int i = size-1; i >= 0; --i){
                std::cout<<" ";
                colour->printTile(mosaicLines[x][i]);
            }
        
            std::cout<<" ||";
            for(int i = 0; i < 5; ++i){
                std::cout<<" ";
                colour->printTile(factoryWall[x][i]);
            }
            std::cout<<std::endl;

        } else {

            for(int i = 0; i < 7; ++i){
                std::cout<<" ";
                colour->printTile(broken[i]);
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
}


void PlayerBoard::calculateScore(int row, int col) {
bool horz = false;
bool vert = false;
int horizontal = 0;
int vertical = 0;

if(!empty(factoryWall[row][col])){

    //horizontal check
    if((col+1)<5){
        if(!empty(factoryWall[row][col+1])){
            horz = true;
        }
    }

    if((col-1)>=0){
        if(!empty(factoryWall[row][col-1])){
            horz = true;
        }
    }

        //vertical check
    if((row+1)<5){
        if(!empty(factoryWall[row+1][col])){
            vert = true;
        }
    }

    if((row-1)>=0){
        if(!empty(factoryWall[row-1][col])){
            vert = true;
        }
    }

    if(horz){
        for(int i = 0; i <5; ++i){
 
            if(!empty(factoryWall[row][i])){
                ++horizontal;
            }
        }
    }
    if(vert){
        for(int i = 0; i <5; ++i){

            if(!empty(factoryWall[i][col])){
                ++vertical;
            }
        }
    }

    if(!horz && !vert){
        ++score;
    }
    score += (horizontal + vertical);
    }
}


void PlayerBoard::endScoring(){
    int count = 0;
    int horzCount = 0;
    int vertCount = 0;
    int colCount = 0;
    //horizontal
    for(int i = 0; i<5; ++i){
        for(int j = 0; j<5; ++j){
            if (!empty(factoryWall[i][j]))
                ++count;
        }
    if (count == 5){
        score += 2;
        horzCount +=2;
        
    }
        count = 0;
    }
    

    //vertical
        for(int i = 0; i<5; ++i){
            for(int j = 0; j<5; ++j){
            if (!empty(factoryWall[j][i]))
                ++count;
        }
    if (count == 5){
        score += 7;
        vertCount += 7;
    }
        count = 0;
    }


    //colours
    colCount += colorScoring('R');
    colCount += colorScoring('Y');
    colCount += colorScoring('B');
    colCount += colorScoring('L');
    colCount += colorScoring('U');



}

int PlayerBoard::colorScoring(char tile) {
    int counter = 0;
    int retValue = 0;

        for(int i = 0; i<5; ++i){
            for(int j = 0; j<5; ++j){
            if (factoryWall[i][j] == tile)
                ++counter;
            }
        }
        if(counter == 5){
            score += 10;
            retValue = 10;
        }
    return retValue;
}





bool PlayerBoard::checkEnd(){
    bool retValue = false;
    int count = 0;

    for(int i = 0; i<5; ++i){
        for(int j = 0; j<5; ++j){
            if (!empty(factoryWall[i][j]))
                ++count;
        }
    if (count == 5){
        retValue = true;
    }
        count = 0;
    }


return retValue;
}

bool PlayerBoard::empty(char x) {
    if (x == 'r' || x == 'y' || x == 'b' || x == 'l' || x == 'u'){
        return true;
    }

    return false;
}

std::string PlayerBoard::playerMosaicString(int rowIndex){
    std::string mosaicOutput = {};
    for(int i = 0; i < 5; i++){
        mosaicOutput += factoryWall[rowIndex][i];
    }

    return mosaicOutput;
}

std::string PlayerBoard::playerLineString(int rowIndex){
    std::string lineOutput = {};
    int vectorSize = mosaicLines[rowIndex].size();
    for(int i = 0; i < vectorSize; i++){
        lineOutput += mosaicLines[rowIndex][i];
    }

    return lineOutput;
}

std::string PlayerBoard::brokenTileString(){
    std::string brokenTileOutput = {};
    for(int i : broken){
        brokenTileOutput += i;
    }
    
    return brokenTileOutput;
}

bool PlayerBoard::loadMosaicLines(std::string loadInput, int rowIndex){
    for(std::string::size_type i = 0; i < loadInput.size(); i++){
        if(loadInput[i] == 'R' || loadInput[i] == 'Y' || loadInput[i] == 'B' || loadInput[i] == 'U' || loadInput[i] == 'L' || loadInput[i] == '.'){
            if(loadInput[i] == loadInput[0] || loadInput[i] == '.'){
                mosaicLines[rowIndex][i] = loadInput[i];
            } else {
                std::cout << "Player line data invalid, cancelling load.";
                return false;
            }
        } else {
            std::cout << "Player line data invalid, cancelling load.";
            return false;
        }
    }
    return true;
}

bool PlayerBoard::loadFactoryWall(std::string loadInput, int rowIndex){
    if(loadInput.size() != 5){
        std::cout << "Player wall data invalid, cancelling load.";
        return false;
    }

    std::vector<char> tileOrder{ 'B', 'Y', 'R', 'U', 'L'};

    if(rowIndex != 0){
        std::rotate(tileOrder.begin(), tileOrder.begin() + (5 - rowIndex), tileOrder.end());
    }

    for(std::string::size_type i = 0; i < loadInput.size(); i++){
        if(std::toupper(loadInput[i]) == tileOrder[i] ){
            factoryWall[rowIndex][i] = loadInput[i];
        } else {
            std::cout << "Player wall data invalid, cancelling load.";
            return false;
        }
    }

    return true;
}

bool PlayerBoard::loadBrokenTiles(std::string loadInput){
    for(std::string::size_type i = 0; i < loadInput.size(); i++){
        if(loadInput[i] == 'B' || loadInput[i] == 'Y' || loadInput[i] == 'U' || loadInput[i] == 'L' || loadInput[i] == 'R' || loadInput[i] == 'F' || loadInput[i] == ' '){
            broken[i] = loadInput[i];
        } else {
            std::cout << "Broken tile data invalid, cancelling load.";
            return false;
        }
    }

    return true;
}

void PlayerBoard::clearScore(){
    score = 0;
}


char* PlayerBoard::getBot(int num) {
    char* retValue = nullptr;

    if (num == 0) {

        retValue = broken;
    } 
    if (num >= 1 && num < 6) {
        char temp[num]= {};

        for (int i = 0; i < num; ++i){
            temp[i] = mosaicLines[num-1][i];
        }
        retValue = temp;

    } 
    if (num >= 6 && num < 11) {

        retValue = factoryWall[num-6];
    } 
    return retValue;
}