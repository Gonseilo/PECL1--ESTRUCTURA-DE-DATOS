#ifndef PILAS_H
#define PILAS_H
#define N3 5
#include "Paquetes.h"

class Pilas{
    public:
        Pilas();
        int top;
        void push(Paquete*, Paquete*[]);
        void pop(Paquete*[]);
        virtual ~Pilas();

    protected:

    private:
};

#endif // PILAS_H
