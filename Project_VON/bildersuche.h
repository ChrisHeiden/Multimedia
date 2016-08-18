#include <QThread>
#include <String>
#include <vector>
#include <QDirIterator>
#include <QString>
#include <regex>
#include <QFileDialog>
#include <QImage>
#include <QGridLayout>
#include <mylabel.h>
#include <map>
#include "datenbank.h"

#ifndef BILDERSUCHE_H
#define BILDERSUCHE_H

/**
 * @brief The BilderSuche class ist ein Thread, welcher sich um die Suche aller Bilder kümmert
 *        und diese dann umwandelt von den bisherigen Strings zu QImages
 */
class BilderSuche : public QThread
{
    Q_OBJECT
public:
    /**
     * @brief BilderSuche ist der Konstruktor der Klasse, welcher die Membervariable initialsiert
     * @param pfad: &QString ist der Bildpfad von dem die Suche starten soll
     * @param anzahhlBilder: &int
     * @param bank: *Datenbank
     */
    BilderSuche(QString &pfad, int &anzahhlBilder, Datenbank *bank);

    /**
     * @brief ~Bildersuche loescht den Zeiger m_bank
     */
    virtual ~BilderSuche();

    /**
     * @brief run ist der Start des Threads, welcher dem Thread anweist in die
     *        alleGenfundenenBilder()-Funktion zu gehen und in die umwandeln()-Funktion.
     */
    void run();

    /**
     * @brief alleGefundenenBilder sucht alle Bilder, die vom Dateityp jpg sind und speichert die
     *        Pfade in einem Vector vom Typ string
     * @return vector<string> enthält alle Bildpfad, die gefunden sind
     */
    std::vector<std::string> alleGefundenenBilder();

    /**
     * @brief umwandeln, wandelt die gefundenen Bilder in QImages um
     * @param images: vector<string>*, welcher alle Bildpfade enthaelt
     * @param zahl: &int, anzahl der Bilder, die dargestellt werden sollen ohne zu scollen
     * @return vector<QImage> enthält alle Bilder, welche in der Aplikation dargestellt werden sollen
     */
    std::map<string, QImage *> umwandeln(std::vector<std::string> *images, int &zahl);


signals: //SIGNAL-Funktion
   void sucheBeenden(std::map<string, QImage*> *images);


private: //Membervariablen
    Datenbank *m_bank;
    std::vector<std::string> *images;
    std::map<string, QImage*> *qimages;

    QString m_pfad;
    int m_anzahhlBilder;


private:
    void ordnerVerzeichnis();

};

#endif // BILDERSUCHE_H
