#include <QWidget>
#include <QPushButton>
#include "notification.h"
#include "gespeichertewerte.h"
#include <QProcess>
#include <vector>
#include <QVBoxLayout>
#include <QObject>

#ifndef GESTENSTEUERUNG_H
#define GESTENSTEUERUNG_H

using namespace std;

class Gestensteuerung : public QWidget
{
    Q_OBJECT
public:
    Gestensteuerung(QVBoxLayout *buttons, QWidget *parent = 0);
    ~Gestensteuerung();


signals:
    void verkleinereBild();
    void vergroessereBild();
    void dreheBild();
    void vorhereigesBild();
    void nachstesBild();


private:
    QProcess *process;
    GespeichertWerte *speichert;
    vector<GespeichertWerte*> *alleGespeichertenWerte;
    vector<GespeichertWerte*> *alleWerte;
    Notification *n;
    QVBoxLayout *buttons;
    QPushButton *aktiv;


private slots:
    void auslesen();
    void connectionAktivieren();


private:
    void gestenErkennung();
    void verkleinerGeste();
    void wischGeste();
    void drehGeste();
    void vergroesserGeste();
    unsigned int mengeAnG;
    void stil();
};

#endif // GESTENSTEUERUNG_H
