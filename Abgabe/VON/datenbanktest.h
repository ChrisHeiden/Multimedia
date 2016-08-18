#ifndef DATENBANKTEST_H
#define DATENBANKTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "datenbank.h"

/**
 * @brief The datenbanktest class für 25 Unittets aus
 */
class datenbanktest : public QObject
{
    Q_OBJECT
public:
    explicit datenbanktest(QObject *parent = 0);

private:
   Datenbank *testbank;

private slots:

   /**
     * @brief initTestCase Vorbereitung der restlichen Tests
     */
    void initTestCase();

    /**
     * @brief datenbankEmptyTrue datenbankEmpty wird getestet, für den Fall, dass die Datenbank leer ist
     */
    void datenbankEmptyTrue();

    /**
     * @brief neuesBild neuesBild wird getestet, indem ein neues Bild der Datenbank hinzugefuegt wird
     */
    void neuesBild();

    /**
     * @brief datenbankEmptyFalse datenbankEmpty wird getestet, für den Fall, dass die Datenbank nicht leer ist
     */
    void datenbankEmptyFalse();

    /**
     * @brief bildpfadExistsFalse bildpfadExists wird getestet, für den Fall, dass der Bildpfad nicht existiert
     */
    void bildpfadExistsFalse();

    /**
     * @brief bildpfadExistsTrue bildpfadExists wird getestet, für den Fall, dass der Bildpfad existiert
     */
    void bildpfadExistsTrue();

    /**
     * @brief bildExistsTrue bildExists wird getestet, für den Fall, dass die gesuchte ID in der Datenbank existiert
     */
    void bildExistsTrue();

    /**
     * @brief bildExistsFalse bildExists wird getestet, für den Fall, dass die gesuchte ID in der Datenbank nicht existiert
     */
    void bildExistsFalse();

    /**
     * @brief getIDTrue getID wird getestet, für den Fall, dass es den gesuchten Bildpfad in der Datenbank gibt
     */
    void getIDTrue();

    /**
     * @brief getIDFalse getID wird getestet, für den Fall, dass es den gesuchten Bildpfad in der Datenbank nicht gibt
     */
    void getIDFalse();

    /**
     * @brief bildBewertenTrue bildBewerten wird getestet, für den Fall, dass ID und Bewertung zulässig sind
     */
    void bildBewertenTrue();

    /**
     * @brief bildBewertenFalse bildBewerten wird getestet, für den Fall, dass die Bewertung nicht zulässig sind
     */
    void bildBewertenFalse();

    /**
     * @brief bildtagsAendernTrue bildtagsAendern wird getestet, für den Fall, dass die uebergebene ID in der Datenbank existiert
     */
    void bildtagsAendernTrue();

    /**
     * @brief bildtagsAendernFalse bildtagsAendern wird getestet, für den Fall, dass die uebergebene ID in der Datenbank nicht existiert
     */
    void bildtagsAendernFalse();

    /**
     * @brief aktuellenBildPfadAnzeigenTrue aktuellenBildPfadAnzeigen wird getestet, für den Fall, dass die gesuchte ID in der Datenbank existiert
     */
    void aktuellenBildPfadAnzeigenTrue();

    /**
     * @brief aktuellenBildPfadAnzeigenFalse aktuellenBildPfadAnzeigen wird getestet, für den Fall, dass die gesuchte ID nicht in der Datenbank existiert
     */
    void aktuellenBildPfadAnzeigenFalse();

    /**
     * @brief bewertungAnzeigen bewertungAnzeigen wird getestet, für den Fall, dass die ID in der Datenbank existiert
     */
    void bewertungAnzeigen();

    /**
     * @brief bildtagsAnzeigen bildtagsAnzeigen wird getestet, für den Fall, dass die ID in der Datenbank existiert
     */
    void bildtagsAnzeigen();

    /**
     * @brief getBildausrichtung getBildausrichtung wird getestet, für den Fall, dass die ID in der Datenbank existiert
     */
    void getBildausrichtung();

    /**
     * @brief bildDrehen setNeueBildausrichtung wird für den Normalfall getestet
     */
    void bildDrehen();

    /**
     * @brief bewertungFiltern bewertungFiltern wird für den Fall getestet, dass es Bilder mit der Bewertung in der Datenbank gibt
     */
    void bewertungFiltern();

    /**
     * @brief bildtagsFiltern bildtagsFiltern wird für den Fall getestet, dass es Bilder mit dem Tag in der Datenbank gibt
     */
    void bildtagsFiltern();

    /**
     * @brief bildLoeschenFalse bildLoeschen wird für den Fall getestet, dass es ein Bild mit der ID nicht in der Datenbank gibt
     */
    void bildLoeschenFalse();

    /**
     * @brief bildLoeschenTrue bildLoeschen wird für den Fall getestet, dass es ein Bild mit der ID in der Datenbank gibt
     */
    void bildLoeschenTrue();

    /**
     * @brief cleanupTestCase loescht alle uebrig gebliebenen Testobjekte
     */
    void cleanupTestCase();

};

#endif // DATENBANKTEST_H
