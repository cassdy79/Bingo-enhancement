#ifndef TYPES_H
#define TYPES_H


typedef char* DefaultTiles[5];
typedef char* Red;
typedef char* Yellow;
typedef char* DBlue;
typedef char* LBlue;
typedef char* Black;
typedef char* FPlayer;
typedef char* Empty;

//maximum tiles inside tilebag
#define MAX_TILES 100
//number of factores except the centre one
#define NUM_FACTORIES 5
//size of a factory
#define FACTORY_SIZE 4
//number of all factories
#define ALL_FACTORES 6
//default random engine value
#define RANDOM_ENGINE 10
//maximum number of tiles in the centre factory
#define CENTRE_FACTORY 16

//colours

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BLACK   "\033[30m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define END     "\033[0m"

#endif //TYPES_H