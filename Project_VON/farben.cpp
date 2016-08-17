#include "farben.h"

Farben::Farben(QWidget *fenster, QWidget *westpart, QLabel *filter, QLabel *hintergrund,
               QLabel *anzahlBilder, QLabel *vollbild, QPushButton *vollbildmodus, QLabel *option,
               QPushButton *zwanzig, QPushButton *vierzig, QPushButton *sechsig, QLabel *sprache,
               QLabel *tags, QLabel *bildBewertung, QLabel *bildPfad, QLineEdit *tagsFeld,
               QComboBox *bildBewertungsFeld, QLineEdit  *bildPfadFeld, QLineEdit *filtern, QPushButton *vollbildModus)
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

    m_tags = tags;
    m_bildBewertung = bildBewertung;
    m_bildPfad = bildPfad;
    m_tagsFeld = tagsFeld;
    m_bildBewertungsFeld = bildBewertungsFeld;
    m_bildPfadFeld = bildPfadFeld;
    m_filtern = filtern;
    m_vollbildModus = vollbildModus;
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
    m_tags->setStyleSheet("color: rgb(199,187,187);");
    m_bildBewertung->setStyleSheet("color: rgb(199,187,187);");
    m_bildPfad->setStyleSheet("color: rgb(199,187,187);");

    m_tagsFeld->setStyleSheet("background-color: back; color: gray");
    m_bildBewertungsFeld->setStyleSheet("background-color: back; color: gray");
    m_bildPfadFeld->setStyleSheet("background-color: rbg(33,30,33); color: gray");
    m_filtern->setStyleSheet("background-color: rbg(33,30,33); color: gray");
    m_vollbildModus->setStyleSheet("border: none; margin: 0px; padding: 0px; background-color: tomato; width: 30px; height: 25px;"); //farbe noch ändern

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

    m_tags->setStyleSheet("color: rgb(245,194,93);");
    m_bildBewertung->setStyleSheet("color: rgb(245,194,93);");
    m_bildPfad->setStyleSheet("color: rgb(245,194,93);");

    m_tagsFeld->setStyleSheet("background-color: beige; color: rgb(245,194,93)");
    m_bildBewertungsFeld->setStyleSheet("background-color:beige; color: rgb(245,194,93)");
    m_bildPfadFeld->setStyleSheet("background-color:rgb(245,230,199); color: rgb(245,194,93)");
    m_filtern->setStyleSheet("background-color: beige; color: rgb(245,194,93)");
    m_vollbildModus->setStyleSheet("border: none; margin: 0px; padding: 0px; background-color: tomato; width: 30px; height: 25px;"); //farbe noch ändern

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

    m_tags->setStyleSheet("color: black;");
    m_bildBewertung->setStyleSheet("color: black;");
    m_bildPfad->setStyleSheet("color: black;");

    m_tagsFeld->setStyleSheet("background-color: white; color: black");
    m_bildBewertungsFeld->setStyleSheet("background-color: white; color: white");
    m_bildPfadFeld->setStyleSheet("background-color: grey; color: white");
    m_filtern->setStyleSheet("background-color: white; color: black");
    m_vollbildModus->setStyleSheet("border: none; margin: 0px; padding: 0px; background-color: tomato; width: 30px; height: 25px;"); //farbe noch ändern

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


    m_tags->setStyleSheet("color: rgb(171,19,171);");
    m_bildBewertung->setStyleSheet("color: rgb(171,19,171);");
    m_bildPfad->setStyleSheet("color: rgb(171,19,171);");

    m_tagsFeld->setStyleSheet("background-color: pink; color: rgb(171,19,171); ");
    m_bildBewertungsFeld->setStyleSheet("background-color: pink; color: rgb(171,19,171);");
    m_bildPfadFeld->setStyleSheet("background-color: rgb(240,192,240); color: rgb(171,19,171);");
    m_vollbildModus->setStyleSheet("border: none; margin: 0px; padding: 0px; background-color: tomato; width: 30px; height: 25px;"); //farbe noch ändern

    m_fenster->update();
}
