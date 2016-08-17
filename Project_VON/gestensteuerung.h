#include <QWidget>
#include <QPushButton>
#include <QProcess>
#include <vector>
#include <QVBoxLayout>
#include <QObject>
#include <iostream>
#include "notification.h"
#include "gespeichertewerte.h"
#ifndef GESTENSTEUERUNG_H
#define GESTENSTEUERUNG_H

using namespace std;

/**
 * @brief The Gestensteuerung class dient zur Steuerung des Diashowmoduses mit der Kinect
 */
class Gestensteuerung : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Gestensteuerung initialsiert alle Membervaribablen
     * @param buttons: *QVBoxLayout um dem leiste einen weitere Button zu uebergeben
     * @param parent: *QWidget, da die Klasse von QWidget erbt
     */
    Gestensteuerung(QVBoxLayout *buttons, QHBoxLayout *buttons2, QWidget *parent = 0);

    /**
     * @brief ~Gestensteuerung gibt genutzen Speicher wieder frei
     */
    virtual ~Gestensteuerung();


signals: //SIGNAL-Funktionen
    void verkleinereBild();
    void vergroessereBild();
    void dreheBild();
    void vorhereigesBild();
    void nachstesBild();


private slots: //SLOT-Funktionen
    void auslesen();
    void connectionAktivieren();


private: // Membervariablen
    QProcess *process;
    GespeichertWerte *speichert;
    vector<GespeichertWerte*> *alleGespeichertenWerte;
    vector<GespeichertWerte*> *alleWerte;
    Notification *n;
    QVBoxLayout *buttons;
    QPushButton *aktiv;
    unsigned int mengeAnG;


private: //Funktionen
    void gestenErkennung();
    void verkleinerGeste();
    void wischGeste();
    void drehGeste();
    void vergroesserGeste();
    void stil();
};

#endif // GESTENSTEUERUNG_H
