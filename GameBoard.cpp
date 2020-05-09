#include "GameBoard.h"

GameBoard::GameBoard(){
    factory0[CENTRE_FACTORY] = {};
    factory1[FACTORY_SIZE] = {};
    factory2[FACTORY_SIZE] = {};
    factory3[FACTORY_SIZE] = {};
    factory4[FACTORY_SIZE] = {};
    factory5[FACTORY_SIZE] = {};
    factoryTiles[FACTORY_SIZE] = {};
    tileBag = new LinkedList();
    boxLid = new LinkedList();
    centreSize = 1;
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

void GameBoard::fillTileBag(){
    int min = 1;
    int max = 5;

    //std::random_device engine;
    std::default_random_engine engine(RANDOM_ENGINE);
    std::uniform_int_distribution<int> uniform_dist(min, max);

    //Randomize 5 numbers with each digit represents a colour
    int value = -1;
    for (int i = 0; i != MAX_TILES; ++i) {
        value = uniform_dist(engine);
        if(value==1){
            tileBag->addBack('R');
        }
        else if(value==2){
            tileBag->addBack('Y');
        }
        else if(value==3){
            tileBag->addBack('B');
        }
        else if(value==4){
            tileBag->addBack('L');
        }
        else{
            tileBag->addBack('U');
        }
    }
}


void GameBoard::insertIntoFactory(){
    factory0[0] = 'F';
    for(int i=1;i<CENTRE_FACTORY;i++){
        retrieveFactory(0)[i] = '.';
    }
    for(int i=0;i<NUM_FACTORIES;i++){

        for(int j=0;j<FACTORY_SIZE;j++){
            factoryTiles[j] = tileBag->getValue(tileBag->size()-1);
            tileBag->removeBack();
        }

        int k=0;
        int size=0;
        while(size<FACTORY_SIZE){

            int flag = 0;
            int index = -1;
            int indexm = -1;

            for(int l=0;l<5;l++){
                for(int m=0;m<4;m++){
                    if(flag<1){
                        if(tileOrder[l] == factoryTiles[m]){
                            flag=1;
                            index=l;
                            indexm=m;
                        }
                    }
                }
            }
            retrieveFactory(i+1)[k] = tileOrder[index];
            factoryTiles[indexm]= '.';
            size++;
            k++;
        }
    }
}

void GameBoard::generateTileOrder(){
    int min = 1;
    int max = 5;

    //std::random_device engine;
    std::default_random_engine engine(RANDOM_ENGINE);
    std::uniform_int_distribution<int> uniform_dist(min, max);

    std::string output = "";
    int value = -1;
    int size = 0;
    int flagR = 0;
    int flagY = 0;
    int flagB = 0;
    int flagL = 0;
    int flagU = 0;

    while (size<5) {
        value = uniform_dist(engine);
        if(value==1){
            if(flagR==0){
                output = output+"R";
                flagR = 1;
                size++;
            }
        }
        else if(value==2){
            if(flagY==0){
                output = output+"Y";
                flagY = 1;
                size++;
            }
        }
        else if(value==3){
            if(flagB==0){
                output = output+"B";
                flagB = 1;
                size++;
            }
        }
        else if(value==4){
            if(flagL==0){
                output = output+"L";
                flagL = 1;
                size++; 
            }
        }
        else {
            if(flagU==0){
                output = output+"U";
                flagU = 1;
                size++;
            }
        }
    }
    this->tileOrder = output;
}

void GameBoard::printFactory(){
    std::cout << "Factories: " << std::endl;
    //std::cout << "Tile Order: " << tileOrder << std::endl;

    
    //for(int i=0;i<tileBag->size();i++){
    //    std::cout << tileBag->getValue(i)<< std::endl;
    //}
    std::cout << "0: ";
    for(int j=0; j<CENTRE_FACTORY; j++){
        
        if(retrieveFactory(0)[j]!='.'){
            std::cout << retrieveFactory(0)[j] << " ";
        }
    }

    std::cout << std::endl;

    for(int i=1; i<ALL_FACTORES; i++){
        std::cout << i << ": ";
        for(int j=0; j<FACTORY_SIZE; j++){
            if(retrieveFactory(i)[j]!='.'){
                std::cout << retrieveFactory(i)[j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool GameBoard::factoryEmpty(int factoryNumber){
    if(factoryNumber==0){
        int counter=0;
        for(int i=0; i<CENTRE_FACTORY; i++){
            if(retrieveFactory(factoryNumber)[i]=='.'){
                counter++;
            }
        }
        if(counter==CENTRE_FACTORY){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        int counter=0;
        for(int i=0; i<FACTORY_SIZE; i++){
            if(retrieveFactory(factoryNumber)[i]=='.'){
                counter++;
            }
        }
        if(counter==FACTORY_SIZE){
            return true;
        }
        else{
            return false;
        }
    }
    
}

bool GameBoard::factoriesEmpty(){
    int counter=0;
    for(int i=0; i<ALL_FACTORES; i++){
        if(factoryEmpty(i)==true){
            counter++;
        }
    }
    if(counter==ALL_FACTORES){
        return true;
    }
    else{
        return false;
    }
}

int GameBoard::takeTile(int factoryNumber, char tile){
    int check = 0;
    int storeSize = 0;
    char store[4];
    if(factoryNumber==0){
        for(int i=0; i<CENTRE_FACTORY; i++){
            if(tile==retrieveFactory(factoryNumber)[i]){
                check++;
                retrieveFactory(factoryNumber)[i]='.';
                centreSize--;
            }
        }
    }
    else{
        for(int i=0; i<FACTORY_SIZE; i++){
            if(tile==retrieveFactory(factoryNumber)[i]){
                check++;
                retrieveFactory(factoryNumber)[i]='.';
            }
            else{
                store[storeSize] = retrieveFactory(factoryNumber)[i];
                storeSize++;
            }
        }
    }
    if(check>0){
        for(int i=0;i<FACTORY_SIZE;i++){
            for(int j=0;j<storeSize;j++){
               if(retrieveFactory(factoryNumber)[i]==store[j]){
                   retrieveFactory(factoryNumber)[i]='.';
               }
            }
        }

        for(int i=0;i<storeSize;i++){
            addIntoCentre(store[i]);
        }
    }
    return check;
}

void GameBoard::takeFirstMarker(){
    for(int i=0;i<CENTRE_FACTORY;i++){
        if(retrieveFactory(0)[i]=='F'){
            retrieveFactory(0)[i]='.';
        }
    }
}

bool GameBoard::checkCentre(){
    bool check=false;
    for(int i=0;i<CENTRE_FACTORY;i++){
        if(retrieveFactory(0)[i]=='F'){
            check=true;
        }
    }
    return check;
}

void GameBoard::addIntoCentre(char tile){
    retrieveFactory(0)[centreSize]=tile;
    centreSize++;
}

LinkedList* GameBoard::getBoxLid(){
    return boxLid;
}

std::string GameBoard::factoryOutput(int factoryIndex){
    std::string returnString = {};
    if(factoryIndex == 0){
        for(int i : factory0){
            returnString += i;
        }
    } else if (factoryIndex == 1){
        for(int i : factory1){
            returnString += i;
        }
    } else if (factoryIndex == 2){
        for(int i : factory2){
            returnString += i;
        }
    } else if (factoryIndex == 3){
        for(int i : factory3){
            returnString += i;
        }
    } else if (factoryIndex == 4){
        for(int i : factory4){
            returnString += i;
        }
    } else if (factoryIndex == 5){
        for(int i : factory5){
            returnString += i;
        }
    } else {
        return "invalid input";
    }

    return returnString;
}

std::string GameBoard::tileBagString(){
    int count = 0;
    std::string tileBagOutput = {};
    while(count < tileBag->size()){
        tileBagOutput += tileBag->getValue(count);
        count++;
    }

    return tileBagOutput;
}

std::string GameBoard::boxLidString(){
    int count = 0;
    std::string boxLidOutput = {};
    while(count < boxLid->size()){
        boxLidOutput += boxLid->getValue(count);
        count++;
    }

    return boxLidOutput;
}

void GameBoard::loadFactory(std::string loadInput, int rowIndex){
    if(rowIndex == 0){
        for(std::string::size_type i = 0; i < loadInput.size(); i++){
            factory0[i] = loadInput[i];
        }
    } else if(rowIndex == 1){
        for(std::string::size_type i = 0; i < loadInput.size(); i++){
            factory1[i] = loadInput[i];
        }
    } else if(rowIndex == 2){
        for(std::string::size_type i = 0; i < loadInput.size(); i++){
            factory2[i] = loadInput[i];
        }
    } else if(rowIndex == 3){
        for(std::string::size_type i = 0; i < loadInput.size(); i++){
            factory3[i] = loadInput[i];
        }
    } else if(rowIndex == 4){
        for(std::string::size_type i = 0; i < loadInput.size(); i++){
            factory4[i] = loadInput[i];
        }
    } else if(rowIndex == 5){
        for(std::string::size_type i = 0; i < loadInput.size(); i++){
            factory5[i] = loadInput[i];
        }
    }
}

void GameBoard::loadTileBag(std::string loadInput){
    for(std::string::size_type i = 0; i < loadInput.size(); i++){
            tileBag->addBack(loadInput[i]);
    }
}

void GameBoard::loadBoxLid(std::string loadInput){
    for(std::string::size_type i = 0; i < loadInput.size(); i++){
            boxLid->addBack(loadInput[i]);
    }
}