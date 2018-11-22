#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "nodo.h"

template<class T>
class ListaDoble
{
    public:
        Nodo<T>* primero;
        int tam;
    public:
        typedef T type;
        ListaDoble();
        ListaDoble(ListaDoble<T>  const &original);
        void insertarNodo (T Dato);
        void imprimirLista();
        int getTam();
        Nodo<T>* operator[](int const index);
};


#endif // ListaSimple_H
