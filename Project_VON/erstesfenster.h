#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QTranslator>
#include <QApplication>
#include "sound.h"
#include "datenbank.h"
#include "bildersuche.h"

#ifndef ERSTESFENSTER_H
#define ERSTESFENSTER_H

/**
 * @brief The erstesFenster class
 */
class erstesFenster : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief erstesFenster ist der Konstruktor der Klasse und zeigt das erstes Fenster der Applikation
     * @param fenster: *QWidget
     * @param translator: *translator
     * @param bank: *Datenbank
     * @param parent: *QWidget
     */
    erstesFenster(QWidget *fenster, QTranslator *translator, Datenbank *bank, QWidget *parent = 0);

    /**
     * Dekonstruktor, welcher sich um die Freigebung des Speichers kuemmert
     */
    virtual ~erstesFenster();


signals: //SIGNAL-Funktionen
    void openSecondWindow();
    void showLetzteBilder();


private: //Funktionen
    void englischUebersetzung();
    void deutschUebersetzung();
    inline void changeEvent(QEvent *event)
    {
        if (event->type() == QEvent::LanguageChange) {
            startButton->setText(tr("Starting index"));
            letztenOrdnerButton->setText(tr("Show last images"));
            txt->setText(tr("<h1><strong>Please choose starting index</strong></h1>"));

        } else
            QWidget::changeEvent(event);
    }


private: //Membervariablen
    QTranslator *m_translator;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *startButton;
    QPushButton *letztenOrdnerButton;
    QLabel *txt;
    Sound *sound;
    Datenbank *m_bank;
    QPushButton *deutsch;
    QPushButton *englisch;
};

#endif // ERSTESFENSTER_H
