#include "zweitesfenster.h"
#include "hilfe.h"

zweitesFenster::zweitesFenster(QWidget *fenster, QTranslator *translator, Datenbank *bank, QWidget *parent) : QWidget(parent)
{
    m_translator = translator;
    m_bank = bank;
    m_bilderAnzahl = 20;
    this->fenster = fenster;
    ganzesWindow = new QVBoxLayout;
    oberesWindow = new QGridLayout;
    west = new QVBoxLayout;
    center = new QVBoxLayout;
    menu = new QVBoxLayout;
    westpart = new QWidget;
    east = new QVBoxLayout;
    south = new QHBoxLayout;
    southpart = new QWidget;
    tagsFeld = new QLineEdit;
    bildBewertungsFeld = new QComboBox;
    bildPfadFeld = new QLineEdit;

    option = new QLabel("Optionen");
    hintergrund = new QLabel("Hintergrund");
    anzahlBilder = new QLabel("Bildergröße");
    zwanzig = new QPushButton;
    vierzig = new QPushButton;
    sechsig = new QPushButton;
    vollbild = new QLabel("Vollbildmodus");
    vollbildmodus = new QPushButton("X");
    sprache = new QLabel("Sprache");
    deutsch = new QPushButton;
    englisch = new QPushButton;
    filter = new QLabel("Filter");
    schwarz = new QPushButton();
    weiss = new QPushButton();
    beige = new QPushButton();
    rose = new QPushButton();
    filtern = new QLineEdit;
    sterne = new QHBoxLayout;
    eins = new QPushButton;
    zwei = new QPushButton;
    drei = new QPushButton;
    vier = new QPushButton;
    fuenf = new QPushButton;
    filterAufloesen = new QPushButton;
    hilfe = new QPushButton;
    filteraktivieren = new QPushButton;
    umgewandelteBilder = new std::map<string, QImage*>;
    gefilterteBilder = new vector<string>;
    menu2 = new QVBoxLayout();
    vollbildModusDeaktiviern = new QPushButton;
    menu3 = new QHBoxLayout;
    farben = new QGridLayout();
    farb = new QGridLayout();
    farbenWidget = new QWidget();
    bilder = new QGridLayout();
    bild = new QGridLayout();
    language = new QHBoxLayout;
    sprachen = new QVBoxLayout;
    sprachenWidget = new QWidget;
    filt = new QGridLayout();
    filterWidget = new QWidget();
    bilderWidget = new QWidget();
    tags = new QLabel("Tags:");
    bildBewertung = new QLabel("Sterne:");
    bildPfad = new QLabel("Pfad:");

    f = new Farben(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                   vollbildmodus, option, zwanzig, vierzig, sechsig,sprache, tags,
                   bildBewertung, bildPfad, tagsFeld, bildBewertungsFeld, bildPfadFeld,
                   filtern, vollbildmodus);
    setzeSignals();
    labelStil();
    buttonsStil();
    fensterStil();
    optionsleisteDarstellen();
    informationsleisteDarstellen();
}

zweitesFenster::~zweitesFenster(){

    delete (fenster);
    delete (m_bank);
    delete (ganzesWindow);
    delete (oberesWindow);
    delete (west);
    delete (center);
    delete (menu);
    delete (westpart);
    delete (east);
    delete (south);
    delete (southpart);

    delete (tags);
    delete (bildBewertung);
    delete (bildPfad);
    delete (tagsFeld);
    delete (bildBewertungsFeld);
    delete (bildPfadFeld);

    delete (option);
    delete (hintergrund);
    delete (anzahlBilder);
    delete (zwanzig);
    delete (vierzig);
    delete (sechsig);
    delete (vollbild);
    delete (vollbildmodus);
    delete (vollbildModusDeaktiviern);
    delete (sprache);
    delete (deutsch);
    delete (englisch);
    delete (filter);
    delete (filterAufloesen);
    delete (filtern);

    delete (suche);
    delete (m_translator);
    delete (beenden);

    delete (schwarz);
    delete (weiss);
    delete (beige);
    delete (rose);

    delete (farben);
    delete (farb);
    delete (farbenWidget);

    delete (bilder);
    delete (bild);
    delete (bilderWidget);

    delete (vollWidget);
    delete (filteraktivieren);
    delete (filt);
    delete (filterWidget);

    delete (sterne);
    delete (eins);
    delete (zwei);
    delete (drei);
    delete (vier);
    delete (fuenf);
    delete (hilfe);
    delete (menu2);

    delete (language);
    delete (sprachen);
    delete (sprachenWidget);
    delete (l);
    delete (information);
    delete (gefilterteBilder);
    delete (umgewandelteBilder);
    delete (menu3);
    delete (f);
}

void zweitesFenster::informationsleisteDarstellen(){
    south->addWidget(bildBewertung);
    bildBewertungsFeld->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
    bildBewertungsFeld->setMinimumContentsLength(25);
    south->addWidget(bildBewertungsFeld);
    south->addWidget(tags);
    south->addWidget(tagsFeld);
    tagsFeld->clear();
    south->addWidget(bildPfad);
    south->addWidget(bildPfadFeld);
    southpart->setLayout(south);
}

void zweitesFenster::optionsleisteDarstellen()
{

    menu3->addWidget(option,0, Qt::AlignRight | Qt::AlignTop);
    menu3->addWidget(vollbildmodus,0, Qt::AlignRight | Qt::AlignTop);

    farb->addWidget(schwarz,0,0);
    farb->addWidget(weiss,0,1);
    farb->addWidget(beige,0,2);
    farb->addWidget(rose,0,3);
    farben->addWidget(hintergrund,0,0);
    farben->addLayout(farb,1,0);
    farbenWidget->setLayout(farben);

    bild->addWidget(zwanzig,1,0);
    bild->addWidget(vierzig,1,1);
    bild->addWidget(sechsig,1,2);
    bilder->addWidget(anzahlBilder,0,0);
    bilder->addLayout(bild,1,0);
    bilderWidget->setLayout(bilder);

    language->addWidget(deutsch);

    language->addWidget(englisch);
    sprachen->addWidget(sprache);
    sprachen->addLayout(language);
    sprachenWidget->setLayout(sprachen);

    filt->addWidget(filter,0,0);
    filt->addWidget(filtern,2,0);
    filt->addWidget(filteraktivieren,2,2);
    filterWidget->setLayout(filt);

    sterne->addWidget(eins);
    sterne->addWidget(zwei);
    sterne->addWidget(drei);
    sterne->addWidget(vier);
    sterne->addWidget(fuenf);
    sterne->addWidget(filterAufloesen);
    filt->addLayout(sterne,3,0);

    menu->addLayout(menu3);
    menu->addWidget(farbenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(bilderWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(sprachenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(filterWidget, 0, Qt::AlignLeft | Qt::AlignTop);

    menu->insertStretch(300,30);
    menu->addLayout(menu2);
    menu2->addWidget(hilfe, 0, Qt::AlignLeft | Qt::AlignVCenter);


    westpart->setLayout(menu);
    west->addWidget(westpart);
    oberesWindow->addWidget(westpart);
}

void zweitesFenster::erzeugeNeueGalerie()
{
    QString gewuenschterPfad = ordnerVerzeichnis();
    suche = new BilderSuche(gewuenschterPfad, m_bilderAnzahl, m_bank);
    suche->start();
    QObject::connect(suche,&BilderSuche::sucheBeenden,this, &zweitesFenster::BilderDarstellen);
    QObject::connect(suche,&BilderSuche::finished, suche, &BilderSuche::deleteLater);
}

void zweitesFenster::erzeugeLetzteGalerie()
{
    (*gefilterteBilder) = m_bank->getAlleBilder_dargestelltTrue();
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

QString zweitesFenster::ordnerVerzeichnis()
{
    int index; //Hilfsvarable zur Speicherung des letzen Slashes (/)
    QString filename = QFileDialog::getOpenFileName(            //Pfad zum Bild innerhalb des gewünschten Ordners wird gespeichert
        this,
        tr("Bilderordner"),      // Titel des Fensters
        "C://Users", //Startverzeichnis, welches angegeben wird
        tr("JPG Dateien(*.jpg)")); // Möglichkeiten zur Filterung
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

void zweitesFenster::bildtagsAendern()
{
    //cout << pfad << endl;
    int id = m_bank->getID(pfad);
    m_bank->bildtagsAendern(id,tagsFeld->text());
}

void zweitesFenster::bildBewertungAendern()
{
    int wert = bildBewertungsFeld->currentIndex();
    //cout << wert << endl;
    //cout << pfad << endl;
    int id = m_bank->getID(pfad);
    m_bank->bildBewerten(id,wert);
}

void zweitesFenster::BilderDarstellen(map<string, QImage*> *qimages)
{
    m_mainLayout = new QVBoxLayout;
    m_area = new QScrollArea;
    contents = new QWidget;
    layout = new QVBoxLayout(contents);
    center1 = new QHBoxLayout;

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    m_area->setWidget(contents);
    int index = 0;
    map<string,QImage*>::iterator bilderDurchgehen;

    for(bilderDurchgehen = qimages->begin(); bilderDurchgehen != qimages->end(); bilderDurchgehen++){
        l = new MyLabel(bilderDurchgehen->first, m_bank);
        l->setAlignment(Qt::AlignBottom);
        QObject::connect(l,&MyLabel::pfadNutzen,this, &zweitesFenster::setPfad);
        QObject::connect(l,&MyLabel::tagsAnzeigen,this, &zweitesFenster::tagsInInfoleisteAnzeige);
        QObject::connect(l,&MyLabel::bewertungAnzeigen,this, &zweitesFenster::bewertungInInfoleisteAnzeige);
        QObject::connect(l,&MyLabel::diahow,this, &zweitesFenster::openThirdWindow);

        l->setPixmap(QPixmap::fromImage(*(bilderDurchgehen->second)));
        index = index + 1;
        center1->addWidget(l);

        if(m_bilderAnzahl == 20 && index % 5 == 0){
            center1 = new QHBoxLayout;
            layout->addLayout(center1);
        }
        else if(m_bilderAnzahl == 40 && index % 10 == 0){
            center1 = new QHBoxLayout;
            layout->addLayout(center1);
        }
        if(m_bilderAnzahl == 60 && index % 15 == 0){
            center1 = new QHBoxLayout;
            layout->addLayout(center1);
        }
    }

    m_area->verticalScrollBarPolicy();
    m_mainLayout->addWidget(m_area);
    layout->addLayout(center1);

    oberesWindow->addWidget(westpart,0,0,0,1);
    oberesWindow->addWidget(m_area,0,1,1,4);

    ganzesWindow->addLayout(oberesWindow);
    ganzesWindow->addWidget(southpart);
    this->setLayout(ganzesWindow);
}

void zweitesFenster::schwarzFunktion()
{
    f->schwarz();
}

void zweitesFenster::beigeFunktion()
{
    f->beige();
}

void zweitesFenster::weissFunktion()
{
    f->weiss();
}

void zweitesFenster::pinkFunktion()
{
    f->pink();
}

void zweitesFenster::hilfeAngeklicket()
{
    Hilfe hilf;
    hilf.hilfeAnzeigenZweitesFenster();
}

/*void zweitesFenster::englischUebersetzung()
{
    QApplication::instance()->removeTranslator(m_translator);
}

void zweitesFenster::deutschUebersetzung()
{
    QApplication::instance()->removeTranslator(m_translator);

    if (m_translator->load(":/language/VON_Englisch_zu_Deutsch.qm"))

    {
    qDebug() << "LOAD FINISHED";

    QApplication::instance()->installTranslator(m_translator);
    }
}*/

void zweitesFenster::vollbildModusAktiv()
{
    m_bilderAnzahl = 10;
    erzeugeLetzteGalerie();
    vollbildModusDeaktiviern->setHidden(false);
    south->addWidget(vollbildModusDeaktiviern);
    westpart->setHidden(true);
    fenster->update();
}

void zweitesFenster::vollbildModusInaktiv()
{   
    m_bilderAnzahl = 20;
    erzeugeLetzteGalerie();
    westpart->setHidden(false);
    vollbildModusDeaktiviern->setHidden(true);
    fenster->update();
}

void zweitesFenster::nachEinsFiltern()
{
    int bewertung = 1;
    bewerteteBilder(bewertung);
}

void zweitesFenster::nachZweiFiltern()
{
    int bewertung = 2;
    bewerteteBilder(bewertung);
}

void zweitesFenster::nachDreiFiltern()
{
    int bewertung = 3;
    bewerteteBilder(bewertung);
}

void zweitesFenster::nachVierFiltern()
{
    int bewertung = 4;
    bewerteteBilder(bewertung);
}

void zweitesFenster::nachFuenfFiltern()
{
    int bewertung = 5;
    bewerteteBilder(bewertung);
}

void zweitesFenster::nachTagFiltern(QString tag)
{
    if(gefilterteBilder->empty() == true){
        information = new QMessageBox();
        QString text = (tr("<h1>Achtung!</h1>"
                       "Es existieren keine Bilder mit dem eingegebenen Tags."));

        information->setIcon(QMessageBox::Information); //setzt das Icon, welches das Hauptfenster auch hat
        QMessageBox::information(this,"Hilfe",text);
    }
    else{
        fenster->layout()->deleteLater();
        (*gefilterteBilder) = m_bank->bildtagsFiltern(tag);
        (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
        BilderDarstellen(umgewandelteBilder);
    }
}

void zweitesFenster::zwanzigBilder(){
    fenster->layout()->deleteLater();
    m_bilderAnzahl = 20;
    erzeugeLetzteGalerie();
}

void zweitesFenster::vierzigBilder(){
    fenster->layout()->deleteLater();
    m_bilderAnzahl = 40;
    erzeugeLetzteGalerie();
}

void zweitesFenster::sechsigBilder(){
    fenster->layout()->deleteLater();
    m_bilderAnzahl = 60;
    erzeugeLetzteGalerie();
}

void zweitesFenster::setPfad(string pfad)
{
    this->pfad = pfad;
    bildPfadFeld->setText(QString::fromStdString(pfad));
}

void zweitesFenster::tagsInInfoleisteAnzeige(QString tags)
{
    tagsFeld->setText(tags);
}

void zweitesFenster::bewertungInInfoleisteAnzeige(int bewertung)
{
    bildBewertungsFeld->setCurrentIndex(bewertung);
}

void zweitesFenster::ungefiltert()
{
    (*gefilterteBilder) = m_bank->getAlleBilder_dargestelltMemory();
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::bewerteteBilder(int &bewertung)
{
    fenster->layout()->deleteLater();
    (*gefilterteBilder) = m_bank->bewertungFiltern(bewertung);
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::fensterStil()
{
    bildPfadFeld->setStyleSheet("background-color: rgb(209,209,209); width: 100px; ");
    bildPfadFeld->setReadOnly(true);
    bildPfadFeld->setAlignment(Qt::AlignLeft);
    south->minimumSize();

    fenster->setStyleSheet("background-color:white;");
    westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
    vollbildmodus->setStyleSheet("border: none; margin: 0px; padding: 0px; background-color: tomato; width: 30px; height: 30px;");

    filtern->setStyleSheet("background-color: white;");

}

void zweitesFenster::labelStil()
{
    QFont font1( "Calibri", 20, QFont::Bold);
    option->setFont(font1);

    QFont font2( "Calibri", 10, QFont::Bold);
    hintergrund->setFont(font2);

    QFont font3( "Calibri", 10, QFont::Bold);
    anzahlBilder->setFont(font3);

    QFont font5( "Calibri", 10, QFont::Bold);
    sprache->setFont(font5);
    deutsch->setChecked(true);

    QFont font6( "Calibri", 10, QFont::Bold);
    filter->setFont(font6);
}

void zweitesFenster::buttonsStil()
{
    /* Hintergrundfarbe bestimmen */
    schwarz->setStyleSheet("background-color:black; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    weiss->setStyleSheet("background-color:white; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    beige->setStyleSheet("background-color:beige; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    rose->setStyleSheet("background-color:pink; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");

    /* Bildergroesse bestimmen*/
    zwanzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 60px; height: 60px;");
    vierzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 40px; height: 40px;");
    sechsig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 20px; height: 20px;");


    /**********************Sprache**************************************/
    /*Sprache zu deutsch aendern*/
    QPixmap pixmap4(":/icon/deutsch.jpg");
    QIcon buttonIcon4(pixmap4);
    deutsch->setIcon(buttonIcon4);
    deutsch->setIconSize(QSize(50, 25));
    deutsch->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Sprache zu Englisch aendern*/
    QPixmap pixmap5(":/icon/englisch.jpg");
    QIcon buttonIcon5(pixmap5);
    englisch->setIcon(buttonIcon5);
    englisch->setIconSize(QSize(50, 25));
    englisch->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    /******************************************************************/

    /**********************Filter**************************************/
    /* Tags suchen*/
    tagsFeld->setText("Bitte gesuchte Tags eintragen");

    /* Filter aktivieren */
    QPixmap pixmap3(":/icon/trichter.tif");
    QIcon buttonIcon3(pixmap3);
    filteraktivieren->setIcon(buttonIcon3);
    filteraktivieren->setIconSize(QSize(50, 25));
    filteraktivieren->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 1*/
    QPixmap pixmap6(":/icon/eins.tif");
    QIcon buttonIcon6(pixmap6);
    eins->setIcon(buttonIcon6);
    eins->setIconSize(QSize(50, 50));
    eins->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 2*/
    QPixmap pixmap7(":/icon/zwei.tif");
    QIcon buttonIcon7(pixmap7);
    zwei->setIcon(buttonIcon7);
    zwei->setIconSize(QSize(50, 50));
    zwei->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 3*/
    QPixmap pixmap8(":/icon/drei.tif");
    QIcon buttonIcon8(pixmap8);
    drei->setIcon(buttonIcon8);
    drei->setIconSize(QSize(50, 50));
    drei->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 4*/
    QPixmap pixmap9(":/icon/vier.tif");
    QIcon buttonIcon9(pixmap9);
    vier->setIcon(buttonIcon9);
    vier->setIconSize(QSize(50, 50));
    vier->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Bewertung: 5*/
    QPixmap pixmap10(":/icon/fuenf.tif");
    QIcon buttonIcon10(pixmap10);
    fuenf->setIcon(buttonIcon10);
    fuenf->setIconSize(QSize(50, 50));
    fuenf->setStyleSheet("border: none; margin: 0px; padding: 0px;");

    /* Filter zuruecksetzen*/
    QPixmap pixmap11(":/icon/back_Transparent.tif");
    QIcon buttonIcon11(pixmap11);
    filterAufloesen->setIcon(buttonIcon11);
    filterAufloesen->setStyleSheet("border: none; margin: 0px;padding: 0px;");
    filterAufloesen->setIconSize(QSize(50,50));
    /********************************************************************/

    /* Vollbildmodus deaktivieren */
    QPixmap pixmap2(":/icon/back_Transparent_schwarz.tif");
    QIcon buttonIcon2(pixmap2);
    vollbildModusDeaktiviern->setIcon(buttonIcon2);
    vollbildModusDeaktiviern->setIconSize(QSize(50, 50));
    vollbildModusDeaktiviern->setStyleSheet("border: none; margin-bottom: 0px;padding: 0px;");

    /* Bilder Bewerten*/
    bildBewertungsFeld->addItem("");
    bildBewertungsFeld->addItem("1");
    bildBewertungsFeld->addItem("2");
    bildBewertungsFeld->addItem("3");
    bildBewertungsFeld->addItem("4");
    bildBewertungsFeld->addItem("5");

    /*Hilfebutton*/
    QPixmap pixmap1(":/icon/Fragezeichen.tif");
    QIcon buttonIcon1(pixmap1);
    hilfe->setIcon(buttonIcon1);
    hilfe->setIconSize(QSize(50, 50));
    hilfe->setStyleSheet("border: none; margin-bottom: 0px;padding: 0px;");
}

void zweitesFenster::setzeSignals()
{
    QObject::connect(schwarz, &QPushButton::clicked,this, &zweitesFenster::schwarzFunktion);
    QObject::connect(weiss, &QPushButton::clicked,this, &zweitesFenster::weissFunktion);
    QObject::connect(beige, &QPushButton::clicked,this, &zweitesFenster::beigeFunktion);
    QObject::connect(rose, &QPushButton::clicked,this, &zweitesFenster::pinkFunktion);
    QObject::connect(filtern, &QLineEdit::textEdited,this, &zweitesFenster::nachTagFiltern);
    QObject::connect(eins, &QPushButton::clicked,this, &zweitesFenster::nachEinsFiltern);
    QObject::connect(zwei, &QPushButton::clicked,this, &zweitesFenster::nachZweiFiltern);
    QObject::connect(drei, &QPushButton::clicked,this, &zweitesFenster::nachDreiFiltern);
    QObject::connect(vier, &QPushButton::clicked,this, &zweitesFenster::nachVierFiltern);
    QObject::connect(fuenf, &QPushButton::clicked,this, &zweitesFenster::nachFuenfFiltern);
    QObject::connect(filterAufloesen, &QPushButton::clicked,this, &zweitesFenster::ungefiltert);
    QObject::connect(hilfe, &QPushButton::clicked,this, &zweitesFenster::hilfeAngeklicket);
    QObject::connect(tagsFeld, &QLineEdit::editingFinished,this, &zweitesFenster::bildtagsAendern);// BildID muss als erster Parameter übergeben werden
    QObject::connect(bildBewertungsFeld, static_cast<void (QComboBox::*)(const int)>(&QComboBox::currentIndexChanged),this, &zweitesFenster::bildBewertungAendern);// BildID muss als erster Parameter übergeben werden
    QObject::connect(vollbildmodus, &QRadioButton::clicked,this, &zweitesFenster::vollbildModusAktiv);
    QObject::connect(zwanzig, &QPushButton::clicked,this, &zweitesFenster::zwanzigBilder);
    QObject::connect(vierzig, &QPushButton::clicked,this, &zweitesFenster::vierzigBilder);
    QObject::connect(sechsig, &QPushButton::clicked,this, &zweitesFenster::sechsigBilder);
    QObject::connect(deutsch, &QRadioButton::clicked,this, &zweitesFenster::deutschUebersetzung);
    QObject::connect(englisch, &QRadioButton::clicked,this, &zweitesFenster::englischUebersetzung);
    QObject::connect(vollbildModusDeaktiviern, &QPushButton::clicked,this, &zweitesFenster::vollbildModusInaktiv);

}
