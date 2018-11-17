#include "MainWindow.h"
#include "reinas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    reinas *juego = new reinas();
    bool respuesta = false;
    int reina = 1;
    //juego->mostrarList();
    juego->ponerReina(reina,respuesta);
    juego->mostrarList();
    for(int n=0;n<64;n++)
    {
        //setLabelsDeReinas(n,0);
    }
    MainWindow w;
    w.show();

    return a.exec();
}
