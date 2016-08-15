#ifndef DRITTESFENSTER_H
#define DRITTESFENSTER_H

#include "datenbank.h"
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QMessageBox>

using namespace std;


class drittesFenster : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief drittesDenster
     * @param fenster
     * @param parent
     */
    explicit drittesFenster(QWidget *fenster, Datenbank *bank, QWidget *parent = 0);

    virtual ~drittesFenster();
    /**
     * @brief erzeuge drittes Fenster und stellt es dar
     */
    void erzeugeDrittesFenster(string pfad);

    void bewertenEins();
    void bewertenZwei();
    void bewertenDrei();
    void bewertenVier();
    void bewertenFuenf();
    void bildDrehen();

    void naechstesBild();
    void vorherigesBild();
    int vectorDurchsuchen();
    void fehlerMelden();
    void vertikal();
    void horizontal();
    void interaktion();
    void buttonleisteErzeugen();
    void buttonsStyle();
private:

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
    QImage image;
    bool bereitsDurchsucht = false;
    unsigned int index;

    virtual void wheelEvent(QWheelEvent* event);

signals:
    void showBildergalerie();
};

#endif // DRITTESFENSTER_H
