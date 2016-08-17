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
#include <QApplication>

class erstesFenster : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief erstesFenster ist der Konstruktor der Klasse und zeigt das erstes Fenster der Applikation
     * @param fenster
     * @param parent
     */
    erstesFenster(QWidget *fenster, QTranslator *translator, Datenbank *bank, QWidget *parent = 0);

    /**
     * Dekonstruktor, welcher sich um die Löschung der Zeiger kümmern soll
     */
    virtual ~erstesFenster();

signals:
    void openSecondWindow();
    void showLetzteBilder();

private:

    void englischUebersetzung(); //vielleicht besser die beiden Methoden im zweitenFenster public machen?
    void deutschUebersetzung();

    /* für die Übersetzung */
    inline void changeEvent(QEvent *event)
    {
        if (event->type() == QEvent::LanguageChange) {
            startButton->setText(tr("Starting index"));
            letztenOrdnerButton->setText(tr("Show last images"));
            txt->setText(tr("<h1><strong>Please choose starting index</strong></h1>"));

        } else
            QWidget::changeEvent(event);
    }
    QTranslator *m_translator = new QTranslator();

    /* Zur Darstellung des Fensters */
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *startButton = new QPushButton("Startverzeichnis");
    QPushButton *letztenOrdnerButton = new QPushButton("Letzte Bilder anzeigen");
    QLabel *txt = new QLabel("<h1><strong>Bitte Startverzeichnis auswählen</strong></h1>");
    Sound *sound;
    Datenbank *m_bank;
    QPushButton *deutsch = new QPushButton();
    QPushButton *englisch = new QPushButton();
};

#endif // ERSTESFENSTER_H
