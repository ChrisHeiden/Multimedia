#include "erstesfenster.h"

erstesFenster::erstesFenster(QWidget *fenster, QTranslator *translator, Datenbank *bank, QWidget *parent)
    : QMainWindow(parent)
{
    m_bank = bank;
    m_translator = translator;
    startButton = new QPushButton(tr("Startverzeichnis"));
    letztenOrdnerButton = new QPushButton(tr("Letzte Bilder anzeigen"));
    txt = new QLabel(tr("<h1><strong>Bitte Startverzeichnis auswählen</strong></h1>"));
    deutsch = new QPushButton;
    englisch = new QPushButton;
    view = new QGraphicsView(fenster);
    scene = new QGraphicsScene;
    pen = new QPen();
    sound = new Sound();

    setzeSignals();
    buttonStil();
    labelStil();
}

erstesFenster::~erstesFenster()
{
    delete (view);
    delete (scene);
    delete (startButton);
    delete (letztenOrdnerButton);
    delete (txt);
    delete (sound);
    delete (m_bank);
    delete (deutsch);
    delete (englisch);
    delete (m_translator);
    delete (pen);
}

void erstesFenster::erzeugen()
{
    hintergrundSetzen();
    sound->start();
    scene->addWidget(txt);
    scene->addWidget(deutsch);
    scene->addWidget(englisch);

    if( m_bank->datenbankEmpty() == true ){
        scene->addWidget(startButton);
        startButton->setGeometry(300, 550, 150, 25);  // absolute positionierung
    }
    else{
        scene->addWidget(startButton);
        startButton->setGeometry(50, 550, 150, 25);  // absolute positionierung

        letztenOrdnerButton->setGeometry(550, 550, 220, 25);  // absolute positionierung
        scene->addWidget(letztenOrdnerButton);   //Button "letztenOrdner" wird zur Scene hinzugefügt
    }
    this->setCentralWidget(view);   //View soll dargestellt werden
}

void erstesFenster::englischUebersetzung()
{
    QApplication::instance()->removeTranslator(m_translator);
}

void erstesFenster::deutschUebersetzung()
{
    QApplication::instance()->removeTranslator(m_translator);

    if (m_translator->load(":/language/VON_Englisch_zu_Deutsch.qm"))

    {
    qDebug() << "LOAD FINISHED";

    QApplication::instance()->installTranslator(m_translator);
    }
}

void erstesFenster::setzeSignals()
{
    QObject::connect(sound,&Sound::finished,sound, &Sound::deleteLater);
    QObject::connect(startButton, &QPushButton::clicked,this, &erstesFenster::openSecondWindow);
    QObject::connect(letztenOrdnerButton, &QPushButton::clicked, this, &erstesFenster::showLetzteBilder);
    QObject::connect(deutsch, &QPushButton::clicked,this, &erstesFenster::deutschUebersetzung);
    QObject::connect(englisch, &QPushButton::clicked,this, &erstesFenster::englischUebersetzung);
}

void erstesFenster::buttonStil()
{

    QPixmap pixmap1(":/icon/deutsch.jpg");
    QIcon buttonIcon1(pixmap1);
    deutsch->setIcon(buttonIcon1);
    deutsch->setIconSize(QSize(50, 50));
    deutsch->setStyleSheet("border: none; margin-bottom: 0px;padding: 0px;");
    deutsch->setGeometry(700, 35, 50, 50);
    deutsch->setStyleSheet("background-color: black;");

    /* Vollbildmodus deaktivieren */
    QPixmap pixmap2(":/icon/englisch.jpg");
    QIcon buttonIcon2(pixmap2);
    englisch->setIcon(buttonIcon2);
    englisch->setIconSize(QSize(50, 50));
    englisch->setStyleSheet("border: none; margin-bottom: 0px;padding: 0px;");
    englisch->setGeometry(700, 90, 50 ,50);;
    englisch->setStyleSheet("background-color: black;");
}

void erstesFenster::labelStil()
{
    txt->setAlignment(Qt::AlignCenter);         //Label befindet sich im Mittelpunkt
    QFont* font = new QFont("Courier New");
    font->setItalic(true);
    txt->setGeometry(125, 350, 550, 40);  // absolute positionierung

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::gray);
    txt->setPalette(*palette);

    txt->setStyleSheet("background-color: black; color: rgb(255,250,250)");

    startButton->setStyleSheet("background-color: black; color: rgb(255,250,250); border: none; margin: 0px;padding: 0px; width: 30px; height: 25px; font-size: 13pt; font-weight: bold;");

    letztenOrdnerButton->setStyleSheet("background-color: black; color: rgb(255,250,250); border: none; margin: 0px;padding: 0px; width: 30px; height: 25px; font-size: 13pt; font-weight: bold;");

}

void erstesFenster::hintergrundSetzen()
{
    scene->setSceneRect(0,0,800,600);
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
}

