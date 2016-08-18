#include "WindowManager.h"
#include <QApplication>
#include <QtTest/QtTest>
#include "datenbanktest.h"

int main(int argc, char *argv[])
{
    //Anweisungen fuer Unit-Tests:
    //datenbanktest datenbanktest;
    //QTest::qExec(&datenbanktest);

    QApplication a(argc, argv);

    QTranslator *translator = new QTranslator();
    a.installTranslator(translator);
    WindowManager w(translator);
    w.show();

    return a.exec();
}
