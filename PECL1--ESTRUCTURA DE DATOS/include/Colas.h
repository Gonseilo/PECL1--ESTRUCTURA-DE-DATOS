#ifndef COLAS_H
#define COLAS_H
#include "Paquetes.h"

class Colas{
    public:
        Colas();
        virtual ~Colas();
        void Enqueue(Paquete*);
        void Print(Paquete*);
        Paquete* head1;
        Paquete* rear1;

    protected:

    private:
};

#endif // COLAS_H

