#include <iostream>
#include "Pilas.h"

using std::cout; using std::cin; using std::endl;

Pilas::Pilas(){
    //ctor
}

Pilas::~Pilas(){
    //dtor
}

int top = 0;

void Pilas::push(Paquete* dato, Paquete* pila[]) {
    if (top == N3){
        cout << "La pila está llena" << endl;
    }
    else {
        pila[top++] = dato;
        cout << "Añadiendo " << dato->informacion.codigoID << " a la pila..." << endl;
    }
}

void Pilas::pop(Paquete* pila[]) {
    if (top == 0){
        cout << "La pila está vacía";
    }
    else {
        top--;
        cout << "Eliminando " << pila[top]->informacion.codigoID << " de la pila..." << endl;
    }
}
