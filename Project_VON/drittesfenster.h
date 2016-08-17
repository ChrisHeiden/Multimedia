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
 *        zwischen den Bildern zu wechseln, wieder zurück zur Bildergalerie zu gehen.
 */
class drittesFenster : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief drittesDenster dient zur Initialisierung aller Membervariablen, die genutzt werden um den
     *        Diashowmodus darzustelen und mit ihm zu interagieren
     * @param fenster
     * @param parent
     */
    explicit drittesFenster(QWidget *fenster, Datenbank *bank, QWidget *parent = 0);

    /**
     * @brief ~drittesFenster dient dem frei machen von genutzem Speicher
     */
    virtual ~drittesFenster();

    /**
     * @brief erzeugeDrittesFenster erzeuge den Diashowmodus und stellt es dar abhängig von der Auflösung des Bildschirmes
     * @param pfad ist der Pfad des Bildes, welches in der Bildergalerie angeklickt wurde um es m Diashowmodus darzustellen
     */
    void erzeugeDrittesFenster(string pfad);

    /**
     * @brief bewertenEins bewertet das sichtbare Bild mit einer Eins
     */
    void bewertenEins();

    /**
     * @brief bewertenZwei bewertet das sichtbare Bild mit einer Zwei
     */
    void bewertenZwei();

    /**
     * @brief bewertenDrei bewertet das sichtbare Bild mit einer Drei
     */
    void bewertenDrei();

    /**
     * @brief bewertenVier bewertet das sichtbare Bild mit einer Vier
     */
    void bewertenVier();

    /**
     * @brief bewertenFuenf bewertet das sichtbare Bild mit einer Fuenf
     */
    void bewertenFuenf();

    /**
     * @brief bildDrehen dreht das gezeigte Bild um 45 Grad
     */
    void bildDrehen();

    /**
     * @brief naechstesBild stellt das nächste Bild dar, welches in der Bildergalerie dargestellt wurde
     */
    void naechstesBild();

    /**
     * @brief vorherigesBild stellt das vorherige Bild dar, welches in der Bildergalerie dargestellt wurde
     */
    void vorherigesBild();

    /**
     * @brief fehlerMelden erzeugt eine Fehlermeldung, wenn das Bild nicht gefunden wurde um es darzustellen
     */
    void fehlerMelden();

    /**
     * @brief buttonsStyle designed die Buttons, welche dargestellt werden sollen
     */
    void buttonsStyle();

public slots: //SLOT-Funktionen
    /**
     * @brief verkleinereBild verkleinert das Bild
     */
    void verkleinereBild();

    /**
     * @brief vergroessereBild vergrößert das Bild
     */
    void vergroessereBild();


signals: //SIGANL-Funktionen
    void showBildergalerie();


private: // Funktionen
    virtual void wheelEvent(QWheelEvent* event);
    void vectorDurchsuchen();
    void interaktion();
    void vertikal();
    void horizontal();

private: //Membervariablen

    QWidget *m_fenster;
    QHBoxLayout *layout;
    QVBoxLayout *layout2;
    QVBoxLayout *buttons;
    QHBoxLayout *buttons2;
    QVBoxLayout *fuellung1;
    QVBoxLayout *fuellung2;
    QHBoxLayout *fuellung3;
    QHBoxLayout *fuellung4;
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
    string m_pfad;
    QPushButton *drehen;
    QPushButton *links;
    QPushButton *rechts;
    vector<string> *bilder;
    QMessageBox *information;
    QScreen *screen;
    Gestensteuerung *gesten;

    QImage image;
    bool bereitsDurchsucht;
    unsigned int index;
};

#endif // DRITTESFENSTER_H
