#include "zweitesfenster.h"

zweitesFenster::zweitesFenster(QWidget *fenster, QTranslator *translator, Datenbank *bank, QWidget *parent) : QWidget(parent)
{
    m_translator = translator;
    m_bank = bank;
    m_bilderAnzahl = 20;
    this->fenster = fenster;
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
    delete (tagsFeld );
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

}

void zweitesFenster::erzeugeZweitesFenster(){

    optionsleisteDarstellen();

    /* Center muss hier programmiert werden */
    QString gewuenschterPfad = ordnerVerzeichnis(); // gewünschter Ordnerpfad wird gespeichert
    suche = new BilderSuche(gewuenschterPfad, m_bilderAnzahl, m_bank);
    suche->start();
    QObject::connect(suche,&BilderSuche::sucheBeenden,this, &zweitesFenster::BilderDarstellen);
    QObject::connect(suche,&BilderSuche::finished, suche, &BilderSuche::deleteLater);

}

void zweitesFenster::optionsleisteDarstellen(){


    QHBoxLayout *menu3 = new QHBoxLayout;
    vollbildmodus->setStyleSheet("border: none; margin: 0px; padding: 0px; background-color: tomato; width: 30px; height: 25px;"); //farbe noch ändern
    QObject::connect(vollbildmodus, &QRadioButton::clicked,this, &zweitesFenster::vollbildModusAktiv);
    //menu3->addWidget(vollbildmodus,0, Qt::AlignRight);

    QFont font1( "Calibri", 20, QFont::Bold);
    option->setFont(font1);
    menu3->addWidget(option,0, Qt::AlignRight | Qt::AlignTop);
    menu3->addWidget(vollbildmodus,0, Qt::AlignRight | Qt::AlignTop);

    /*Hintergrundfarben mit ihrem Label Hintergrund */
    QFont font2( "Calibri", 10, QFont::Bold);
    hintergrund->setFont(font2);


    schwarz = new QPushButton();
    schwarz->setStyleSheet("background-color:black; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(schwarz, &QPushButton::clicked,this, &zweitesFenster::schwarzFunktion);
    weiss = new QPushButton();
    weiss->setStyleSheet("background-color:white; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(weiss, &QPushButton::clicked,this, &zweitesFenster::weissFunktion);
    beige = new QPushButton();
    beige->setStyleSheet("background-color:beige; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(beige, &QPushButton::clicked,this, &zweitesFenster::beigeFunktion);
    rose = new QPushButton();
    rose->setStyleSheet("background-color:pink; border: none; margin: 0px;padding: 0px; width: 30px; height: 25px;");
    QObject::connect(rose, &QPushButton::clicked,this, &zweitesFenster::pinkFunktion);
    farben = new QGridLayout();
    farb = new QGridLayout();
    farbenWidget = new QWidget();
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
    zwanzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 60px; height: 60px;");
    vierzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 40px; height: 40px;");
    sechsig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 20px; height: 20px;");
    QObject::connect(zwanzig, &QPushButton::clicked,this, &zweitesFenster::zwanzigBilder);
    QObject::connect(vierzig, &QPushButton::clicked,this, &zweitesFenster::vierzigBilder);
    QObject::connect(sechsig, &QPushButton::clicked,this, &zweitesFenster::sechsigBilder);


    bilder = new QGridLayout();
    bild = new QGridLayout();
    bild->addWidget(zwanzig,1,0);
    bild->addWidget(vierzig,1,1);
    bild->addWidget(sechsig,1,2);
    bilder->addWidget(anzahlBilder,0,0);
    bilder->addLayout(bild,1,0);
    bilderWidget = new QWidget();
    bilderWidget->setLayout(bilder);


    /*Einstellung des Vollbildmoduses mit dem Label*/
    vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(189, 195, 199); color: black; border: none; margin: 0px;padding: 0px; width: 150px; height: 50px;");


    QFont font5( "Calibri", 10, QFont::Bold);
    sprache->setFont(font5);
    language = new QHBoxLayout;
    sprachen = new QVBoxLayout;
    sprachenWidget = new QWidget;
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
    filtern = new QLineEdit;
    filtern->setStyleSheet("background-color:white, color: black");
    /* zu testzwecken */
    QObject::connect(filtern, &QLineEdit::textEdited,this, &zweitesFenster::nachTagFiltern);


    filteraktivieren = new QPushButton;
    QPixmap pixmap2(":/icon/trichter.tif");
    QIcon buttonIcon2(pixmap2);
    filteraktivieren->setIcon(buttonIcon2);
    filteraktivieren->setIconSize(QSize(50, 25));
    filteraktivieren->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    filt = new QGridLayout();
    filt->addWidget(filter,0,0);
    filt->addWidget(filtern,2,0);
    filt->addWidget(filteraktivieren,2,2);
    filterWidget = new QWidget();
    filterWidget->setLayout(filt);

    sterne = new QHBoxLayout;
    eins = new QPushButton;

    QPixmap pixmap3(":/icon/eins.tif");
    QIcon buttonIcon3(pixmap3);
    eins->setIcon(buttonIcon3);
    eins->setIconSize(QSize(50, 50));
    eins->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    QObject::connect(eins, &QPushButton::clicked,this, &zweitesFenster::nachEinsFiltern);

    zwei = new QPushButton;
    QPixmap pixmap4(":/icon/zwei.tif");
    QIcon buttonIcon4(pixmap4);
    zwei->setIcon(buttonIcon4);
    zwei->setIconSize(QSize(50, 50));
    zwei->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    QObject::connect(zwei, &QPushButton::clicked,this, &zweitesFenster::nachZweiFiltern);

    drei = new QPushButton;
    QPixmap pixmap5(":/icon/drei.tif");
    QIcon buttonIcon5(pixmap5);
    drei->setIcon(buttonIcon5);
    drei->setIconSize(QSize(50, 50));
    drei->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    QObject::connect(drei, &QPushButton::clicked,this, &zweitesFenster::nachDreiFiltern);

    vier = new QPushButton;
    QPixmap pixmap6(":/icon/vier.tif");
    QIcon buttonIcon6(pixmap6);
    vier->setIcon(buttonIcon6);
    vier->setIconSize(QSize(50, 50));
    vier->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    QObject::connect(vier, &QPushButton::clicked,this, &zweitesFenster::nachVierFiltern);

    fuenf = new QPushButton;
    QPixmap pixmap7(":/icon/fuenf.tif");
    QIcon buttonIcon7(pixmap7);
    fuenf->setIcon(buttonIcon7);
    fuenf->setIconSize(QSize(50, 50));
    fuenf->setStyleSheet("border: none; margin: 0px; padding: 0px;");
    QObject::connect(fuenf, &QPushButton::clicked,this, &zweitesFenster::nachFuenfFiltern);

    filterAufloesen = new QPushButton;
    QObject::connect(filterAufloesen, &QPushButton::clicked,this, &zweitesFenster::ungefiltert);
    QPixmap pixmap1(":/icon/back_Transparent.tif");
    QIcon buttonIcon1(pixmap1);
    filterAufloesen->setIcon(buttonIcon1);
    filterAufloesen->setStyleSheet("border: none; margin: 0px;padding: 0px;");
    filterAufloesen->setIconSize(QSize(50,50));


    sterne->addWidget(eins);
    sterne->addWidget(zwei);
    sterne->addWidget(drei);
    sterne->addWidget(vier);
    sterne->addWidget(fuenf);
    sterne->addWidget(filterAufloesen);
    filt->addLayout(sterne,3,0);

    menu->addLayout(menu3);
    //menu->addWidget(option);
    menu->addWidget(farbenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(bilderWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(sprachenWidget, 0, Qt::AlignLeft | Qt::AlignTop);
    menu->addWidget(filterWidget, 0, Qt::AlignLeft | Qt::AlignTop);

    /*Hilfe Button*/
    hilfe = new QPushButton;
    QPixmap pixmap(":/icon/Fragezeichen.tif");
    QIcon buttonIcon(pixmap);
    hilfe->setIcon(buttonIcon);
    hilfe->setIconSize(QSize(50, 50));
    hilfe->setStyleSheet("border: none; margin-bottom: 0px;padding: 0px;");
    QObject::connect(hilfe, &QPushButton::clicked,this, &zweitesFenster::hilfeAngeklicket);

/*Hier habe ich einen Button eingesetzt um zum dritten Fenster zu gelangen */
/*Im späteren Verlauf wird der Button ersetzt duch den Doppelklick des Nutzers auf ein Bild*/

    menu2 = new QVBoxLayout();
    menu->insertStretch(300,30);
    menu->addLayout(menu2);
    menu2->addWidget(hilfe, 0, Qt::AlignLeft | Qt::AlignVCenter);


    fenster->setStyleSheet("background-color:white;");
    westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
    westpart->setLayout(menu);
    west->addWidget(westpart);
    oberesWindow->addWidget(westpart);

    /* Southpart muss hier programmiert werden */
    south->addWidget(bildBewertung);
    bildBewertungsFeld->addItem(" ");
    bildBewertungsFeld->addItem("1");
    bildBewertungsFeld->addItem("2");
    bildBewertungsFeld->addItem("3");
    bildBewertungsFeld->addItem("4");
    bildBewertungsFeld->addItem("5");
    bildBewertungsFeld->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
    bildBewertungsFeld->setMinimumContentsLength(25);
    south->addWidget(bildBewertungsFeld);
    south->addWidget(tags);
    south->addWidget(tagsFeld);

    tagsFeld->setText("");
    QObject::connect(tagsFeld, &QLineEdit::editingFinished,this, &zweitesFenster::bildtagsAendern);// BildID muss als erster Parameter übergeben werden
    tagsFeld->clear();
    QObject::connect(bildBewertungsFeld, static_cast<void (QComboBox::*)(const int)>(&QComboBox::currentIndexChanged),this, &zweitesFenster::bildBewertungAendern);// BildID muss als erster Parameter übergeben werden
    south->addWidget(bildPfad);
    south->addWidget(bildPfadFeld);

    bildPfadFeld->setReadOnly(true);
    bildPfadFeld->setStyleSheet("background-color: rgb(209,209,209)");
    bildPfadFeld->setAlignment(Qt::AlignLeft);
    south->minimumSize();
    southpart->setLayout(south);
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

    optionsleisteDarstellen();
    vector<string> *letzteBilder = new vector<string>;
    (*letzteBilder) = m_bank->getAlleBilder_dargestelltTrue();
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(letzteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::bildtagsAendern(){
    cout << pfad << endl;
    int id = m_bank->getID(pfad);
    m_bank->bildtagsAendern(id,tagsFeld->text());
}

void zweitesFenster::bildBewertungAendern(){
    int wert = bildBewertungsFeld->currentIndex();
    cout << wert << endl;
    cout << pfad << endl;
    int id = m_bank->getID(pfad);
    m_bank->bildBewerten(id,wert);
}

void zweitesFenster::BilderDarstellen(map<string, QImage*> *qimages){

    QVBoxLayout *m_mainLayout = new QVBoxLayout;
    QScrollArea *m_area = new QScrollArea;
    m_area->verticalScrollBarPolicy();

    m_mainLayout->addWidget(m_area);
    QWidget *contents = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(contents);
    QHBoxLayout *center1 = new QHBoxLayout;
    layout->addLayout(center1);
    int index = 0;

    map<string,QImage*>::iterator bilderDurchgehen;

    for(bilderDurchgehen = qimages->begin(); bilderDurchgehen != qimages->end(); bilderDurchgehen++){
        MyLabel *l = new MyLabel(bilderDurchgehen->first, m_bank);
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

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    m_area->setWidget(contents);

    /*Layouts dem Widget hinzufügen*/

    oberesWindow->addWidget(westpart,0,0,0,1);
    oberesWindow->addWidget(m_area,0,1,1,4);

    ganzesWindow->addLayout(oberesWindow);
    ganzesWindow->addWidget(southpart);
    this->setLayout(ganzesWindow);
    this->showMaximized();

}

void zweitesFenster::schwarzFunktion(){
    Farben schwarz(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                   vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                   deutsch,  englisch,  vollbildModusDeaktiviern, tags, bildBewertung,
                   bildPfad, tagsFeld, bildBewertungsFeld, bildPfadFeld, filtern);
    schwarz.schwarz();
}

void zweitesFenster::beigeFunktion(){
    Farben beige(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                 vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                 deutsch,  englisch,  vollbildModusDeaktiviern, tags, bildBewertung,
                 bildPfad, tagsFeld, bildBewertungsFeld, bildPfadFeld, filtern);
    beige.beige();
}

void zweitesFenster::weissFunktion(){
    Farben weiss(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                 vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                 deutsch,  englisch,  vollbildModusDeaktiviern, tags, bildBewertung,
                 bildPfad, tagsFeld, bildBewertungsFeld, bildPfadFeld, filtern);
    weiss.weiss();
}

void zweitesFenster::pinkFunktion(){
    Farben pink(fenster, westpart, filter, hintergrund, anzahlBilder, vollbild,
                    vollbildmodus,  option,  zwanzig, vierzig,  sechsig,  sprache,
                    deutsch,  englisch,  vollbildModusDeaktiviern, tags, bildBewertung,
                    bildPfad, tagsFeld, bildBewertungsFeld, bildPfadFeld, filtern);
    pink.pink();
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
}

void zweitesFenster::vollbildModusAktiv(){

    vollbildModusDeaktiviern->setHidden(false);
    southpart->setHidden(true);
    tags->setHidden(false);
    bildBewertung->setHidden(false);
    bildPfad->setHidden(false);
    tagsFeld->setHidden(false);
    bildBewertungsFeld->setHidden(false);
    bildPfadFeld->setHidden(false);
    south->addWidget(vollbildModusDeaktiviern);
    southpart->setHidden(false);
    westpart->setHidden(true); //Menu wird versteckt
    QObject::connect(vollbildModusDeaktiviern, &QPushButton::clicked,this, &zweitesFenster::vollbildModusInaktiv);
    fenster->update();
}

void zweitesFenster::vollbildModusInaktiv(){

    southpart->setHidden(false);
    tags->setHidden(false);
    bildBewertung->setHidden(false);
    bildPfad->setHidden(false);
    tagsFeld->setHidden(false);
    bildBewertungsFeld->setHidden(false);
    bildPfadFeld->setHidden(false);
    westpart->setHidden(false); //Menu wird wieder angezeigt
    vollbildModusDeaktiviern->setHidden(true);  //Button, der Vollbildmodus deaktivieren kann wird unsichtbar
    vollbildmodus->setChecked(false);
    fenster->update();
}

void zweitesFenster::nachEinsFiltern(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->bewertungFiltern(1);
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::nachZweiFiltern(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->bewertungFiltern(2);
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::nachDreiFiltern(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->bewertungFiltern(3);
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);

}

void zweitesFenster::nachVierFiltern(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->bewertungFiltern(4);
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);

}

void zweitesFenster::nachFuenfFiltern(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->bewertungFiltern(5);
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);

}

void zweitesFenster::nachTagFiltern(QString tag){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->bildtagsFiltern(tag);


    if(gefilterteBilder->empty() == true){
        QMessageBox *information = new QMessageBox();
        QString text = (tr("<h1>Achtung!</h1>"
                       "Es existieren keine Bilder mit dem eingegebenen Tags."));

        information->setIcon(QMessageBox::Information); //setzt das Icon, welches das Hauptfenster auch hat
        QMessageBox::information(this,"Hilfe",text);
    }
    else{
        std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
        (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
        BilderDarstellen(umgewandelteBilder);
    }
}

void zweitesFenster::zwanzigBilder(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->getAlleBilder_dargestelltTrue();
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::vierzigBilder(){
    m_bilderAnzahl = 40;
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->getAlleBilder_dargestelltTrue();
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::sechsigBilder(){
    m_bilderAnzahl = 60;
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->getAlleBilder_dargestelltTrue();
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}

void zweitesFenster::setPfad(string pfad){
    this->pfad = pfad;
    bildPfadFeld->setText(QString::fromStdString(pfad));
}

void zweitesFenster::tagsInInfoleisteAnzeige(QString tags){
    tagsFeld->setText(tags);
}

void zweitesFenster::bewertungInInfoleisteAnzeige(int bewertung){
    bildBewertungsFeld->setCurrentIndex(bewertung);
}

void zweitesFenster::ungefiltert(){
    vector<string> *gefilterteBilder = new vector<string>;
    (*gefilterteBilder) = m_bank->getAlleBilder_dargestelltMemory();
    std::map<string, QImage*> *umgewandelteBilder = new std::map<string, QImage*>;
    (*umgewandelteBilder) = suche->umwandeln(gefilterteBilder, m_bilderAnzahl);
    BilderDarstellen(umgewandelteBilder);
}
