#include "bilderSucheThread.h"
#include "datenbank.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <iostream>
#include <QHBoxLayout>

using namespace std;

/*
 * Idee: Zerstückelung der Vektors Images in mehrere gleich große Teile, welche
 *       Threads bearbeiten (umnwandln).
 *       Der jetztige Thread muss dabei auf das Ende der Umwandlung warten.
 */

AlleBilderSuchThread::AlleBilderSuchThread(QString str){
        m_string = str;
}

void AlleBilderSuchThread::run(){
    vector<string> *images = new vector<string>();
    (*images) = alleGefundenenBilder(); // alle Bilder ab einem bestimmten Verzeichnis werden geladen

    vector<QImage*> *qimages = new vector<QImage*>();
    (*qimages) = umwandeln(images);
    sucheBeendet(qimages);
}

vector<string> AlleBilderSuchThread::alleGefundenenBilder(){

    vector<string> bilder;
    QDirIterator it( m_string, QDirIterator::Subdirectories ); // Iterator für Verzeichnis erstellen
    smatch e;
    regex exp(".*.jpg$");
    Datenbank bilderdatenbank;

    while(it.next() != NULL){
         if((it.fileInfo().isFile() == true)  && (regex_match(it.fileInfo().absoluteFilePath().toStdString(),e,exp))){
             for(auto a:e){
//                 QString qstr = QString::fromStdString(a);
                 bilderdatenbank.neuesBild(a);
                 bilder.push_back(a);
              }
         }
    }
   return bilder;
}

vector<QImage*> AlleBilderSuchThread::umwandeln(vector<string> *images){
    vector<QImage*> qimages;
    cout << "5" <<endl;

    for(unsigned int i= 0; i < images->size(); i++){
         QString qstring(images->at(i).c_str());
         QImage *image = new QImage(qstring);

         qDebug() << qstring;
         (*image) = image->scaledToWidth(150, Qt::SmoothTransformation);
         qimages.push_back(image);

    }
    cout << "Ende" << endl;
    return qimages;
}
