#include "erstesfenster.h"

erstesFenster::erstesFenster(QWidget *fenster, QWidget *parent)
    : QMainWindow(parent)
{
    bank = new Datenbank();

    if( bank->datenbankEmpty() == true ){

        /*--------1.Fenster----------*/

        this->setWindowTitle("VON");  //Setzt Titel des Fensters

        /*--------Sound abspielen----------*/

        sound = new Sound();
        sound->start();
        QObject::connect(sound,&Sound::finished,sound, &Sound::deleteLater);


        /*--------------Hintergrundbild------------------*/

        view = new QGraphicsView(fenster);
        scene = new QGraphicsScene;

        /* Zeichnung von Linen in einer bestimmten Farbe von einem bestimmten Pixel zu einem anderen */
        scene->setSceneRect(0,0,800,600);
        QPen *pen = new QPen();
        pen->setColor("lime");

        scene->addLine(0, 120, 170, 240, *pen); scene->addLine(170, 240, 0, 370, *pen);
        scene->addLine(0, 540, 170, 470, *pen); scene->addLine(170, 470, 290, 600, *pen);
        scene->addLine(470, 600, 520, 420, *pen); scene->addLine(520, 420, 800, 510, *pen);
        scene->addLine(450, 0, 560, 130, *pen); scene->addLine(560, 130, 700, 60, *pen); scene->addLine(700, 60, 685, 0, *pen);

        pen->setColor("magenta");

        scene->addLine(90, 185, 220, 0, *pen);
        scene->addLine(105, 495, 135, 265, *pen); scene->addLine(135, 265, 355, 375, *pen); scene->addLine(355, 375, 238, 540, *pen);
        scene->addLine(800, 260, 660, 375, *pen); scene->addLine(660, 375, 650, 85, *pen);

        pen->setColor("deepskyblue");

        scene->addLine(195, 35, 270, 330, *pen);
        scene->addLine(325, 420, 503, 480, *pen);
        scene->addLine(755, 495, 685, 353, *pen);
        scene->addLine(656, 295, 440, 190, *pen); scene->addLine(440, 190, 520, 85, *pen);

        pen->setColor("coral");

        scene->addLine(216, 115, 496, 115, *pen);
        scene->addLine(308, 350, 555, 245, *pen); scene->addLine(555, 245, 560, 433, *pen);

        view->setScene(scene);
        scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

        /*--------------Text Layout------------------*/



        txt->setAlignment(Qt::AlignCenter);         //Label befindet sich im Mittelpunkt
        QFont* font = new QFont("Courier New");
        font->setItalic(true);
        txt->setGeometry(125, 350, 550, 40);  // absolute positionierung

        QPalette* palette = new QPalette();
        palette->setColor(QPalette::WindowText,Qt::gray);
        txt->setPalette(*palette);

        txt->setStyleSheet("QLabel { background-color: black;color:  grey  }");
        scene->addWidget(txt);                //Label txt wird zur Scene hinzugefügt

        /*--------------Button Layout------------------*/

        QObject::connect(startButton, &QPushButton::clicked,this, &erstesFenster::openSecondWindow);
        startButton->setStyleSheet("background-color: black; color:  grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px; font-size: 10pt; font-weight: bold;");
        startButton->setGeometry(285, 550, 180, 35);  // absolute positionierung


        scene->addWidget(startButton);           //Button Startverzeichnisbutton wird zur Scene hinzugefügt

        this->setCentralWidget(view);   //View soll dargestellt werden

    }
    else{
        /*--------1.Fenster----------*/

        this->setWindowTitle("VON");  //Setzt Titel des Fensters

        /*--------Sound abspielen----------*/

        sound = new Sound();
        sound->start();
        QObject::connect(sound,&Sound::finished,sound, &Sound::deleteLater);


        /*--------------Hintergrundbild------------------*/

        view = new QGraphicsView(fenster);
        scene = new QGraphicsScene;

        /* Zeichnung von Linen in einer bestimmten Farbe von einem bestimmten Pixel zu einem anderen */
        scene->setSceneRect(0,0,800,600);
        QPen *pen = new QPen();
        pen->setColor("lime");

        scene->addLine(0, 120, 170, 240, *pen); scene->addLine(170, 240, 0, 370, *pen);
        scene->addLine(0, 540, 170, 470, *pen); scene->addLine(170, 470, 290, 600, *pen);
        scene->addLine(470, 600, 520, 420, *pen); scene->addLine(520, 420, 800, 510, *pen);
        scene->addLine(450, 0, 560, 130, *pen); scene->addLine(560, 130, 700, 60, *pen); scene->addLine(700, 60, 685, 0, *pen);

        pen->setColor("magenta");

        scene->addLine(90, 185, 220, 0, *pen);
        scene->addLine(105, 495, 135, 265, *pen); scene->addLine(135, 265, 355, 375, *pen); scene->addLine(355, 375, 238, 540, *pen);
        scene->addLine(800, 260, 660, 375, *pen); scene->addLine(660, 375, 650, 85, *pen);

        pen->setColor("deepskyblue");

        scene->addLine(195, 35, 270, 330, *pen);
        scene->addLine(325, 420, 503, 480, *pen);
        scene->addLine(755, 495, 685, 353, *pen);
        scene->addLine(656, 295, 440, 190, *pen); scene->addLine(440, 190, 520, 85, *pen);

        pen->setColor("coral");

        scene->addLine(216, 115, 496, 115, *pen);
        scene->addLine(308, 350, 555, 245, *pen); scene->addLine(555, 245, 560, 433, *pen);

        view->setScene(scene);
        scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

        /*--------------Text Layout------------------*/

        txt->setAlignment(Qt::AlignCenter);         //Label befindet sich im Mittelpunkt
        QFont* font = new QFont("Courier New");
        font->setItalic(true);
        txt->setGeometry(125, 350, 550, 40);  // absolute positionierung

        QPalette* palette = new QPalette();
        palette->setColor(QPalette::WindowText,Qt::gray);
        txt->setPalette(*palette);

        txt->setStyleSheet("QLabel { background-color: black }");
        scene->addWidget(txt);                //Label txt wird zur Scene hinzugefügt

        /*--------------Button Layout------------------*/
        QObject::connect(startButton, &QPushButton::clicked,this, &erstesFenster::openSecondWindow);
        startButton->setStyleSheet("background-color: black; color:  grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px; font-size: 13pt; font-weight: bold;");
        startButton->setGeometry(15, 550, 220, 25);  // absolute positionierung

        //QObject::connect(letztenOrdnerButton, &QPushButton::clicked,this, &erstesFenster::letzter);
        letztenOrdnerButton->setStyleSheet("background-color: black; color:  grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px; font-size: 13pt; font-weight: bold;");
        letztenOrdnerButton->setGeometry(490, 550, 300, 35);  // absolute positionierung

        scene->addWidget(startButton);           //Button "ja" wird zur Scene hinzugefügt
        scene->addWidget(letztenOrdnerButton);   //Button "letztenOrdner" wird zur Scene hinzugefügt

        this->setCentralWidget(view);   //View soll dargestellt werden
        setWindowIcon(QIcon(":/icon/Icon.png"));
    }

}

//warum braucht man die Klammern () um die Zeiger
erstesFenster::~erstesFenster()
{
    delete (view);
    delete (scene);
    delete (startButton);
    delete (letztenOrdnerButton);
    delete (txt);
    delete (sound);
}
