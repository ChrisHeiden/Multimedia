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
#include "Bildersuche.h"
#include "farben.h"
#include "hilfe.h"
#include "datenbank.h"
#include "mylabel.h"
#ifndef ZWEITESFENSTER_H
#define ZWEITESFENSTER_H

/**
 * @brief The zweitesFenster class erbt von QWidget und stellt das weite Fenster dar.
 */

class zweitesFenster : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief zweitesFenster
     * @param fenster: *QWidget
     * @param translator: *QTranslator
     * @param bank: *Datenbank
     * @param parent: *QWidget
     */
    explicit zweitesFenster(QWidget *fenster, QTranslator *translator,Datenbank *bank, QWidget *parent = 0);

    /**
     * @brief ~zweitesFenster dient zur Freigebung des Speichers
     */
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
     * @param qimages: map<string, QImage *>* ist ein vector, welcher alle QImages entält
     */
    void BilderDarstellen(map<string, QImage *> *qimages);

    /**
     * @brief zweitesFenster::optionsleisteDarstellen stellt die Optionsleiste dar
     */
    void optionsleisteDarstellen();


signals: //SIGNAL-Funktionen
    void bildBewertet(int zahl);
    void bildTagsGesetzt(string tags);
    void openThirdWindow(string m_pfad);


public slots: //SLOT-Funktionen
    void setPfad(std::string pfad);
    void tagsInInfoleisteAnzeige(QString tags);
    void bewertungInInfoleisteAnzeige(int bewertung);


private: //Membervariablen
    /* für die Darstelltung im Fenster */
    QWidget *fenster;
    Datenbank *m_bank;
    QVBoxLayout *ganzesWindow;
    QGridLayout *oberesWindow ;
    QVBoxLayout *west;
    QVBoxLayout *center;
    QVBoxLayout *menu;
    QWidget *westpart;
    QVBoxLayout *east;
    QHBoxLayout *south;
    QWidget *southpart;

    /* Für die Infobox -> Southpart */
    QLabel *tags;
    QLabel *bildBewertung;
    QLabel *bildPfad ;
    QLineEdit *tagsFeld;
    QComboBox *bildBewertungsFeld;
    QLineEdit *bildPfadFeld;

    /* Für die Optionen -> Westpart */
    QLabel *option;
    QLabel *hintergrund;
    QLabel *anzahlBilder;
    QPushButton *zwanzig;
    QPushButton *vierzig;
    QPushButton *sechsig;
    QLabel *vollbild;
    QPushButton *vollbildmodus;
    QPushButton *vollbildModusDeaktiviern;
    QLabel *sprache;
    QPushButton *deutsch;
    QPushButton *englisch;
    QLabel *filter;
    QPushButton *filterAufloesen;
    QLineEdit *filtern;

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
    vector<string> *gefilterteBilder;
    std::map<string, QImage*> *umgewandelteBilder;
    QHBoxLayout *menu3;
    Farben *f;

    QString gewuenschterPfad;
    QString filternNachTags;
    int m_bilderAnzahl;
    string pfad;
    string m_pfad;

private: //Funktionen
    void setzeSignals();
    void bildtagsAendern();
    void bildBewertungAendern();
    void nachEinsFiltern();
    void nachZweiFiltern();
    void nachDreiFiltern();
    void nachVierFiltern();
    void nachFuenfFiltern();
    void nachTagFiltern(QString tag);
    void interaktion();
    void schwarzFunktion();
    void beigeFunktion();
    void weissFunktion();
    void pinkFunktion();
    void hilfeAngeklicket();
    void englischUebersetzung();
    void deutschUebersetzung();
    void vollbildModusAktiv();
    void vollbildModusInaktiv();
    void ungefiltert();
    void zwanzigBilder();
    void vierzigBilder();
    void sechsigBilder();
    void labelStil();
    void buttonsStil();
    void fensterStil();
    inline void changeEvent(QEvent *event)
    {
        if (event->type() == QEvent::LanguageChange) {
            filter->setText(tr("Filters"));
            hintergrund->setText(tr("Background"));
            anzahlBilder->setText(tr("Number of images"));
            vollbild->setText(tr("Full screen")); //Wo steht das???
            option->setText(tr("Options"));
            sprache->setText(tr("Language"));
            bildBewertung->setText(tr("Stars:"));
            bildPfad->setText(tr("Path:"));

        } else
            QWidget::changeEvent(event);
    }
};

#endif // ZWEITESFENSTER_H
