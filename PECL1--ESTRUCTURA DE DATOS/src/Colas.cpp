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

Paquete *head = nullptr;
Paquete *rear = nullptr;

void Colas::Enqueue(Paquete *temp){
    temp->siguiente = nullptr;

    if (head == nullptr && rear == nullptr){
        head = rear = temp;
    }
    else{
        rear->siguiente = temp;
        rear = temp;
    }
}

void Colas::Print(Paquete *tempPrint){
    int cont =1;
    tempPrint = head;

    cout<<"Tu cola es :"<<endl;
    while(tempPrint != nullptr){
        cout<<"Paquete "<<cont<<endl;
        cout<<tempPrint->informacion.codigoID<<endl;
        cout<<tempPrint->informacion.coordenadas.latitud<<endl;
        cout<<tempPrint->informacion.coordenadas.longitud<<endl;
        cout<<tempPrint->informacion.DNI<<endl;
        cont ++;
        tempPrint = tempPrint->siguiente;
    }
}

Paquete* Colas::Dequeue(Paquete *temp){
    temp = head;

    if (head != nullptr){
        if (head == rear){
            head = rear = nullptr;
        }
        else{
            head = temp->siguiente;
        }
    }

    return temp;
}
