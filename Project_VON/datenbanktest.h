#ifndef DATENBANKTEST_H
#define DATENBANKTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "datenbank.h"

class datenbanktest : public QObject
{
    Q_OBJECT
public:
    explicit datenbanktest(QObject *parent = 0);

private:
   Datenbank *testbank;

private slots:

    void initTestCase();

    void datenbankEmptyTrue();

    void neuesBild();

    void datenbankEmptyFalse();

    void bildpfadExistsFalse();

    void bildpfadExistsTrue();

    void getIDTrue();

    void getIDFalse();

    void bildBewertenTrue();

    void bildBewertenFalse();

    void bildtagsAendernTrue();

    void bildtagsAendernFalse();

    void bewertungAnzeigen();

    void bildtagsAnzeigen();

    void getBildausrichtung();

    void bildLoeschenFalse();

    void bildLoeschenTrue();

    void cleanupTestCase();

};

#endif // DATENBANKTEST_H
