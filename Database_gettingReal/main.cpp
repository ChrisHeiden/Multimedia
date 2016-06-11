#include "mainwindow.h"
#include "datenbank.h"
#include "iostream"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    Datenbank test;
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

    test.alleBilderAusgeben();
    test.alleIDsAusgeben();
    //test.DatenbankEmpty();
    //cout << test.BewertungAnzeigen(4) << endl;
    //test.BildtagsAendern(3, "Tiere");
    //test.TagsAnzeigen(3);
    //test.BildBewerten(4, 5);
    //cout << test.BewertungAnzeigen(4) << endl;

    //return a.exec();
    return 0;
}
