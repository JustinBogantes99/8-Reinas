#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include <QMainWindow>
#include <reinas.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void generarSolucion();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    QList<QLabel*>Labels;
    void setLabelsDeReinas(int tableroPos, bool reina);
    void cambiarImagenes(int tableroPos,bool reina);
    ~MainWindow();
    reinas *juego = new reinas();
    int reina = 0;
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
