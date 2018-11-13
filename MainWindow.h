#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class MainWindow
{
public:
    MainWindow();
    void setLabelsDeReinas(int tableroPos, bool reina);
    void cambiarImagenes(int tableroPos,bool reina);
};

#endif // MAINWINDOW_H
