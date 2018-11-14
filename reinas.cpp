#include "reinas.h"
const int N = 8;
const int n = (N+1);
int reinasList[n];
reinas::reinas()
{

}

bool reinas::valido(int i)
{
    // comprueba si la reina de la columna i es atacada por alguna
    // reina colocada anteriormente
    int r;
    bool v = true;
    for(r = 1; r <= i - 1; r++)
    {
        v = v && (reinasList[r]!= reinasList[i]); // no esté en la misma fila
        v = v && ((reinasList[i] - i) != (reinasList[r] - r)); // diagonal 1
        v = v && ((reinasList[i] + i) != (reinasList[r] + r)); // diagonal 2
    }
    return v;
}


void reinas::ponerReina(int i, bool& solucion)
{
    int k;
    solucion = false;
    k = 0; // inicializa contador de movimientos
    do {
        k++;
        reinasList[i] = k; // coloca y anota reina i en fila k
        if (valido(i))
        {
            if (i < N)
            {
                ponerReina(i + 1, solucion);
                // vuelta atrás
                if (!solucion)
                    reinasList[i] = 0;
            }
        else // todas las reinas colocadas
        solucion = true;
        }
    } while(!solucion && (k < 8));
}
