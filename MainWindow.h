#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QList<QLabel>Labels;
    void setLabelsDeReinas(int tableroPos, bool reina);
    void cambiarImagenes(int tableroPos,bool reina);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_frame_customContextMenuRequested(const QPoint &pos);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
