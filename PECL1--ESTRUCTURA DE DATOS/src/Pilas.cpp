#include "Pilas.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Pilas::Pilas(){
    //ctor
}

Pilas::~Pilas(){
    //dtor
}

int top = 0;

void Pilas::push(int dato, int pila[]) {
    if (top == N3){
        cout << "La pila est� llena" << endl;
    }
    else {
        pila[top++] = dato;
        cout << "A�adiendo " << dato << " a la pila..." << endl;
    }
}

void Pilas::pop(int pila[]) {
    if (top == 0){
        cout << "La pila est� vac�a";
    }
    else {
        top--;
        cout << "Eliminando " << pila[top] << " de la pila..." << endl;
    }
}

void printPila (int pila[]){
    while (top != 0){
        cout << pila[top] << endl;
        top--;
    }
}
