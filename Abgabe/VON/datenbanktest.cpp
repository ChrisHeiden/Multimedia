#include "datenbanktest.h"

datenbanktest::datenbanktest(QObject *parent) : QObject(parent)
{
   //testbank = new Datenbank();
}

void datenbanktest::initTestCase(){
   testbank = new Datenbank();
}

void datenbanktest::datenbankEmptyTrue(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode datenbankEmpty im, wenn die Datenbank leer ist
   //Vorbedingungen: Es gibt keine Einträge in der Datenbank.
   //erwartete Ausgabe: true
   //Testergebnis: bestanden
   QVERIFY(testbank->datenbankEmpty() == true);
}

void datenbanktest::neuesBild(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode neuesBild im Normalfall
   //Vorbedingungen: den Bildpfad gibt es noch nicht in der Datenbank
   //Eingabe: Bildpfad: ./Testbild.jpg
   //erwartete Ausgabe: true, weil das Bild erfolgreich hinzugefuegt wird
   //Testergebnis: bestanden
   QVERIFY(testbank->neuesBild("./Testbild.jpg") == true);
}

void datenbanktest::datenbankEmptyFalse(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode datenbankEmptyFalse, wenn die Datenbank nicht leer ist
   //Vorbedingungen: Die Datenbank ist nicht mehr leer.
   //erwartete Ausgabe: false, weil Datenbank nicht mehr leer ist
   //Testergebnis: bestanden
   QVERIFY(testbank->datenbankEmpty() == false);
}

void datenbanktest::bildpfadExistsTrue(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildpfadExists im Normalfall
   //Vorbedingungen: Der Bildpfad existiert in der Datenbank.
   //Eingabe: Bildpfad: ./Testbild.jpg
   //erwartete Ausgabe: true
   //Testergebnis: bestanden
   QVERIFY(testbank->bildpfadExists("./Testbild.jpg") == true);
}

void datenbanktest::bildpfadExistsFalse(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildpfadExists, wenn ein Bildpfad nicht existiert
   //Vorbedingungen: Den Bildpfad gibt es nicht in der Datenbank.
   //Eingabe: Bildpfad: ./Affe.jpg
   //erwartete Ausgabe: false, weil der Bildpfad nicht existiert
   //Testergebnis: bestanden
   QVERIFY(testbank->bildpfadExists("./Affe.jpg") == false);
}

void datenbanktest::bildExistsTrue(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode bildExists im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //Eingabe: ID: 1
   //erwartete Ausgabe: true
   //Testergebnis: bestanden
   QVERIFY(testbank->bildExists(1) == true);
}

void datenbanktest::bildExistsFalse(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode bildExists, wenn die ID nicht existiert
   //Vorbedingungen: Den ID gibt es nicht in der Datenbank.
   //Eingabe: ID: 100
   //erwartete Ausgabe: false, weil die BildID nicht existiert
   //Testergebnis: bestanden
   QVERIFY(testbank->bildExists(100) == false);
}

void datenbanktest::getIDTrue(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode getID im Normalfall
   //Vorbedingungen: Der Bildpfad ist in der Datenbank vorhanden.
   //Eingabe: Bildpfad: ./Testbild.jpg
   //erwartete Ausgabe: 1 (1 ist die ID des Bildpfads ./Testbild.jpg in der Datenbank)
   //Testergebnis: bestanden
   QVERIFY(testbank->getID("./Testbild.jpg") == 1);
}

void datenbanktest::getIDFalse(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode getID, wenn der Bildpfad nicht in der Datenbank existiert
   //Vorbedingungen: Es gibt den Bildpfad nicht in der Datenbank.
   //Eingabe: Bildpfad: ./Affe.jpg
   //erwartete Ausgabe: -1, weil es den Pfad nicht in der Datenbank gibt
   //Testergebnis: bestanden
   QCOMPARE(testbank->getID("./Affe.jpg"), -1);
}

void datenbanktest::bildBewertenTrue(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildBewerten im Normalfall
   //Vorbedingungen: Es gibt ein Bild mit der ID 1 und die Bewertung ist eine Zahl von 1 bis 5.
   //Eingabe: ID: 1, Bewertung: 3
   //erwartete Ausgabe: true
   //Testergebnis: bestanden
   QVERIFY(testbank->bildBewerten(1, 3) == true);
}

void datenbanktest::bildBewertenFalse(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildBewerten, wenn die Bewertung nicht zwischen 1 und 5 liegt
   //Vorbedingungen: Es gibt ein Bild mit der ID 1 in der Datenbank, aber die Bewertung ist keine Zahl von 1 bis 5.
   //Eingabe: ID: 1, Bewertung: 7
   //erwartete Ausgabe: false
   //Testergebnis: bestanden
   QVERIFY(testbank->bildBewerten(1, 7) == false);
}

void datenbanktest::bildtagsAendernTrue(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildtagsAendern im Normalfall
   //Vorbedingungen: Es gibt ein Bild mit der ID 1.
   //Eingabe: ID: 1 Tag: Test
   //erwartete Ausgabe: true
   //Testergebnis: bestanden
   QVERIFY(testbank->bildtagsAendern(1, "Test") == true);
}

void datenbanktest::bildtagsAendernFalse(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildtagsAendern, wenn die ID nicht existiert
   //Vorbedingungen: Die ID existiert nicht in der Datenbank.
   //Eingabe: ID: 5 Tag: Tier
   //erwartete Ausgabe: false
   //Testergebnis: bestanden
   QVERIFY(testbank->bildtagsAendern(5, "Tier") == false);
}

void datenbanktest::aktuellenBildPfadAnzeigenTrue(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode aktuellenBildPfadAnzeigen im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //erwartete Ausgabe: "./Testbild.jpg"
   //Testergebnis: bestanden
   QString pfad = testbank->aktuellenBildPfadAnzeigen(1);
   QVERIFY("./Testbild.jpg" == pfad.toStdString());
}

void datenbanktest::aktuellenBildPfadAnzeigenFalse(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode aktuellenBildPfadAnzeigen, wenn die ID nicht existiert
   //Vorbedingungen: Die ID existiert nicht in der Datenbank.
   //erwartete Ausgabe: ""
   //Testergebnis: bestanden
   QString pfad = testbank->aktuellenBildPfadAnzeigen(99);
   QVERIFY("" == pfad.toStdString());
}

void datenbanktest::bewertungAnzeigen(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bewertungAnzeigen im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //Eingabe: ID: 1
   //erwartete Ausgabe: 3
   //Testergebnis: bestanden
   QVERIFY(testbank->bewertungAnzeigen(1) == 3);
}

void datenbanktest::bildtagsAnzeigen(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildtagsAnzeigen im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //Eingabe: ID: 1
   //erwartete Ausgabe: "Test"
   //Testergebnis: bestanden
   QVERIFY(testbank->bildtagsAnzeigen(1) == "Test");
}

void datenbanktest::getBildausrichtung(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode getBildausrichtung im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //Eingabe: ID: 1
   //erwartete Ausgabe: 0
   //Testergebnis: bestanden
   QVERIFY(testbank->getBildausrichtung(1) == 0);
}

void datenbanktest::bildDrehen(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode setNeueBildausrichtung im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //erwartete Ausgabe: 90
   //Testergebnis: bestanden
   testbank->setNeueBildausrichtung(1); //Bild wird um 90° gedreht
   QVERIFY(testbank->getBildausrichtung(1) == 90);
}

void datenbanktest::bewertungFiltern(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode bewertungFiltern im Normalfall
   //Vorbedingungen: Es gibt Bilder mit der Bewertung 3 in der Datenbank.
   //Eingabe: 3
   //erwartete Ausgabe: "./Testbild.jpg"
   //Testergebnis: bestanden
   vector<string> gefilterteBilder;
   gefilterteBilder = testbank->bewertungFiltern(3);
   QVERIFY(gefilterteBilder.at(0) == "./Testbild.jpg");
}

void datenbanktest::bildtagsFiltern(){
   //Autor: Delia Metzler
   //Testdatum: 18.08.2016
   //getestet wird die Methode bildtagsFiltern im Normalfall
   //Vorbedingungen: Es gibt Bilder mit dem gesuchten tag in der Datenbank.
   //Eingabe: Test
   //erwartete Ausgabe: "./Testbild.jpg"
   //Testergebnis: bestanden
   vector<string> gefilterteBilder;
   gefilterteBilder = testbank->bildtagsFiltern("Test");
   QVERIFY(gefilterteBilder.at(0) == "./Testbild.jpg");
}

void datenbanktest::bildLoeschenFalse(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildLoeschen, wenn die ID nicht existiert
   //Vorbedingungen: Die ID existiert nicht in der Datenbank.
   //Eingabe: ID: 6
   //erwartete Ausgabe: false
   //Testergebnis: bestanden
   QVERIFY(testbank->bildLoeschen(6) == false);
}

void datenbanktest::bildLoeschenTrue(){
   //Autor: Delia Metzler
   //Testdatum: 11.08.2016
   //getestet wird die Methode bildLoeschen im Normalfall
   //Vorbedingungen: Die ID existiert in der Datenbank.
   //Eingabe: ID: 1
   //erwartete Ausgabe: true
   //Testergebnis: bestanden
   QVERIFY(testbank->bildLoeschen(1) == true);
}

void datenbanktest::cleanupTestCase(){
   testbank->datenbankLoeschen();
   delete testbank;
}
