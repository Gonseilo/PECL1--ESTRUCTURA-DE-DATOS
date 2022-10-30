#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <stdio.h>
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
Colas cNEaux;
Colas cNOaux;
Colas cSEaux;
Colas cSOaux;
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
        cout << "\nSeleccionando 10 paquetes de la central...\n\n" << endl;
        for (int i=0; i < N2; i++){
            c2.Enqueue(c1.Dequeue(tempaux));
        }
        c2.Print(tempaux);

        for (int i = 0; i < N2; i++){
            tempaux = c2.Dequeue(tempaux);
            char* muelle = m.AsignarMuelle(tempaux->informacion.coordenadas.latitud, tempaux->informacion.coordenadas.longitud);

            if (strcmp((muelle), "NO") == 0){
                cNOaux.Enqueue(tempaux);
                piNO.push(tempaux, muelleNO);
                if (piNO.top == N3){
                    cout << "=====================Sale furgoneta del muelle NO=====================\n" << endl;
                    for (int i = 0; i < N3 ; i++){
                        cNO.Enqueue(cNOaux.Dequeue(tempaux));
                        piNO.pop(muelleNO);
                    }
                }
            }

            if (strcmp((muelle), "NE") == 0){
                cNEaux.Enqueue(tempaux);
                piNE.push(tempaux, muelleNE);
                if (piNE.top == N3){
                    cout << "=====================Sale furgoneta del muelle NE=====================\n" << endl;
                    for (int i = 0; i < N3 ; i++){
                        cNE.Enqueue(cNEaux.Dequeue(tempaux));
                        piNE.pop(muelleNE);
                    }
                }
            }

            if (strcmp((muelle), "SO") == 0){
                cSOaux.Enqueue(tempaux);
                piSO.push(tempaux, muelleSO);
                if (piSO.top == N3){
                    cout << "=====================Sale furgoneta del muelle SO=====================\n" << endl;
                    for (int i = 0; i < N3 ; i++){
                        cSO.Enqueue(cSOaux.Dequeue(tempaux));
                        piSO.pop(muelleSO);
                    }
                }
            }

            if (strcmp((muelle), "SE") == 0){
                cSEaux.Enqueue(tempaux);
                piSE.push(tempaux, muelleSE);
                if (piSE.top == N3){
                    cout << "=====================Sale furgoneta del muelle SE=====================\n" << endl;
                    for (int i = 0; i < N3 ; i++){
                        cSE.Enqueue(cSEaux.Dequeue(tempaux));
                        piSE.pop(muelleSE);
                    }
                }
            }
        }
        int x = 0;
        while (x == 0) {
            char respuesta[1];
            cout << "¿Qué desea hacer?" << endl;
            cout << "0: Finalizar proceso." << endl;
            cout << "1: Ver el estado actual de las furgonetas." << endl;
            cout << "2: Ver los paquetes enviados a cada zona." << endl;
            cout << "3: Seleccionar otros " << N2 << " paquetes de la central." << endl;
            cin >> respuesta;
            switch(respuesta[0]){
            case '0':
                c1.head = nullptr;
                x = 1;
                break;
            case '1':
                cout << "\n\n=============Estado actual de la furgoneta del muelle NO:=============\n" << endl;
                piNO.print(muelleNO);
                cout << "\n\n=============Estado actual de la furgoneta del muelle NE:=============\n" << endl;
                piNE.print(muelleNE);
                cout << "\n\n=============Estado actual de la furgoneta del muelle SO:=============\n" << endl;
                piSO.print(muelleSO);
                cout << "\n\n=============Estado actual de la furgoneta del muelle SE:=============\n" << endl;
                piSE.print(muelleSE);
                cout << "\n\n" << endl;
                break;
            case '2':
                cout << "\n\n===================Paquetes enviados a la zona NO:====================\n" << endl;
                cNO.PrintEnviado(tempaux);
                cout << "\n\n===================Paquetes enviados a la zona NE:====================\n" << endl;
                cNE.PrintEnviado(tempaux);
                cout << "\n\n===================Paquetes enviados a la zona SO:====================\n" << endl;
                cSO.PrintEnviado(tempaux);
                cout << "\n\n===================Paquetes enviados a la zona SE:====================\n" << endl;
                cSE.PrintEnviado(tempaux);
                break;
            case '3':
                x = 1;
                break;
            default:
                break;
            }
        }
    }
    cout << "Fin del proceso." << endl;

    getch();
    return 0;
}
