#include "farben.h"

Farben::Farben(QWidget *fenster, QWidget *westpart, QLabel *filter, QLabel *hintergrund,
               QLabel *anzahlBilder,QLabel *vollbild, QRadioButton *vollbildmodus, QLabel *option,
               QPushButton *zwanzig, QPushButton *vierzig, QPushButton *sechsig, QLabel *sprache, QRadioButton *deutsch,
               QRadioButton *englisch, QPushButton *vollbildModusDeaktiviern,  QLabel *tags, QLabel *bildBewertung,
               QLabel *bildPfad, QLineEdit *tagsFeld, QComboBox *bildBewertungsFeld, QLineEdit  *bildPfadFeld, QLineEdit *filtern)
{
    m_fenster = fenster;
    m_westpart = westpart;
    m_filter = filter;
    m_hintergrund = hintergrund;
    m_anzahlBilder = anzahlBilder;
    m_vollbild = vollbild;
    m_vollbildmodus = vollbildmodus;
    m_option = option;
    m_zwanzig = zwanzig;
    m_vierzig = vierzig;
    m_sechsig = sechsig;
    m_sprache = sprache;
    m_deutsch = deutsch;
    m_englisch = englisch;
    m_vollbildModusDeaktiviern = vollbildModusDeaktiviern;

    m_tags = tags;
    m_bildBewertung = bildBewertung;
    m_bildPfad = bildPfad;
    m_tagsFeld = tagsFeld;
    m_bildBewertungsFeld = bildBewertungsFeld;
    m_bildPfadFeld = bildPfadFeld;
    m_filtern = filtern;
}

void Farben::schwarz(){
    m_fenster->setStyleSheet("background-color:black;");
    m_westpart->setStyleSheet("background-color: rbg(33,30,33);");
    m_filter->setStyleSheet("color: rgb(199,187,187);");
    m_hintergrund->setStyleSheet("color: rgb(199,187,187);");
    m_anzahlBilder->setStyleSheet("color: rgb(199,187,187);");
    m_vollbild->setStyleSheet("color: rgb(199,187,187);");
    m_vollbildmodus->setStyleSheet("color: rgb(199,187,187);");
    m_option->setStyleSheet("color: rgb(199,187,187);");

    m_zwanzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 60px; height: 60px;");
    m_vierzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 40px; height: 40px;");
    m_sechsig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 20px; height: 20px;");

    m_sprache->setStyleSheet("color: rgb(199,187,187);");
    m_deutsch->setStyleSheet("color: rgb(199,187,187);");
    m_englisch->setStyleSheet("color: rgb(199,187,187);");
    m_vollbildModusDeaktiviern->setStyleSheet("background-color: rbg(33,30,33); color: rgb(199,187,187); border: none; margin: 0px; padding: 0px; width: 100px; height: 50px;");

    m_tags->setStyleSheet("color: rgb(199,187,187);");
    m_bildBewertung->setStyleSheet("color: rgb(199,187,187);");
    m_bildPfad->setStyleSheet("color: rgb(199,187,187);");

    m_tagsFeld->setStyleSheet("background-color: back; color: gray");
    m_bildBewertungsFeld->setStyleSheet("background-color: back; color: gray");
    m_bildPfadFeld->setStyleSheet("background-color: rbg(33,30,33); color: gray");
    m_filtern->setStyleSheet("background-color: rbg(33,30,33); color: gray");

    m_fenster->update();
}

void Farben::beige(){
    m_fenster->setStyleSheet("background-color:beige;");
    m_westpart->setStyleSheet("background-color:rgb(245,230,199);");
    m_filter->setStyleSheet("color: rgb(245,194,93);");
    m_hintergrund->setStyleSheet("color: rgb(245,194,93);");
    m_anzahlBilder->setStyleSheet("color: rgb(245,194,93);");
    m_vollbild->setStyleSheet("color: rgb(245,194,93);");
    m_vollbildmodus->setStyleSheet("color: rgb(245,194,93);");
    m_option->setStyleSheet("color: rgb(245,194,93);");


    m_zwanzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 60px; height: 60px;");
    m_vierzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 40px; height: 40px;");
    m_sechsig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 20px; height: 20px;");

    m_sprache->setStyleSheet("color: rgb(245,194,93);");
    m_deutsch->setStyleSheet("color: rgb(245,194,93);");
    m_englisch->setStyleSheet("color: rgb(245,194,93);");
    m_vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(245,230,199); color: rgb(245,194,93); border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");

    m_tags->setStyleSheet("color: rgb(245,194,93);");
    m_bildBewertung->setStyleSheet("color: rgb(245,194,93);");
    m_bildPfad->setStyleSheet("color: rgb(245,194,93);");

    m_tagsFeld->setStyleSheet("background-color: beige; color: rgb(245,194,93)");
    m_bildBewertungsFeld->setStyleSheet("background-color:beige; color: rgb(245,194,93)");
    m_bildPfadFeld->setStyleSheet("background-color:rgb(245,230,199); color: rgb(245,194,93)");
    m_filtern->setStyleSheet("background-color: beige; color: rgb(245,194,93)");

    m_fenster->update();
}

void Farben::weiss(){
    m_fenster->setStyleSheet("background-color:white;");
    m_westpart->setStyleSheet("background-color:rgb(189, 195, 199);");
    m_filter->setStyleSheet("color: black;");
    m_hintergrund->setStyleSheet("color: black;");
    m_anzahlBilder->setStyleSheet("color: black;");
    m_vollbild->setStyleSheet("color: black;");
    m_vollbildmodus->setStyleSheet("color: black;");
    m_option->setStyleSheet("color: black;");

    m_zwanzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 60px; height: 60px;");
    m_vierzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 40px; height: 40px;");
    m_sechsig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 20px; height: 20px;");

    m_sprache->setStyleSheet("color: black;");
    m_deutsch->setStyleSheet("color: black;");
    m_englisch->setStyleSheet("color: black;");
    m_vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(189, 195, 199); color: black; border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");

    m_tags->setStyleSheet("color: black;");
    m_bildBewertung->setStyleSheet("color: black;");
    m_bildPfad->setStyleSheet("color: black;");

    m_tagsFeld->setStyleSheet("background-color: white; color: black");
    m_bildBewertungsFeld->setStyleSheet("background-color: white; color: white");
    m_bildPfadFeld->setStyleSheet("background-color: grey; color: white");
    m_filtern->setStyleSheet("background-color: white; color: black");

    m_fenster->update();
}

void Farben::pink(){
    m_fenster->setStyleSheet("background-color:pink;");
    m_westpart->setStyleSheet("background-color:rgb(240,192,240);");
    m_filter->setStyleSheet("color: rgb(171,19,171);");
    m_hintergrund->setStyleSheet("color: rgb(171,19,171);");
    m_anzahlBilder->setStyleSheet("color: rgb(171,19,171);");
    m_vollbild->setStyleSheet("color: rgb(171,19,171);");
    m_vollbildmodus->setStyleSheet("color: rgb(171,19,171);");
    m_option->setStyleSheet("color: rgb(171,19,171);");

    m_zwanzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 60px; height: 60px;");
    m_vierzig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 40px; height: 40px;");
    m_sechsig->setStyleSheet("background-color: rgb(255,250,250); border: none; margin: 0px; padding: 0px; width: 20px; height: 20px;");

    m_sprache->setStyleSheet("color: rgb(171,19,171);");
    m_deutsch->setStyleSheet("color: rgb(171,19,171);");
    m_englisch->setStyleSheet("color: rgb(171,19,171);");
    m_vollbildModusDeaktiviern->setStyleSheet("background-color:rgb(240,192,240); color: rgb(171,19,171); border: none; margin: 0px;padding: 0px; width: 100px; height: 50px;");

    m_tags->setStyleSheet("color: rgb(171,19,171);");
    m_bildBewertung->setStyleSheet("color: rgb(171,19,171);");
    m_bildPfad->setStyleSheet("color: rgb(171,19,171);");

    m_tagsFeld->setStyleSheet("background-color: pink; color: rgb(171,19,171); ");
    m_bildBewertungsFeld->setStyleSheet("background-color: pink; color: rgb(171,19,171);");
    m_bildPfadFeld->setStyleSheet("background-color: rgb(240,192,240); color: rgb(171,19,171);");

    m_fenster->update();
}
