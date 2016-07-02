#include "vollbildmodus.h"

Vollbildmodus::Vollbildmodus(QVBoxLayout *west,  QLabel *tags, QLabel *bildBewertung, QLabel *bildPfad, QLineEdit *tagsFeld, QLineEdit *bildBewertungsFeld, QLineEdit *bildPfadFeld, QHBoxLayout south)
{

    m_west = west;
    m_tags = tags;
    m_bildBewertung = bildBewertung;
    m_bildPfad = bildPfad;
    m_tagsFeld = tagsFeld;
    m_bildBewertungsFeld = bildBewertungsFeld;
    m_bildPfadFeld = bildPfadFeld;
    m_south = south;
    beenden = new QPushButton("ESC");
}

Vollbildmodus::~Vollbildmodus(){

    delete (m_west);
    delete (m_tags);
    delete (m_bildBewertung);
    delete (m_bildPfad);
    delete (m_tagsFeld);
    delete (m_bildBewertungsFeld);
    delete (m_bildPfadFeld);
    delete (beenden);

}

void Vollbildmodus::inaktive(){

    m_west->setHidden(true);
    m_tags->setHidden(true);
    m_bildBewertung->setHidden(true);
    m_bildPfad->setHidden(true);
    m_tagsFeld->setHidden(true);
    m_bildBewertungsFeld->setHidden(true);
    m_bildPfadFeld->setHidden(true);

    m_south->addWidget(beenden);

}
