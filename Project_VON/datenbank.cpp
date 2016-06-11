#include "datenbank.h"

using namespace std;

unsigned int Datenbank::IDZaehler = 1;

Datenbank::Datenbank(){

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("./testdatabase.db");

    if (!mydb.open())
    {
       //qDebug() << "Error: connection with database fail";
    }
    else
    {
       //qDebug() << "Database: connection ok";
    }

    /*QSqlQuery qry;
    qry.prepare( "Drop table Bilder" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
            qDebug() << "Table dropped!";*/

    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS Bilder (BildID integer primary key AUTOINCREMENT, Bildpfad text, Bildwertung integer check(Bildwertung between 0 and 5), Bildtags text)" );
    qry.exec();
    //if( !qry.exec() )
        //qDebug() << qry.lastError();
      //else
          //qDebug() << "Table created!" << IDZaehler;
}

/*bool Datenbank::DatenbankEmpty(){
    bool empty = false;
    QSqlQuery query("SELECT COUNT(*) FROM Bilder");
    int idName = query.record().indexOf();
    int count = query.value(idName).toInt();
    qDebug() << count;
    if(count == 0){
        empty = true;
    }
    return empty;
}*/

bool Datenbank::neuesBild(string Bildpfad){

    cout << "1" <<endl;
    bool erfolgreich = false;
    QString Pfad = QString::fromStdString(Bildpfad);
    QSqlQuery query;
    //query.prepare("INSERT INTO Bilder(BildID, Bildpfad, Bildwertung, Tags) values ((:BildID), (:Bildpfad), 3, 'TestTag')");
    query.prepare("INSERT INTO Bilder(BildID, Bildpfad) values (null,(:Bildpfad))");
    query.bindValue(":Bildpfad", Pfad);
    cout << "2" <<endl;

    if(query.exec())
    {
        erfolgreich = true;
        cout << "3" <<endl;

        //qDebug() << "Bild hinzugefuegt!"; //" ID: " <<  IDZaehler
        //IDZaehler++;
    }
    else
    {
        cout << "-1" <<endl;

        //qDebug() << "neuesBild error:  "
                  //<< query.lastError();
    }

    return erfolgreich;
}

bool Datenbank::BildExists(int ID){

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

bool Datenbank::BildLoeschen(int ID){
    bool erfolgreich = false;
    if (BildExists(ID))
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

void Datenbank::alleIDsAusgeben(){
    QSqlQuery query("SELECT BildID FROM Bilder");
    int idName = query.record().indexOf("BildID");
    while (query.next())
    {
       int ID = query.value(idName).toInt();
       qDebug() << ID;
    }
}

bool Datenbank::BildBewerten(int ID, int Bewertung){
    bool erfolgreich = false;
    if(BildExists(ID)){
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

int Datenbank::BewertungAnzeigen(int ID){
    int wertung = -1;
    if(BildExists(ID)){
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

bool Datenbank::BildtagsAendern(int ID, QString Tag){
    bool erfolgreich = false;
    if(BildExists(ID)){
        QString Tags = TagsAnzeigen(ID);

        Tags = Tags + ", " + Tag;
        QSqlQuery query;
        query.prepare("UPDATE Bilder SET Tags = (:Tags) WHERE BildID = (:BildID)");
        query.bindValue(":Tags", Tags);
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

QString Datenbank::TagsAnzeigen(int ID){
    QString Tags;
    if(BildExists(ID)){
        QSqlQuery query;
        query.prepare("SELECT Tags FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", ID);
        if(!query.exec()){
            qDebug() << "Query Error:" << query.lastError();
        }
        else{
            int idName = query.record().indexOf("Tags");
            while (query.next()){
                Tags = query.value(idName).toString();
                qDebug() << query.value(idName).toString();
            }
        }
    }
    return Tags;
}

