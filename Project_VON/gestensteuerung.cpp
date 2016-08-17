#include "gestensteuerung.h"
#include <QCoreApplication>
#include <qDebug>
 #include <QFile>
Gestensteuerung::Gestensteuerung(QVBoxLayout *buttons, QHBoxLayout *buttons2, QWidget *parent) : QWidget(parent)
{
    this->buttons = buttons;
    alleGespeichertenWerte = new vector<GespeichertWerte*>;
    alleWerte = new vector<GespeichertWerte*>;
    n = new Notification;
    aktiv = new QPushButton();
    buttons->addWidget(aktiv);
    buttons2->addWidget(aktiv);
    connect(aktiv, &QPushButton::clicked, this, &Gestensteuerung::connectionAktivieren);
    process = new QProcess(this);
    mengeAnG = 0;
    stil();

    if(process)
    {

        process->setProcessChannelMode(QProcess::MergedChannels);
        process->setEnvironment(QProcess::systemEnvironment());

        /*Hier muss ich mir noch was überlegen*/

/*
        string pfad = QCoreApplication::applicationFilePath().toStdString();

        unsigned int index;
        for(unsigned int i = 0; i < pfad.size(); i++){
            if(pfad.at(i) == '/'){
                --slashes;
                index = i;
            }
            else{
                continue;
            }
        }

        pfad.resize(index);     //kürzt den Pfad bis zu diesem Slash
        string path = pfad + "/BodyBasics-D2D.exe";

*/
        QFile::copy(":/Kinect/BodyBasics-D2D.exe", "./BodyBasics-D2D.exe");

        QString file = "./BodyBasics-D2D.exe";
        process->start(file);
        process->waitForStarted();
        connect(process, &QProcess::readyReadStandardOutput, this, &Gestensteuerung::auslesen);
    }
}

Gestensteuerung::~Gestensteuerung()
{
    delete (process);
    delete (speichert);
    delete (alleGespeichertenWerte);
    delete (alleWerte);
    delete (n);
    delete (buttons);
    delete (aktiv);
}

void Gestensteuerung::auslesen()
{
    string ersetzeElement = ";";

    double x;
    double y;

    QString test (process->readAllStandardOutput());
    string hilfe = test.toStdString();

    for(unsigned int i = 0; i< hilfe.length(); i++){
        if(hilfe.at(0) == 'O'){
            mengeAnG = 0;
            if(hilfe.at(i) == ';'){
                hilfe.erase(0, i + ersetzeElement.length());
                unsigned int index = hilfe.find(ersetzeElement);
                int size = hilfe.length();
                x = stod(hilfe.substr(0, index));
                y = stod(hilfe.substr(index +1, size - index));
                //cout << "X-Wert: " << x << endl;
                //cout << "Y-Wert: " <<y << endl;
                //cout << "Wert werden uebermittelt." << endl;
                speichert = new GespeichertWerte(x,y);
                alleGespeichertenWerte->push_back(speichert);
            }
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
            if(alleWerte->empty() == false && alleWerte->size() > 80){
                gestenErkennung();
                alleWerte->clear();
                alleGespeichertenWerte->clear();
            }
        }
    }
}

void Gestensteuerung::gestenErkennung(){
    int laenge = alleWerte->size();

    vector<GespeichertWerte*> firstpart; std::copy(alleWerte->begin(),(alleWerte->begin() + (alleWerte->size() * 0.25)),  std::back_inserter(firstpart));
    vector<GespeichertWerte*> secondpart; std::copy(alleWerte->begin() + (alleWerte->size() * 0.25),(alleWerte->begin() + (alleWerte->size() * 0.50)), std::back_inserter(secondpart));
    vector<GespeichertWerte*> thirdpart; std::copy(alleWerte->begin() + (alleWerte->size() * 0.5),(alleWerte->begin() + (alleWerte->size() * 0.75)), std::back_inserter(thirdpart));
    vector<GespeichertWerte*> fourthpart; std::copy(alleWerte->begin() + (alleWerte->size() * 0.75),(alleWerte->end()), std::back_inserter(fourthpart));

    double schwankungX = 50;
    double schwankungY = 50;

    double y1 = alleWerte->at(0)->getYWert();
    double y2 = alleWerte->at(laenge -1)->getYWert();
    //cout << "Zweiter Y-Wert: " << y2 << endl;

    double x1 = alleWerte->at(0)->getXWert();
    double x2 = alleWerte->at(laenge -1)->getXWert();

    double schwankungX1 = alleWerte->at(0)->getXWert() - schwankungX;
    double schwankungX2 = alleWerte->at(0)->getXWert() + schwankungX;
    //cout << "Schwankung X1-Wert: " << schwankungX1 <<endl;
    //cout << "Schwankung X2-Wert: " << schwankungX2 <<endl;


    double schwankungY1 = alleWerte->at(0)->getYWert() + schwankungY;
    double schwankungY2 = alleWerte->at(0)->getYWert() - schwankungY;
  //  cout << "Schwankung Y1-Wert: " << schwankungY1 <<endl;
  //  cout << "Schwankung Y2-Wert: " << schwankungY2 <<endl;

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
    if(schwankungY2 < y1 &&  schwankungY1 > y1 && schwankungX1 < x1 && schwankungX2 >x1){
        if (schwankungY2 < y2 && schwankungY1 > y2 && schwankungX1 < x1 && schwankungX2 >x1){
            for(unsigned short i = 0; i < secondpart.size(); ++i){
                if(schwankungY1 > secondpart.at(i)->getYWert() && schwankungX2 > secondpart.at(i)->getXWert()){
                    for(unsigned short y = 0; y < thirdpart.size(); ++y){
                        if(schwankungY1 < thirdpart.at(y)->getYWert() && schwankungX1 < thirdpart.at(y)->getXWert() && schwankungX2 > thirdpart.at(y)->getXWert()){
                            for(unsigned short z = 0; z < fourthpart.size(); ++z){
                                if(schwankungY1 < fourthpart.at(z)->getYWert() && schwankungX1 > fourthpart.at(z)->getXWert()){
                                    break;
                                }
                            }
                            break;
                        }
                  }
                    break;
                }
            }
        }
    drehGeste();
    }
    else{
        cout << "Keine Geste erkannt." <<endl;
    }
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

void Gestensteuerung::drehGeste()
{
    // Bild mit uhrzeiger drehen
    cout << " Bilder wird gedreht." << endl;
    dreheBild();
}

void Gestensteuerung::vergroesserGeste()
{
    //Bild vergroesser
    cout << " Bilder wird groesser dargestellt." << endl;
    vergroessereBild();
}

void Gestensteuerung::verkleinerGeste()
{
    //Bild verkleinern
    cout << "Bild wird kleiner dartgestellt." << endl;
    verkleinereBild();
}

void Gestensteuerung::connectionAktivieren()
{
    connect(process, &QProcess::readyReadStandardOutput, this, &Gestensteuerung::auslesen);
    alleWerte->clear();
    alleGespeichertenWerte->clear();
}

void Gestensteuerung::stil()
{
    QPixmap pixmap(":/icon/Kinect_Icon.png");
    QIcon buttonIcon(pixmap);
    aktiv->setIcon(buttonIcon);
    aktiv->setIconSize(QSize(75, 75));
    aktiv->setStyleSheet("border: none; margin: 0px; padding: 0px;");
}
