#ifndef SPRACHEN_H
#define SPRACHEN_H

#include <QTranslator>
#include <QApplication>
#include <QDebug>
#include <QObject>

/**
 * @brief The Sprachen class dient zur Übersetzt der Objecte in der Apllikation
 */
class Sprachen: public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Sprachen initialisiert alle Variablen, die in der der Klasse gebraucht werden
     * @param translator: *QTranslator
     */
    Sprachen(QTranslator *translator);

    /**
     * @brief ~Sprachen gibt genutzen Speicher frei
     */
    virtual ~Sprachen();

    /**
     * @brief englischUebersetzung übersetzt die Object in Englisch
     */
    void englischUebersetzung();

    /**
     * @brief deutschUebersetzung übersetzt die Object in Deutsch
     */
    void deutschUebersetzung();

private:
    QTranslator *m_translator;
};

#endif // SPRACHEN_H
