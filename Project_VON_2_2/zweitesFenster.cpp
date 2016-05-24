#include "zweitesFenster.h"
#include <QGridLayout>
#include <QTextBrowser>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* Erstellung des Fensterlayouts*/
    this->setCentralWidget(fenster);;
    fenster->setWindowTitle("Project VON");

    /*----- Westpart wird designed -----*/

    /*Label Optionen mit einer bestimmten Form*/
    QFont font1( "Calibri", 20, QFont::Bold);
    option->setFont(font1);
    option->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    option->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);


    /*Hintergrundfarben mit ihrem Label Hintergrund */
    QFont font2( "Calibri", 10, QFont::Bold);
    hintergrund->setFont(font2);


    QPushButton *schwarz = new QPushButton();
    schwarz->setStyleSheet("background-color: black");
    QObject::connect(schwarz, &QPushButton::clicked,this, &MainWindow::schwarz);
    QPushButton *weiss = new QPushButton();
    weiss->setStyleSheet("background-color: white");
    QObject::connect(weiss, &QPushButton::clicked,this, &MainWindow::weiss);
    QPushButton *beige = new QPushButton();
    beige->setStyleSheet("background-color: beige");
    QObject::connect(beige, &QPushButton::clicked,this, &MainWindow::beige);
    QPushButton *rose = new QPushButton();
    rose->setStyleSheet("background-color: pink");
    QObject::connect(rose, &QPushButton::clicked,this, &MainWindow::pink);
    QGridLayout *farben = new QGridLayout();
    QGridLayout *farb = new QGridLayout();
    QWidget *farbenWidget = new QWidget();
    farb->addWidget(schwarz,0,0);
    farb->addWidget(weiss,0,1);
    farb->addWidget(beige,0,2);
    farb->addWidget(rose,0,3);
    farben->addWidget(hintergrund,0,0);
    farben->addLayout(farb,1,0);
    farbenWidget->setLayout(farben);

    /*Bilderanzahl als Buttons mit dem Label "Anzahl Bilder"*/
    QFont font3( "Calibri", 10, QFont::Bold);
    anzahlBilder->setFont(font3);

    QGridLayout *bilder = new QGridLayout();
    QGridLayout *bild = new QGridLayout();
    bild->addWidget(zwanzig,1,0);
    bild->addWidget(vierzig,1,1);
    bild->addWidget(sechsig,1,2);
    bilder->addWidget(anzahlBilder,0,0);
    bilder->addLayout(bild,1,0);
    QWidget *bilderWidget = new QWidget();
    bilderWidget->setLayout(bilder);


    /*Einstellung des Vollbildmoduses mit dem Label*/
    QFont font4( "Calibri", 10, QFont::Bold);
    vollbild->setFont(font4);
    QVBoxLayout *voll = new QVBoxLayout();
    voll->addWidget(vollbild);
    voll->addWidget(vollbildmodus);
    QWidget *vollWidget = new QWidget();
    vollWidget->setLayout(voll);

    /*Filter zur Behandlung ihrer Bildermenge + Label Filter*/
    QFont font5( "Calibri", 10, QFont::Bold);
    filter->setFont(font5);
    QLineEdit *filtern = new QLineEdit();
    QGridLayout *filt = new QGridLayout();
    filt->addWidget(filter,0,1);
    filt->addWidget(filtern,2,1);
    QWidget *filterWidget = new QWidget();
    filterWidget->setLayout(filt);


    menu->addWidget(option);
    menu->addWidget(farbenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(bilderWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(vollWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(filterWidget, 0, Qt::AlignLeft | Qt::AlignTop);


    QVBoxLayout *menu2 = new QVBoxLayout();
    menu->insertStretch(300,30);
    menu->addLayout(menu);

    fenster->setStyleSheet("background-color:white;");
    westpart->setStyleSheet("background-color:rgb(245,245,245);");
    westpart->setLayout(menu);
    west->addWidget(westpart);
    window->addWidget(westpart);


    /*Center muss hier programmiert werden*/

//    centerpart->setStyleSheet("background-color:black;");
    center->addWidget(centerpart);


    /*Layouts dem Widget hinzufügen*/

    window->addLayout(west,0,0,0,1);
    window->addLayout(center,0,1,1,4);

    fenster->setLayout(window);
}

MainWindow::~MainWindow()
{

}

void MainWindow::schwarz(){
    fenster->setStyleSheet("background-color:black;");
    westpart->setStyleSheet("background-color: rbg(33,30,33);");
    filter->setStyleSheet("color: rgb(199,187,187);");
    hintergrund->setStyleSheet("color: rgb(199,187,187);");
    anzahlBilder->setStyleSheet("color: rgb(199,187,187);");
    vollbild->setStyleSheet("color: rgb(199,187,187);");
    vollbildmodus->setStyleSheet("color: rgb(199,187,187);");
    option->setStyleSheet("color: rgb(199,187,187);");
    zwanzig->setStyleSheet("color: rgb(199,187,187);");
    vierzig->setStyleSheet("color: rgb(199,187,187);");
    sechsig->setStyleSheet("color: rgb(199,187,187);");


//    westpart->setStyleSheet("QPushButton {color:white;}");
    fenster->update();
}

void MainWindow::beige(){
    fenster->setStyleSheet("background-color:beige;");
    westpart->setStyleSheet("background-color:rgb(245,231,201);");
    filter->setStyleSheet("color: rgb(255,140,0);");
    hintergrund->setStyleSheet("color: rgb(255,140,0);");
    anzahlBilder->setStyleSheet("color: rgb(255,140,0);");
    vollbild->setStyleSheet("color: rgb(255,140,0);");
    vollbildmodus->setStyleSheet("color: rgb(255,140,0);");
    option->setStyleSheet("color: rgb(255,140,0);");
    zwanzig->setStyleSheet("color: rgb(255,140,0);");
    vierzig->setStyleSheet("color: rgb(255,140,0);");
    sechsig->setStyleSheet("color: rgb(255,140,0);");

    fenster->update();
}


void MainWindow::weiss(){
    fenster->setStyleSheet("background-color:white;");
    westpart->setStyleSheet("background-color:rgb(245,245,245);");
    filter->setStyleSheet("color: black;");
    hintergrund->setStyleSheet("color: black;");
    anzahlBilder->setStyleSheet("color: black;");
    vollbild->setStyleSheet("color: black;");
    vollbildmodus->setStyleSheet("color: black;");
    option->setStyleSheet("color: black;");
    zwanzig->setStyleSheet("color: black;");
    vierzig->setStyleSheet("color: black;");
    sechsig->setStyleSheet("color: black;");

    fenster->update();
}

void MainWindow::pink(){
    fenster->setStyleSheet("background-color:pink;");
    westpart->setStyleSheet("background-color:rgb(209,148,209);");
    filter->setStyleSheet("color: pink;");
    hintergrund->setStyleSheet("color: pink;");
    anzahlBilder->setStyleSheet("color: pink;");
    vollbild->setStyleSheet("color: pink;");
    vollbildmodus->setStyleSheet("color: pink;");
    option->setStyleSheet("color: pink;");
    zwanzig->setStyleSheet("color: pink;");
    vierzig->setStyleSheet("color: pink;");
    sechsig->setStyleSheet("color: pink;");

    fenster->update();
}


