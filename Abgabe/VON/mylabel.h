#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
#include "datenbank.h"

#ifndef MYLABEL_H
#define MYLABEL_H

using namespace std;

/**
 * @brief The MyLabel class dient zur weiteren Nutzung der Bilder.
 *        QLabel wurde um eine Einfach- und eine Doppelklick erweitert
 */
class MyLabel: public QLabel
{
    Q_OBJECT
public:
    /**
     * @brief MyLabel initalisiert Membervaribalen, die in der Klasse genutzt werden
     * @param pfad: string ist der Pfad des Bilder
     * @param bank: *Datenbank ist eine Pointer auf die Datenbank, die im Hintergrund laeuft
     * @param parent: *QWidget, da von dieser Klasse geerbt wird
     */
    explicit MyLabel(string pfad, Datenbank *bank, QWidget *parent = 0);

    /**
     * @brief MyLabel
     * @param parent: *QWidget, da von dieser Klasse geerbt wird
     */
    MyLabel(QWidget* parent = 0);

    /**
     * @brief ~MyLabel gibt den Speicher frei, die in der Klasse genutzt wurde
     */
    virtual ~MyLabel();


public slots:
    /**
     * @brief bildBewertung zeigt die Bewertung des Bildes an
     */
    void bildBewertung();

    /**
     * @brief bildTags zeigt die Tags des Bildes an
     */
    void bildTags();


signals: //SIGNAL-Funktionen
    void pfadNutzen(std::string pfad);
    void tagsAnzeigen(QString tags);
    void bewertungAnzeigen(int bewertung);
    void diahow(string m_pfad);


private: //Funktionen
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    int buttonByNumber(const Qt::MouseButton button);
    QString enumNameFromValue(const Qt::MouseButton button);
    QString enumNamesFromMouseButtons(const Qt::MouseButtons buttons);


private: //Membervariablen
    string m_pfad;
    int bewertung;
    QString tags;
    Datenbank *bank;
};

#endif // MYLABEL_H

