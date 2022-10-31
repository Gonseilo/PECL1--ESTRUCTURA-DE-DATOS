#ifndef PILAS_H
#define PILAS_H
#include "Paquetes.h"
#define N3 5 //Valor que indica el tamaño máximo que podrá tener la pila(furgoneta)

class Pilas{
    public:
        Pilas(); //ctor
        int top; //Declaración de la variable que indica la parte superior de la pila
        void push(Paquete*, Paquete*[]); //Declaración de la función push usada para insertar punteros a paquetes en una pila compuesta de estos
        void pop(Paquete*[]); //Declaración de la función pop usada para eliminar el último valor añadido a una pila compuesta de punteros a paquetes
        void printPila(Paquete*[]); //Declaración de la función print usada para imprimir todos los valores de una pila en forma de tabla
        virtual ~Pilas(); //dtor

    protected:
    private:
};

#endif // PILAS_H
