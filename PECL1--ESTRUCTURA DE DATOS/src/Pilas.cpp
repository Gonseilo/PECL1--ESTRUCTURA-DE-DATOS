#include <iostream>
#include <iomanip>
#include "Pilas.h"

using std::cout; using std::endl; using std::setw;

Pilas::Pilas(){
    //ctor
}

Pilas::~Pilas(){
    //dtor
}

int top = 0; //Declaramos una variable top que nos va a marcar la cima de la pila

void Pilas::push(Paquete* dato, Paquete* pila[]) { //Función push para insertar un valor(dato) a una pila(pila[]) de punteros a paquetes
    if (top == N3){ //Si la pila ha llegado a su límite, el cual nos es dado por N3 entonces no podemos insertar más valores
    }
    else { //Si en la pila todavía hay espacio para más valores:
        pila[top++] = dato; //se añade el dato a la pila y se sube el top un puesto para que el próximo valor no sobreescriba este
    }
}

void Pilas::pop(Paquete* pila[]) { //Función pop para sacar el último dato que se introdujo en la pila compuesta de punteros a paquetes
    if (top == 0){ //Si la pila está vacía no podemos sacar ningún dato
    }
    else { //Si en la pila hay algún valor:
        top--; //Bajamos el top para omitir el último valor que se introdujo en la pila
    }

}

void Pilas::print(Paquete* pila[]) { //Función print para imprimir todos los valores de la pila compuesta de punteros a paquetes en forma de tabla
    cout << "||==================================================================||" << endl; //Parte superior de la tabla
    cout << "|| Estado del paquete | Código ID |" << setw(16) << "Coordenadas" << setw(6) << "|" << setw(7) << "DNI" <<  setw(6) << "||" << endl; //Cabecera con los nombres de los valores de la tabla
    cout << "||--------------------|-----------|---------------------|-----------||" << endl; //Línea divisoria entre la cabecera y los valores
    for (int i = 0; i < top; i++) { //Por cada valor en la pila:
        cout << "||" << setw(16) << "Esperando..." << setw(5) << "|" << setw(9) << pila[i]->informacion.codigoID << setw(3) << "|" << setw(9) << pila[i]->informacion.coordenadas.latitud << setw(11) << pila[i]->informacion.coordenadas.longitud << setw(2) << "|" << setw(10) << pila[i]->informacion.DNI << setw(3) << "||" << endl; //Imprimimos los valores de la pila en forma de tabla
    }
    cout << "||==================================================================||" << endl; //Parte inferior de la tabla
}
