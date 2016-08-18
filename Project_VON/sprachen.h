#ifndef SPRACHEN_H
#define SPRACHEN_H

#include <QTranslator>
#include <QApplication>
#include <QDebug>
#include <QObject>

class Sprachen: public QObject
{
    Q_OBJECT

public:
    Sprachen(QTranslator *translator);

    virtual ~Sprachen();

    void englischUebersetzung();
    void deutschUebersetzung();

private:
    QTranslator *m_translator;
};

#endif // SPRACHEN_H
