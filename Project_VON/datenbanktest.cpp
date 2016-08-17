#include "datenbanktest.h"

datenbanktest::datenbanktest(QObject *parent) : QObject(parent)
{
   //testbank = new Datenbank();
}

void datenbanktest::initTestCase(){
   testbank = new Datenbank();
}

void datenbanktest::datenbankEmptyTrue(){
   QVERIFY(testbank->datenbankEmpty() == true);
}

void datenbanktest::neuesBild(){
   QVERIFY(testbank->neuesBild("./Testbild.jpg") == true);
}

void datenbanktest::datenbankEmptyFalse(){
   QVERIFY(testbank->datenbankEmpty() == false);
}

void datenbanktest::bildpfadExistsTrue(){
   QVERIFY(testbank->bildpfadExists("./Testbild.jpg") == true);
}

void datenbanktest::bildpfadExistsFalse(){
   QVERIFY(testbank->bildpfadExists("./Affe.jpg") == false);
}

void datenbanktest::getIDTrue(){
   QVERIFY(testbank->getID("./Testbild.jpg") == 1);
}

void datenbanktest::getIDFalse(){
   QCOMPARE(testbank->getID("./Affe.jpg"), -1);
}

void datenbanktest::bildBewertenTrue(){
   QVERIFY(testbank->bildBewerten(1, 3) == true);
}

void datenbanktest::bildBewertenFalse(){
   QVERIFY(testbank->bildBewerten(1, 7) == false);
}

void datenbanktest::bildtagsAendernTrue(){
   QVERIFY(testbank->bildtagsAendern(1, "Test") == true);
}

void datenbanktest::bildtagsAendernFalse(){
   QVERIFY(testbank->bildtagsAendern(5, "Tier") == false);
}

void datenbanktest::bewertungAnzeigen(){
   QVERIFY(testbank->bewertungAnzeigen(1) == 3);
}

void datenbanktest::bildtagsAnzeigen(){
   QVERIFY(testbank->bildtagsAnzeigen(1) == "Test");
}

void datenbanktest::getBildausrichtung(){
   QVERIFY(testbank->getBildausrichtung(1) == 0);
}

void datenbanktest::bildLoeschenFalse(){
   QVERIFY(testbank->bildLoeschen(6) == false);
}

void datenbanktest::bildLoeschenTrue(){
   QVERIFY(testbank->bildLoeschen(1) == true);
}

void datenbanktest::cleanupTestCase(){
   testbank->datenbankLoeschen();
   delete testbank;
}
