#include <QObject>
#include <QString>

#include <QMessageBox>



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
     * @brief hilfeAnzeigen zeigt die Hilfestelltung für den Nutzer an
     */
    void hilfeAnzeigenZweitesFenster();
    void hilfeAnzeigenErstesFenster();


private: //Funktionen
    QMessageBox *information;
    QString text;

};

#endif // HILFE_H
