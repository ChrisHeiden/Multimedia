#include "datenbank.h"

unsigned int Datenbank::IDZaehler = 1;

Datenbank::Datenbank(){

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("./testdatabase.db");

    if (!mydb.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    /*QSqlQuery qry;
    qry.prepare( "Drop table Bilder" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
            qDebug() << "Table dropped!";*/

    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS Bilder (BildID integer primary key AUTOINCREMENT, Bildpfad text, Bildwertung integer check(Bildwertung between 1 and 5), Bildtags text, Bild_dargestellt integer)" ); //Bild_dargestellt 0 = false, 1 = true
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
          qDebug() << "Table created!";
}

bool Datenbank::datenbankEmpty(){
    bool empty = false;
    QSqlQuery query("SELECT COUNT(*) FROM Bilder");
    query.first();
    int count = query.value(0).toInt();
    if(count == 0){
        empty = true;
    }
    return empty;
}

bool Datenbank::bildpfadExists(QString Pfad){

    bool existiert = false;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bildpfad = (:Bildpfad)");
    query.bindValue(":Bildpfad", Pfad);

    if (query.exec())
    {
       if (query.next())
       {
          existiert = true;
       }
    }
    return existiert;
}

bool Datenbank::neuesBild(QString Bildpfad){

    bool erfolgreich = false;
    if(!bildpfadExists(Bildpfad)){
        QSqlQuery query;
        //query.prepare("INSERT INTO Bilder(BildID, Bildpfad, Bildwertung, Tags, Bild_dargestellt) values ((:BildID), (:Bildpfad), 3, 'TestTag')");
        query.prepare("INSERT INTO Bilder(BildID, Bildpfad, Bild_dargestellt) values (null,(:Bildpfad), 1)");
        query.bindValue(":Bildpfad", Bildpfad);
        if(query.exec())
        {
            erfolgreich = true;
            qDebug() << "Bild hinzugefuegt!"; //" ID: " <<  IDZaehler
            //IDZaehler++;
        }
        else
        {
            qDebug() << "neuesBild error:  "
                      << query.lastError();
        }
    }
    else{
        qDebug() << "Bild existiert bereits!";
    }

    return erfolgreich;
}

int Datenbank::getID(string pfad){
    QString qPfad = QString::fromStdString(pfad);
    if(bildpfadExists(qPfad)){
        int ID;
        QSqlQuery query;
        query.prepare("SELECT BildID FROM Bilder WHERE Bildpfad = (:Bildpfad)");
        query.bindValue(":Bildpfad", qPfad);
        if(query.exec()){

            query.first();
            ID = query.value(0).toInt();
            qDebug() << "ID gefunden:" << ID;
        }
        else{
            qDebug() << "ID nicht gefunden";
        }
        return ID;
    }
    else{
        return -1;
    }
}

bool Datenbank::bildExists(int ID){

    bool existiert = false;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE BildID = (:BildID)");
    query.bindValue(":BildID", ID);

    if (query.exec())
    {
       if (query.next())
       {
          existiert = true;
       }
    }
    return existiert;
}

bool Datenbank::bildLoeschen(int ID){
    bool erfolgreich = false;
    if (bildExists(ID))
    {
       QSqlQuery query;
       query.prepare("DELETE FROM Bilder WHERE BildID = (:BildID)");
       query.bindValue(":BildID", ID);

       if(query.exec())
       {
           erfolgreich = true;
           qDebug() << "Bild geloescht!";
       }
       else
       {
           qDebug() << "Bildloeschen error:  "
                     << query.lastError();
       }

    }
    return erfolgreich;
}

void Datenbank::alleBilderAusgeben(){
    QSqlQuery query("SELECT Bildpfad FROM Bilder");
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString Bildpfad = query.value(idName).toString();
       qDebug() << Bildpfad;
    }
}

QString Datenbank::aktuellenBildPfadAnzeigen(int ID){
    QString Pfad = "";
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE BildID = (:BildID)");
    query.bindValue(":BildID", ID);
    if(!query.exec()){
        qDebug() << "Query Error:" << query.lastError();
    }
    else{
        query.first();
        Pfad = query.value(0).toString();
        qDebug() << Pfad;
    }
    return Pfad;
}

void Datenbank::alleIDsAusgeben(){
    QSqlQuery query("SELECT BildID FROM Bilder");
    int idName = query.record().indexOf("BildID");
    while (query.next())
    {
       int ID = query.value(idName).toInt();
       qDebug() << ID;
    }
}

bool Datenbank::bildBewerten(int ID, int Bewertung){
    bool erfolgreich = false;
    if(bildExists(ID)){
        QSqlQuery query;
        query.prepare("UPDATE Bilder SET Bildwertung = (:Bildwertung) WHERE BildID = (:BildID)");
        query.bindValue(":Bildwertung", Bewertung);
        query.bindValue(":BildID", ID);

        if(query.exec())
        {
            erfolgreich = true;
            qDebug() << "Bild bewertet!";
        }
        else
        {
            qDebug() << "Bildbewerten error:  "
                      << query.lastError();
        }
    }
    return erfolgreich;
}

int Datenbank::bewertungAnzeigen(int ID){
    int wertung = -1;
    if(bildExists(ID)){
        QSqlQuery query;
        query.prepare("SELECT Bildwertung FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", ID);
        if(!query.exec()){
            qDebug() << "Query Error:" << query.lastError();
        }
        else{
            int idName = query.record().indexOf("Bildwertung");
            while (query.next())
            {
               wertung = query.value(idName).toInt();
               //qDebug() << wertung;
            }
        }
    }
    return wertung;
}

vector<QString> Datenbank::bewertungFiltern(int filterwertung){
    alleBilder_dargestelltFalse();
    vector<QString> bildauswahl;
    QSqlQuery query;
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 1 WHERE Bildpfad IN (SELECT Bildpfad FROM Bilder WHERE Bildwertung = (:Bildwertung))");
    query.bindValue(":Bildwertung", filterwertung);
    query.exec();
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bildwertung = (:Bildwertung)");
    query.bindValue(":Bildwertung", filterwertung);
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString Bildpfad = query.value(idName).toString();
       bildauswahl.push_back(Bildpfad);
       qDebug() << Bildpfad;
    }
    return bildauswahl;
}

/* ALT
bool Datenbank::bildtagsAendern(int ID, QString Tag){
    bool erfolgreich = false;
    if(bildExists(ID)){
        QString alteTags = bildtagsAnzeigen(ID);
        qDebug() << alteTags;

        alteTags = alteTags + ", " + Tag;
        QSqlQuery query;
        query.prepare("UPDATE Bilder SET Bildtags = (:Bildtags) WHERE BildID = (:BildID)");
        query.bindValue(":Bildtags", alteTags);
        query.bindValue(":BildID", ID);

        if(query.exec())
        {
            erfolgreich = true;
            qDebug() << "Tags geaendert!";
        }
        else
        {
            qDebug() << "BildtagsAendern error:  "
                      << query.lastError();
        }
    }
    return erfolgreich;
}*/

bool Datenbank::bildtagsAendern(int ID, QString Tag){
    bool erfolgreich = false;
    if(bildExists(ID)){
        QSqlQuery query;
        query.prepare("UPDATE Bilder SET Bildtags = (:Bildtags) WHERE BildID = (:BildID)");
        query.bindValue(":Bildtags", Tag);
        query.bindValue(":BildID", ID);

        if(query.exec())
        {
            erfolgreich = true;
            qDebug() << "Tags geaendert!";
        }
        else
        {
            qDebug() << "BildtagsAendern error:  "
                      << query.lastError();
        }
    }
    return erfolgreich;
}

QString Datenbank::bildtagsAnzeigen(int ID){
    QString Tags = "";
    if(bildExists(ID)){
        QSqlQuery query;
        query.prepare("SELECT Bildtags FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", ID);
        if(!query.exec()){
            qDebug() << "bildtagsAnzeigen Error:" << query.lastError();
        }
        else{
            int idName = query.record().indexOf("Bildtags");
            while (query.next()){
                Tags = query.value(idName).toString();
                qDebug() << query.value(idName).toString();
            }
        }
    }
    return Tags;
}

vector<QString> Datenbank::bildtagsFiltern(QString filtertag){
    this->alleBilder_dargestelltFalse();
    vector<QString> bildauswahl;
    QSqlQuery query;
    QString filter = "%" + filtertag + "%";
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 1 WHERE Bildpfad IN (SELECT Bildpfad FROM Bilder WHERE Bildtags LIKE (:Filtertag))");
    query.bindValue(":Filtertag", filter);
    query.exec();
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bildtags LIKE (:Filtertag)");
    query.bindValue(":Filtertag", filter);
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString Bildpfad = query.value(idName).toString();
       bildauswahl.push_back(Bildpfad);
       qDebug() << Bildpfad;
    }
    return bildauswahl;
}

void Datenbank::alleBilder_dargestelltFalse(){
    QSqlQuery query;
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 0 WHERE Bild_dargestellt = 1");
    if(query.exec()){
        qDebug() << "Alle Bild_dargestellt auf false gesetzt";
    }
    else{
        qDebug() << "alleBilder_dargestelltFalse Error:" << query.lastError();
    }
}

vector<QString> Datenbank::getAlleBilder_dargestelltTrue(){
    vector<QString> bildauswahl;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bild_dargestellt = 1");
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while(query.next()){
        QString Bildpfad = query.value(idName).toString();
        bildauswahl.push_back(Bildpfad);
        qDebug() << Bildpfad;
    }
    return bildauswahl;
}

