#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QLabel>
#include <QString>
#include <iostream>
#include <string>

#ifndef DATENBANK_H
#define DATENBANK_H

using namespace std;

/**
 * @brief The Datenbank class erzeut eine Datenbank mit der die Applikation kommuniziert,
 *        um bestimmte Funktionen anzubieten
 */
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

    /**
     * @brief datenbankEmpty ueberprueft, ob die Datenbank leer ist
     * @return bool empty, ob die Datenbank leer ist (true) oder nicht (false)
     */
    bool datenbankEmpty();

    /**
     * @brief bildpfadExists ueberprueft, ob ein bestimmter Bildpfad bereits in der Datenbank existiert oder nicht
     * @param Pfad Bildpfad, der ueberprueft werden soll
     * @return true, wenn Bildpfad bereits existiert, false, wenn nicht
     */
    bool bildpfadExists(QString pfad);

    /**
     * @brief bildExists ueberprueft, ob das Bild in der Datenbank existiert oder nicht
     * @param ID ID des Bildes, das gesucht wird
     * @return bool erfolgreich, ob das Bild existiert (true) oder nicht (false)
     */
    bool bildExists(int id);

    /**
     * @brief neuesBild speichert ein neues Bild in der Datenbank
     * @param Bildpfad Pfad, unter dem das Bild auf dem Computer des Nutzers zu finden ist
     * @return bool erfolgreich, ob das Bild hinzugefuegt wurde (true) oder nicht (false)
     */
    bool neuesBild(QString bildpfad);

    /**
     * @brief alleBilder_dargestelltFalse setzt das Bild_dargestellt-Attribut aller Bilder der Datenbank auf false (0)
     */
    void setAlleBilder_dargestelltFalse();

    /**
     * @brief setBilder_dargestelltMemory setzt das Bild_dargestellt-Attribut aller angezeigten Bilder auf memory (1)
     */
    void setBilder_dargestelltMemory();

    /**
     * @brief setAlleBilder_dargestelltTrue setzt das Bild_dargestellt-Attribut aller Bilder der Datenbank auf true (2)
     */
    void setAlleBilder_dargestelltTrue();

    /**
     * @brief getAlleBilder_dargestelltTrue liefert alle Bilder zurueck, die angezeigt werden
     * @return vector mit allen Bilder, bei denen Bild_dargestellt true (2) ist
     */
    vector<string> getAlleBilder_dargestelltTrue();

    /**
     * @brief getAlleBilder_dargestelltMemory liefert alle Bilder zurueck, die den memory-Status (1) als Bild_dargestellt-Attribut haben
     * @return vector mit allen Bildern, bei denen Bild_dargestellt auf memory (1) gesetzt ist
     */
    vector<string> getAlleBilder_dargestelltMemory();

    /**
     * @brief aktuellenBildPfadAnzeigen gibt den Bildpfad einer bestimmten ID zurueck
     * @param ID ID des Bildes, dessen Pfad angezeigt werden soll
     * @return Bildpfad des Bildes mit der ausgewählten ID
     */
    QString aktuellenBildPfadAnzeigen(int id);

    /**
     * @brief bildBewerten bewertet ein Bild in der Datenbank
     * @param ID ID des Bildes, das bewertet werden soll
     * @param Bewertung (von 1 bis 5) welche Bewertung das Bild erhalten soll
     * @return bool erfolgreich, ob das Bild bewertet werden konnte (true) oder nicht (false)
     */
    bool bildBewerten(int id, int bewertung);

    /**
     * @brief bildtagsAendern fuegt Tags zu einem Bild hinzu
     * @param ID ID des Bilds, das einen neuen Tag erhalten soll
     * @param Tag Tag, der hinzugefuegt werden soll
     * @return bool erfolgreich, ob der tag hinzugefuegt werden konnte (true) oder nicht (false)
     */
    bool bildtagsAendern(int ID, QString Tag);

    /**
     * @brief bewertungAnzeigen zeigt die Bewertung eines Bildes an
     * @param ID ID des Bildes, dessen Bewertung angezeigt werden soll
     * @return int wertung die Bewertung des Bildes
     */
    int bewertungAnzeigen(int id);

    /**
     * @brief bildtagsAnzeigen zeigt die Tags von einem Bild an
     * @param ID ID des Bildes, dessen Tags angezeigt werden sollen
     * @return Qstring Tags die Tags des Bildes
     */
    QString bildtagsAnzeigen(int id);

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

    /**
     * @brief bildLoeschen loescht ein Bild aus der Datenbank
     * @param ID ID des Bildes, das geloescht werden soll
     * @return bool erfolgreich, ob das Bild geloescht wurde (true) oder nicht (false)
     * zum testen der Datenbank - kein Aufruf im Programm
     */
    bool bildLoeschen(int id);

    /**
     * @brief alleIDsAusgeben gibt in qDebug alle IDs aus, die in der Datenbank gespeichert sind
     * nur zum Testen der Datenbank - kein Aufruf im Programm
     */
    void alleIDsAusgeben();

    /**
     * @brief alleBilderAusgeben gibt alle Bildpfade aus der Datenbank in qDebug aus
     * nur zum Testen der Datenbank - kein Aufruf im Programm
     */
    void alleBilderAusgeben();

private: //Membervariablen
    QSqlDatabase mydb;

};

#endif // DATENBANK_H

