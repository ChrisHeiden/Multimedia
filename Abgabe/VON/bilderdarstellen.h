#ifndef BILDERDARSTELLEN_H
#define BILDERDARSTELLEN_H

#include <QThread>
#include <QString>


class Bilderdarstellen : public QThread
{
public:
    Bilderdarstellen(QString pfad);
};

#endif // BILDERDARSTELLEN_H
