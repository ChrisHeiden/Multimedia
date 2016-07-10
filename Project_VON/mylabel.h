#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
#include "datenbank.h"

using namespace std;

class MyLabel: public QLabel
{
    Q_OBJECT
public:

    explicit MyLabel(string pfad, Datenbank *bank, QWidget *parent = 0);

    MyLabel(QWidget* parent = 0);

    string getPfad();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

    int     buttonByNumber(const Qt::MouseButton button);
    QString enumNameFromValue(const Qt::MouseButton button);
    QString enumNamesFromMouseButtons(const Qt::MouseButtons buttons);



private:
    string m_pfad;
    int bewertung;
    QString tags;
    Datenbank *bank;

public slots:
    void bildBewertung();
    void bildTags();


public:
signals:
void pfadNutzen(std::string pfad);
void tagsAnzeigen(QString tags);
void bewertungAnzeigen(int bewertung);
void diahow(string m_pfad);

};

#endif // MYLABEL_H

