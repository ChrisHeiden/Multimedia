#ifndef ZWEITESFENSTER_H
#define ZWEITESFENSTER_H

#include "Bildersuche.h"
#include "farben.h"
#include "hilfe.h"
#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollArea>
#include <QApplication>
#include <QTranslator>
#include <QTextEdit>

/**
 * @brief The zweitesFenster class erbt von QWidget und stellt das weite Fenster dar.
 */

class zweitesFenster : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief zweitesFenster
     * @param fenster
     * @param parent
     */
    explicit zweitesFenster(QWidget *fenster, QTranslator *translator, QWidget *parent = 0);

    /**
     * @brief erzeugeZweitesFenster stellt das zweite Fenster dar
     */
    void erzeugeZweitesFenster();

    /**
     * @brief ordnerVerzeichnis zeigt dem Nutzer seine Verzeichnisse, wodurch er sich das Verzeichnis
     *        selbst auswählen kann
     * @return QString ist der Pfad zu dem Verzeichnis, welches der Nutzer selbst auswählen konnte
     */
    QString ordnerVerzeichnis();

    /**
     * @brief letzter zeigt dem Nutzer die Bilder im Fenster, welche bei letzten Mal angeschaut wurden
     */
    void letzter();

    /**
     * @brief BilderDarstellen stellt die gefundenen Bilder, welche in QImages umgewandet wurden in
     *        im Fenster dar
     * @param qimages ist ein vector, welcher alle QImages entält
     */
    void BilderDarstellen(vector<QImage*> *qimages);



private:

    /* für die Darstelltung */
    QWidget *fenster;
    Datenbank *bank;
    QVBoxLayout *ganzesWindow = new QVBoxLayout;
    QGridLayout *oberesWindow = new QGridLayout;   //wird fenster übergeben
    QVBoxLayout *west = new QVBoxLayout;     //wird window übergeben und enthält Labels, Buttons und andere Layouts
    QVBoxLayout *center = new QVBoxLayout;   //wird später Bilder des Nutzers darstellen
    QVBoxLayout *menu = new QVBoxLayout;     //menu wird westpart übergeben
    QWidget *westpart = new QWidget;         //westpart entält das Menu mit allen Optionen
    QVBoxLayout *east = new QVBoxLayout;     //wird später Bilder des Nutzers darstellen
    QLineEdit *filtern = new QLineEdit;
    QHBoxLayout *south = new QHBoxLayout;
    QWidget *southpart = new QWidget;

    /* Für die Infobox */
    QLabel *tags = new QLabel("Tags:");
    QLabel *bildBewertung = new QLabel(tr("Sterne:"));
    QLabel *bildPfad = new QLabel(tr("Pfad:"));
    QLineEdit *tagsFeld = new QLineEdit ;
    QLineEdit *bildBewertungsFeld = new QLineEdit ;
    QLineEdit *bildPfadFeld = new QLineEdit;


    /* Für die Optionen */
    QLabel *filter = new QLabel(tr("Filter"));
    QLabel *hintergrund = new QLabel(tr("Hintergrund"));
    QLabel *anzahlBilder = new QLabel(tr("Anzahl Bilder"));
    QLabel *vollbild = new QLabel(tr("Vollbildmodus"));
    QRadioButton *vollbildmodus = new QRadioButton(tr("Vollbildmodus"));
    QLabel *option = new QLabel(tr("Optionen"));
    QPushButton *zwanzig = new QPushButton("20");
    QPushButton *vierzig = new QPushButton("40");
    QPushButton *sechsig = new QPushButton("60");
    QLabel *sprache = new QLabel(tr("Sprache"));
    QRadioButton *deutsch = new QRadioButton(tr("Deutsch"));
    QRadioButton *englisch = new QRadioButton(tr("Englisch"));
    QPushButton *vollbildModusDeaktiviern = new QPushButton(tr("Vollbildmodus deaktiviern"));
    QLabel *myLabel = new QLabel;
    BilderSuche *suche;
    QTranslator *m_translator;

    QPushButton *beenden;



    void schwarz();
    void beige();
    void weiss();
    void pink();
    void hilfeAngeklicket();
    void englischUebersetzung();
    void deutschUebersetzung();
    void vollbildModusAktiv();
    void vollbildModusInaktiv();


    /* für die Übersetzung */
    inline void changeEvent(QEvent *event)
    {
        if (event->type() == QEvent::LanguageChange) {
            filter->setText(tr("Filters"));
            hintergrund->setText(tr("Background"));
            anzahlBilder->setText(tr("Number of images"));
            vollbild->setText(tr("Full screen"));
            vollbildmodus->setText(tr("full screen mode"));
            option->setText(tr("Options"));
            zwanzig->setText(tr("20"));
            vierzig->setText(tr("40"));
            sechsig->setText(tr("60"));
            sprache->setText(tr("Language"));
            deutsch->setText(tr("German"));
            englisch->setText(tr("English"));
            vollbildModusDeaktiviern->setText(tr("deactivate full screen mode"));

        } else
            QWidget::changeEvent(event);
    }


signals:

public slots:
};

#endif // ZWEITESFENSTER_H
