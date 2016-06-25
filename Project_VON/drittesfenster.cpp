#include "drittesfenster.h"


drittesFenster::drittesFenster(QWidget *fenster, QWidget *parent){
    m_fenster = fenster;
    eins = new QPushButton();
    zwei = new QPushButton();
    drei = new QPushButton();
    vier = new QPushButton();
    fuenf = new QPushButton();
    bank = new Datenbank;
}

drittesFenster::~drittesFenster(){
    delete (eins);
    delete (zwei);
    delete (drei);
    delete (vier);
    delete (fuenf);
    delete (beenden);
    delete (bank);
}

void drittesFenster::erzeugeDrittesFenster(){


    eins->setText("1");
    eins->setStyleSheet("background-color:red ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(eins, &QPushButton::clicked,this, ...);

    zwei->setText("2");
    zwei->setStyleSheet("background-color:orange ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(zwei, &QPushButton::clicked,this, ...);

    drei->setText("3");
    drei->setStyleSheet("background-color:yellow ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(drei, &QPushButton::clicked,this, ...);

    vier->setText("4");
    vier->setStyleSheet("background-color:blue ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(vier, &QPushButton::clicked,this, ...);

    fuenf->setText("5");
    fuenf->setStyleSheet("background-color:green ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(fuenf, &QPushButton::clicked,this, ...);

    beenden->setText("beenden");
    beenden->setStyleSheet("background-color:black ; border: none; margin: 0px;padding: 0px; width: 100px; height: 30px;");
    //QObject::connect(beenden, &QPushButton::clicked,this, ...);   -> Niels fragen, wie man zurück zum zweiten Bildschirm kommt


    layout->addWidget(eins,4,6,4,6);
    layout->addWidget(zwei,5,6,4,6);
    layout->addWidget(drei,6,6,4,6);
    layout->addWidget(vier,7,6,4,6);
    layout->addWidget(fuenf,8,6,4,6);
    layout->addWidget(beenden,10,6,4,6);


}
/*
void bildInGrossDarstellen(){

    QLabel *bild = new QLabel();
    QImage image;
    bild->setPixmap(QPixmap::fromImage(*(qimages->at(y))));
    bild->setMinimumSize(image.width(), image.height());
    layout->addWidget(bild,0,2,2,6);
}

*/
