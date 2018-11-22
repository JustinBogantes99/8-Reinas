#ifndef REINAS_H
#define REINAS_H
#include <QLabel>
#include <ListaDoble.cpp>

class reinas
{
public:
    reinas();
    bool valido(int i, int* reinasList);
    void ponerReina(int i, bool& solucion,int* reinasList);
    void mostrarList(int* reinasList);
    int* buscarSol(int i, int* reinasList);
    bool solucionNoEncontrada(int* reinasList);
    bool arraysIguales(vector<int> array1,int* array2);
     ListaDoble<vector<int>>* soluciones =  new ListaDoble<vector<int>>();
private:
    const int N = 8;



};

#endif // REINAS_H
