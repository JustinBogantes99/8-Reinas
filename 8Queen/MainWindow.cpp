#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <stdio.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int n=0;n<64;n++)
    {
        setLabelsDeReinas(n,0);
    }
    connect(ui->generarSolucionButton,SIGNAL(released()), this, SLOT (generarSolucion()));

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
    label->setGeometry(15+90*(tableroPos/8),15+90*(tableroPos%8),90,90);
    QPixmap pixmap;
    //En esta parte tableroPos es el lugar donde se encuentra el espacio a verificar
    //si reina es verdadero entonces el crea dependiendo de donde sea que este un espacio
    //blanco con la reina o negro dependiendo de la posicion donde se encuentre
    if(((tableroPos%8+tableroPos/8)%2==0)&& !reina){
         pixmap=QPixmap(":/resources/images/negro.jpg");
    } else if (((tableroPos%8+tableroPos/8)%2==0)&& reina){
         pixmap=QPixmap(":/resources/images/blackQueen.png");
    } else if (((tableroPos%8+tableroPos/8)%2!=0) && !reina){
         pixmap= QPixmap (":/resources/images/blanco.jpg");
    } else {
         pixmap=QPixmap (":/resources/images/whiteQueen.png");
    }
    label->setPixmap(pixmap);
    label->setMask(pixmap.mask());

}
void MainWindow::cambiarImagenes(int tableroPos,bool reina){
    QPixmap pixmap;
    if(((tableroPos%8+tableroPos/8)%2==0)  &&!reina){
        pixmap =QPixmap (":/resources/images/negro.jpg");
    } else if (((tableroPos%8+tableroPos/8)%2==0)&& reina){
        pixmap=QPixmap(":/resources/images/blackQueen.png");
    } else if (((tableroPos%8+tableroPos/8)%2!=0) && !reina){
        pixmap= QPixmap (":/resources/images/blanco.jpg");
    } else {
       pixmap=QPixmap (":/resources/images/whiteQueen.png");
    }
    Labels.at(tableroPos)->setPixmap(pixmap);
    Labels.at(tableroPos)->setMask(pixmap.mask());

}

void MainWindow::generarSolucion(){
    int reinaList[9];
    int* listaReinas = juego->buscarSol(reina,reinaList);
    for(int n=0;n<64;n++)
    {
        cambiarImagenes(n,0);
    }
    QString solucion = "[";
    for(int n=1;n<9;n++)
    {
        solucion = solucion + QString::number(listaReinas[n]);
        int pos = listaReinas[n]-1 + (n-1)*8;
        std::cout<<pos<<std::endl;
        cambiarImagenes(pos,1);
    }
    solucion = solucion + "]" + "\n";
    ui->soluciones->append(solucion);


}
