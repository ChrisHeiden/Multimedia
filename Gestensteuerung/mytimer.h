#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QtCore>
using namespace std;
class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer();
    ~MyTimer();
    bool getAuslesen();
    void setAuslesen(bool auslesen);
    bool starten();

public slots:
    void timeOut();

private: //Funktionen
    void auslesenStoppen();
    void auslesenStarten();

private: //Membervariablen
    QTimer *timer;
    bool auslesen;
    bool helfer;


};

#endif // MYTIMER_H
