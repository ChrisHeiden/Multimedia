#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

#ifndef FARBEN_H
#define FARBEN_H


/**
 * @brief The Farben class verändert die Farbe des dargestllten Fenstern in verschiedenen Farben
 */
class Farben
{
public:
    /**
     * @brief Farben ist der Konstruktor der Klasse Farben, welcher alle nötigen Objecs initalsiert
     * @param fenster: *QWidget
     * @param westpart: *QWidget
     * @param filter: *QLabel
     * @param hintergrund: *QLabel
     * @param anzahlBilder: *Qlabel
     * @param vollbild: *Label
     * @param vollbildmodus: *QPushButton
     * @param option: *QLabel
     * @param zwanzig: *QPushButton
     * @param vierzig: *QPushButton
     * @param sechsig: *QPushButton
     * @param sprach: *QLabel
     * @param tags: *QLabel
     * @param bildBewertung: *QLabel
     * @param bildPfad: *QLabel
     * @param tagsFeld: *QLineEdit
     * @param bildBewertungsFeld: *QComboBox
     * @param bildPfadFeld: *QLineEdit
     * @param filtern: *QLineEdit
     * @param vollbildModus: *QPushButton
     */
    Farben(QWidget *fenster, QWidget *westpart, QLabel *filter,
           QLabel *hintergrund, QLabel *anzahlBilder, QLabel *vollbild,
           QPushButton *vollbildmodus, QLabel *option, QPushButton *zwanzig,
           QPushButton *vierzig, QPushButton *sechsig, QLabel *sprach,
           QLabel *tags, QLabel *bildBewertung, QLabel *bildPfad, QLineEdit *tagsFeld,
           QComboBox *bildBewertungsFeld, QLineEdit  *bildPfadFeld, QLineEdit *filtern, QPushButton *vollbildModus);


    virtual ~Farben();
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

private: //Membervariablen
    QWidget *m_fenster;
    QWidget *m_westpart;
    QLabel *m_filter;
    QLabel *m_hintergrund;
    QLabel *m_anzahlBilder;
    QLabel *m_vollbild;
    QPushButton *m_vollbildmodus;
    QLabel *m_option;
    QPushButton *m_zwanzig;
    QPushButton *m_vierzig;
    QPushButton *m_sechsig;
    QLabel *m_sprache;
    QRadioButton *m_deutsch;
    QRadioButton *m_englisch;
    QLabel *m_tags;
    QLabel *m_bildBewertung;
    QLabel *m_bildPfad;
    QLineEdit *m_tagsFeld;
    QComboBox *m_bildBewertungsFeld;
    QLineEdit *m_bildPfadFeld;
    QLineEdit *m_filtern;
    QPushButton *m_vollbildModus;
};

#endif // FARBEN_H
