#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QMessageBox>
#include <QScreen>
#include <iostream>
#include <QApplication>
#include <QWheelEvent>
#include "datenbank.h"
#include "gestensteuerung.h"

#ifndef DRITTESFENSTER_H
#define DRITTESFENSTER_H

using namespace std;

/**
 * @brief The drittesFenster class erzeugt den Diashowmodus und bietet die
 *        Möglichkeit Bilder zu bewerten, zu drehen, zu vergroeßers/verkleinern
 *        zwischen den Bildern zu wechseln bzw. wieder zurück zur Bildergalerie zu gehen.
 */
class drittesFenster : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief drittesDenster dient zur Initialisierung aller Membervariablen, die genutzt werden um den
     *        Diashowmodus darzustelen und mit ihm zu interagieren
     * @param fenster: *QWidget
     * @param bank: *Datenbank
     * @param parent: *QWidget
     */
    explicit drittesFenster(QWidget *fenster, Datenbank *bank, QWidget *parent = 0);

    /**
     * @brief ~drittesFenster dient dem frei machen von genutzem Speicher
     */
    virtual ~drittesFenster();

    /**
     * @brief erzeugeDrittesFenster erzeuge den Diashowmodus und stellt das Bild abhängig von der Auflösung des Bildschirmes dar
     * @param pfad: string ist der Pfad des Bildes, welches in der Bildergalerie angeklickt wurde um es m Diashowmodus darzustellen
     */
    void erzeugeDrittesFenster(string pfad);


private slots: //SLOT-Funktionen
    void verkleinereBild();
    void vergroessereBild();
    void bewertenEins();
    void bewertenZwei();
    void bewertenDrei();
    void bewertenVier();
    void bewertenFuenf();
    void bildDrehen();
    void naechstesBild();
    void vorherigesBild();


signals: //SIGANL-Funktionen
    void showBildergalerie();


private: // Funktionen
    virtual void wheelEvent(QWheelEvent* event);
    void vectorDurchsuchen();
    void interaktion();
    void vertikal();
    void fehlerMelden();
    void buttonsStyle();

private: //Membervariablen

    QWidget *m_fenster;
    QHBoxLayout *layout;
    QVBoxLayout *buttons;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPushButton *eins;
    QPushButton *zwei;
    QPushButton *drei;
    QPushButton *vier;
    QPushButton *fuenf;
    QPushButton *beenden;
    QGraphicsPixmapItem *item;
    Datenbank *m_bank;
    QPushButton *drehen;
    QPushButton *links;
    QPushButton *rechts;
    vector<string> *bilder;
    QMessageBox *information;
    QScreen *screen;
    Gestensteuerung *gesten;

    QSize size;
    bool bereitsDurchsucht;
    int index;
    string m_pfad;

};

#endif // DRITTESFENSTER_H
