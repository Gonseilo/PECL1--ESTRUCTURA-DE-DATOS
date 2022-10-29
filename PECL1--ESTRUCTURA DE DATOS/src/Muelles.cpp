#include "Muelles.h"
#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include "malloc.h"
#include "string.h"

using std::cout; using std::cin; using std::endl;

Muelles::Muelles(){
    //ctor
}

Muelles::~Muelles(){
    //dtor
}

char* Muelles::AsignarMuelle(char* latitud, char* longitud){
    char muelle[] = "NO";
    int minlat = (latitud[3] - '0') * 10 + (latitud[4] - '0');
    int seglat = (latitud[6] - '0') * 10 + (latitud[7] - '0');
    int minlon = (longitud[3] - '0') * 10 + (longitud[4] - '0');
    int seglon = (longitud[6] - '0') * 10 + (longitud[7] - '0');

    if (minlat <= 48){
        if (seglat <= 35){
            muelle[0] = 'S';
        }
    }

    if (minlon <= 36){
        if (seglon <= 31){
            muelle[1] = 'E';
        }
    }

    char *str = new char[2];
    strcpy(str,muelle);

    return str;
}

