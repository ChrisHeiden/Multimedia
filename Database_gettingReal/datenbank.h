#ifndef DATENBANK_H
#define DATENBANK_H

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QLabel>
#include <QString>
#include <iostream>

class Datenbank
{
public:
    Datenbank();

    bool neuesBild(int ID, QString Bildpfad);
    bool BildExists(int ID);
    bool Bildloeschen(int ID);

    void alleBilderAusgeben();

private:
    QSqlDatabase mydb;

signals:

public slots:
};

#endif // DATENBANK_H
