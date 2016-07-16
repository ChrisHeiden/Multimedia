#include "drittesfenster.h"
#include <QScreen>
#include <iostream>
#include <QApplication>

using namespace std;


drittesFenster::drittesFenster(QWidget *fenster, Datenbank *bank, QWidget *parent) : QWidget(parent){
    m_fenster = fenster;
    m_bank = bank;
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    view->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    drehen  = new QPushButton;

    links = new QPushButton;
    rechts = new QPushButton;

    eins = new QPushButton();
    zwei = new QPushButton();
    drei = new QPushButton();

    vier = new QPushButton();
    fuenf = new QPushButton();
    beenden = new QPushButton();

    buttons = new QVBoxLayout();
    fuellung1 = new QVBoxLayout();
    fuellung2 = new QVBoxLayout();

    buttons2 = new QHBoxLayout();
    fuellung3 = new QHBoxLayout();
    fuellung4 = new QHBoxLayout();

    layout = new QGridLayout();
}

drittesFenster::~drittesFenster(){
    delete (eins);
    delete (zwei);
    delete (drei);
    delete (vier);
    delete (fuenf);
    delete (beenden);

    delete (m_fenster);
    delete (layout);
    delete (buttons);

    delete (fuellung1);
    delete (fuellung2);
    delete (fuellung3);
    delete (fuellung4);

    delete (buttons2);
    delete (fuellung4);
    delete (buttons2);
    delete (fuellung4);
    delete (drehen);
}

void drittesFenster::erzeugeDrittesFenster(string pfad){

    m_pfad = pfad;
    QString qstr = QString::fromStdString(pfad);
    QImage image(qstr);

    eins->setStyleSheet("background-color:tomato; color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    eins->setText("1");
    eins->setFixedSize(80,80);

    zwei->setStyleSheet("background-color:orange; color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    zwei->setText("2");
    zwei->setFixedSize(80,80);

    drei->setStyleSheet("background-color: rgb(218,165,32); color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    drei->setText("3");
    drei->setFixedSize(80,80);

    vier->setStyleSheet("background-color: rgb(173,255,47); color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    vier->setText("4");
    vier->setFixedSize(80,80);

    fuenf->setStyleSheet("background-color:rgb(144,238,144); color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    fuenf->setText("5");
    fuenf->setFixedSize(80,80);

    beenden->setStyleSheet("background-color:gray; color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    beenden->setText("beende");
    beenden->setFixedSize(80,50);

    drehen->setStyleSheet("background-color:gray; color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    drehen->setText("drehen");
    drehen->setFixedSize(80,50);

    links->setStyleSheet("background-color:gray; color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    links->setText("Links");
    links->setFixedSize(80,50);

    rechts->setStyleSheet("background-color:gray; color: white; border: none; margin: 0px;padding: 0px; font-weight: bold; width: 10px; height: 25px;");
    rechts->setText("Rechts");
    rechts->setFixedSize(80,50);

    QScreen *screen = QApplication::screens().at(0);
    QSize size = screen->size();

    if(size.width() == 1280 && size.height() == 720){
        if(image.height() >= image.width()){
            image = image.scaledToHeight(620, Qt::FastTransformation);
            layout->addWidget(view,0,8,3,6);
            fuellung1->addSpacing(500);
            fuellung2->addSpacing(320);

            buttons->addLayout(fuellung1);
            buttons->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons->addWidget(zwei);
            QObject::connect(zwei, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons->addWidget(drei);
            QObject::connect(drei, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons->addWidget(vier);
            QObject::connect(vier, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons->addWidget(fuenf);
            QObject::connect(fuenf, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons->addLayout(fuellung2);
            buttons->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);


            layout->addLayout(buttons,0,0);
        }
        if(image.height() < image.width()){
            image = image.scaledToWidth(530, Qt::FastTransformation);
            layout->addWidget(view,0,8,1,6);
            fuellung3->addSpacing(700);
            fuellung4->addSpacing(700);

            buttons2->addLayout(fuellung3);
            buttons2->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons2->addWidget(zwei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons2->addWidget(drei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons2->addWidget(vier);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons2->addWidget(fuenf);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons2->addLayout(fuellung4);
            buttons2->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);
            layout->addLayout(buttons2,1,8,1,6);
        }
    }
    else if(size.width() == 1920 && size.height() == 1080){
        if(image.height() >= image.width()){
            image = image.scaledToHeight(1100, Qt::FastTransformation);
            layout->addWidget(view,0,8,3,6);
            fuellung1->addSpacing(500);
            fuellung2->addSpacing(320);

            buttons->addLayout(fuellung1);
            buttons->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons->addWidget(zwei);
            QObject::connect(zwei, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons->addWidget(drei);
            QObject::connect(drei, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons->addWidget(vier);
            QObject::connect(vier, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons->addWidget(fuenf);
            QObject::connect(fuenf, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons->addLayout(fuellung2);
            buttons->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);

            layout->addLayout(buttons,0,0);
        }
        if(image.height() < image.width()){
            image = image.scaledToWidth(1000, Qt::FastTransformation);
            layout->addWidget(view,0,8,1,6);
            fuellung3->addSpacing(700);
            fuellung4->addSpacing(700);

            buttons2->addLayout(fuellung3);
            buttons2->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons2->addWidget(zwei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons2->addWidget(drei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons2->addWidget(vier);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons2->addWidget(fuenf);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons2->addLayout(fuellung4);
            buttons2->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);
            layout->addLayout(buttons2,1,8,1,6);
        }
    }

    else if(size.width() == 1680 && size.height() == 1050){     //Bildauflösung des großen Monitors auf dem ich programmiere
        if(image.height() >= image.width()){
            image = image.scaledToHeight(950, Qt::FastTransformation);
            layout->addWidget(view,0,8,3,6);
            fuellung1->addSpacing(500);
            fuellung2->addSpacing(320);

            buttons->addLayout(fuellung1);
            buttons->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons->addWidget(zwei);
            QObject::connect(zwei, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons->addWidget(drei);
            QObject::connect(drei, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons->addWidget(vier);
            QObject::connect(vier, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons->addWidget(fuenf);
            QObject::connect(fuenf, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons->addLayout(fuellung2);
            buttons->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);

            layout->addLayout(buttons,0,0);
        }
        if(image.height() < image.width()){
            image = image.scaledToHeight(870, Qt::FastTransformation);
            layout->addWidget(view,0,8,1,6);
            fuellung3->addSpacing(700);
            fuellung4->addSpacing(700);

            buttons2->addLayout(fuellung3);
            buttons2->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons2->addWidget(zwei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons2->addWidget(drei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons2->addWidget(vier);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons2->addWidget(fuenf);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons2->addLayout(fuellung4);
            buttons2->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);
            layout->addLayout(buttons2,1,8,1,6);
        }
    }
    else{                                                       //Bildauflösung des Surface
        if(image.height() >= image.width()){
            image = image.scaledToHeight(1300, Qt::FastTransformation);
            layout->addWidget(view,0,8,3,6);
            fuellung1->addSpacing(500);
            fuellung2->addSpacing(320);

            buttons->addLayout(fuellung1);
            buttons->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons->addWidget(zwei);
            QObject::connect(zwei, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons->addWidget(drei);
            QObject::connect(drei, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons->addWidget(vier);
            QObject::connect(vier, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons->addWidget(fuenf);
            QObject::connect(fuenf, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons->addLayout(fuellung2);
            buttons->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);
            buttons->addWidget(links);
            QObject::connect(links, &QPushButton::clicked,this, &drittesFenster::vorherigesBild);
            buttons->addWidget(rechts);
            QObject::connect(rechts, &QPushButton::clicked,this, &drittesFenster::naechstesBild);


            layout->addLayout(buttons,0,0);
        }
        if(image.height() < image.width()){
            image = image.scaledToHeight(1200, Qt::FastTransformation);
            layout->addWidget(view,0,8,1,6);
            fuellung3->addSpacing(700);
            fuellung4->addSpacing(700);

            buttons2->addLayout(fuellung3);
            buttons2->addWidget(eins);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
            buttons2->addWidget(zwei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
            buttons2->addWidget(drei);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
            buttons2->addWidget(vier);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
            buttons2->addWidget(fuenf);
            QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
            buttons2->addLayout(fuellung4);
            buttons2->addWidget(beenden);
            QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
            buttons->addWidget(drehen);
            QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);
            buttons->addWidget(links);
            QObject::connect(links, &QPushButton::clicked,this, &drittesFenster::vorherigesBild);
            buttons->addWidget(rechts);
            QObject::connect(rechts, &QPushButton::clicked,this, &drittesFenster::naechstesBild);


            layout->addLayout(buttons2,1,8,1,6);
        }
    }
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);

    this->setLayout(layout);
    this->showMaximized();
}

void drittesFenster::bewertenEins(){
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,1);
}
void drittesFenster::bewertenZwei(){
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,2);
}

void drittesFenster::bewertenDrei(){
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,3);
}

void drittesFenster::bewertenVier(){
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,4);
}

void drittesFenster::bewertenFuenf(){
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,5);
}

void drittesFenster::bildDrehen(){
    view->rotate(90);
    int id = m_bank->getID(m_pfad);
    cout << id << endl;
    m_bank->setNeueBildausrichtung(id);
    m_bank->getBildausrichtung(id);
}

void drittesFenster::naechstesBild(){
    int index;
    vector<string> *bilder = new vector<string>;
    (*bilder) = m_bank->getAlleBilder_dargestelltTrue();


    for(unsigned int i = 0 ; i < bilder->size(); i++){
        try{
            if(bilder->at(i) == m_pfad){
                index = i;
            }
            else{
                continue;
            }
        }catch(...){
            index = 0;
        }

    }
    erzeugeDrittesFenster(bilder->at(index + 1));
}

void drittesFenster::vorherigesBild(){
    int index;
    vector<string> *bilder = new vector<string>;
    (*bilder) = m_bank->getAlleBilder_dargestelltTrue();
    cout << "Size: " << bilder->size() << endl;


    try{
        for(unsigned int i = 0 ;i < bilder->size(); i++){
            if(bilder->at(i) == m_pfad){
                index = i;
                cout << "Index: " << index << endl;
            }
            else{
                continue;
            }
        }
        erzeugeDrittesFenster(bilder->at(index - 1));
        cout << "Pfad: " << bilder->at(index -1)<< endl;
    }catch(...){
        index = bilder->size();
        erzeugeDrittesFenster(bilder->at(index));
        cout << "Pfad: " << bilder->at(index -1)<< endl;
    }
}
