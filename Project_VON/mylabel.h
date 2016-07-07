#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <iostream>

using namespace std;

class MyLabel: public QLabel
{
public:

    explicit MyLabel(string pfad, QWidget *parent = 0);

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
};

#endif // MYLABEL_H

