#include <iostream>
#include <iomanip>
#include "Pilas.h"

using std::cout; using std::endl; using std::setw;

Pilas::Pilas(){
    //ctor
}

Pilas::~Pilas(){
    //dtor
}

int top = 0;

void Pilas::push(Paquete* dato, Paquete* pila[]) {
    if (top == N3){
    }
    else {
        pila[top++] = dato;
    }
}

void Pilas::pop(Paquete* pila[]) {
    if (top == 0){
    }
    else {
        top--;
    }
}

void Pilas::print(Paquete* pila[]) {
    cout << "||==================================================================||" << endl;
    cout << "|| Estado del paquete | Código ID |" << setw(16) << "Coordenadas" << setw(6) << "|" << setw(7) << "DNI" <<  setw(6) << "||" << endl;
    cout << "||--------------------|-----------|---------------------|-----------||" << endl;
    for (int i = 0; i < top; i++) {
        cout << "||" << setw(16) << "Esperando..." << setw(5) << "|" << setw(9) << pila[i]->informacion.codigoID << setw(3) << "|" << setw(9) << pila[i]->informacion.coordenadas.latitud << setw(11) << pila[i]->informacion.coordenadas.longitud << setw(2) << "|" << setw(10) << pila[i]->informacion.DNI << setw(3) << "||" << endl;
    }
    cout << "||==================================================================||" << endl;
}
