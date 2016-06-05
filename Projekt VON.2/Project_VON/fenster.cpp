#include "fenster.h"
using namespace std;

/* erstes Fenster darstellen */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*--------1.Fenster----------*/

    this->setWindowTitle("VON");  //Setzt Titel des Fensters


    /*--------------Hintergrundbild------------------*/

    view = new QGraphicsView;
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

    QLabel *txt = new QLabel();
    txt->setText("<h1><strong>Alle Bilder darstellen?</strong></h1>");
    txt->setAlignment(Qt::AlignCenter);         //Label befindet sich im Mittelpunkt
    QFont* font = new QFont("Courier New");
    font->setItalic(true);
    txt->setGeometry(260, 350, 245, 25);  // absolute positionierung

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::gray);
    txt->setPalette(*palette);

    txt->setStyleSheet("QLabel { background-color: black }");
    scene->addWidget(txt);                //Label txt wird zur Scene hinzugefügt

    /*--------------Button Layout------------------*/


    QPushButton *ja = new QPushButton("Ja");
    QObject::connect(ja, &QPushButton::clicked,this, &MainWindow::ja);
    ja->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(190,190,190)");
    ja->setGeometry(130, 550, 35, 35);  // absolute positionierung

    QPushButton *nein = new QPushButton("Nein");
    QObject::connect(nein, &QPushButton::clicked,this, &MainWindow::nein);
    nein->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(190,190,190)");
    nein->setGeometry(350, 550, 35, 35);  // absolute positionierung

    QPushButton *letztenOrdner = new QPushButton("Letzten geöffneten Ordner anzeigen");
    QObject::connect(letztenOrdner, &QPushButton::clicked,this, &MainWindow::ja);
    letztenOrdner->setStyleSheet("background-color: rgb(0,0,0); color: rgb(190,190,190)");
    letztenOrdner->setGeometry(500, 550, 300, 35);  // absolute positionierung

    scene->addWidget(ja);           //Button "ja" wird zur Scene hinzugefügt
    scene->addWidget(nein);         //Button "nein" wird zur Scene hinzugefügt
    scene->addWidget(letztenOrdner);//Button "letztenOrdner" wird zur Scene hinzugefügt

    this->setCentralWidget(view);   //View soll dargestellt werden
    setWindowIcon(QIcon("C:/Users/Christopher/Documents/Privat/Studium/Semester 4/Entwicklung von Multimediasysteme/Icon.png")); // zur darstellung des Icons oben links
}

/* Zweites Fenster darstellen wenn ja angeklickt wurden */
void MainWindow::ja(){
   this->setCentralWidget(fenster);

    /* Schriftzug Optionen sollte besonders aussehen uznd positioniert werden*/
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
   QObject::connect(vollbildmodus, &QRadioButton::clicked,this, &MainWindow::vollbildModusAktiv);
   QVBoxLayout *voll = new QVBoxLayout();
   voll->addWidget(vollbild);
   voll->addWidget(vollbildmodus);
   QWidget *vollWidget = new QWidget();
   vollWidget->setLayout(voll);
   vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(189, 195, 199); color: black; border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");


   QFont font5( "Calibri", 10, QFont::Bold);
   sprache->setFont(font5);
   QHBoxLayout *language = new QHBoxLayout;
   QVBoxLayout *sprachen = new QVBoxLayout;
   QWidget *sprachenWidget = new QWidget;
   language->addWidget(deutsch);
   deutsch->setChecked(true);
   language->addWidget(englisch);
   sprachen->addWidget(sprache);
   sprachen->addLayout(language);
   sprachenWidget->setLayout(sprachen);

   /*Filter zur Behandlung ihrer Bildermenge + Label Filter*/
   QFont font6( "Calibri", 10, QFont::Bold);
   filter->setFont(font6);
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
   menu->addWidget(sprachenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
   menu->addWidget(filterWidget, 0, Qt::AlignLeft | Qt::AlignTop);


   QVBoxLayout *menu2 = new QVBoxLayout();
   menu->insertStretch(300,30);
   menu->addLayout(menu2);

   fenster->setStyleSheet("background-color:white;");
   westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
   westpart->setLayout(menu);
   west->addWidget(westpart);
   window->addWidget(westpart);


   /*Center muss hier programmiert werden*/

   QScrollArea *scrallArea = new QScrollArea; // Erzeugung der Area in dem Bilder dargestellt werden sollen
   scrallArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);   // soll möglichkeit bieten nach unten zu scallen
   QVBoxLayout *center2 = new QVBoxLayout;


   vector<string> images = alleGefundeneBidler(); // alle Bilder ab einem bestimmten Verzeichnis werden geladen
   for (unsigned int y = 0; y < images.size(); y++){
        QHBoxLayout *center1 = new QHBoxLayout;
        for(unsigned int i = 0; i < 5; i++){
            QString image = QString::fromStdString(images[i]);
            QPushButton *button = new QPushButton;
            button->setMaximumWidth(300);
            button->setMaximumHeight(300);
            QPixmap pixmap(image);
            QIcon ButtonIcon(pixmap);
            button->setIcon(ButtonIcon);
            button->setIconSize(pixmap.rect().size());
            center1->addWidget(button);
            images.erase(images.begin());
        }
       center2->addLayout(center1);
   }
   scrallArea->setLayout(center2);

   /*Layouts dem Widget hinzufügen*/

   window->addLayout(west,0,0,0,1);
   window->addWidget(scrallArea,0,1,1,4);

   fenster->setLayout(window);
}

/* Zweites Fenster darstellen wenn nein angeklickt wurden */
void MainWindow::nein(){
   this->setCentralWidget(fenster);

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
   QObject::connect(vollbildmodus, &QRadioButton::clicked,this, &MainWindow::vollbildModusAktiv);
   QVBoxLayout *voll = new QVBoxLayout();
   voll->addWidget(vollbild);
   voll->addWidget(vollbildmodus);
   QWidget *vollWidget = new QWidget();
   vollWidget->setLayout(voll);
   vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(189, 195, 199); color: black; border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");


   QFont font5( "Calibri", 10, QFont::Bold);
   sprache->setFont(font5);
   QHBoxLayout *language = new QHBoxLayout;
   QVBoxLayout *sprachen = new QVBoxLayout;
   QWidget *sprachenWidget = new QWidget;
   language->addWidget(deutsch);
   deutsch->setChecked(true);
   language->addWidget(englisch);
   sprachen->addWidget(sprache);
   sprachen->addLayout(language);
   sprachenWidget->setLayout(sprachen);


   /*Filter zur Behandlung ihrer Bildermenge + Label Filter*/
   QFont font6( "Calibri", 10, QFont::Bold);
   filter->setFont(font6);
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
   menu->addWidget(sprachenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
   menu->addWidget(filterWidget, 0, Qt::AlignLeft | Qt::AlignTop);


   QVBoxLayout *menu2 = new QVBoxLayout();
   menu->insertStretch(300,30);
   menu->addLayout(menu2);

   fenster->setStyleSheet("background-color:white;");
   westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
   westpart->setLayout(menu);
   west->addWidget(westpart);
   window->addWidget(westpart);


   /*Center muss hier programmiert werden*/

   QScrollArea *scrallArea = new QScrollArea;
   scrallArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
   QVBoxLayout *center2 = new QVBoxLayout;

   QString gewuenschterPfad = ausgewaehlterOrdnern(); // gewünschter Ordnerpfad wird gespeichert
   vector<string> images = gefundeneBidlerImOrdner(gewuenschterPfad);   // innerhalb dieses Ordners wird nach Bilder gesucht und später dargestellt
   for (unsigned int y = 0; y < images.size(); y++){
        QHBoxLayout *center1 = new QHBoxLayout;
        for(unsigned int i = 0; i < 5; i++){
            QString image = QString::fromStdString(images[i]);
            QPushButton *button = new QPushButton;
            button->setMaximumWidth(300);
            button->setMaximumHeight(300);
            QPixmap pixmap(image);
            QIcon ButtonIcon(pixmap);
            button->setIcon(ButtonIcon);
            button->setIconSize(pixmap.rect().size());
            center1->addWidget(button);
            images.erase(images.begin());
        }
       center2->addLayout(center1);
   }
   scrallArea->setLayout(center2);

   /*Layouts dem Widget hinzufügen*/

   window->addLayout(west,0,0,0,1);
   window->addWidget(scrallArea,0,1,1,4);

   fenster->setLayout(window);
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
    sprache->setStyleSheet("color: rgb(199,187,187);");
    deutsch->setStyleSheet("color: rgb(199,187,187);");
    englisch->setStyleSheet("color: rgb(199,187,187);");
    vollbildModusDeaktiviern->setStyleSheet("background-color: rbg(33,30,33); color: rgb(199,187,187); border: none; margin: 0px; padding: 0px; width: 100px; height: 50px;");
    fenster->update(); // muss geupdatet werden, damit Änderungen sichtbar werden
}

void MainWindow::beige(){
    fenster->setStyleSheet("background-color:beige;");
    westpart->setStyleSheet("background-color:rgb(245,230,199);");
    filter->setStyleSheet("color: rgb(245,194,93);");
    hintergrund->setStyleSheet("color: rgb(245,194,93);");
    anzahlBilder->setStyleSheet("color: rgb(245,194,93);");
    vollbild->setStyleSheet("color: rgb(245,194,93);");
    vollbildmodus->setStyleSheet("color: rgb(245,194,93);");
    option->setStyleSheet("color: rgb(245,194,93);");
    zwanzig->setStyleSheet("color: rgb(245,194,93);");
    vierzig->setStyleSheet("color: rgb(245,194,93);");
    sechsig->setStyleSheet("color: rgb(245,194,93);");
    sprache->setStyleSheet("color: rgb(245,194,93);");
    deutsch->setStyleSheet("color: rgb(245,194,93);");
    englisch->setStyleSheet("color: rgb(245,194,93);");
    vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(245,230,199); color: rgb(245,194,93); border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");
    fenster->update();
}

void MainWindow::weiss(){
    fenster->setStyleSheet("background-color:white;");
    westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
    filter->setStyleSheet("color: black;");
    hintergrund->setStyleSheet("color: black;");
    anzahlBilder->setStyleSheet("color: black;");
    vollbild->setStyleSheet("color: black;");
    vollbildmodus->setStyleSheet("color: black;");
    option->setStyleSheet("color: black;");
    zwanzig->setStyleSheet("color: black;");
    vierzig->setStyleSheet("color: black;");
    sechsig->setStyleSheet("color: black;");
    sprache->setStyleSheet("color: black;");
    deutsch->setStyleSheet("color: black;");
    englisch->setStyleSheet("color: black;");
    vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(189, 195, 199); color: black; border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");
    fenster->update();
}

void MainWindow::pink(){
    fenster->setStyleSheet("background-color:pink;");
    westpart->setStyleSheet("background-color:rgb(240,192,240);");
    filter->setStyleSheet("color: rgb(171,19,171);");
    hintergrund->setStyleSheet("color: rgb(171,19,171);");
    anzahlBilder->setStyleSheet("color: rgb(171,19,171);");
    vollbild->setStyleSheet("color: rgb(171,19,171);");
    vollbildmodus->setStyleSheet("color: rgb(171,19,171);");
    option->setStyleSheet("color: rgb(171,19,171);");
    zwanzig->setStyleSheet("color: rgb(171,19,171);");
    vierzig->setStyleSheet("color: rgb(171,19,171);");
    sechsig->setStyleSheet("color: rgb(171,19,171);");
    sprache->setStyleSheet("color: rgb(171,19,171);");
    deutsch->setStyleSheet("color: rgb(171,19,171);");
    englisch->setStyleSheet("color: rgb(171,19,171);");
    vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(240,192,240); color: rgb(171,19,171); border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");
    fenster->update();
}

void MainWindow::vollbildModusAktiv(){
    westpart->setHidden(true); //Menu wird versteckt
    vollbildmodus->setChecked(false); // der Button am Label ist nicht aktiv

    /*Erzeugung eines neuen Layouts in dem sich der Button zur deaktivierung des Vollbildmodus existiert*/
    QVBoxLayout *menu2 = new QVBoxLayout();
    menu2->insertStretch(300,30); //muss eine gewisse länge haben, damit Button ganz unten steht
    east->addLayout(menu2);
    east->addWidget(vollbildModusDeaktiviern);
    window->addLayout(east,0,4);

    QObject::connect(vollbildModusDeaktiviern, &QPushButton::clicked,this, &MainWindow::vollbildModusInaktiv);
    vollbildModusDeaktiviern->setVisible(true);
}

void MainWindow::vollbildModusInaktiv(){
    westpart->setHidden(false); //Menu wird wieder angezeigt
    vollbildModusDeaktiviern->setHidden(true);  //Button, der Vollbildmodus deaktivieren kann wird unsichtbar
}

vector<string> MainWindow::gefundeneBidlerImOrdner(QString name){

    vector<string> bilder;  //Deklaration des Vekors, welche die Pfade der Bilder enthalten soll
    QDirIterator it( name, QDirIterator::Subdirectories ); // Iterator für Verzeichnis erstellen
    it.next();    // nächstes Verzeichnis

    smatch e;
    regex exp(".*.jpg$");   // mit Wildcards gearbeitet um jpg Dateien zu finden
    do
    {
     if((it.fileInfo().isFile() == true)  && (regex_match(it.fileInfo().absoluteFilePath().toStdString(),e,exp)))
          for(auto a:e){
              bilder.push_back(a);  //Pfad der Bilder wird im Vektor gespeichert
          }
      it.next();                 // nächste Datei bzw. Ordner
    } while( it.hasNext() );     // Schleife läuft solange Dateien oder Ordner im Verzeichnis sind
    return bilder;
}

vector<string> MainWindow::alleGefundeneBidler(){

    vector<string> bilder;

    QDirIterator it( "C:/Users/Christopher/Desktop/beste Bilder/", QDirIterator::Subdirectories ); // Iterator für Verzeichnis erstellen
    it.next();    // nächstes Verzeichnis

    smatch e;
    regex exp(".*.jpg$");
    do
    {
     if((it.fileInfo().isFile() == true)  && (regex_match(it.fileInfo().absoluteFilePath().toStdString(),e,exp)))
          for(auto a:e){
              bilder.push_back(a);
          }
      it.next();                 // nächste Datei bzw. Ordner
    } while( it.hasNext() );     // Schleife läuft solange Dateien oder Ordner im Verzeichnis sind
    return bilder;
}

QString MainWindow::ausgewaehlterOrdnern(){

    int index; //Hilfsvarable zur Speicherung des letzen Slashes (/)
    QString filename = QFileDialog::getOpenFileName(            //Pfad zum Bild innerhalb des gewünschten Ordners wird gespeichert
            this,
            tr("Bilderordner"),      // Titel des Fensters
            "C://Users/Christopher", //Startverzeichnis, welches angegeben wird
            tr("All Files(*.*);;JPG Files(*.jpg);;PNG Files(*.png);; TIFF Files (*.tiff);; GIF Files(*.gif)")); // Möglichkeiten zur Filterung
    string path = filename.toStdString();

    for(unsigned int i = 0; i <path.size(); i++){       //geht String durch und sucht nach letztem Slash
        if(path.at(i) == '/'){
            index = i;      //speichert den Index des letzten gefundenen Slashes
        }
        else{
            continue;
        }
    }
    path.resize(index);     //kürzt den Pfad bis zu diesem Slash
    QString pfad = QString::fromStdString(path);
    return pfad;
}

