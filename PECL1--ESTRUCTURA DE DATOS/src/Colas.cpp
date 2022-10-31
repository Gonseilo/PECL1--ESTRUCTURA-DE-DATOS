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
//Inicializamos los atributos globales "head" y "rear" apuntando a null, es decir, la cola esta vacía.
Paquete *head = nullptr;
Paquete *rear = nullptr;

void Colas::Enqueue(Paquete *temp){ //Pasamos por parámetro un puntero temporal que apunte a una estructura paquete.
    temp->siguiente = nullptr; //De momento el puntero del paquete apuntara a null.

    if (head == nullptr && rear == nullptr){ //Si la cola esta vacía; este primer paquete que entra la cola se define como el "head" y el "rear".
        head = rear = temp;
    }
    else{ // Si la cola no esta vacía, es decir, hay al menos un paquete, el paquete se almacena al final de la cola y de define como el "rear".
        rear->siguiente = temp;
        rear = temp;
    }
}

void Colas::Print(Paquete* temp){ //Pasamos por parámetro un puntero temporal que apunte a una estructura paquete.
    temp = head;

    //Usamos la funcion setw() para crear espacios y hacer una tabla que almacene los datos del paquete.

    cout << "||==================================================================||" << endl;
    cout << "|| Número del paquete | Código ID |" << setw(16) << "Coordenadas" << setw(6) << "|" << setw(7) << "DNI" <<  setw(6) << "||" << endl;
    cout << "||--------------------|-----------|---------------------|-----------||" << endl;
    while(temp != nullptr){ //Mientras temp no llegue al final de la cola, se pega por pantalla la información del paquete que este apuntando en la cola.
        contCola ++; //En cada vuelta del bucle sumamos +1 al contador para almacenar que numero de paquete es el que se pega por pantalla.
        cout << "||" << setw(11) << contCola << setw(10) << "|" << setw(9) << temp->informacion.codigoID << setw(3) << "|" << setw(9) << temp->informacion.coordenadas.latitud << setw(11) << temp->informacion.coordenadas.longitud << setw(2) << "|" << setw(10) << temp->informacion.DNI << setw(3) << "||" << endl;
        temp = temp->siguiente; //En cada vuelta del bucle una vez ha pegado por pantalla información del paquete, avanza al siguiente en la cola.
    }
    cout << "||==================================================================||\n" << endl;
}

void Colas::PrintEnviado(Paquete* temp){ // Esta función tiene el mismo algoritmo
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

Paquete* Colas::Dequeue(Paquete* temp){ //Pasamos por parámetro un puntero temporal que apunte a una estructura paquete.
    //Recorremos la lista hasta que temp apunte al ultimo paquete de la cola
    temp = head;

    if (head != nullptr && head == rear){ // Si solo hay un paquete se vacia la cola
        head = rear = nullptr;
    }
    else{ //Si hay mas de un paquete head apunta al siguiente paquete del que queremos eliminar apuntado por temp
        head = temp->siguiente;
    }
    return temp;// retornamos el puntero que apunta al ultimo paquete de la cola que hemos eliminado
}

int Colas::recorrerCola(Paquete* temp){ // //Pasamos por parámetro un puntero temporal que apunte a una estructura paquete.
    int cont = 0;
    temp = head;

    while(temp != nullptr){//Recorremos la cola mientras temp no apunte a null y contamos cuantos paquetes hay sumando +1 al contador
        cont++;
        temp = temp->siguiente;
    }
    return cont; // Retornamos el contador
}
