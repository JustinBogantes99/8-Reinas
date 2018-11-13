#include "MainWindow.h"
#include <QLabel>
void  MainWindow::setLabelsDeReinas(int tableroPos, bool reina){
    QLabel *label = new QLabel(this);
    Labels.push_back(label);
    label->setGeometry(15+100*(tableroPos%8),15+100*(tableroPos/8),100,100);
    QPixmap pixmap;
    if(((tableroPos%8+tableroPos/8)%2==0)&& !reina){
         pixmap=QPixmap("Negro.png");
    } else if (((tableroPos%8+tableroPos/8)%2==0)&& reina){
         pixmap=QPixmap("NegroR.png");
    } else if (((tableroPos%8+tableroPos/8)%2!=0) && !reina){
         pixmap= QPixmap ("Blanco.png");
    } else {
         pixmap=QPixmap ("BlancoR.png");
    }
    label->setPixmap(pixmap);
    label->setMask(pixmap.mask());
}
void MainWindow::cambiarImagenes(int tableroPos,bool reina){
    QPixmap pixmap;
    if(((tableroPos%8+tableroPos/8)%2==0)  &&!reina){
        pixmap =QPixmap ("Negro.png");
    } else if (((tableroPos%8+tableroPos/8)%2==0)&& reina){
        pixmap=QPixmap("NegroR.png");
    } else if (((tableroPos%8+tableroPos/8)%2!=0) && !reina){
        pixmap= QPixmap ("Blanco.png");
    } else {
       pixmap=QPixmap ("BlancoR.png");
    }
    Labels.at(tableroPos)->setPixmap(pixmap);
    Labels.at(tableroPos)->setMask(pixmap.mask());
}
