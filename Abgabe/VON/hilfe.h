#include <QObject>
#include <QString>
#include <QMessageBox>

#ifndef HILFE_H
#define HILFE_H

/**
 * @brief The Hilfe class dient zur Hilfe, falls der Nutzer diese benoetigt
 */
class Hilfe : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Hilfe initialisiert alle Memervariablen
     * @param fenster: *QWidget
     * @param parent: *QWidget
     */
    Hilfe();

    /**
     * @brief ~Hilfe gibt genutzen Speicher wieder frei
     */
    virtual ~Hilfe();

    /**
     * @brief hilfeAnzeigenZweitesFenster zeigt die Hilfestelltung für das zweite Fenster an
     */
    void hilfeAnzeigenZweitesFenster();

    /**
     * @brief hilfeAnzeigenZweitesFenster zeigt die Hilfestelltung für das erste Fenster an
     */
    void hilfeAnzeigenErstesFenster();


private: //Funktionen
    QMessageBox *information;
    QString text1;
    QString text2;
};

#endif // HILFE_H
