#include "bildersuche.h"

BilderSuche::BilderSuche(QString pfad, int anzahhlBilder)
{
    m_pfad = pfad;
    m_anzahhlBilder = anzahhlBilder;
}

void BilderSuche::run(){
    std::vector<std::string> *images = new std::vector<std::string>();
    (*images) = alleGefundenenBilder(); // alle Bilder ab einem bestimmten Verzeichnis werden geladen

    std::map<string, QImage*> *qimages = new  std::map<string, QImage*>;
    (*qimages) = umwandeln(images, m_anzahhlBilder);
    sucheBeenden(qimages);
}

std::vector<std::string> BilderSuche::alleGefundenenBilder(){

    std::vector<std::string> bilder;
    QDirIterator it( m_pfad, QDirIterator::Subdirectories ); // Iterator fÃ¼r Verzeichnis erstellen
    smatch e;
    regex exp(".*.jpg$");
    Datenbank bilderdatenbank;

    while(it.next() != NULL){
        if((it.fileInfo().isFile() == true)  && (regex_match(it.fileInfo().absoluteFilePath().toStdString(),e,exp))){
            for(auto a:e){
                QString b = QString::fromStdString(a);
                bilderdatenbank.neuesBild(b);
                bilder.push_back(a);
             }
        }
    }
    return bilder;
}


std::map<string, QImage*> BilderSuche::umwandeln(std::vector<std::string> *images, int zahl){
    std::map<string, QImage*> qimages;
    for(unsigned int i= 0; i < images->size(); i++){
         QString qstring(images->at(i).c_str());
         QImage *image = new QImage(qstring);
         if(zahl == 20){
            if(image->height() > image->width()){
                (*image) = image->scaledToHeight(300, Qt::SmoothTransformation);
                 qimages[images->at(i)] = image;
            }
            else{
                (*image) = image->scaledToWidth(300, Qt::SmoothTransformation);
                qimages[images->at(i)] = image;
            }
         }
         else if(zahl == 40){
             qDebug() << "test";
         }
         else{
             qDebug() << "test2";
         }
    }
    std::cout << "Ende" << std::endl;
    return qimages;
}

