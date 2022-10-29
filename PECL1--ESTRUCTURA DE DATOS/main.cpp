#include <iostream>
#include "stdio.h"
#include <locale.h>
#include "Paquetes.h"
#include <conio.h>
#include "Colas.h"
#include "Pilas.h"
#include "Muelles.h"

using std::cout; using std::cin; using std::endl;


Paquete *tempPrint1 = nullptr;
Colas c;
Paquetes p;

int main(){
    char* ptr;
    for (int j=0;j<N1;j++){
        Paquete *temp = new Paquete();/*
        ptr = "         ";
        for (int i=0;i<9;i++){
            temp->informacion.codigoID[i] = ptr[i];
            temp->informacion.coordenadas.latitud[i] = ptr[i];
            temp->informacion.coordenadas.longitud[i] = ptr[i];
            temp->informacion.DNI[i] = ptr[i];
        }*/
        ptr = p.GenerarID();
        temp->informacion.codigoID = ptr;
        //cout<<temp->informacion.codigoID<<endl;

        ptr = p.GenerarLatitud();
        temp->informacion.coordenadas.latitud = ptr;
        //cout<<temp->informacion.coordenadas.latitud<<endl;

        ptr = p.GenerarLongitud();
        temp->informacion.coordenadas.longitud = ptr;
        //cout<<temp->informacion.coordenadas.longitud<<endl;

        ptr = p.GenerarDNI();
        temp->informacion.DNI = ptr;
        //cout<<temp->informacion.codigoID<<endl;
        //cout<<temp->informacion.coordenadas.latitud<<endl;
        //cout<<temp->informacion.coordenadas.longitud<<endl;
        //cout<<temp->informacion.DNI<<endl;
        //delete[] ptr;

        c.Enqueue(temp);
    }
    c.Print(tempPrint1);
    delete[] ptr;

    getch();
    return 0;
}
