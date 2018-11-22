#include "MainWindow.h"
#include <QApplication>
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* reinas *juego = new reinas();
    bool respuesta = false;
    int reina = 1;
    //juego->mostrarList();
    juego->ponerReina(reina,respuesta);
    //juego->mostrarList();
    int* listaReinas = juego->getReinasList();
    std::cout<<listaReinas[2]<<std::endl;*/
    MainWindow w;
    w.show();

    return a.exec();
}
