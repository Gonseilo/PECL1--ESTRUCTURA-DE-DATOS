#ifndef PILAS_H
#define PILAS_H
#include "Paquetes.h"
#define N3 5 //Valor que indica el tama�o m�ximo que podr� tener la pila(furgoneta)

class Pilas{
    public:
        Pilas(); //ctor
        int top; //Declaraci�n de la variable que indica la parte superior de la pila
        void push(Paquete*, Paquete*[]); //Declaraci�n de la funci�n push usada para insertar punteros a paquetes en una pila compuesta de estos
        void pop(Paquete*[]); //Declaraci�n de la funci�n pop usada para eliminar el �ltimo valor a�adido a una pila compuesta de punteros a paquetes
        void printPila(Paquete*[]); //Declaraci�n de la funci�n print usada para imprimir todos los valores de una pila en forma de tabla
        virtual ~Pilas(); //dtor

    protected:
    private:
};

#endif // PILAS_H
