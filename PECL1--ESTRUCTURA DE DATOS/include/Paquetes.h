#ifndef PAQUETES_H
#define PAQUETES_H
#define N1 100
#define N2 10

struct CoordenadasGPS {
    char* latitud;
    char* longitud;
};

struct Etiqueta{
    char* codigoID;
    struct CoordenadasGPS coordenadas;
    char* DNI;
};

struct Paquete{
   struct Etiqueta informacion;
   Paquete *siguiente;
};

class Paquetes{
    public:
        Paquetes();
        virtual ~Paquetes();
        int counter;
        char* GenerarID();
        char* GenerarLatitud();
        char* GenerarLongitud();
        char* GenerarDNI();
        void setCodigoID(char*);
        void setLatitud(char*);
        void setLongitud(char*);
        void setDNI(char*);
        char* getCodigoID();
        char* getLatitud();
        char* getLongitud();
        char* getDNI();

    protected:
    private:
        char* codigoID;
        char* latitud;
        char* longitud;
        char* DNI;
};
//


#endif // PAQUETES_H
