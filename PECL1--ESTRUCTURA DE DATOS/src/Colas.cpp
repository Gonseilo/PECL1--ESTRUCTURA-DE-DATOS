#include "Colas.h"
#include "Paquetes.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Colas::Colas(){
    //ctor
}

Colas::~Colas(){
    //dtor
}

Paquete *head1 = nullptr;
Paquete *rear1 = nullptr;

void Colas::Enqueue(Paquete *temp){
    temp->siguiente = nullptr;

    if (head1 == nullptr && rear1 == nullptr){
        head1 = rear1 = temp;
    }
    else{
        rear1->siguiente = temp;
        rear1 = temp;
    }
}

void Colas::Print(Paquete *tempPrint){
    int cont =1;
    tempPrint = head1;

    cout<<"Tu cola es :"<<endl;
    while(tempPrint != nullptr){
        cout<<" Paquete "<<cont<<endl;
        cout<<tempPrint->informacion.codigoID<<endl;
        cout<<tempPrint->informacion.coordenadas.latitud<<endl;
        cout<<tempPrint->informacion.coordenadas.longitud<<endl;
        cout<<tempPrint->informacion.DNI<<endl;
        cont ++;
        tempPrint = tempPrint->siguiente;
    }
}
