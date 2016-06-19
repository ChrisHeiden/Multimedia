#ifndef HILFE_H
#define HILFE_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>


class Hilfe : public QWidget
{
    Q_OBJECT
public:

    Hilfe(QWidget *fenster, QWidget *parent = 0);
    void hilfeAnzeigen();

private:
    QWidget *m_fenster;
    QMessageBox *information = new QMessageBox();

};

#endif // HILFE_H
