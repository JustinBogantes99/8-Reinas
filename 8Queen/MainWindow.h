#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QList<QLabel*>Labels;
    void setLabelsDeReinas(int tableroPos, bool reina);
    void cambiarImagenes(int tableroPos,bool reina);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
