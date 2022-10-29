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
Colas c1;
Paquetes p;
Paquete *head1 = nullptr;
Paquete *rear1 = nullptr;

int main(){
    char* ptr;
    c1.head = head1;
    c1.rear = rear1;

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

        c1.Enqueue(temp);
    }
    c1.Print(tempPrint1);
    delete[] ptr;

    getch();
    return 0;
}
