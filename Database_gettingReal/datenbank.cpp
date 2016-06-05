#include "datenbank.h"

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
    qry.prepare( "CREATE TABLE IF NOT EXISTS Bilder (BildID integer primary key, Bildpfad text, Bildwertung integer check(Bildwertung between 1 and 5), Tags text)" );
      if( !qry.exec() )
        qDebug() << qry.lastError();
      else
        qDebug() << "Table created!";

}

bool Datenbank::neuesBild(int ID, QString Bildpfad){

    bool erfolgreich = false;
    QSqlQuery query;
    query.prepare("INSERT INTO Bilder(BildID, Bildpfad, Bildwertung, Tags) values ((:BildID), (:Bildpfad), 3, 'TestTag')");
    query.bindValue(":BildID", ID);
    query.bindValue(":Bildpfad", Bildpfad);
    if(query.exec())
    {
        erfolgreich = true;
        qDebug() << "Bild hinzugefuegt!";
    }
    else
    {
        qDebug() << "neuesBild error:  "
                  << query.lastError();
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

bool Datenbank::Bildloeschen(int ID){
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
    /*qry.prepare("select Bildpfad from Bilder where BildID = 1");
    qDebug()<<qry.exec()<<endl;

    QSqlQuery query("SELECT * FROM Bilder");
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString name = query.value(idName).toString();
       qDebug() << name;
    }

     qry.prepare("insert into Bilder(BildID, Bildname, Bildwertung, Tags) values (1, 'Testbild', 3, 'Ferien, Ostsee, Strand')");
     qDebug()<<qry.exec()<<endl;

     */

