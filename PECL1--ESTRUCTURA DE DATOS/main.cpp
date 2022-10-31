#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include "Paquetes.h"
#include "Colas.h"
#include "Pilas.h"
#include "Muelles.h"

using std::cout; using std::cin; using std::endl; using std::setw;
//Creamos todos los objetos necesarios
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
//Creamos punteros con los nombres de los muelles que nos devolverá la función AsignarMuelle() para poder compararlos
char* NE = "NE";
char* NO = "NO";
char* SE = "SE";
char* SO = "SO";
//Creamos contadores con la cantidad de furgonetas que salgan de cada muelle
int contNO;
int contNE;
int contSO;
int contSE;
//Creamos las pilas que nos servirán como las furgonetas de cada muelle
Paquete* muelleNE[N2];
Paquete* muelleNO[N2];
Paquete* muelleSE[N2];
Paquete* muelleSO[N2];

int main(){
    //Hacemos que el randomizado funcione
    time_t current_time = time(NULL);
    srand((unsigned) time(NULL));

    setlocale(LC_ALL, "spanish"); //Declaramos el idioma español

    Paquete* aux; //Declaramos un puntero a paquete auxiliar
    cout<<"\n" << setw(19) << "||LLEGAN "<<N1<<" PAQUETES A LA CENTRAL DE PAQUETERÍA||"<<endl; //Imprimir frase "Llegan n1 paquetes a la central"
    for (int i=0;i<N1;i++){ //Por cada N1:
        Paquete *temp = new Paquete(); //Creamos un paquete

        p.setCodigoID(p.GenerarID()); //Generamos su ID
        temp->informacion.codigoID = p.getCodigoID(); //Almacenamos su ID

        p.setLatitud(p.GenerarLatitud()); //Generamos su latitud
        temp->informacion.coordenadas.latitud = p.getLatitud(); //Almacenamos su latitud

        p.setLongitud(p.GenerarLongitud()); //Generamos su longitud
        temp->informacion.coordenadas.longitud = p.getLongitud(); //Almacenamos su longitud

        p.setDNI(p.GenerarDNI()); //Generamos el DNI
        temp->informacion.DNI = p.getDNI(); //Almacenamos el DNI

        c1.Enqueue(temp); //Encolamos el paquete en la cola1
    }
    c1.PrintCola(aux); //Imprimimos los N1 paquetes en forma de tabla

    while ((c1.head != nullptr) && (c1.rear != nullptr)) { //Mientras haya datos en la cola:
        cout << "\n\n" << setw(26) << "||SELECCIONANDO " << N2 << " PAQUETES DE LA CENTRAL...||" << endl; //Imprimimos la cabezera de selecionar paquetes
        for (int i=0; i < N2; i++){ //Por cada N2:
            c2.Enqueue(c1.Dequeue(aux)); //Encolamos en una cola2 el desencolado de la cola1
        }
        c2.PrintCola(aux); //Imprimimos la cola2 en forma de tabla
        cout << "*Distribuyendo cada paquete según sus coordenadas en los muelles...*" << endl; //Cout informativo
        cout << "\n\n\n\n==========================||ESTADO DE SALIDA DE LAS FURGONETAS||========================\n\n\n" << endl; //Cabecera del estado de salida de las furgonetas

        for (int i = 0; i < N2; i++){ //Por cada N2:
            aux = c2.Dequeue(aux); //Almacenamos en el paquete* auxiliar el desencolado de la cola2
            char* muelle = m.AsignarMuelle(aux->informacion.coordenadas.latitud, aux->informacion.coordenadas.longitud); //Le asignamos el muelle al valor desencolado en aux

            if (strcmp((muelle), "NO") == 0){ //Si el muelle es el NO
                cNOaux.Enqueue(aux); //Encolamos el dato en la cola auxiliar del NO
                piNO.push(aux, muelleNO); //Introducimos el dato en la pila del NO
                if (piNO.top == N3){ //Si la pila se llena:
                    contNO++; //Subimos el contador de las furgonetas del NO
                    cout << "======================Furgoneta " << contNO << " llena del muelle NO, saliendo...================>>>>>>" << endl; //cout informativo
                    cout << "<<<<<<===================Llega furgoneta " << contNO + 1 << " vacía al muelle NO===========================\n"<<endl; //cout informativo
                    for (int i = 0; i < N3 ; i++){ //Por cada N3 (dato en la pila)
                        cNO.Enqueue(cNOaux.Dequeue(aux)); //Encolamos el dato en la cola del NO
                        piNO.pop(muelleNO); //Sacamos el dato de la pila
                    }
                }
            }
            //Repetimos el anterior proceso para NE, SO y SE
            if (strcmp((muelle), "NE") == 0){
                cNEaux.Enqueue(aux);
                piNE.push(aux, muelleNE);
                if (piNE.top == N3){
                    contNE++;
                    cout << "======================Furgoneta " << contNE << " llena del muelle NE, saliendo...================>>>>>>" << endl;
                    cout << "<<<<<<===================Llega furgoneta " << contNE + 1 << " vacía al muelle NE===========================\n"<<endl;
                    for (int i = 0; i < N3 ; i++){
                        cNE.Enqueue(cNEaux.Dequeue(aux));
                        piNE.pop(muelleNE);
                    }
                }
            }

            if (strcmp((muelle), "SO") == 0){
                cSOaux.Enqueue(aux);
                piSO.push(aux, muelleSO);
                if (piSO.top == N3){
                    contSO++;
                    cout << "======================Furgoneta " << contSO << " llena del muelle SO, saliendo...================>>>>>>" << endl;
                    cout << "<<<<<<===================Llega furgoneta " << contSO + 1 << " vacía al muelle SO===========================\n"<<endl;
                    for (int i = 0; i < N3 ; i++){
                        cSO.Enqueue(cSOaux.Dequeue(aux));
                        piSO.pop(muelleSO);
                    }
                }
            }

            if (strcmp((muelle), "SE") == 0){
                cSEaux.Enqueue(aux);
                piSE.push(aux, muelleSE);
                if (piSE.top == N3){
                    contSE++;
                    cout << "======================Furgoneta " << contSE << " llena del muelle SE, saliendo...================>>>>>>" << endl;
                    cout << "<<<<<<===================Llega furgoneta " << contSE + 1 << " vacía al muelle SE===========================\n"<<endl;
                    for (int i = 0; i < N3 ; i++){
                        cSE.Enqueue(cSEaux.Dequeue(aux));
                        piSE.pop(muelleSE);

                    }
                }
            }
        }
        cout<<"\n\n========================================================================================\n\n"<<endl; //Decoración
        int x = 0; //Declaramos una variable a 0 que nos ayudará en el siguiente while
        while (x == 0) { //Mientras x==0
            char respuesta[1]; //Declaramos la variable respuesta de tamaño 1
            //Imprimimos el menú de operaciones del switch:
            cout << "\n\n\n            ||MENÚ DE OPERACIONES||"<<endl;
            cout << "----------------------------------------------" << endl;
            cout << "0: Finalizar proceso." << endl;
            cout << "1: Mostrar el estado actual de las furgonetas." << endl;
            cout << "2: Mostrar los paquetes enviados a cada zona." << endl;
            cout << "3: Seleccionar otros " << N2 << " paquetes de la central." << endl;
            cout<<  "Introduzca su próxima operación : "<<endl;
            //Guardamos la respuesta del usuario
            cin >> respuesta;
            switch(respuesta[0]){ //Según el primer valor introducido en la respuesta del usuario:
            case '0': //Si es 0:
                c1.head = nullptr; //Hacemos que se salga del while grande
                x = 1; //Hacemos que se salga del while pequeño
                break; //Salimos del switch
            case '1': //Si es 1 imprimimos los estados de las furgonetas de cada muelle imprimiendo sus respectivas pilas
                cout << "\n\n=============Estado actual de la furgoneta del muelle NO:=============\n" << endl;
                piNO.printPila(muelleNO);
                cout << "\n\n=============Estado actual de la furgoneta del muelle NE:=============\n" << endl;
                piNE.printPila(muelleNE);
                cout << "\n\n=============Estado actual de la furgoneta del muelle SO:=============\n" << endl;
                piSO.printPila(muelleSO);
                cout << "\n\n=============Estado actual de la furgoneta del muelle SE:=============\n" << endl;
                piSE.printPila(muelleSE);
                cout << "\n\n" << endl;
                break; //Salimos del switch
            case '2': //Si es 2 imprimimos los paquetes enviados a cada muelle imprimiendo sus respectivas colas
                cout << "\n\n===================Paquetes enviados a la zona NO:====================\n" << endl;
                cNO.PrintEnviado(aux);
                cout << "\n\n===================Paquetes enviados a la zona NE:====================\n" << endl;
                cNE.PrintEnviado(aux);
                cout << "\n\n===================Paquetes enviados a la zona SO:====================\n" << endl;
                cSO.PrintEnviado(aux);
                cout << "\n\n===================Paquetes enviados a la zona SE:====================\n" << endl;
                cSE.PrintEnviado(aux);
                break; //Salimos del switch
            case '3': //Si es 3:
                if (c1.head == nullptr){ //Si no quedan paquetes en la cola del N1:
                    cout << "\n\n*****No se pueden seleccionar más paquetes de la central, por favor seleccione otra opción.*****\n" << endl; //cout informativo
                    break; //Salimos del switch
                }
                x = 1; //Salimos del while pequeño para extraer otros N2 paquetes
                break; //Salimos del switch
            default: //Si el usuario no introduce ninguno de los valores especificados
                break; //Salimos del switch
            }
        }
    }
    //Imprimimos el informe estadístico en forma de tabla, para la cual usamos los valores de las colas y las pilas ya utilizadas
    cout << "\n||====================================================||" << endl;
    cout << "||" << setw(20) << "Informe estadístico" << setw(5) << "|" << setw(4) << "NO" << setw(3) << "|" << setw(4) << "NE" << setw(3) << "|" << setw(4) << "SO" << setw(3) << "|" << setw(4) << "SE" << setw(4) << "||" << endl;
    cout << "||------------------------|------|------|------|------||" << endl;
    cout << "||" << setw(20) << "Paquetes recibidos:" << setw(5) << "|" << setw(4) << cNO.recorrerCola(aux) + piNO.top << setw(3) << "|" << setw(4) << cNE.recorrerCola(aux) + piNE.top << setw(3) << "|" << setw(4) << cSO.recorrerCola(aux) + piSO.top << setw(3) << "|" << setw(4) << cSE.recorrerCola(aux) + piSE.top << setw(4) << "||" << endl;
    cout << "||" << setw(19) << "Paquetes enviados:" << setw(6) << "|" << setw(4) << cNO.recorrerCola(aux) << setw(3) << "|" << setw(4) << cNE.recorrerCola(aux) << setw(3) << "|" << setw(4) << cSO.recorrerCola(aux) << setw(3) << "|" << setw(4) << cSE.recorrerCola(aux) << setw(4) << "||" << endl;
    cout << "||" << setw(21) << "Paquetes sin enviar:" << setw(4) << "|" << setw(4) << piNO.top << setw(3) << "|" << setw(4) << piNE.top << setw(3) << "|" << setw(4) << piSO.top << setw(3) << "|" << setw(4) << piSE.top << setw(4) << "||" << endl;
    cout << "||" << setw(23) << "Furgonetas utilizadas:" << setw(2) << "|" << setw(4) << contNO << setw(3) << "|" << setw(4) << contNE << setw(3) << "|" << setw(4) << contSO << setw(3) << "|" << setw(4) << contSE << setw(4) << "||" << endl;
    cout << "||====================================================||\n" << endl;
    cout << "Fin del proceso." << endl;

    getch();
    return 0;
}
