#ifndef REINAS_H
#define REINAS_H
#include <QLabel>
#include <QList>
class reinas
{
public:
    QList<QLabel>Labels;
    reinas();
    bool valido(int i);
    void ponerReina(int i, bool& solucion);

};

#endif // REINAS_H
