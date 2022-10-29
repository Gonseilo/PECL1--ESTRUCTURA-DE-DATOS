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
        Paquete *temp = new Paquete();

        ptr = p.GenerarID();
        temp->informacion.codigoID = ptr;

        ptr = p.GenerarLatitud();
        temp->informacion.coordenadas.latitud = ptr;

        ptr = p.GenerarLongitud();
        temp->informacion.coordenadas.longitud = ptr;

        ptr = p.GenerarDNI();
        temp->informacion.DNI = ptr;

        c.Enqueue(temp);
    }
    c.Print(tempPrint1);
    delete[] ptr;

    getch();
    return 0;
}
