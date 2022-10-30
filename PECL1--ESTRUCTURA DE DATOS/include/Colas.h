#ifndef COLAS_H
#define COLAS_H
#include "Paquetes.h"

class Colas{
    public:
        Colas();
        virtual ~Colas();
        void Enqueue(Paquete*);
        void Print(Paquete*);
        Paquete* Dequeue(Paquete*);
        Paquete* head;
        Paquete* rear;

    protected:
    private:
};

#endif // COLAS_H
