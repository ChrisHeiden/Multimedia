#ifndef FARBEN_H
#define FARBEN_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

/**
 * @brief The Farben class verändert die Farbe des dargestllten Fenstern in verschiedenen Farben
 */
class Farben
{
public:
    /**
     * @brief Farben ist der Konstruktor der Klasse Farben, welcher alle nötigen Objecs initalsiert
     * @param fenster
     * @param westpart
     * @param filter
     * @param hintergrund
     * @param anzahlBilder
     * @param vollbild
     * @param vollbildmodus
     * @param option
     * @param zwanzig
     * @param vierzig
     * @param sechsig
     * @param sprach
     * @param deutsch
     * @param englisch
     * @param vollbildModusDeaktiviern
     */
    Farben(QWidget *fenster, QWidget *westpart, QLabel *filter,
           QLabel *hintergrund, QLabel *anzahlBilder, QLabel *vollbild,
           QRadioButton *vollbildmodus, QLabel *option, QPushButton *zwanzig,
           QPushButton *vierzig, QPushButton *sechsig, QLabel *sprach,
           QRadioButton *deutsch, QRadioButton *englisch, QPushButton *vollbildModusDeaktiviern,
           QLabel *tags, QLabel *bildBewertung, QLabel *bildPfad, QLineEdit *tagsFeld,
           QComboBox *bildBewertungsFeld, QLineEdit  *bildPfadFeld, QLineEdit *filtern);

    /**
     * @brief schwarz verändert alle Elemente des dargestellten Fensters, sodass das Fenster schwarz
     *        dargestellt wird
     */
    void schwarz();

    /**
     * @brief beige verändert alle Elemente des dargestellten Fensters, sodass das Fenster beige
     *        dargestellt wird
     */
    void beige();

    /**
     * @brief weiss verändert alle Elemente des dargestellten Fensters, sodass das Fenster weiß
     *        dargestellt wird, welches auch der Standart ist
     */
    void weiss();

    /**
     * @brief pink verändert alle Elemente des dargestellten Fensters, sodass das Fenster pink
     *        dargestellt wird
     */
    void pink();

private:
    QWidget *m_fenster;
    QWidget *m_westpart;
    QLabel *m_filter;
    QLabel *m_hintergrund;
    QLabel *m_anzahlBilder;
    QLabel *m_vollbild;
    QRadioButton *m_vollbildmodus;
    QLabel *m_option;
    QPushButton *m_zwanzig;
    QPushButton *m_vierzig;
    QPushButton *m_sechsig;
    QLabel *m_sprache;
    QRadioButton *m_deutsch;
    QRadioButton *m_englisch;
    QPushButton *m_vollbildModusDeaktiviern;
    QLabel *m_tags;
    QLabel *m_bildBewertung;
    QLabel *m_bildPfad;
    QLineEdit *m_tagsFeld;
    QComboBox *m_bildBewertungsFeld;
    QLineEdit *m_bildPfadFeld;
    QLineEdit *m_filtern;

};

#endif // FARBEN_H
