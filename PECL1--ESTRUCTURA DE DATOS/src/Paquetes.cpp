#include "Paquetes.h"
#include <iostream>
#include "stdio.h"
#include <locale.h>
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
    int counter = cont;
    char ID[] = "00a0000";
    char letter[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    int num1, num2, num3, num4;
    int contaux;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    num4 = 0;
    contaux = counter;
    cont++;

    num1 = contaux / 1000;
    contaux -= num1 * 1000;
    num2 = contaux / 100;
    contaux -= num2 * 100;
    num3 = contaux / 10;
    contaux -= num3 * 10;
    num4 = contaux;

    ID[0] = numbers[rand() % 10];
    ID[1] = numbers[rand() % 10];
    ID[2] = letter[rand() % 26];
    ID[3] = numbers[num1];
    ID[4] = numbers[num2];
    ID[5] = numbers[num3];
    ID[6] = numbers[num4];

    char *str = new char[7];
    memcpy(str,ID,7);

    return str;
}

char* Paquetes::GenerarLatitud(){
    char latitud[] = "40 00 00";
    char num[] = "0123456789";
    int segundo;
    int minuto = rand() % 6;

    if (minuto == 0){
        int segundo = (rand() % 54) + 6;
    }
    if (0 < minuto && minuto < 5){
        int segundo = rand() % 60;
    }
    if (minuto == 5){
        int segundo = rand() % 7;
    }

    latitud[3] = num[(minuto + 46) / 10];
    latitud[4] = num[(minuto + 46) % 10];
    latitud[6] = num[(segundo + 1) / 10];
    latitud[7] = num[(segundo + 1) % 10];

    char *str = new char[8];
    strcpy(str,latitud);

    return str;
}

char* Paquetes::GenerarLongitud(){
    char longitud[] = "-3 00 00";
    char num[] = "0123456789";
    int segundo;
    int minuto = rand() % 10;

    if (minuto == 0){
        int segundo = (rand() % 57) + 3;
    }
    if (0 < minuto && minuto < 9){
        int segundo = rand() % 60;
    }
    if (minuto == 9){
        int segundo = rand() % 2;
    }

    longitud[3] = num[(minuto + 32) / 10];
    longitud[4] = num[(minuto + 32  ) % 10];
    longitud[6] = num[(segundo + 1) / 10];
    longitud[7] = num[(segundo + 1) % 10];

    char *str = new char[8];
    strcpy(str,longitud);

    return str;
}

char* Paquetes::GenerarDNI(){
    char DNI[] = "03173882C";
    char DNIf[] = "03173882C";

    for (int i = 0; i < 8; i++){
        DNIf[i] = DNI[rand() % 8];
    }

    char *str = new char[9];
    strcpy(str,DNIf);

    return str;
}
