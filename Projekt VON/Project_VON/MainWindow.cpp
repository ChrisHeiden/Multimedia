#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*--------1.Fenster----------*/

    QWidget *window = new QWidget;          //erzeugt Widget
    this->setCentralWidget(window);;
    window->setWindowTitle("Project VON");  //Setzte Titel des Fensters
    window->setStyleSheet("background-image:url(C:/Users/Christopher/Desktop/Hintergrund_2)");

    /*--------------Text Layout------------------*/

    QLabel *txt = new QLabel();
    txt->setText("<h1><strong>Alle Bilder darstellen?</strong></h1>");
    txt->setAlignment(Qt::AlignCenter);         //Label befindet sich im Mittelpunkt
    QFont* font = new QFont("Courier New");
    font->setItalic(true);

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::gray);
    txt->setPalette(*palette);

    QHBoxLayout *textLayout = new QHBoxLayout;
    textLayout->addWidget(txt);

    /*--------------Button Layout------------------*/


    QPushButton *ja = new QPushButton("Ja");
    QObject::connect(ja, SIGNAL(clicked()),this, SLOT(close));
    ja->setStyleSheet("background-collor:black");

    QPushButton *nein = new QPushButton("Nein");
    QObject::connect(nein, SIGNAL(clicked()),this, SLOT(close));
    nein->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(190,190,190)");

    QPushButton *letztenOrdner = new QPushButton("Letzten geöffneten Ordner anzeigen");
    QObject::connect(letztenOrdner, SIGNAL(clicked()),this, SLOT(close));
    letztenOrdner->setStyleSheet("background-color: rgb(0,0,0); color: rgb(190,190,190)");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(ja);
    buttonLayout->addWidget(nein);
    buttonLayout->addWidget(letztenOrdner);


    /*--------------Hinzufügen der Layouts zum Window-----------------*/

    QVBoxLayout *mainLayout = new QVBoxLayout;      // erzeugt BoxLayout in dem sich alle anderen Layouts befinden sollen

    mainLayout->addLayout(textLayout);
    mainLayout->addLayout(buttonLayout);
    window->setLayout(mainLayout);
}
