#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 *Este netidi me crea un Qlist con elementos tipo Qlabel
 *el Qpixmap se supone que cambia la imagen que posee el label
 * cada if
/*/
void  MainWindow::setLabelsDeReinas(int tableroPos, bool reina){
    QLabel *label = new QLabel(this);
    Labels.push_back(label);
    label->setGeometry(15+100*(tableroPos%8),15+100*(tableroPos/8),100,100);
    QPixmap pixmap;
    //En esta parte tableroPos es el lugar donde se encuentra el espacio a verificar
    //si reina es verdadero entonces el crea dependiendo de donde sea que este un espacio
    //blanco con la reina o negro dependiendo de la posicion donde se encuentre
    if(((tableroPos%8+tableroPos/8)%2==0)&& !reina){
         pixmap=QPixmap("negro.jpg");
    } else if (((tableroPos%8+tableroPos/8)%2==0)&& reina){
         pixmap=QPixmap("negroR.jpg");
    } else if (((tableroPos%8+tableroPos/8)%2!=0) && !reina){
         pixmap= QPixmap ("blanco.jpg");
    } else {
         pixmap=QPixmap ("blancoR.jpg");
    }
    label->setPixmap(pixmap);
    label->setMask(pixmap.mask());
}
void MainWindow::cambiarImagenes(int tableroPos,bool reina){
    QPixmap pixmap;
    if(((tableroPos%8+tableroPos/8)%2==0)  &&!reina){
        pixmap =QPixmap ("negro.jpg");
    } else if (((tableroPos%8+tableroPos/8)%2==0)&& reina){
        pixmap=QPixmap("negroR.jpg");
    } else if (((tableroPos%8+tableroPos/8)%2!=0) && !reina){
        pixmap= QPixmap ("blanco.jpg");
    } else {
       pixmap=QPixmap ("blancoR.jpg");
    }
    Labels.at(tableroPos)->setPixmap(pixmap);
    Labels.at(tableroPos)->setMask(pixmap.mask());

}
