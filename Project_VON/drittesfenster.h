#ifndef DRITTESFENSTER_H
#define DRITTESFENSTER_H

#include "datenbank.h"
#include <QPushButton>
#include <QGridLayout>


class drittesFenster : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief drittesDenster
     * @param fenster
     * @param parent
     */
    explicit drittesFenster(QWidget *fenster, QWidget *parent = 0);

    virtual ~drittesFenster();
    /**
     * @brief erzeuge drittes Fenster und stellt es dar
     */
    void erzeugeDrittesFenster();

    /**
     * @brief bildInGrossDarstellen zeigt dem Nutzer das gewünschte Bild in einer Diashow
     */
    void bildInGrossDarstellen();


private:

    QWidget *m_fenster;
    QPushButton *eins;
    QPushButton *zwei;
    QPushButton *drei;
    QPushButton *vier;
    QPushButton *fuenf;
    QPushButton *beenden;
    Datenbank *bank;
    QGridLayout *layout;

signals:

public slots:
};

#endif // DRITTESFENSTER_H
