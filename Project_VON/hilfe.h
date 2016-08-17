#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>

#ifndef HILFE_H
#define HILFE_H

/**
 * @brief The Hilfe class dient zur Hilfe, falls der Nutzer diese benoetigt
 */
class Hilfe : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Hilfe initialisiert alle Memervariablen
     * @param fenster: *QWidget
     * @param parent: *QWidget
     */
    Hilfe(QWidget *fenster, QWidget *parent = 0);

    /**
     * @brief hilfeAnzeigen zeigt die Hilfestelltung für den Nutzer an
     */
    void hilfeAnzeigen();


private: //Funktionen
    QWidget *m_fenster;
    QMessageBox *information = new QMessageBox();
};

#endif // HILFE_H
