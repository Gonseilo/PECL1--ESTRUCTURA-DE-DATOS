#include <iostream>
#include "Muelles.h"
#include "string.h"

Muelles::Muelles(){
    //ctor
}

Muelles::~Muelles(){
    //dtor
}

char* Muelles::AsignarMuelle(char* latitud, char* longitud){ //Función AsignarMuelle usada para decidir a que muelle irá un paquete en base a sus coordenadas
    char muelle[] = "NO"; //Todos los paquetes irán predeterminadamente al NO, aunque esto cambiará a lo largo de la función
    int minlat = (latitud[3] - '0') * 10 + (latitud[4] - '0'); //Extraemos los minutos de la latitud introducida al llamar a la función
    int seglat = (latitud[6] - '0') * 10 + (latitud[7] - '0'); //Extraemos los segundos de la latitud introducida al llamar a la función
    int minlon = (longitud[3] - '0') * 10 + (longitud[4] - '0'); //Extraemos los minutos de la longitud introducida al llamar a la función
    int seglon = (longitud[6] - '0') * 10 + (longitud[7] - '0'); //Extraemos los segundos de la longitud introducida al llamar a la función

    if (minlat <= 48){ //Si los minutos de la latitud son menores o iguales que 48:
        muelle[0] = 'S'; //El muelle al que pertenece el paquete está al sur
        if (minlat == 48 && seglat >= 35){ //Pero si los minutos son = 48 y los segundos >= 35 entonces está al norte
            muelle[0] = 'N'; //El muelle al que pertenece el paquete está al norte
        }
    }

    if (minlon <= 36){ //Si los minutos de la longitud son menores o iguales que 36:
        muelle[1] = 'E'; //El muelle al que pertenece el paquete está al este
        if (minlon == 36 && seglon >= 31){ //Pero si los minutos son iguales a 36 y los segundos >= 31 entonces está al oeste
            muelle[1] = 'O'; //El muelle al que pertenece el paquete está al oeste
        }
    }

    char *str = new char[2]; //Reservamos memoria para un array char de tamaño 2 al que apunta str
    strcpy(str,muelle); //Copiamos la informacción del array muelle en str

    return str; //retornamos el puntero que apunta al muelle al que pertenece el paquete
}
