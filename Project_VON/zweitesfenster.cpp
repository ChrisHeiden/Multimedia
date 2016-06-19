#include "zweitesfenster.h"

zweitesFenster::zweitesFenster(QWidget *fenster, QTranslator *translator, QWidget *parent) : QWidget(parent)
{
    m_translator = translator;
    this->fenster = fenster;
}

void zweitesFenster::erzeugeZweitesFenster(){

    QFont font1( "Calibri", 20, QFont::Bold);
    option->setFont(font1);
    option->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    option->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);


    /*Hintergrundfarben mit ihrem Label Hintergrund */
    QFont font2( "Calibri", 10, QFont::Bold);
    hintergrund->setFont(font2);


    QPushButton *schwarz = new QPushButton();
    schwarz->setStyleSheet("background-color:black; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(schwarz, &QPushButton::clicked,this, &zweitesFenster::schwarz);
    QPushButton *weiss = new QPushButton();
    weiss->setStyleSheet("background-color:white; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(weiss, &QPushButton::clicked,this, &zweitesFenster::weiss);
    QPushButton *beige = new QPushButton();
    beige->setStyleSheet("background-color:beige; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(beige, &QPushButton::clicked,this, &zweitesFenster::beige);
    QPushButton *rose = new QPushButton();
    rose->setStyleSheet("background-color:pink; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(rose, &QPushButton::clicked,this, &zweitesFenster::pink);
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
    zwanzig->setStyleSheet("background-color:grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    vierzig->setStyleSheet("background-color:grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    sechsig->setStyleSheet("background-color:grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");


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
    //QObject::connect(vollbildmodus, &QRadioButton::clicked,this, &erstesFenster::vollbildModusAktiv);
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
    QObject::connect(deutsch, &QRadioButton::clicked,this, &zweitesFenster::deutschUebersetzung);
    QObject::connect(englisch, &QRadioButton::clicked,this, &zweitesFenster::englischUebersetzung);
    deutsch->setChecked(true);
    language->addWidget(englisch);
    sprachen->addWidget(sprache);
    sprachen->addLayout(language);
    sprachenWidget->setLayout(sprachen);


    /*Filter zur Behandlung ihrer Bildermenge + Label Filter*/
    QFont font6( "Calibri", 10, QFont::Bold);
    filter->setFont(font6);
    QLineEdit *filtern = new QLineEdit();
    QPushButton *filteraktivieren = new QPushButton("Filtern");
    filteraktivieren->setStyleSheet("background-color:grey ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    QGridLayout *filt = new QGridLayout();
    filt->addWidget(filter,0,0);
    filt->addWidget(filtern,2,0);
    filt->addWidget(filteraktivieren,2,2);
    QWidget *filterWidget = new QWidget();
    filterWidget->setLayout(filt);

    QHBoxLayout *sterne = new QHBoxLayout;
    QPushButton *eins = new QPushButton;
    eins->setText("1");
    eins->setStyleSheet("background-color:red ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(eins, &QPushButton::clicked,this, ...);

    QPushButton *zwei = new QPushButton;
    zwei->setText("2");
    zwei->setStyleSheet("background-color:orange ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(zwei, &QPushButton::clicked,this, ...);

    QPushButton *drei = new QPushButton;
    drei->setText("3");
    drei->setStyleSheet("background-color:yellow ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(drei, &QPushButton::clicked,this, ...);

    QPushButton *vier = new QPushButton;
    vier->setText("4");
    vier->setStyleSheet("background-color:blue ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(vier, &QPushButton::clicked,this, ...);

    QPushButton *fuenf = new QPushButton;
    fuenf->setText("5");
    fuenf->setStyleSheet("background-color:green ; border: none; margin: 0px;padding: 0px; width: 40px; height: 25px;");
    //QObject::connect(fuenf, &QPushButton::clicked,this, ...);

    sterne->addWidget(eins);
    sterne->addWidget(zwei);
    sterne->addWidget(drei);
    sterne->addWidget(vier);
    sterne->addWidget(fuenf);

    filt->addLayout(sterne,3,0);

    menu->addWidget(option);
    menu->addWidget(farbenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(bilderWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(vollWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(sprachenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(filterWidget, 0, Qt::AlignLeft | Qt::AlignTop);

    /*Hilfe Button*/
    QPushButton *hilfe = new QPushButton("Hilfe");
    QFont font7( "Calibri", 10, QFont::Bold);
    hilfe->setFont(font7);
    hilfe->setStyleSheet("background-color:grey ; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(hilfe, &QPushButton::clicked,this, &zweitesFenster::hilfeAngeklicket);
    menu->addWidget(hilfe, 0, Qt::AlignLeft | Qt::AlignTop);

    QVBoxLayout *menu2 = new QVBoxLayout();
    menu->insertStretch(300,30);
    menu->addLayout(menu2);

    fenster->setStyleSheet("background-color:white;");
    westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
    westpart->setLayout(menu);
    west->addWidget(westpart);
    window->addWidget(westpart);

    south->addWidget(vollbildModusDeaktiviern);
    south->insertStretch(30,300);
    southpart->setStyleSheet("background-color:red;");
    southpart->setLayout(south);


    /*Center muss hier programmiert werden*/

    QString gewuenschterPfad = ordnerVerzeichnis(); // gewünschter Ordnerpfad wird gespeichert
    suche = new BilderSuche(gewuenschterPfad);
    suche->start();
    QObject::connect(suche,&BilderSuche::sucheBeenden,this, &zweitesFenster::BilderDarstellen);
    QObject::connect(suche,&BilderSuche::finished, suche, &BilderSuche::deleteLater);

}

QString zweitesFenster::ordnerVerzeichnis(){
    int index; //Hilfsvarable zur Speicherung des letzen Slashes (/)
    QString filename = QFileDialog::getOpenFileName(            //Pfad zum Bild innerhalb des gewünschten Ordners wird gespeichert
        this,
        tr("Bilderordner"),      // Titel des Fensters
        "C://Users", //Startverzeichnis, welches angegeben wird
        tr("Alle Dateien(*.*);;JPG Dateien(*.jpg);;PNG Dateien(*.png);; TIFF Dateien (*.tiff);; GIF Dateien(*.gif)")); // Möglichkeiten zur Filterung
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

void zweitesFenster::letzter(){
    std::cout << 3 << std::endl;

}

void zweitesFenster::BilderDarstellen(vector<QImage*> *qimages){


    QVBoxLayout *m_mainLayout = new QVBoxLayout;
    QScrollArea *m_area = new QScrollArea;
    m_area->verticalScrollBarPolicy();

    m_mainLayout->addWidget(m_area);
    QWidget *contents = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(contents);
    QHBoxLayout *center1 = new QHBoxLayout;
    layout->addLayout(center1);
    int index = 0;

    for (unsigned int y = 0; y < qimages->size() ; y++) {
        //for(unsigned int x = 0; x < 5; x++){
            /* Funktioniert nicht */
            QLabel *l = new QLabel();
            l->setPixmap(QPixmap::fromImage(*(qimages->at(y))));
            index = index + 1;
            center1->addWidget(l);
            if(index % 5 == 0){
                center1 = new QHBoxLayout;
                layout->addLayout(center1);
            }
    }

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    m_area->setWidget(contents);

    /*Layouts dem Widget hinzufügen*/

    window->addWidget(westpart,0,0,0,1);
    window->addWidget(m_area,0,1,1,4);


    //fenster->update();
    cout << "1" << endl;

    this->setLayout(window);
}

void zweitesFenster::schwarz(){
    Farben schwarz(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                    vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                    deutsch,  englisch,  vollbildModusDeaktiviern);
    schwarz.schwarz();
}

void zweitesFenster::beige(){
    Farben beige(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                    vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                    deutsch,  englisch,  vollbildModusDeaktiviern);    beige.beige();
}

void zweitesFenster::weiss(){
    Farben weiss(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                    vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                    deutsch,  englisch,  vollbildModusDeaktiviern);    weiss.weiss();
}

void zweitesFenster::pink(){
    Farben pink(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                    vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                    deutsch,  englisch,  vollbildModusDeaktiviern);    pink.pink();
}

void zweitesFenster::hilfeAngeklicket(){
   // Hilfe hilf(fenster);
   // hilf.hilfeAnzeigen();
    QMessageBox *information = new QMessageBox();

    QString text = (tr("<h1>Hilfe</h1>"

                   "<h2>Hintergrundfarbe ändern</h2>"
                   "<br>Um die Hintergrundfarbe zu ändern müssen "
                   "sie eine einen der Buttons drücken, welche "
                   "unter dem Textfeld Hintergrund angklicken. "
                   "Dadurch verändert sich die Hintergrundfarbe,"
                   " die Farbe der Schrift und die Farbe der Menuleiste."
                   "Standart ist die Farbe weiß."

                   "<h2>Anzahl Bilder</h2>"
                   "<br>Um die Anzahl der angezeigten Bilder zu bestimmen, "
                   "müssen sie auf einen der Buttons drücken, die unter dem"
                   "Textfeld Anzahl Bilder angezeigt werden. Zur Auswahl stehen"
                   "20 Bilder, 40 Bilder und 60 Bilder. Standartgemäß werden "
                   "20 Bilder angezeigt."

                   "<h2>Vollbildmodus</h2>"
                   "<br>Damit die Menuleiste verschindet und man somit mehr Platz"
                   "für das Anzeigen der Bild hat, kann man den Vollbildmodus aktivieren "
                   "Um aus diesem Modus wieder rauszukommen, muss der Button Vollbildmodus"
                   "deaktivieren angeklicket werden."

                   "<h2>Sprache</h2>"
                   "<br>Um die Sprache zu Ändern, muss man die Button für Deutsch oder Englisch"
                   "anglicken. Standart ist die deutsche Sprache."

                   "<h2>Filter</h2>"
                   "<br>Um die Bilder nach etwas bestimmten zu Filtern, kann man entweder die"
                   "Bewertung des Bildes angegeben, woduch nur die Bilder angezeigt werden, die "
                   "solch einer Bewertung entsprechen oder man Filtern nach Themen oder Tags.</p>"

                   "<h2>Hilfe</h2>"
                   "<br>Der Button für Hilfe erzeugt eine neues Fenster, welches alle Funktionen "
                   "der Applikation anzeigt."));

    information->setIcon(QMessageBox::Information); //setzt das Icon, welches das Hauptfenster auch hat
    QMessageBox::information(this,"Hilfe",text);
}

void zweitesFenster::englischUebersetzung(){
    QApplication::instance()->removeTranslator(m_translator);

     if (m_translator->load(":/language/VON_Ueberstzung_Deutsch_zu_Englisch.qm"))

     {
     qDebug() << "LOAD FINISHED";

     QApplication::instance()->installTranslator(m_translator);
     }
}

void zweitesFenster::deutschUebersetzung(){
    QApplication::instance()->removeTranslator(m_translator);
    qDebug() << "1";
}
