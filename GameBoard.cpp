#include "GameBoard.h"

GameBoard::GameBoard(){
    factory0[FACTORY_SIZE] = {};
    factory1[FACTORY_SIZE] = {};
    factory2[FACTORY_SIZE] = {};
    factory3[FACTORY_SIZE] = {};
    factory4[FACTORY_SIZE] = {};
    factory5[FACTORY_SIZE] = {};
    factoryTiles[FACTORY_SIZE] = {};
    tileBag = new LinkedList();
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
    std::cout << "Tile Order: " << tileOrder << std::endl;

    //for(int i=0;i<tileBag->size();i++){
    //    std::cout << tileBag->getValue(i)<< std::endl;
    //}

    for(int i=0; i<ALL_FACTORES; i++){
        std::cout << i << ": ";
        for(int j=0; j<FACTORY_SIZE; j++){
            std::cout << retrieveFactory(i)[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}