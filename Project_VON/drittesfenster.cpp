#include "drittesfenster.h"

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

    gesten = new Gestensteuerung(buttons, buttons2);
    bereitsDurchsucht = false;
    interaktion();
    buttonsStyle();
}

drittesFenster::~drittesFenster()
{
    delete (m_fenster);
    delete (layout);
    delete (layout2);
    delete (buttons);
    delete (buttons2);
    delete (fuellung1);
    delete (fuellung2);
    delete (fuellung3);
    delete (fuellung4);
    delete (scene);
    delete (view);
    delete (eins);
    delete (zwei);
    delete (drei);
    delete (vier);
    delete (fuenf);
    delete (beenden);
    delete (item);
    delete (m_bank);
    delete (drehen);
    delete (links);
    delete (rechts);
    delete (bilder);
    delete (information);
    delete (screen);
    delete (gesten);
}

void drittesFenster::erzeugeDrittesFenster(string pfad){
    m_pfad = pfad;

    QString qstr = QString::fromStdString(pfad);
    QImage image(qstr);


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

    else if(size.width() == 1680 && size.height() == 1050){
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
    else{
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

    /* Bewertung: 1*/
    QPixmap pixmap1(":/icon/schwarzEins.tif");
    QIcon buttonIcon1(pixmap1);
    eins->setIcon(buttonIcon1);
    eins->setIconSize(QSize(75, 75));
    eins->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 2*/
    QPixmap pixmap2(":/icon/schwarzZwei.tif");
    QIcon buttonIcon2(pixmap2);
    zwei->setIcon(buttonIcon2);
    zwei->setIconSize(QSize(75, 75));
    zwei->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 3*/
    QPixmap pixmap3(":/icon/schwarzDrei.tif");
    QIcon buttonIcon3(pixmap3);
    drei->setIcon(buttonIcon3);
    drei->setIconSize(QSize(75, 75));
    drei->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 4*/
    QPixmap pixmap4(":/icon/schwarzVier.tif");
    QIcon buttonIcon4(pixmap4);
    vier->setIcon(buttonIcon4);
    vier->setIconSize(QSize(75, 75));
    vier->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 5*/
    QPixmap pixmap5(":/icon/schwarzFuenf.tif");
    QIcon buttonIcon5(pixmap5);
    fuenf->setIcon(buttonIcon5);
    fuenf->setIconSize(QSize(75, 75));
    fuenf->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Beenden */
    QPixmap pixmap6(":/icon/zurueck.tif");
    QIcon buttonIcon6(pixmap6);
    beenden->setIcon(buttonIcon6);
    beenden->setIconSize(QSize(50, 50));
    beenden->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Drehen */
    QPixmap pixmap7(":/icon/drehen.tif");
    QIcon buttonIcon7(pixmap7);
    drehen->setIcon(buttonIcon7);
    drehen->setIconSize(QSize(50, 50));
    drehen->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Links */
    QPixmap pixmap8(":/icon/links.tif");
    QIcon buttonIcon8(pixmap8);
    links->setIcon(buttonIcon8);
    links->setIconSize(QSize(50, 50));
    links->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Rechts */
    QPixmap pixmap9(":/icon/rechts.tif");
    QIcon buttonIcon9(pixmap9);
    rechts->setIcon(buttonIcon9);
    rechts->setIconSize(QSize(50, 50));
    rechts->setStyleSheet("border: none; margin: 0px; padding: 0px;");
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

void drittesFenster::vertikal()
{
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

void drittesFenster::horizontal()
{
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

void drittesFenster::bewertenEins()
{
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,1);
}

void drittesFenster::bewertenZwei()
{
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,2);
}

void drittesFenster::bewertenDrei()
{
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,3);
}

void drittesFenster::bewertenVier()
{
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,4);
}

void drittesFenster::bewertenFuenf()
{
    int id = m_bank->getID(m_pfad);
    m_bank->bildBewerten(id,5);
}

void drittesFenster::bildDrehen()
{
    view->rotate(90);
    int id = m_bank->getID(m_pfad);
    cout << id << endl;
    m_bank->setNeueBildausrichtung(id);
    m_bank->getBildausrichtung(id);
}

void drittesFenster::vectorDurchsuchen()
{
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

void drittesFenster::naechstesBild()
{
    // delete(layout);
    // delete(layout2);
    // delete(item);

    if(bereitsDurchsucht == false){
        try{
            vectorDurchsuchen();
            if(index < bilder->size()){
                ++index;
                erzeugeDrittesFenster(bilder->at(index));
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
            erzeugeDrittesFenster(bilder->at(index));
        }else{
            index = 0;
            erzeugeDrittesFenster(bilder->at(index));
        }
    }
}

void drittesFenster::vorherigesBild()
{
   // delete(layout);
   // delete(layout2);
   // delete(item);

    if(bereitsDurchsucht == false){
        try{
            vectorDurchsuchen();
            if(index < bilder->size()){
                ++index;
                erzeugeDrittesFenster(bilder->at(index));
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
            erzeugeDrittesFenster(bilder->at(index));
        }else{
            index = 0;
            erzeugeDrittesFenster(bilder->at(index));
        }
    }
}

void drittesFenster::fehlerMelden()
{
    information = new QMessageBox();
    QString text = (tr("<h1>Bild wurde nicht gefunden!</h1>"));
    information->setIcon(QMessageBox::Information);
    QMessageBox::information(this,"Achtung",text);
}

void drittesFenster::wheelEvent(QWheelEvent *event)
{
        view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        double scaleFactor = 1.15;
        if(event->delta() > 0) {
            // Zoom rein
            view-> scale(scaleFactor, scaleFactor);

        } else {
            // Zooming raus
             view->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
}

void drittesFenster::verkleinereBild()
{
   double scaleFactor = 25.0;
   view->scale(scaleFactor, scaleFactor);
}

void drittesFenster::vergroessereBild()
{
    double scaleFactor = 25.0;
    view->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}


