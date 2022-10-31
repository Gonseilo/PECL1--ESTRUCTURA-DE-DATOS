#include <iostream>
#include "Muelles.h"
#include "string.h"

Muelles::Muelles(){
    //ctor
}

Muelles::~Muelles(){
    //dtor
}

char* Muelles::AsignarMuelle(char* latitud, char* longitud){ //Funci�n AsignarMuelle usada para decidir a que muelle ir� un paquete en base a sus coordenadas
    char muelle[] = "NO"; //Todos los paquetes ir�n predeterminadamente al NO, aunque esto cambiar� a lo largo de la funci�n
    int minlat = (latitud[3] - '0') * 10 + (latitud[4] - '0'); //Extraemos los minutos de la latitud introducida al llamar a la funci�n
    int seglat = (latitud[6] - '0') * 10 + (latitud[7] - '0'); //Extraemos los segundos de la latitud introducida al llamar a la funci�n
    int minlon = (longitud[3] - '0') * 10 + (longitud[4] - '0'); //Extraemos los minutos de la longitud introducida al llamar a la funci�n
    int seglon = (longitud[6] - '0') * 10 + (longitud[7] - '0'); //Extraemos los segundos de la longitud introducida al llamar a la funci�n

    if (minlat <= 48){ //Si los minutos de la latitud son menores o iguales que 48:
        muelle[0] = 'S'; //El muelle al que pertenece el paquete est� al sur
        if (minlat == 48 && seglat >= 35){ //Pero si los minutos son = 48 y los segundos >= 35 entonces est� al norte
            muelle[0] = 'N'; //El muelle al que pertenece el paquete est� al norte
        }
    }

    if (minlon <= 36){ //Si los minutos de la longitud son menores o iguales que 36:
        muelle[1] = 'E'; //El muelle al que pertenece el paquete est� al este
        if (minlon == 36 && seglon >= 31){ //Pero si los minutos son iguales a 36 y los segundos >= 31 entonces est� al oeste
            muelle[1] = 'O'; //El muelle al que pertenece el paquete est� al oeste
        }
    }

    char *str = new char[2]; //Reservamos memoria para un array char de tama�o 2 al que apunta str
    strcpy(str,muelle); //Copiamos la informacci�n del array muelle en str

    return str; //retornamos el puntero que apunta al muelle al que pertenece el paquete
}
