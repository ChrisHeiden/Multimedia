#include <QObject>
#include <QtTest/QtTest>
#include "datenbank.h"

#ifndef DATENBANKTEST_H
#define DATENBANKTEST_H

/**
 * @brief The datenbanktest class dient zur testen der Datenbankklasse
 */
class datenbanktest : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief datenbanktest
     * @param parent
     */
    explicit datenbanktest(QObject *parent = 0);

private: //Membervariablen
   Datenbank *testbank;

private slots: //SLOT-Funktionen

    /**
     * @brief initTestCase
     */
    void initTestCase();

    /**
     * @brief datenbankEmptyTrue
     */
    void datenbankEmptyTrue();

    /**
     * @brief neuesBild
     */
    void neuesBild();

    /**
     * @brief datenbankEmptyFalse
     */
    void datenbankEmptyFalse();

    /**
     * @brief bildpfadExistsFalse
     */
    void bildpfadExistsFalse();

    /**
     * @brief bildpfadExistsTrue
     */
    void bildpfadExistsTrue();

    /**
     * @brief getIDTrue
     */
    void getIDTrue();

    /**
     * @brief getIDFalse
     */
    void getIDFalse();

    /**
     * @brief bildBewertenTrue
     */
    void bildBewertenTrue();

    /**
     * @brief bildBewertenFalse
     */
    void bildBewertenFalse();

    /**
     * @brief bildtagsAendernTrue
     */
    void bildtagsAendernTrue();

    /**
     * @brief bildtagsAendernFalse
     */
    void bildtagsAendernFalse();

    /**
     * @brief bewertungAnzeigen
     */
    void bewertungAnzeigen();

    /**
     * @brief bildtagsAnzeigen
     */
    void bildtagsAnzeigen();

    /**
     * @brief getBildausrichtung
     */
    void getBildausrichtung();

    /**
     * @brief bildLoeschenFalse
     */
    void bildLoeschenFalse();

    /**
     * @brief bildLoeschenTrue
     */
    void bildLoeschenTrue();

    /**
     * @brief cleanupTestCase
     */
    void cleanupTestCase();
};

#endif // DATENBANKTEST_H
