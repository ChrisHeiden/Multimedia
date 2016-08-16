#include "drittesfenster.h"
#include <QScreen>
#include <iostream>
#include <QApplication>
#include <QWheelEvent>

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

    bilder =  new vector<string>;
    (*bilder) = m_bank->getAlleBilder_dargestelltTrue();

    layout = new QHBoxLayout;
    layout2 = new QVBoxLayout;

    buttons = new QVBoxLayout;
    buttons2 = new QHBoxLayout;

    fuellung1 = new QVBoxLayout;
    fuellung2 = new QVBoxLayout;
    fuellung3 = new QHBoxLayout;
    fuellung4 = new QHBoxLayout;

    gesten = new Gestensteuerung(buttons);

    interaktion();

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
    delete (layout2);
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
    delete (bilder);


}

void drittesFenster::erzeugeDrittesFenster(string pfad){
     m_pfad = pfad;

    QString qstr = QString::fromStdString(pfad);
    QImage image(qstr);

    buttonsStyle();

    screen = QApplication::screens().at(0);
    QSize size = screen->size();

    if(size.width() == 1280 && size.height() == 720){
        if(image.height() >= image.width()){
            image = image.scaledToHeight(620, Qt::FastTransformation);
            vertikal();
            layout->addLayout(buttons);
            layout->addWidget(view);

            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout);
        }
        if(image.height() < image.width()){
            image = image.scaledToWidth(530, Qt::FastTransformation);
            horizontal();
            layout2->addWidget(view);
            layout2->addLayout(buttons2);
            this->setLayout(layout2);
        }
    }
    else if(size.width() == 1920 && size.height() == 1080){
        if(image.height() >= image.width()){
            image = image.scaledToHeight(1100, Qt::FastTransformation);
            vertikal();
            layout->addLayout(buttons);
            layout->addWidget(view);

            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout2);
        }
        if(image.height() < image.width()){
            image = image.scaledToWidth(1000, Qt::FastTransformation);
            horizontal();
            layout2->addWidget(view);
            layout2->addLayout(buttons2);

            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout2);
        }
    }

    else if(size.width() == 1680 && size.height() == 1050){     //Bildauflösung des großen Monitors auf dem ich programmiere
        if(image.height() >= image.width()){
            image = image.scaledToHeight(950, Qt::FastTransformation);
            vertikal();
            layout->addLayout(buttons);
            layout->addWidget(view);
            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout);
        }
        if(image.height() < image.width()){
            image = image.scaledToHeight(870, Qt::FastTransformation);
            horizontal();
            layout2->addWidget(view);
            layout2->addLayout(buttons2);

            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout2);
        }
    }
    else{                                                       //Bildauflösung des Surface
        if(image.height() >= image.width()){
            image = image.scaledToHeight(1300, Qt::FastTransformation);
            vertikal();
            layout->addLayout(buttons);
            layout->addWidget(view);

            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout);
        }
        if(image.height() < image.width()){
            image = image.scaledToHeight(1200, Qt::FastTransformation);
            horizontal();
            layout2->addWidget(view);
            layout2->addLayout(buttons2);

            item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            scene->addItem(item);
            this->setLayout(layout2);
        }
    }
}

void drittesFenster::buttonsStyle(){
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
}

void drittesFenster::interaktion(){
    QObject::connect(eins, &QPushButton::clicked,this, &drittesFenster::bewertenEins);
    QObject::connect(zwei, &QPushButton::clicked,this, &drittesFenster::bewertenZwei);
    QObject::connect(drei, &QPushButton::clicked,this, &drittesFenster::bewertenDrei);
    QObject::connect(vier, &QPushButton::clicked,this, &drittesFenster::bewertenVier);
    QObject::connect(fuenf, &QPushButton::clicked,this, &drittesFenster::bewertenFuenf);
    QObject::connect(beenden, &QPushButton::clicked,this, &drittesFenster::showBildergalerie);
    QObject::connect(drehen, &QPushButton::clicked,this, &drittesFenster::bildDrehen);
    QObject::connect(links, &QPushButton::clicked,this, &drittesFenster::vorherigesBild);
    QObject::connect(rechts, &QPushButton::clicked,this, &drittesFenster::naechstesBild);

    QObject::connect(gesten, &Gestensteuerung::verkleinereBild, this, &verkleinereBild);
    QObject::connect(gesten, &Gestensteuerung::vergroessereBild, this, &vergroessereBild);
    QObject::connect(gesten, &Gestensteuerung::dreheBild, this, &bildDrehen);
    QObject::connect(gesten, &Gestensteuerung::vorhereigesBild, this, &vorherigesBild);
    QObject::connect(gesten, &Gestensteuerung::nachstesBild, this, &naechstesBild);

}

void drittesFenster::vertikal(){
    fuellung1->addSpacing(250);
    fuellung2->addSpacing(250);

    buttons->addLayout(fuellung1);
    buttons->addWidget(eins);
    buttons->addWidget(zwei);
    buttons->addWidget(drei);
    buttons->addWidget(vier);
    buttons->addWidget(fuenf);
    buttons->addLayout(fuellung2);
    buttons->addWidget(beenden);
    buttons->addWidget(drehen);
    buttons->addWidget(links);
    buttons->addWidget(rechts);
}

void drittesFenster::horizontal(){
    fuellung3->addSpacing(500);
    fuellung4->addSpacing(500);

    buttons2->addLayout(fuellung3);
    buttons2->addWidget(eins);
    buttons2->addWidget(zwei);
    buttons2->addWidget(drei);
    buttons2->addWidget(vier);
    buttons2->addWidget(fuenf);
    buttons2->addLayout(fuellung4);
    buttons2->addWidget(beenden);
    buttons2->addWidget(drehen);
    buttons2->addWidget(links);
    buttons2->addWidget(rechts);
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

void drittesFenster::vectorDurchsuchen(){

    cout << m_pfad << endl;

    for(unsigned int i = 0; i < bilder->size(); i++){
        if(bilder->at(i) == m_pfad){
            index = i;
            bereitsDurchsucht = true;
        }
        else{
            continue;
        }
    }
}

void drittesFenster::naechstesBild(){
    // delete(layout);
    // delete(layout2);
    // delete(item);

    if(bereitsDurchsucht == false){
        try{
            vectorDurchsuchen();
            if(index < bilder->size()){
                cout << "Davor: " << index << endl;
                ++index;
                erzeugeDrittesFenster(bilder->at(index));
                cout << "Danach: " << index << endl;
            }else{
                index = 0;
                erzeugeDrittesFenster(bilder->at(index));
            }
        }catch(...){
            fehlerMelden();
        }
    }else if(bereitsDurchsucht == true){
        ++index;
        if(index < bilder->size()){
            cout << "gut "  << endl;
            cout << "Davor: " << index << endl;
            erzeugeDrittesFenster(bilder->at(index));
            cout << "Danach: " << index << endl;
        }else{
            index = 0;
            cout << "Warum?" << endl;
            erzeugeDrittesFenster(bilder->at(index));
        }
    }
}

void drittesFenster::vorherigesBild(){
   // delete(layout);
   // delete(layout2);
   // delete(item);

    if(bereitsDurchsucht == false){
        try{
            vectorDurchsuchen();
            if(index < bilder->size()){
                ++index;
                cout << "Davor: " << index << endl;
                erzeugeDrittesFenster(bilder->at(index));
                cout << "Danach: " << index << endl;
            }else{
                index = 0;
                erzeugeDrittesFenster(bilder->at(index));
            }
        }catch(...){
            fehlerMelden();
        }
    }else if(bereitsDurchsucht == true){
        ++index;
        if(index < bilder->size()){
            cout << "gut "  << endl;
            cout << "Davor: " << index << endl;
            erzeugeDrittesFenster(bilder->at(index));
            cout << "Danach: " << index << endl;
        }else{
            index = 0;
            cout << "Warum?" << endl;
            erzeugeDrittesFenster(bilder->at(index));
        }
    }
}

void drittesFenster::fehlerMelden(){
    information = new QMessageBox();
    QString text = (tr("<h1>Bild wurde nicht gefunden!</h1>"));
    information->setIcon(QMessageBox::Information); //setzt das Icon, welches das Hauptfenster auch hat
    QMessageBox::information(this,"Achtung",text);
}

void drittesFenster::wheelEvent(QWheelEvent *event){

        view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        // Scale the view / do the zoom
        double scaleFactor = 1.15;
        if(event->delta() > 0) {
            // Zoom in
            view-> scale(scaleFactor, scaleFactor);

        } else {
            // Zooming out
             view->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
}

void drittesFenster::verkleinereBild(){
   double scaleFactor = 25.0;
   view->scale(scaleFactor, scaleFactor);
}

void drittesFenster::vergroessereBild(){
    double scaleFactor = 25.0;
    view->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}


