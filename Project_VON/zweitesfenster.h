#ifndef ZWEITESFENSTER_H
#define ZWEITESFENSTER_H

#include "Bildersuche.h"
#include "farben.h"
#include "hilfe.h"
#include "datenbank.h"
#include "mylabel.h"
#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <map>
#include <QScrollArea>
#include <QApplication>
#include <QTranslator>
#include <QTextEdit>
#include <iostream>

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
    explicit zweitesFenster(QWidget *fenster, QTranslator *translator,Datenbank *bank, QWidget *parent = 0);

    virtual ~zweitesFenster();

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
    void BilderDarstellen(map<string, QImage *> *qimages);

    /**
     * @brief zweitesFenster::optionsleisteDarstellen stellt die Optionsleiste dar
     */
    void optionsleisteDarstellen();


    /* Ab hier ist was verändert */
    string m_pfad;


private:

    /* für die Darstelltung im Fenster */
    QWidget *fenster;
    Datenbank *m_bank;
    QVBoxLayout *ganzesWindow = new QVBoxLayout;
    QGridLayout *oberesWindow = new QGridLayout;   //wird fenster übergeben
    QVBoxLayout *west = new QVBoxLayout;     //wird window übergeben und enthält Labels, Buttons und andere Layouts
    QVBoxLayout *center = new QVBoxLayout;   //wird später Bilder des Nutzers darstellen
    QVBoxLayout *menu = new QVBoxLayout;     //menu wird westpart übergeben
    QWidget *westpart = new QWidget;         //westpart entält das Menu mit allen Optionen
    QVBoxLayout *east = new QVBoxLayout;     //wird später Bilder des Nutzers darstellen
    QHBoxLayout *south = new QHBoxLayout;
    QWidget *southpart = new QWidget;

    /* Für die Infobox -> Southpart */
    QLabel *tags = new QLabel("Tags:");
    QLabel *bildBewertung = new QLabel(tr("Sterne:"));
    QLabel *bildPfad = new QLabel(tr("Pfad:"));
    QLineEdit *tagsFeld = new QLineEdit;
    QComboBox *bildBewertungsFeld = new QComboBox;
    QLineEdit *bildPfadFeld = new QLineEdit;



    /* Für die Optionen -> Westpart */
    QLabel *option = new QLabel(tr("Optionen"));
    QLabel *hintergrund = new QLabel(tr("Hintergrund"));
    QLabel *anzahlBilder = new QLabel(tr("Bildergröße"));
    QPushButton *zwanzig = new QPushButton;
    QPushButton *vierzig = new QPushButton;
    QPushButton *sechsig = new QPushButton;
    QLabel *vollbild = new QLabel(tr("Vollbildmodus"));
    QPushButton *vollbildmodus = new QPushButton("X");
    QPushButton *vollbildModusDeaktiviern = new QPushButton(tr("Vollbildmodus deaktiviern"));
    QLabel *sprache = new QLabel(tr("Sprache"));
    QRadioButton *deutsch = new QRadioButton(tr("Deutsch"));
    QRadioButton *englisch = new QRadioButton(tr("Englisch"));
    QLabel *filter = new QLabel(tr("Filter"));
    QPushButton *filterAufloesen;
    QLineEdit *filtern;
    QString filternNachTags;
    int m_bilderAnzahl;
    string pfad;

    BilderSuche *suche;
    QTranslator *m_translator;
    QPushButton *beenden;

    QPushButton *schwarz;
    QPushButton *weiss;
    QPushButton *beige;
    QPushButton *rose;

    QGridLayout *farben;
    QGridLayout *farb;
    QWidget *farbenWidget;

    QGridLayout *bilder;
    QGridLayout *bild;
    QWidget *bilderWidget;


    QWidget *vollWidget;
    QPushButton *filteraktivieren;
    QGridLayout *filt;
    QWidget *filterWidget;

    QHBoxLayout *sterne;
    QPushButton *eins;
    QPushButton *zwei;
    QPushButton *drei;
    QPushButton *vier;
    QPushButton *fuenf;
    QPushButton *hilfe;
    QVBoxLayout *menu2;


    QHBoxLayout *language;
    QVBoxLayout *sprachen;
    QWidget *sprachenWidget;
    MyLabel *l;
    QMessageBox *information;

    void bildtagsAendern();
    void bildBewertungAendern();
    void nachEinsFiltern();
    void nachZweiFiltern();
    void nachDreiFiltern();
    void nachVierFiltern();
    void nachFuenfFiltern();
    void nachTagFiltern(QString tag);


    void schwarzFunktion();
    void beigeFunktion();
    void weissFunktion();
    void pinkFunktion();
    void hilfeAngeklicket();
    void englischUebersetzung();
    void deutschUebersetzung();
    void vollbildModusAktiv();
    void vollbildModusInaktiv();
    void ungefiltert(); //Hier muss das stehen, was man benötig, um alle Bilder dazustellen, welche vor dem Filtern angezeigt wurden


    void zwanzigBilder();
    void vierzigBilder();
    void sechsigBilder();



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
    void bildBewertet(int zahl);
    void bildTagsGesetzt(string tags);
    void openThirdWindow(string m_pfad);

public slots:
    void setPfad(std::string pfad);
    void tagsInInfoleisteAnzeige(QString tags);
    void bewertungInInfoleisteAnzeige(int bewertung);

};

#endif // ZWEITESFENSTER_H
