#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QScrollArea>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>

int main(int argc, char *argv[])
{

  QApplication *myApp = new QApplication(argc, argv);

  /*---------- Fenster erstellen ----------*/

  QMainWindow *top = new QMainWindow();
  top->setWindowTitle("Bildergalerie Gestensteuerung");
  QScrollArea *scroll = new QScrollArea;
  top->setCentralWidget(scroll);
  top->setGeometry(500, 500, 800, 600);
  top->show();

  QLabel *label = new QLabel;
  scroll->setWidget(label);


  /*---------- Menu ----------*/
  /*---------- Optionenmenu ----------*/

  QMenu *optionen = top->menuBar()->addMenu("&Optionen");
  optionen->addAction("&Suchen", myApp, SLOT(quit()));
  optionen->addAction("&Sortieren nach Datum", myApp, SLOT(quit()));
  optionen->addAction("&Gestensteuerung", myApp, SLOT(quit()));
  optionen->addAction("&Beenden", myApp, SLOT(quit()));

  /*---------- Fenstermenu ----------*/

  QMenu *Fenster = top->menuBar()->addMenu("&Fenster");
  Fenster->addAction("&Vergrößern", myApp, SLOT(quit()));
  Fenster->addAction("&Verkleinern", myApp, SLOT(quit()));
  Fenster->addAction("&Vollbildmodus", myApp, SLOT(quit()));
  Fenster->addAction("&Hintergrundfarbe ändern", myApp, SLOT(quit()));


  QImage image;
  if (argc > 1) image = QImage(argv[1]);
  else image = QImage(QFileDialog::getOpenFileName());
  label->setPixmap(QPixmap::fromImage(image));
  label->setMinimumSize(image.width(), image.height());
  return myApp->exec();
}

