#ifndef MUELLES_H
#define MUELLES_H

class Muelles{
    public:
        Muelles(); //ctor
        virtual ~Muelles(); //dtor
        char* AsignarMuelle(char*, char*); //Declaramos la funci�n AsignarMuelle que nos indicar� a que muelle tiene que ir el paquete en base a sus coordenadas

    protected:
    private:
};

#endif // MUELLES_H
