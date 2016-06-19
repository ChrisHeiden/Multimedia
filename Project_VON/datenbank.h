#ifndef DATENBANK_H
#define DATENBANK_H

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QLabel>
#include <QString>
#include <iostream>
#include <string>

using namespace std;
/**
 * @brief The Datenbank class stellt eine Datenbank dar, mit der innerhalbd er Applikation
 *        gearbeitet wird, um Bilder zu speichern, diese zu Bewerten oder zu Filtern
 */
class Datenbank{

public:
    /**
     * @brief Datenbank
     * legt eine neue Datenbank an, falls noch keine existiert
     */
    Datenbank();

    /**
     * @brief neuesBild speichert ein neues Bild in der Datenbank
     * @param Bildpfad Pfad, unter dem das Bild auf dem Computer des Nutzers zu finden ist
     * @return bool erfolgreich, ob das Bild hinzugefuegt wurde (true) oder nicht (false)
     */
    bool neuesBild(string Bildpfad);

    /**
     * @brief BildExists ueberprueft, ob das Bild in der Datenbank existiert oder nicht
     * @param ID ID des Bildes, das gesucht wird
     * @return bool erfolgreich, ob das Bild existiert (true) oder nicht (false)
     */
    bool BildExists(int ID);

    /**
     * @brief BildLoeschen loescht ein Bild aus der Datenbank
     * @param ID ID des Bildes, das geloescht werden soll
     * @return bool erfolgreich, ob das Bild geloescht wurde (true) oder nicht (false)
     */
    bool BildLoeschen(int ID);

    /**
     * @brief BildBewerten bewertet ein Bild in der Datenbank
     * @param ID ID des Bildes, das bewertet werden soll
     * @param Bewertung (von 1 bis 5) welche Bewertung das Bild erhalten soll
     * @return bool erfolgreich, ob das Bild bewertet werden konnte (true) oder nicht (false)
     */
    bool BildBewerten(int ID, int Bewertung);

    /**
     * @brief BildtagsAendern fuegt Tags zu einem Bild hinzu
     * @param ID ID des Bilds, das einen neuen Tag erhalten soll
     * @param Tag Tag, der hinzugefuegt werden soll
     * @return bool erfolgreich, ob der tag hinzugefuegt werden konnte (true) oder nicht (false)
     */
    bool BildtagsAendern(int ID, QString Tag);

    /**
     * @brief DatenbankEmpty ueberprueft, ob die Datenbank leer ist
     * @return bool empty, ob die Datenbank leer ist (true) oder nicht (false)
     */
    //bool DatenbankEmpty();

    /**
     * @brief alleBilderAusgeben gibt alle Bildpfade aus der Datenbank in qDebug aus
     */
    void alleBilderAusgeben();

    /**
     * @brief BewertungAnzeigen zeigt die Bewertung eines Bildes an
     * @param ID ID des Bildes, dessen Bewertung angezeigt werden soll
     * @return int wertung die Bewertung des Bildes
     */
    int BewertungAnzeigen(int ID);

    /**
     * @brief TagsAnzeigen zeigt die Tags von einem Bild an
     * @param ID ID des Bildes, dessen Tags angezeigt werden sollen
     * @return Qstring Tags die Tags des Bildes
     */
    QString TagsAnzeigen(int ID);

    /**
     * @brief alleIDsAusgeben gibt in qDebug alle IDs aus, die in der Datenbank gespeichert sind
     */
    void alleIDsAusgeben();

    /**
     * @brief liefert den IDZaehler zurück
     * @return int: IDZaehler
     */
    int getID();

private:
    QSqlDatabase mydb;
    static unsigned int IDZaehler;

signals:

public slots:
};

#endif // DATENBANK_H
