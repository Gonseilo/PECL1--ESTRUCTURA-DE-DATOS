#include <iostream>
#include "Muelles.h"
#include "string.h"

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
        muelle[0] = 'S';
        if (minlat == 48 && seglat >= 35){
            muelle[0] = 'N';
        }
    }

    if (minlon <= 36){
        muelle[1] = 'E';
        if (minlon == 36 && seglon >= 31){
            muelle[1] = 'O';
        }
    }

    char *str = new char[2];
    strcpy(str,muelle);

    return str;
}

