#include <iostream>
#include "Paquetes.h"
#include "string.h"

using std::cout; using std::cin; using std::endl;

int cont = 1;

Paquetes::Paquetes(){
    //ctor
}

Paquetes::~Paquetes(){
    //dtor
}

char* Paquetes::GenerarID(){
    char ID[] = "00a0000"; //Definimos el formato del array del codigoID.
    char letter[] = "abcdefghijklmnopqrstuvwxyz"; //Definimos un array que almacene el abcedario
    char numbers[] = "0123456789"; //Definimos un array que almacene los numeros usados
    int num1, num2, num3, num4;
    int contaux;
    contaux = cont;
    cont++;

    //Separamos un numero de 4 cifras en 4 numeros.
    num1 = contaux / 1000;
    contaux -= num1 * 1000;
    num2 = contaux / 100;
    contaux -= num2 * 100;
    num3 = contaux / 10;
    contaux -= num3 * 10;
    num4 = contaux;

    //Creamos de forma aleatoria con la función rand() en cada posición del array lop que corresponda.
    ID[0] = numbers[rand() % 10];
    ID[1] = numbers[rand() % 10];
    ID[2] = letter[rand() % 26];
    ID[3] = numbers[num1];
    ID[4] = numbers[num2];
    ID[5] = numbers[num3];
    ID[6] = numbers[num4];

    char *str = new char[7]; //Reservamos memoria con un espacio suficiente para almacenar el array de codigoID.
    memcpy(str,ID,7); //Copiamos la información del array de ID en ese espacio reservado y que esta apuntado por str.

    return str; //Retornamos el puntero.
}

char* Paquetes::GenerarLatitud(){
    //Definimos cada uno de los arrays junto con su formato
    char latitud[] = "40 00 00";
    char num[] = "0123456789";
    int segundo;
    int minuto = rand() % 6; //Generamos un min random del 0 al 5 (posteriormente del 46 al 51)

    if (minuto == 0){ //Si el minuto es 0 (46)
        segundo = (rand() % 54) + 6; //Los segundos son random del 5 al 59
    }
    if (0 < minuto && minuto < 5){ //Si el minuto es del 1 al 4 (47-50)
        segundo = rand() % 60; //Los segundos son random del 0 al 59
    }
    if (minuto == 5){ //Si el minuto es 5 (51)
        segundo = rand() % 7; //Los segundos son random del 0 al 6
    }
    //Asignamos los valores generados a los datos de la latitud extrayendo de ellos el primer valor con (/10) y el segundo con (%10)
    latitud[3] = num[(minuto + 46) / 10];
    latitud[4] = num[(minuto + 46) % 10];
    latitud[6] = num[(segundo + 1) / 10];
    latitud[7] = num[(segundo + 1) % 10];

    char *str = new char[8]; //Reservamos memoria con un espacio suficiente para almacenar el array de codigoID.
    strcpy(str,latitud); //Copiamos la información del array latitud en el espacio reservado apuntado por str.

    return str; //Retornamos el puntero.
}

char* Paquetes::GenerarLongitud(){
    //Definimos cada uno de los arrays junto con su formato
    char longitud[] = "-3 00 00";
    char num[] = "0123456789";
    int segundo;
    int minuto = rand() % 10; //Generamos un min random del 0 al 9 (posteriormente del 32 al 41)

    if (minuto == 0){ //Si el minuto es 0 (32)
        segundo = (rand() % 57) + 3; //Los segundos son random del 3 al 59
    }
    if (0 < minuto && minuto < 9){ //Si el minuto es del 1 al 4 (33-40)
        segundo = rand() % 60; //Los segundos son random del 0 al 59
    }
    if (minuto == 9){ //Si el minuto es 5 (41)
        segundo = rand() % 2; //Los segundos son random del 0 al 1
    }
    //Asignamos los valores generados a los datos de la latitud extrayendo de ellos el primer valor con (/10) y el segundo con (%10)
    longitud[3] = num[(minuto + 32) / 10];
    longitud[4] = num[(minuto + 32  ) % 10];
    longitud[6] = num[(segundo + 1) / 10];
    longitud[7] = num[(segundo + 1) % 10];

    char *str = new char[8]; //Reservamos memoria con un espacio suficiente para almacenar el array de codigoID.
    strcpy(str,longitud); //Copiamos la información del array longitud en el espacio reservado apuntado por str.

    return str; //Retornamos el puntero.
}

char* Paquetes::GenerarDNI(){
    //Definimos el array con el formato y una copia del mismo
    char DNI[] = "03173882C";
    char DNIf[] = "03173882C";

    for (int i = 0; i < 8; i++){ //Por cada posición generamos un numero aleatorio entre las 8 posiciones.
        DNIf[i] = DNI[rand() % 8];
    }

    char *str = new char[9]; //Rservamos un esapcio de memoria suficiente para almacenar el array del DNI.
    strcpy(str,DNIf); //Copiamos la información del array DNI en el espacio reservado apuntado por str.

    return str; //Retornamos el puntero.
}

void Paquetes::setCodigoID(char* _codigoID)
{
    codigoID = _codigoID;
}

void Paquetes::setLatitud(char* _latitud)
{
    latitud = _latitud;
}

void Paquetes::setLongitud(char* _longitud)
{
    longitud = _longitud;
}

void Paquetes::setDNI(char* _DNI)
{
    DNI = _DNI;
}


char* Paquetes::getCodigoID()
{
    return codigoID;
}

char* Paquetes::getLatitud()
{
    return latitud;
}

char* Paquetes::getLongitud()
{
    return longitud;
}

char* Paquetes::getDNI()
{
    return DNI;
}
