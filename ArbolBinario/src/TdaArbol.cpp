#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

struct arbol
	{
	int dato;
	struct arbol *izq;
	struct arbol *der;
	}*raiz;

enum{ FALSO=0, VERDADERO };

