#include "reinas.h"
#include <stdio.h>
#include <iostream>
#include <vector>
reinas::reinas()
{

}

bool reinas::valido(int i,int* reinasList)
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

bool reinas::solucionNoEncontrada(int* reinasList){
    int tam = soluciones->getTam();
    for(int i = 0; i<tam ; i++){
       vector<int> n = soluciones->operator[](i)->getDato();
       if(arraysIguales(n,reinasList))
           return false;
    }
    return true;
}

bool reinas::arraysIguales(vector<int> array1,int* array2){
    for(int e = 0; e < array1.size()-1; e++){
        if(array1[e] != array2[e])
            return false;
    }
    return true;
}

int* reinas::buscarSol(int i,int* reinasList){
    bool respuesta = false;
    ponerReina(i,respuesta,reinasList);
    vector<int> listaCopia;
    for(int i = 0; i<9;i++){
        listaCopia.push_back(reinasList[i]);
    }
    soluciones->insertarNodo(listaCopia);
    return reinasList;
}


void reinas::ponerReina(int i, bool& solucion,int* reinasList)
{
    int k;
    solucion = false;
    k = 0; // inicializa contador de movimientos
    do {
        k++;
        reinasList[i] = k; // coloca y anota reina i en fila k
        if (valido(i,reinasList) && solucionNoEncontrada(reinasList))
        {
            if (i < N)
            {
                ponerReina(i + 1, solucion,reinasList);
                // vuelta atrás
                if (!solucion )
                    reinasList[i] = 0;
            }
        else // todas las reinas colocadas
        solucion = true;
        }
    } while(!solucion && (k < 8));
}
using namespace std;
void reinas::mostrarList(int* reinasList)
{
    int tam = 8;
    for (int i=0;i<=tam;i++)
    {
        cout<<reinasList[i]<<endl;
    }
}

