#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QWindow>
#include <QPixmap>

// Qstyle soll das Bild in den Hintergrund legen

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setFixedSize(800,600);
    mainWindow.showMaximized();
    return app.exec();
}




