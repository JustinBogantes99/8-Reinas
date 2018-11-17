#ifndef REINAS_H
#define REINAS_H
#include <QLabel>
#include <QList>
class reinas
{
public:
    reinas();
    bool valido(int i);
    void ponerReina(int i, bool& solucion);
    void mostrarList();
private:
    const int N = 8;
    int reinasList[8];

};

#endif // REINAS_H
