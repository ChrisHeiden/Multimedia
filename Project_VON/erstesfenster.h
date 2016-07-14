#ifndef ERSTESFENSTER_H
#define ERSTESFENSTER_H

#include "sound.h"
#include "datenbank.h"
#include "bildersuche.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>

class erstesFenster : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief erstesFenster ist der Konstruktor der Klasse und zeigt das erstes Fenster der Applikation
     * @param fenster
     * @param parent
     */
    erstesFenster(QWidget *fenster, QWidget *parent = 0);

    /**
     * Dekonstruktor, welcher sich um die Lösung der Zeiger kümmern soll
     */
    ~erstesFenster();

signals:
    void openSecondWindow();
    void showLetzteBilder();

private:

    /* für die Übersetzung */
    inline void changeEvent(QEvent *event)
    {
        if (event->type() == QEvent::LanguageChange) {
            startButton->setText(tr("Starting index"));
            letztenOrdnerButton->setText(tr("Show last images"));
            txt->setText(tr("Please choose starting index"));

        } else
            QWidget::changeEvent(event);
    }

    /* Zur Darstellung des Fensters */
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *startButton = new QPushButton(tr("Startverzeichnis"));
    QPushButton *letztenOrdnerButton = new QPushButton(tr("Letzte Bilder anzeigen"));
    QLabel *txt = new QLabel(tr("<h1><strong>Bitte Startverzeichnis auswählen</strong></h1>"));
    Sound *sound;
    Datenbank *bank;
};

#endif // ERSTESFENSTER_H
