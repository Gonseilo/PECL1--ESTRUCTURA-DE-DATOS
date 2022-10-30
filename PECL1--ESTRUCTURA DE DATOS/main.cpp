#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>
#include "Paquetes.h"
#include "Colas.h"
#include "Pilas.h"
#include "Muelles.h"

using std::cout; using std::cin; using std::endl;

Paquetes p;
Muelles m;
Colas c1;
Colas c2;
Colas cNE;
Colas cNO;
Colas cSE;
Colas cSO;
Pilas piNE;
Pilas piNO;
Pilas piSE;
Pilas piSO;

char* NE = "NE";
char* NO = "NO";
char* SE = "SE";
char* SO = "SO";

Paquete* muelleNE[N2];
Paquete* muelleNO[N2];
Paquete* muelleSE[N2];
Paquete* muelleSO[N2];

int main(){
    time_t current_time = time(NULL);
    srand((unsigned) time(NULL));

    setlocale(LC_ALL, "spanish");

    Paquete* tempaux;

    for (int i=0;i<N1;i++){
        Paquete *temp = new Paquete();

        p.setCodigoID(p.GenerarID());
        temp->informacion.codigoID = p.getCodigoID();

        p.setLatitud(p.GenerarLatitud());
        temp->informacion.coordenadas.latitud = p.getLatitud();

        p.setLongitud(p.GenerarLongitud());
        temp->informacion.coordenadas.longitud = p.getLongitud();

        p.setDNI(p.GenerarDNI());
        temp->informacion.DNI = p.getDNI();

        c1.Enqueue(temp);
    }
    c1.Print(tempaux);

    while ((c1.head != nullptr) && (c1.rear != nullptr)) {
        for (int i=0; i < N2; i++){
            c2.Enqueue(c1.Dequeue(tempaux));
        }
        c2.Print(tempaux);

        for (int i = 0; i < N2; i++){
            tempaux = c2.Dequeue(tempaux);
            char* muelle = m.AsignarMuelle(tempaux->informacion.coordenadas.latitud, tempaux->informacion.coordenadas.longitud);

            if (strcmp((muelle), "NO") == 0){
                cout << "NO" << endl;
                cNO.Enqueue(tempaux);
                piNO.push(tempaux, muelleNO);
                if (piNO.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piNO.pop(muelleNO);
                    }
                }
            }

            if (strcmp((muelle), "NE") == 0){
                cout << "NE" << endl;
                cNE.Enqueue(tempaux);
                piNE.push(tempaux, muelleNE);
                if (piNE.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piNE.pop(muelleNE);
                    }
                }
            }

            if (strcmp((muelle), "SO") == 0){
                cout << "SO" << endl;
                cSO.Enqueue(tempaux);
                piSO.push(tempaux, muelleSO);
                if (piSO.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piSO.pop(muelleSO);
                    }
                }
            }

            if (strcmp((muelle), "SE") == 0){
                cout << "SE" << endl;
                cSE.Enqueue(tempaux);
                piSE.push(tempaux, muelleSE);
                if (piSE.top == N3){
                    for (int i = 0; i < N3 ; i++){
                        piSE.pop(muelleSE);
                    }
                }
            }
        }

        int aux;
        cout << "Introduzca 1 para repetir el proceso: ";
        cin >> aux;
        if (aux == 1){
            cout << "Repitiendo proceso..." << endl;
        }
        else{
            c1.head = nullptr;
        }
    }
    cout << "Fin del proceso." << endl;

    getch();
    return 0;
}
