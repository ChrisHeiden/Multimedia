#ifndef VOLLBILDMODUS_H
#define VOLLBILDMODUS_H
#include <QVBoxLayout>
#include <QLabel>
#include <QlineEdit>
#include <QPushButton>


class Vollbildmodus
{
public:
    Vollbildmodus(QVBoxLayout *west,  QLabel *tags, QLabel *bildBewertung, QLabel *bildPfad, QLineEdit *tagsFeld, QLineEdit *bildBewertungsFeld, QLineEdit *bildPfadFeld, QHBoxLayout *south);
    virtual ~Vollbildmodus();
    void inaktive();

private:
    QVBoxLayout *m_west;
    QLabel *m_tags;
    QLabel *m_bildBewertung;
    QLabel *m_bildPfad;
    QLineEdit *m_tagsFeld;
    QLineEdit *m_bildBewertungsFeld;
    QLineEdit *m_bildPfadFeld;
    QHBoxLayout *m_south;


};

#endif // VOLLBILDMODUS_H
