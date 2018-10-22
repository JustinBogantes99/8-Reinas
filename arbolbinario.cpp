#include "arbolbinario.h"
ArbolBinario::ArbolBinario()
{
    //ctor
}

ArbolBinario::~ArbolBinario()
{
    //dtor
}

void inicializar( void )
    {
    raiz= NULL;
    }

int vacio( struct arbol *hoja )
    {
    if( !hoja ) return VERDADERO;
    return FALSO;
    }

int eshoja( struct arbol *hoja )
    {
    if( hoja->izq==NULL && hoja->der==NULL )
        return VERDADERO;
    return FALSO;
   }

struct arbol *insertar( struct arbol *raiz, struct arbol *hoja, int num )
    {
    if( !hoja )
        {
        hoja= (struct arbol *) malloc( sizeof (struct arbol) );
        hoja->dato= num;
        hoja->izq= NULL;
        hoja->der= NULL;
        if( !raiz ) return hoja;
        else if( num<raiz->dato ) raiz->izq= hoja;
        else raiz->der= hoja;
        return hoja;
        }
    else if( num<hoja->dato )
        insertar( hoja, hoja->izq, num );
    else insertar( hoja, hoja->der, num );
    return raiz;
    }

int busqueda( struct arbol *hoja, int num )
    {
    while( hoja )
        {
        if( num==hoja->dato ) return VERDADERO;
        else
            {
            if( num<hoja->dato ) hoja= hoja->izq;
            else hoja= hoja->der;
            }
        }
    return FALSO;
    }

int alturax( struct arbol *hoja, int num )
    {
    int altura=1;

    while( hoja )
        {
        if( num==hoja->dato ) return altura;
        else
            {
            altura++;
            if( num<hoja->dato ) hoja= hoja->izq;
            else hoja= hoja->der;
            }
        }
    return FALSO;
    }

void auxaltura( struct arbol *hoja, int *altura, int cont )
    {
    if( !hoja ) return;

    auxaltura( hoja->izq, altura, cont+1 );
    auxaltura( hoja->der, altura, cont+1 );
    if( (eshoja( hoja ) && cont)>*altura ) *altura= cont;
    }

int alturafull( struct arbol *hoja, int *altura )
    {
    auxaltura( hoja, altura, 1 );
    return *altura;
    }


void auxnodos( struct arbol *hoja, int *cont )
    {
    if( !hoja ) return;

    (*cont)++;
    auxnodos( hoja->izq, cont );
    auxnodos( hoja->der, cont );
    }


int nodos( struct arbol *hoja )
    {
    int nodos=0;
    auxnodos( hoja, &nodos );
    return nodos;
    }


struct arbol *borrarx( struct arbol *hoja, int num )
    {
    if( hoja->dato==num )
        {
        struct arbol *p, *p2;

        if( vacio( hoja ) )
            {
            free( hoja );
            hoja= NULL;
            return hoja;
            }
        else if( hoja->izq==NULL )
            {
            p= hoja->der;
            free( hoja );
            return p;
            }
        else if( hoja->der==NULL )
            {
            p= hoja->izq;
            free( hoja );
            return p;
            }
        else
            {
            p= hoja->der;
            p2= hoja->der;
            while( p->izq ) p= p->izq;
            p->izq= hoja->izq;
            free( hoja );
            return p2;
         }
        }
    else if( num<hoja->dato )
        hoja->izq= borrarx( hoja->izq, num );
    else
        hoja->der= borrarx( hoja->der, num );
    return hoja;
    }

struct arbol *podar( struct arbol *hoja )
    {
    if( !hoja ) return hoja;

    podar( hoja->izq );
    podar( hoja->der );
    free( hoja );
    hoja= NULL;
   return hoja;
   }

/*Recorridos*/

void preorden( struct arbol *hoja )
    {
    if( !hoja ) return;

    printf( "%i ", hoja->dato );
    preorden( hoja->izq );
    preorden( hoja->der );
    }

void inorden( struct arbol *hoja )
    {
    if( !hoja ) return;

    inorden( hoja->izq );
    printf( "%i ", hoja->dato );
    inorden( hoja->der );
    }

void posorden( struct arbol *hoja )
    {
    if( !hoja ) return;

    posorden( hoja->izq );
    posorden( hoja->der );
    printf( "%i ", hoja->dato );
    }
