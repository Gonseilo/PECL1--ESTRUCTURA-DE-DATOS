#ifndef COLAS_H
#define COLAS_H
#include "Paquetes.h"

class Colas{
    public:
        Colas(); //Constructor.
        virtual ~Colas(); //Destructor.
        void Enqueue(Paquete*); //Definici�n de m�todo que encola paquetes en una cola especifica.
        void Print(Paquete*); //Definici�n de m�todo que pega por pantalla una cola especifica con su numero de paquete,ID,coordenadas y DNI.
        void PrintEnviado(Paquete*); //Definici�n de m�todo que pega por pantalla una cola especifica indicando su estado de "enviado".
        int recorrerCola(Paquete*); //Definici�n de m�todo para recorrer mediante un puntero todos los paquetes de una cola especifica.
        Paquete* Dequeue(Paquete*); //Definici�n  de m�todo que elimina de la cola y guarda un paquete.
        Paquete* head; //Atributo "head" que almacena la cabeza de la cola que se desee.
        Paquete* rear; //Atributo "rear" que almacena el ultima entidad de la cola que se desee.
        int contCola; //Contador utilizado para establecer el numero de paquete en las colas c1(N1) y c2(N2)

    protected:

    private:
};

#endif // COLAS_H
