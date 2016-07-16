#include "mainwindow.h"
#include "datenbank.h"
#include "iostream"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]) //int argc, char *argv[]
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    Datenbank test;
    /*if(test.datenbankEmpty()){
        cout << "Die Datenbank ist leer!" << endl;
    }
    else{
        cout << "Die Datenbank ist nicht leer." << endl;
    }*/

    //test.aktuellenBildPfadAnzeigen(2);
    /*test.BildLoeschen(1);
    test.BildLoeschen(2);
    test.BildLoeschen(3);
    test.BildLoeschen(4);
    test.BildLoeschen(5);*/

    test.neuesBild("./Testpilder/Testbild.jpg");
    test.neuesBild("./Testbilder/Panorama.jpg");
    test.neuesBild("./Testbilder/Esel.jpg");
    test.neuesBild("./Testbilder/Affe.jpg");
    test.neuesBild("./Testbilder/Blume.jpg");
    test.neuesBild("./Testbilder/Phil.jpg");
    test.neuesBild("./Testbilder/Delia.jpg");

    //test.getID("./Testbilder/Phil.jpg");

    //test.alleBilderAusgeben();
    //test.alleIDsAusgeben();
    //test.datenbankEmpty();
    //cout << test.bewertungAnzeigen(4) << endl;
    /*test.bildtagsAnzeigen(10);
    test.bildtagsAendern(10, "Tiere, Zoo");
    test.bildtagsAnzeigen(10);*/
    //test.bildtagsFiltern("Tiere");
    //test.bildtagsAendern(3, "Tiere");
    //test.bildtagsAnzeigen(3);
    /*test.bildtagsAendern(4, "Tiere");
    test.bildtagsAendern(5, "Pflanze");
    test.bildtagsAendern(2, "Test");
    test.bildtagsAendern(2, "Landschaft");
    test.bildtagsAendern(3, "Tiere");
    test.bildtagsAendern(4, "Tiere");
    test.bildtagsAendern(5, "Pflanze");*/
    //test.bildtagsFiltern("Tiere");
    //test.getAlleBilder_dargestelltTrue();
    /*test.bildBewerten(4, 5);
    cout << test.bewertungAnzeigen(4) << endl;
    test.bildBewerten(5, 3);
    cout << test.bewertungAnzeigen(5) << endl;
    test.bildBewerten(6, 5);
    cout << test.bewertungAnzeigen(6) << endl;
    test.bildBewerten(7, 3);
    cout << test.bewertungAnzeigen(7) << endl;
    test.bildBewerten(4, 4);
    cout << test.bewertungAnzeigen(4) << endl;*/
    //test.bewertungFiltern(3);
    //test.getAlleBilder_dargestelltTrue();
    test.setNeueBildausrichtung(5);
    test.getBildausrichtung(5);

    //return a.exec();
    return 0;
}
