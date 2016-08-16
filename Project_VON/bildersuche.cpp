#include "bildersuche.h"

BilderSuche::BilderSuche(QString pfad, int anzahhlBilder, Datenbank *bank)
{
    m_pfad = pfad;
    m_anzahhlBilder = anzahhlBilder;
    m_bank = bank;
    images = new std::vector<std::string>;
    qimages = new  std::map<string, QImage*>;
}

BilderSuche::~BilderSuche(){
    delete (m_bank);
    delete (images);
    delete (qimages);
}

void BilderSuche::run(){
    m_bank->setAlleBilder_dargestelltFalse();
    (*images) = alleGefundenenBilder(); // alle Bilder ab einem bestimmten Verzeichnis werden geladen

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

    if(zahl == 20){
        for(unsigned int i= 0; i < images->size(); i++){
            QString qstring(images->at(i).c_str());
            QImage *image = new QImage(qstring);

            if(image->height() > image->width()){
                (*image) = image->scaledToHeight(300, Qt::SmoothTransformation);
                qimages[images->at(i)] = image;

            }
            else{
                (*image) = image->scaledToWidth(300, Qt::SmoothTransformation);
                qimages[images->at(i)] = image;
            }
         }
    }
    else if(zahl == 40){
        for(unsigned int i= 0; i < images->size(); i++){
            QString qstring(images->at(i).c_str());
            QImage *image = new QImage(qstring);

            if(image->height() > image->width()){
                (*image) = image->scaledToHeight(150, Qt::SmoothTransformation);
                qimages[images->at(i)] = image;

            }
            else{
                (*image) = image->scaledToWidth(150, Qt::SmoothTransformation);
                qimages[images->at(i)] = image;
            }
         }
    }
    else{
        for(unsigned int i= 0; i < images->size(); i++){
            QString qstring(images->at(i).c_str());
            QImage *image = new QImage(qstring);
             if(image->height() > image->width()){
                 (*image) = image->scaledToHeight(100, Qt::SmoothTransformation);
                 qimages[images->at(i)] = image;
             }
             else{
                 (*image) = image->scaledToWidth(100, Qt::SmoothTransformation);
                 qimages[images->at(i)] = image;
             }
         }
    }
    return qimages;
}
