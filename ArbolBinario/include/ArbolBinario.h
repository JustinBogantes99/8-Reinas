#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "TdaArbol.cpp"

class ArbolBinario
{
    public:
        ArbolBinario();
        virtual ~ArbolBinario();
        void inicializar( void );
        int vacio( struct arbol *hoja );
        int eshoja( struct arbol *hoja );
        struct arbol *insertar( struct arbol *raiz, struct arbol *hoja, int num );
        int busqueda( struct arbol *hoja, int num );
        int alturax( struct arbol *hoja, int num );
        int alturafull( struct arbol *hoja, int *altura );
        void auxaltura( struct arbol *hoja, int *altura, int cont );
        int nodos( struct arbol *hoja );
        void auxnodos( struct arbol *hoja, int *cont );
        struct arbol *borrarx( struct arbol *hoja, int num );
        struct arbol *podar( struct arbol *hoja );
        void preorden( struct arbol *hoja );
        void inorden( struct arbol *hoja );
        void posorden( struct arbol *hoja );
        void menu_recorridos( void );
        void menu_busquedas( void );
        void menu_alturas( void );
        void menu_nodos( void );
        void menu_podar( void );
};

#endif // ARBOLBINARIO_H
