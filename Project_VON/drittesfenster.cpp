#include "drittesfenster.h"


drittesFenster::drittesFenster(QWidget *fenster, QWidget *parent) : QWidget(parent){
    m_fenster = fenster;
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);


    eins = new QPushButton(view);
    zwei = new QPushButton(view);
    drei = new QPushButton(view);

    vier = new QPushButton(view);
    fuenf = new QPushButton(view);
    beenden = new QPushButton(view);

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
}

void drittesFenster::erzeugeDrittesFenster(string pfad){

    cout << 1 << endl;
    QString qstr = QString::fromStdString(pfad);
    QImage image(qstr);
   // QImage image("C:\\Users\\Christopher\\Desktop\\Test\\WP_20160225_07_49_05_Pro.jpg");

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


    if(image.height() >= image.width()){
        image = image.scaledToHeight(1300, Qt::FastTransformation);

        layout->addWidget(view,0,8,3,6);
        fuellung1->addSpacing(500);
        fuellung2->addSpacing(320);

        buttons->addLayout(fuellung1);
        buttons->addWidget(eins);
        buttons->addWidget(zwei);
        buttons->addWidget(drei);
        buttons->addWidget(vier);
        buttons->addWidget(fuenf);
        buttons->addLayout(fuellung2);
        buttons->addWidget(beenden);
        layout->addLayout(buttons,0,0);
    }
    if(image.height() < image.width()){
        image = image.scaledToHeight(1200, Qt::FastTransformation);
        layout->addWidget(view,0,8,1,6);
        fuellung3->addSpacing(700);
        fuellung4->addSpacing(700);

        buttons2->addLayout(fuellung3);
        buttons2->addWidget(eins);
        buttons2->addWidget(zwei);
        buttons2->addWidget(drei);
        buttons2->addWidget(vier);
        buttons2->addWidget(fuenf);
        buttons2->addLayout(fuellung4);
        buttons2->addWidget(beenden);
        layout->addLayout(buttons2,1,8,1,6);

    }
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);

    this->setLayout(layout);
    this->showMaximized();
}
