#include <iostream>
#include "stdio.h"
#include <locale.h>
#include "Paquetes.h"
#include <conio.h>
#include "Colas.h"
#include "Pilas.h"
#include "Muelles.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

using std::cout; using std::cin; using std::endl;

Paquetes p;
Muelles m;
Pilas pi;
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
char* NE = "NE";

Colas cNO;
Paquete *headNO = nullptr;
Paquete *rearNO = nullptr;
char* NO = "No";

Colas cSE;
Paquete *headSE = nullptr;
Paquete *rearSE = nullptr;
char* SE = "SE";

Colas cSO;
Paquete *headSO = nullptr;
Paquete *rearSO = nullptr;
char* SO = "SO";

Pilas piNE;
Paquete* muelleNE[N2];

Pilas piNO;
Paquete* muelleNO[N2];

Pilas piSE;
Paquete* muelleSE[N2];

Pilas piSO;
Paquete* muelleSO[N2];

int main(){
    time_t current_time = time(NULL);
    srand((unsigned) time(NULL));

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
            char* muelle = m.AsignarMuelle(ptr2->informacion.coordenadas.latitud, ptr2->informacion.coordenadas.longitud);

            if (strcmp((muelle), "NO") == 0){
                cout << "NO" << endl;
                cNO.Enqueue(ptr2);
                piNO.push(ptr2, muelleNO);
                if (piNO.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piNO.pop(muelleNO);
                    }
                }
            }

            if (strcmp((muelle), "NE") == 0){
                cout << "NE" << endl;
                cNE.Enqueue(ptr2);
                piNE.push(ptr2, muelleNE);
                if (piNE.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piNE.pop(muelleNE);
                    }
                }
            }

            if (strcmp((muelle), "SO") == 0){
                cout << "SO" << endl;
                cSO.Enqueue(ptr2);
                piSO.push(ptr2, muelleSO);
                if (piSO.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piSO.pop(muelleSO);
                    }
                }
            }

            if (strcmp((muelle), "SE") == 0){
                cout << "SE" << endl;
                cSE.Enqueue(ptr2);
                piSE.push(ptr2, muelleSE);
                if (piSE.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piSE.pop(muelleSE);
                    }
                }
            }
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
