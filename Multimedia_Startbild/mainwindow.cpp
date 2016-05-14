#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    view = new QGraphicsView;
    scene = new QGraphicsScene;

    scene->setSceneRect(0,0,800,600);
    QPen *pen = new QPen();
    pen->setColor("lime");

    scene->addLine(0, 120, 170, 240, *pen); scene->addLine(170, 240, 0, 370, *pen);
    scene->addLine(0, 540, 170, 470, *pen); scene->addLine(170, 470, 290, 600, *pen);
    scene->addLine(470, 600, 520, 420, *pen); scene->addLine(520, 420, 800, 510, *pen);
    scene->addLine(450, 0, 560, 130, *pen); scene->addLine(560, 130, 700, 60, *pen); scene->addLine(700, 60, 685, 0, *pen);

    pen->setColor("magenta"); //fuchsia

    scene->addLine(90, 185, 220, 0, *pen);
    scene->addLine(105, 495, 135, 265, *pen); scene->addLine(135, 265, 355, 375, *pen); scene->addLine(355, 375, 238, 540, *pen);
    scene->addLine(800, 260, 660, 375, *pen); scene->addLine(660, 375, 650, 85, *pen);

    pen->setColor("deepskyblue");

    scene->addLine(195, 35, 270, 330, *pen);
    scene->addLine(325, 420, 503, 480, *pen);
    scene->addLine(755, 495, 685, 353, *pen);
    scene->addLine(656, 295, 440, 190, *pen); scene->addLine(440, 190, 520, 85, *pen);

    pen->setColor("coral");

    scene->addLine(216, 115, 496, 115, *pen);
    scene->addLine(308, 350, 555, 245, *pen); scene->addLine(555, 245, 560, 433, *pen);

    view->setScene(scene);
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
