#include "Colas.h"
#include "Paquetes.h"
#include <iostream>

using std::cout; using std::endl;

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

void Colas::Print(Paquete *temp){
    int cont =1;
    temp = head;

    cout<<"Tu cola es :"<<endl;
    while(temp != nullptr){
        cout<<"Paquete "<<cont<<endl;
        cout<<temp->informacion.codigoID<<endl;
        cout<<temp->informacion.coordenadas.latitud<<endl;
        cout<<temp->informacion.coordenadas.longitud<<endl;
        cout<<temp->informacion.DNI<<endl;
        cont ++;
        temp = temp->siguiente;
    }
}

Paquete* Colas::Dequeue(Paquete *temp){
    temp = head;

    if (head != nullptr && head == rear){
        head = rear = nullptr;
    }
    else{
        head = temp->siguiente;
    }
    return temp;
}
