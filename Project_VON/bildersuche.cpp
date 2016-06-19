#include "bildersuche.h"

BilderSuche::BilderSuche(QString pfad)
{
    m_pfad = pfad;
}

void BilderSuche::run(){
    std::vector<std::string> *images = new std::vector<std::string>();
    (*images) = alleGefundenenBilder(); // alle Bilder ab einem bestimmten Verzeichnis werden geladen

    std::vector<QImage*> *qimages = new std::vector<QImage*>();
    (*qimages) = umwandeln(images);
    sucheBeenden(qimages);
}

std::vector<std::string> BilderSuche::alleGefundenenBilder(){

    std::vector<std::string> bilder;
    QDirIterator it( m_pfad, QDirIterator::Subdirectories ); // Iterator für Verzeichnis erstellen
    smatch e;
    regex exp(".*.jpg$");
    Datenbank bilderdatenbank;

    while(it.next() != NULL){
         if((it.fileInfo().isFile() == true)  && (regex_match(it.fileInfo().absoluteFilePath().toStdString(),e,exp))){
             for(auto a:e){
                 bilderdatenbank.neuesBild(a);
                 bilder.push_back(a);
              }
         }
    }
   return bilder;
}

std::vector<QImage*> BilderSuche::umwandeln(std::vector<std::string> *images){
    std::vector<QImage*> qimages;

    for(unsigned int i= 0; i < images->size(); i++){
         QString qstring(images->at(i).c_str());
         QImage *image = new QImage(qstring);

            (*image) = image->scaledToWidth(150, Qt::SmoothTransformation);
            qimages.push_back(image);

    }
    std::cout << "Ende" << std::endl;
    return qimages;
}

