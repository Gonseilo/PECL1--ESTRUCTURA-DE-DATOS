#ifndef PAQUETES_H
#define PAQUETES_H
#define N1 100
#define N2 10

struct CoordenadasGPS { //Estructura que almacena los atributos latitud y coordenadas de cada paquete, que son de tipo puntero a char.
    char* latitud;
    char* longitud;
};

struct Etiqueta{ //Estructura que almacena los atributps codigoID,DNI, y una estructura de tipo coordenadasGPS.
    char* codigoID;
    struct CoordenadasGPS coordenadas;
    char* DNI;
};

struct Paquete{ //Estructura principal anidada que almacena una estructura tipo informaci�n y un puntero del paquete que apuntar� a otro paquete en las colas.
   struct Etiqueta informacion;
   Paquete *siguiente;
};

class Paquetes{
    public:
        Paquetes(); //Constrcutor.
        virtual ~Paquetes(); //Destructor.
        int cont; //Contador para los codigosID.
        char* GenerarID(); //Definici�n de funci�n que genera los codigosID de cada paquete de forma aleatoria.
        char* GenerarLatitud(); //Definici�n de funci�n que genera las latitudes de cada paquete de forma aleatoria.
        char* GenerarLongitud(); //Definici�n de funci�n que genera las longitudes de cada paquete de forma aleatoria.
        char* GenerarDNI(); //Definici�n de funci�n  que genera los DNIs de cada paquete de forma aleatoria.

        //Definici�n de funciones que establecen y retornan los valores de de la informaci�n de cada paquete.
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
        //Variables de la informaci�n de cada paquete en privado
        char* codigoID;
        char* latitud;
        char* longitud;
        char* DNI;
};
//


#endif // PAQUETES_H
