#ifndef COLAS_H
#define COLAS_H
#include "Paquetes.h"

class Colas{
    public:
        Colas();
        virtual ~Colas();
        void Enqueue(Paquete*);
        void Print(Paquete*);
        void PrintEnviado(Paquete*);
        Paquete* Dequeue(Paquete*);
        Paquete* head;
        Paquete* rear;
        int contCola;

    protected:

    private:
};

#endif // COLAS_H
