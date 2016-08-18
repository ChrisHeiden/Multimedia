#include "datenbank.h"

Datenbank::Datenbank(){

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("./imagedatabase.db");

    if (!mydb.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.prepare( "CREATE TABLE IF NOT EXISTS Bilder (BildID integer primary key AUTOINCREMENT, Bildpfad text, Bildwertung integer check(Bildwertung between 1 and 5), Bildtags text, Bild_dargestellt integer, Bildausrichtung integer)" ); //Bild_dargestellt 0 = false, 1 = true
      if( !query.exec() )
        qDebug() << "Datenbank anlegen Error:" << query.lastError();
      else
        qDebug() << "Table created!";
}

bool Datenbank::datenbankLoeschen(){
    QSqlQuery query;
    query.prepare( "Drop table Bilder" );
        if( !query.exec() ){
            qDebug() << query.lastError();
            return false;
        }
        else{
            qDebug() << "Table dropped!";
            return true;
        }
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

bool Datenbank::bildpfadExists(QString pfad){

    bool existiert = false;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bildpfad = (:Bildpfad)");
    query.bindValue(":Bildpfad", pfad);

    if (query.exec())
    {
       if (query.next())
       {
          existiert = true;
       }
    }
    return existiert;
}

bool Datenbank::bildExists(int id){

    bool existiert = false;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE BildID = (:BildID)");
    query.bindValue(":BildID", id);

    if (query.exec())
    {
       if (query.next())
       {
          existiert = true;
       }
    }
    return existiert;
}

bool Datenbank::neuesBild(QString bildpfad){

    bool erfolgreich = false;
    if(!bildpfadExists(bildpfad)){
        QSqlQuery query;
        //query.prepare("INSERT INTO Bilder(BildID, Bildpfad, Bildwertung, Tags, Bild_dargestellt) values ((:BildID), (:Bildpfad), 3, 'TestTag')");
        query.prepare("INSERT INTO Bilder(BildID, Bildpfad, Bild_dargestellt, Bildausrichtung) values (null,(:Bildpfad), 2, 0)");
        query.bindValue(":Bildpfad", bildpfad);
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
    }
    else{
        qDebug() << "Bild existiert bereits!";
        QSqlQuery query;
        query.prepare("UPDATE Bilder SET Bild_dargestellt = 2 WHERE Bildpfad = (:Bildpfad)");
        query.bindValue(":Bildpfad", bildpfad);

        if(query.exec())
        {
            erfolgreich = true;
            qDebug() << "Bild dargestellt!";
        }
        else
        {
            qDebug() << "neuesBild error:  "
                      << query.lastError();
        }
    }
    return erfolgreich;
}

void Datenbank::setAlleBilder_dargestelltFalse(){
    QSqlQuery query;
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 0 WHERE Bild_dargestellt = 2 AND Bild_dargestellt = 1");
    if(query.exec()){
        qDebug() << "Alle Bild_dargestellt auf false gesetzt";
    }
    else{
        qDebug() << "alleBilder_dargestelltFalse Error:" << query.lastError();
    }
}

void Datenbank::setBilder_dargestelltMemory(){
    QSqlQuery query;
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 1 WHERE Bild_dargestellt = 2");
    if(query.exec()){
        qDebug() << "Alle Bild_dargestellt auf false gesetzt";
    }
    else{
        qDebug() << "alleBilder_dargestelltFalse Error:" << query.lastError();
    }
}

void setAlleBilder_dargestelltTrue(){
    QSqlQuery query;
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 2 WHERE Bild_dargestellt = 1");
    if(query.exec()){
        qDebug() << "Alle Bild_dargestellt auf false gesetzt";
    }
    else{
        qDebug() << "alleBilder_dargestelltFalse Error:" << query.lastError();
    }
}

vector<string> Datenbank::getAlleBilder_dargestelltMemory(){
    vector<string> bildauswahl;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bild_dargestellt = 1");
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while(query.next()){
        QString bildpfad = query.value(idName).toString();
        string bild = bildpfad.toStdString();
        bildauswahl.push_back(bild);
        qDebug() << bildpfad;
    }
    return bildauswahl;
}

vector<string> Datenbank::getAlleBilder_dargestelltTrue(){
    vector<string> bildauswahl;
    QSqlQuery query;
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bild_dargestellt = 2");
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while(query.next()){
        QString bildpfad = query.value(idName).toString();
        string bild = bildpfad.toStdString();
        bildauswahl.push_back(bild);
        qDebug() << bildpfad;
    }
    return bildauswahl;
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

bool Datenbank::bildLoeschen(int id){
    bool erfolgreich = false;
    if (bildExists(id))
    {
       QSqlQuery query;
       query.prepare("DELETE FROM Bilder WHERE BildID = (:BildID)");
       query.bindValue(":BildID", id);

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

QString Datenbank::aktuellenBildPfadAnzeigen(int id){
    QString pfad = "";
    if(bildExists(id)){
        QSqlQuery query;
        query.prepare("SELECT Bildpfad FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", id);
        if(!query.exec()){
            qDebug() << "Query Error:" << query.lastError();
        }
        else{
            query.first();
            pfad = query.value(0).toString();
            qDebug() << pfad;
        }
    }
    return pfad;
}

bool Datenbank::bildBewerten(int id, int bewertung){
    bool erfolgreich = false;
    if(bildExists(id)){
        QSqlQuery query;
        query.prepare("UPDATE Bilder SET Bildwertung = (:Bildwertung) WHERE BildID = (:BildID)");
        query.bindValue(":Bildwertung", bewertung);
        query.bindValue(":BildID", id);

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

int Datenbank::bewertungAnzeigen(int id){
    int wertung = -1;
    if(bildExists(id)){
        QSqlQuery query;
        query.prepare("SELECT Bildwertung FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", id);
        if(!query.exec()){
            qDebug() << "Query Error:" << query.lastError();
        }
        else{
            query.first();
            wertung = query.value(0).toInt();
            //qDebug() << wertung;
        }
    }
    return wertung;
}

vector<string> Datenbank::bewertungFiltern(int filterwertung){
    setBilder_dargestelltMemory();
    vector<string> bildauswahl;
    QSqlQuery query;
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 2 WHERE Bildpfad IN (SELECT Bildpfad FROM Bilder WHERE Bildwertung = (:Bildwertung))");
    query.bindValue(":Bildwertung", filterwertung);
    query.exec();
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bildwertung = (:Bildwertung)");
    query.bindValue(":Bildwertung", filterwertung);
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString bildpfad = query.value(idName).toString();
       string pfad = bildpfad.toStdString();
       bildauswahl.push_back(pfad);
       qDebug() << bildpfad;
    }
    return bildauswahl;
}

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

QString Datenbank::bildtagsAnzeigen(int id){
    QString Tags = "";
    if(bildExists(id)){
        QSqlQuery query;
        query.prepare("SELECT Bildtags FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", id);
        if(!query.exec()){
            qDebug() << "bildtagsAnzeigen Error:" << query.lastError();
        }
        else{
            query.first();
            Tags = query.value(0).toString();
            qDebug() << query.value(0).toString();
        }
    }
    return Tags;
}

vector<string> Datenbank::bildtagsFiltern(QString filtertag){
    this->setBilder_dargestelltMemory();
    vector<string> bildauswahl;
    QSqlQuery query;
    QString filter = "%" + filtertag + "%";
    query.prepare("UPDATE Bilder SET Bild_dargestellt = 2 WHERE Bildpfad IN (SELECT Bildpfad FROM Bilder WHERE Bildtags LIKE (:Filtertag))");
    query.bindValue(":Filtertag", filter);
    query.exec();
    query.prepare("SELECT Bildpfad FROM Bilder WHERE Bildtags LIKE (:Filtertag)");
    query.bindValue(":Filtertag", filter);
    query.exec();
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString bildpfad = query.value(idName).toString();
       string pfad = bildpfad.toStdString();
       bildauswahl.push_back(pfad);
       qDebug() << bildpfad;
    }
    return bildauswahl;
}

void Datenbank::setNeueBildausrichtung(int id){
    if(bildExists(id)){
        QSqlQuery query;
        int neueAusrichtung;
        int alteAusrichtung = getBildausrichtung(id);
        if(alteAusrichtung == 270){
            neueAusrichtung = 0;
        }
        else{
            neueAusrichtung = alteAusrichtung + 90;
        }
        query.prepare("UPDATE Bilder SET Bildausrichtung = (:neueAusrichtung) WHERE BildID = (:BildID)");
        query.bindValue(":neueAusrichtung", neueAusrichtung);
        query.bindValue(":BildID", id);
        if(query.exec()){
            qDebug() << "Bild gedreht!";
        }
        else{
            qDebug() << "neueBildausrichtung Error:" << query.lastError();
        }
    }
}

int Datenbank::getBildausrichtung(int id){
    int ausrichtung = 0;
    if(bildExists(id)){
        QSqlQuery query;
        query.prepare("SELECT Bildausrichtung FROM Bilder WHERE BildID = (:BildID)");
        query.bindValue(":BildID", id);
        if(query.exec()){
            query.first();
            ausrichtung = query.value(0).toInt();
            qDebug() << ausrichtung;
        }
        else{
            qDebug() << "getBildausrichtung error:" << query.lastError();
        }
    }
    return ausrichtung;
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

void Datenbank::alleBilderAusgeben(){
    QSqlQuery query("SELECT Bildpfad FROM Bilder");
    int idName = query.record().indexOf("Bildpfad");
    while (query.next())
    {
       QString bildpfad = query.value(idName).toString();
       qDebug() << bildpfad;
    }
}
