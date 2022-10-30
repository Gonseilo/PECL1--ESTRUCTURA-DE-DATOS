#include <iostream>
#include <iomanip>
#include "Colas.h"
#include "Paquetes.h"

using std::cout; using std::endl; using std::setw;

Colas::Colas(){
    //ctor
}

Colas::~Colas(){
    //dtor
}

int contCola;
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

void Colas::Print(Paquete* temp){
    temp = head;

    cout << "||==================================================================||" << endl;
    cout << "|| Número del paquete | Código ID |" << setw(16) << "Coordenadas" << setw(6) << "|" << setw(7) << "DNI" <<  setw(6) << "||" << endl;
    cout << "||--------------------|-----------|---------------------|-----------||" << endl;
    while(temp != nullptr){
        contCola ++;
        cout << "||" << setw(11) << contCola << setw(10) << "|" << setw(9) << temp->informacion.codigoID << setw(3) << "|" << setw(9) << temp->informacion.coordenadas.latitud << setw(11) << temp->informacion.coordenadas.longitud << setw(2) << "|" << setw(10) << temp->informacion.DNI << setw(3) << "||" << endl;
        temp = temp->siguiente;
    }
    cout << "||==================================================================||\n\n" << endl;
}

void Colas::PrintEnviado(Paquete* temp){
    temp = head;

    cout << "||==================================================================||" << endl;
    cout << "|| Estado del paquete | Código ID |" << setw(16) << "Coordenadas" << setw(6) << "|" << setw(7) << "DNI" <<  setw(6) << "||" << endl;
    cout << "||--------------------|-----------|---------------------|-----------||" << endl;
    while(temp != nullptr){
        cout << "||" << setw(14) << "Enviado" << setw(7) << "|" << setw(9) << temp->informacion.codigoID << setw(3) << "|" << setw(9) << temp->informacion.coordenadas.latitud << setw(11) << temp->informacion.coordenadas.longitud << setw(2) << "|" << setw(10) << temp->informacion.DNI << setw(3) << "||" << endl;
        temp = temp->siguiente;
    }
    cout << "||==================================================================||\n\n" << endl;
}

Paquete* Colas::Dequeue(Paquete* temp){
    temp = head;

    if (head != nullptr && head == rear){
        head = rear = nullptr;
    }
    else{
        head = temp->siguiente;
    }
    return temp;
}

int Colas::recorrerCola(Paquete* temp){
    int cont = 0;
    temp = head;

    while(temp != nullptr){
        cont++;
        temp = temp->siguiente;
    }
    return cont;
}
//

