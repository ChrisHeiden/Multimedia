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

class Datenbank
{
public:
    /**
     * @brief Datenbank
     * legt eine neue Datenbank an, falls noch keine existiert
     */
    Datenbank();

    /**
     * @brief datenbankLoeschen loescht die gesamte Datenbank
     * @return true, wenn Datenbank geloescht wurde, false, wenn nicht
     */
    bool datenbankLoeschen();

    bool bildpfadExists(QString Pfad);

    /**
     * @brief neuesBild speichert ein neues Bild in der Datenbank
     * @param Bildpfad Pfad, unter dem das Bild auf dem Computer des Nutzers zu finden ist
     * @return bool erfolgreich, ob das Bild hinzugefuegt wurde (true) oder nicht (false)
     */
    bool neuesBild(QString Bildpfad);

    /**
     * @brief bildExists ueberprueft, ob das Bild in der Datenbank existiert oder nicht
     * @param ID ID des Bildes, das gesucht wird
     * @return bool erfolgreich, ob das Bild existiert (true) oder nicht (false)
     */
    bool bildExists(int ID);

    /**
     * @brief bildLoeschen loescht ein Bild aus der Datenbank
     * @param ID ID des Bildes, das geloescht werden soll
     * @return bool erfolgreich, ob das Bild geloescht wurde (true) oder nicht (false)
     */
    bool bildLoeschen(int ID);

    /**
     * @brief aktuellenBildPfadAnzeigen gibt den Bildpfad einer bestimmten ID zurueck
     * @param ID ID des Bildes, dessen Pfad angezeigt werden soll
     * @return Bildpfad des Bildes mit der ausgewählten ID
     */
    QString aktuellenBildPfadAnzeigen(int ID);

    /**
     * @brief bildBewerten bewertet ein Bild in der Datenbank
     * @param ID ID des Bildes, das bewertet werden soll
     * @param Bewertung (von 1 bis 5) welche Bewertung das Bild erhalten soll
     * @return bool erfolgreich, ob das Bild bewertet werden konnte (true) oder nicht (false)
     */
    bool bildBewerten(int ID, int Bewertung);

    /**
     * @brief bildtagsAendern fuegt Tags zu einem Bild hinzu
     * @param ID ID des Bilds, das einen neuen Tag erhalten soll
     * @param Tag Tag, der hinzugefuegt werden soll
     * @return bool erfolgreich, ob der tag hinzugefuegt werden konnte (true) oder nicht (false)
     */
    bool bildtagsAendern(int ID, QString Tag);

    /**
     * @brief datenbankEmpty ueberprueft, ob die Datenbank leer ist
     * @return bool empty, ob die Datenbank leer ist (true) oder nicht (false)
     */
    bool datenbankEmpty();

    /**
     * @brief alleBilderAusgeben gibt alle Bildpfade aus der Datenbank in qDebug aus
     */
    void alleBilderAusgeben();

    /**
     * @brief bewertungAnzeigen zeigt die Bewertung eines Bildes an
     * @param ID ID des Bildes, dessen Bewertung angezeigt werden soll
     * @return int wertung die Bewertung des Bildes
     */
    int bewertungAnzeigen(int ID);

    /**
     * @brief bildtagsAnzeigen zeigt die Tags von einem Bild an
     * @param ID ID des Bildes, dessen Tags angezeigt werden sollen
     * @return Qstring Tags die Tags des Bildes
     */
    QString bildtagsAnzeigen(int ID);

    /**
     * @brief alleIDsAusgeben gibt in qDebug alle IDs aus, die in der Datenbank gespeichert sind
     */
    void alleIDsAusgeben();

    /**
     * @brief getID gibt die ID zu einem Bildpfad zurueck
     * @param pfad Pfad, dessen ID zurueckgeliefert werden soll
     * @return ID des Pfads
     */
    int getID(string pfad);

    /**
     * @brief bildtagsFiltern laesst den Nutzer nach Tags filtern
     * @param filtertags Tags, nach denen gefiltert werden soll
     * @return IDs, der Bilder mit den entsprechenden Tags
     */
    vector<string> bildtagsFiltern(QString filtertag);

    /**
     * @brief bewertungFiltern laesst den Nutzer nach einer bestimmten Bildwertung filtern
     * @param filterwertung Wertung, nach der gefiltert werden soll
     * @return IDs, der Bilder mit der ausgewählten wertung
     */
    vector<string> bewertungFiltern(int filterwertung);

    /**
     * @brief alleBilder_dargestelltFalse setzt das Bild_dargestellt-Attribut aller Bilder der Datenbank auf false
     */
    void setAlleBilder_dargestelltFalse();

    /**
     * @brief getAlleBilder_dargestelltTrue liefert alle Bilder zurueck, die angezeigt werden
     * @return vector mit allen Bilder, bei denen Bild_dargestellt true ist
     */
    vector<string> getAlleBilder_dargestelltTrue();

    void setAlleBilder_dargestelltTrue();

    vector<string> getAlleBilder_dargestelltMemory();

    void setBilder_dargestelltMemory();

    /**
     * @brief neueBildausrichtung setzt die Bildausrichtung eines Bildes neu, das gedreht wurde
     * @param id ID des Bildes, das gedreht wurde
     */
    void setNeueBildausrichtung(int id);

    /**
     * @brief getBildausrichtung gibt die Bildausrichtung eines Bildes zurueck
     * @param id ID des Bildes, dessen Ausrichtung zurueckgegeben wird
     * @return Bildausrichtung
     */
    int getBildausrichtung(int id);

private:
    QSqlDatabase mydb;

signals:

public slots:
};

#endif // DATENBANK_H

