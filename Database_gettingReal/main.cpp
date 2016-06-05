#include "mainwindow.h"
#include "datenbank.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    Datenbank test;
    test.Bildloeschen(1);
    test.Bildloeschen(2);
    test.Bildloeschen(3);
    test.Bildloeschen(4);
    test.Bildloeschen(5);

    /*test.neuesBild(1, "./Testpilder/Testbild.jpg");
    test.neuesBild(2, "./Testbilder/Panorama.jpg");
    test.neuesBild(3, "./Testbilder/Esel.jpg");
    test.neuesBild(4, "./Testbilder/Affe.jpg");
    test.neuesBild(5, "./Testbilder/Blume.jpg");*/
    test.alleBilderAusgeben();

    //return a.exec();
    return 0;
}
