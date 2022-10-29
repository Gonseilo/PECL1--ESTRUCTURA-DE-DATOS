#include <iostream>
#include "stdio.h"
#include <locale.h>
#include "Paquetes.h"
#include <conio.h>
#include "Colas.h"
#include "Pilas.h"
#include "Muelles.h"

using std::cout; using std::cin; using std::endl;

Paquetes p;
int aux;

Colas c1;
Paquete *head1 = nullptr;
Paquete *rear1 = nullptr;

Colas c2;
Paquete *head2 = nullptr;
Paquete *rear2 = nullptr;

Colas cNE;
Paquete *headNE = nullptr;
Paquete *rearNE = nullptr;

Colas cNO;
Paquete *headNO = nullptr;
Paquete *rearNO = nullptr;

Colas cSE;
Paquete *headSE = nullptr;
Paquete *rearSE = nullptr;

Colas cSO;
Paquete *headSO = nullptr;
Paquete *rearSO = nullptr;

int muelleNE[N2];
int topNE = 0;

int muelleNO[N2];
int topNO = 0;

int muelleSE[N2];
int topSE = 0;

int muelleSO[N2];
int topSO = 0;

int main(){
    char* ptr;
    Paquete* ptr2;

    Paquete *tempPrint1 = nullptr;
    c1.head = head1;
    c1.rear = rear1;

    Paquete *tempPrint2 = nullptr;
    c2.head = head2;
    c2.rear = rear2;

    Paquete *tempPrintNE = nullptr;
    cNE.head = headNE;
    cNE.rear = rearNE;

    Paquete *tempPrintNO = nullptr;
    cNO.head = headNO;
    cNO.rear = rearNO;

    Paquete *tempPrintSE = nullptr;
    cSE.head = headSE;
    cSE.rear = rearSE;

    Paquete *tempPrintSO = nullptr;
    cSO.head = headSO;
    cSO.rear = rearSO;

    Paquete *tempaux;

    for (int i=0;i<N1;i++){
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

    while ((c1.head != nullptr) && (c1.rear != nullptr)) {
        for (int i=0; i < N2; i++){
            c2.Enqueue(c1.Dequeue(tempaux));
        }
        c2.Print(tempPrint2);

        for (int i = 0; i < N2; i++){
            ptr2 = c2.Dequeue(tempaux);


        }

        cout << "Introduzca 1 para repetir el proceso: ";
        cin >> aux;
        if (aux == 1){
            cout << "Repitiendo proceso..." << endl;
        }
        else{
            c1.head = nullptr;
        }
    }
    cout << "fin del proceso" << endl;

    getch();
    return 0;
}
