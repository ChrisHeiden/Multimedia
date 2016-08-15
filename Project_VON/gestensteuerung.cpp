#include "gestensteuerung.h"
#include <iostream>
Gestensteuerung::Gestensteuerung(QVBoxLayout *buttons, QWidget *parent) : QWidget(parent)
{
    this->buttons = buttons;
    alleGespeichertenWerte = new vector<GespeichertWerte*>;
    alleWerte = new vector<GespeichertWerte*>;
    n = new Notification;
    aktiv = new QPushButton("aktivieren");
    buttons->addWidget(aktiv);
    connect(aktiv, &QPushButton::clicked, this, &Gestensteuerung::connectionAktivieren);
    // Init Process
    process = new QProcess(this);
    mengeAnG = 0;


    if(process)
    {

        // Some Settings
        process->setProcessChannelMode(QProcess::MergedChannels);
        process->setEnvironment(QProcess::systemEnvironment());

        // Path to KinectApp
        QString file = "C:/Users/Christopher/Documents/BodyBasics-D2D.exe";

        // Starting KinectApp
        process->start(file);

        // Giving it time to start
        process->waitForStarted();

        // If an stdoutput happens inside the Kinect-App, readOut-Function is triggered
        connect(process, &QProcess::readyReadStandardOutput, this, &Gestensteuerung::auslesen);
    }
}

Gestensteuerung::~Gestensteuerung()
{
    delete (process);
    delete (alleGespeichertenWerte);
    delete (speichert);
    delete (alleWerte);
    delete (n);
}

void Gestensteuerung::auslesen()
{
    string ersetzeElement = ";";

    double x;
    double y;

    // Print Output from KinectApp
    QString test (process->readAllStandardOutput());
    string hilfe = test.toStdString();

    for(unsigned int i = 0; i< hilfe.length(); i++){
        if(hilfe.at(0) == 'O'){
            mengeAnG = 0;
           /* if(t->getAuslesen() == false){
                t->setAuslesen(true);
                cout << "Kinect ist aktiviert." <<endl;
                n->aktiviert();
                connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::readOut);
            }*/
            //else{
                if(hilfe.at(i) == ';'){
                    hilfe.erase(0, i + ersetzeElement.length());
                    unsigned int index = hilfe.find(ersetzeElement);
                    int size = hilfe.length();
                    x = stod(hilfe.substr(0, index));
                    y = stod(hilfe.substr(index +1, size - index));
                    //cout << "X-Wert: " << x << endl;
                    //cout << "Y-Wert: " <<y << endl;
                    cout << "Wert werden uebermittelt." << endl;
                    speichert = new GespeichertWerte(x,y);
                    alleGespeichertenWerte->push_back(speichert);
                }
            //}
        }
    }
    if(hilfe.at(0) == 'G'){
        ++mengeAnG;
        //cout << mengeAnG << endl;
        if(mengeAnG >= 100){
            n->deaktiviert();
            //cout << "Kinect ist deaktiviert." <<endl;
            disconnect(process, &QProcess::readyReadStandardOutput, this, &Gestensteuerung::auslesen);
        }
        else{
            alleWerte = alleGespeichertenWerte;
            if(alleWerte->empty() == false && alleWerte->size() > 20){
                gestenErkennung();
                alleWerte->clear();
                alleGespeichertenWerte->clear();
            }
        }
    }
}

void Gestensteuerung::gestenErkennung(){
    int laenge = alleWerte->size();

    double schwankungX = 50;
    double schwankungY = 50;

    double y1 = alleWerte->at(0)->getYWert();
    double y2 = alleWerte->at(laenge -1)->getYWert();
    cout << "Zweiter Y-Wert: " << y2 << endl;

    double x1 = alleWerte->at(0)->getXWert();
    double x2 = alleWerte->at(laenge -1)->getXWert();

    double schwankungX1 = alleWerte->at(0)->getXWert() - schwankungX;
    double schwankungX2 = alleWerte->at(0)->getXWert() + schwankungX;
    cout << "Schwankung X1-Wert: " << schwankungX1 <<endl;
    cout << "Schwankung X2-Wert: " << schwankungX2 <<endl;


    double schwankungY1 = alleWerte->at(0)->getYWert() + schwankungY;
    double schwankungY2 = alleWerte->at(0)->getYWert() - schwankungY;
    cout << "Schwankung Y1-Wert: " << schwankungY1 <<endl;
    cout << "Schwankung Y2-Wert: " << schwankungY2 <<endl;

    /* Bild verkleinern */
    if(y2 > schwankungY1 && x2 < schwankungX1){
        verkleinerGeste();
    }

    /* Bilder vergroessern*/
    else if(y2<schwankungY2 && x2 > schwankungX2){
        vergroesserGeste();
    }

    /* Wischgeste */
    else if((y1 == y2 && x1!=x2 )|| ((schwankungY2 < y2 && y1 < schwankungY1) && x1 != x2)){
        wischGeste();
    }

    /* Drehung */
    /*    else if((schwankungY1 < y1 && schwankungY2 > y1 && schwankungX1 < x1 && schwankungX2 >x1) && // Start- und Endpunkt muss
                (schwankungY1 < y2 && schwankungY2 > y2 && schwankungX1 < x1 && schwankungX2 >x1) && // sich in diesem Bereich befinden

                (schwankungX2 < (alleWerte->at(alleWerte->size()*0.25)->getXWert()) && (alleWerte->at(alleWerte->size()*0.25)->getXWert()) < schwankungX2 + 100) &&//Erste Stelle der Kreisbewegung
                (schwankungY1 < (alleWerte->at(alleWerte->size()*0.25)->getYWert()) && (alleWerte->at(alleWerte->size()*0.25)->getYWert()) < schwankungY1 + 100) && //muss sich hier befinden

                (schwankungX2 < (alleWerte->at(alleWerte->size()*0.5)->getXWert()) && (alleWerte->at(alleWerte->size()*0.5)->getXWert()) < schwankungX2 + 100) && //Zweite Stelle der Kreisbewegung
                (schwankungY1 < (alleWerte->at(alleWerte->size()*0.5)->getYWert()) && (alleWerte->at(alleWerte->size()*0.5)->getYWert()) < schwankungY1 + 100) && //muss sich hier befinden

                (schwankungX2 < (alleWerte->at(alleWerte->size()*0.75)->getXWert()) && (alleWerte->at(alleWerte->size()*0.75)->getXWert()) < schwankungX2 + 100)&& //Dritte Stelle der Kreisbewegung
                (schwankungY1 < (alleWerte->at(alleWerte->size()*0.75)->getYWert()) && (alleWerte->at(alleWerte->size()*0.75)->getYWert()) < schwankungY1 + 100)){ //muss sich hier befinden

        drehGeste();
    }

    else{
        cout << "Keine Geste erkannt." <<endl;
    }*/
}


void Gestensteuerung::wischGeste(){
    int laenge = alleWerte->size();

    double x1 = alleWerte->at(0)->getXWert();
    double x2 = alleWerte->at(laenge -1)->getXWert();


    if(x1 < x2){ //
        //vorheriges Bild anzeigen
        cout << " Vorheriges Bild wird dargestellt." << endl;
        vorhereigesBild();
    }

    else if(x1 > x2){
        //vorheriges Bild anzeigen
        cout << " Naechstes Bild wird dargestellt." << endl;
        nachstesBild();
    }
}

void Gestensteuerung::drehGeste(){
    // Bild mit uhrzeiger drehen
    cout << " Bilder wird gedreht." << endl;
    dreheBild();
}

void Gestensteuerung::vergroesserGeste(){
    //Bild vergroesser
    cout << " Bilder wird groesser dargestellt." << endl;
    vergroessereBild();
}

void Gestensteuerung::verkleinerGeste(){
    //Bild verkleinern
    cout << "Bild wird kleiner dartgestellt." << endl;
    verkleinereBild();
}

void Gestensteuerung::connectionAktivieren(){

    connect(process, &QProcess::readyReadStandardOutput, this, &Gestensteuerung::auslesen);
    alleWerte->clear();
    alleGespeichertenWerte->clear();
}
