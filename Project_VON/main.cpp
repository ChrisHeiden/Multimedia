#include "WindowManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator *translator = new QTranslator();
    a.installTranslator(translator);
    WindowManager w(translator);
    w.show();

    return a.exec();
}
