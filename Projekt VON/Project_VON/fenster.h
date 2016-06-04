#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsItem>
#include <QPolygonF>
#include <QPointF>
#include <QPen>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCoreApplication>
#include <QWindow>
#include <QPixmap>

/*Für das zweite Fenster*/
#include <QMainWindow>
#include <QGridLayout>
#include <QTextBrowser>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QMenuBar>
#include <QMenu>
#include <QScrollArea>

/*Bidlersuche*/
#include <QDirIterator>
#include <QString>
#include <regex>
#include <String>

using namespace std;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);


private: 

    /*Für das erste Fenster*/
    QGraphicsView *view;
    QGraphicsScene *scene;
//    QWidget *window = new QWidget;          //erzeugt Widget

    /*Für das Zweite Fenster*/
    QWidget *fenster = new QWidget;          //erzeugt Widget(komplete)
    QGridLayout *window = new QGridLayout;   //wird fenster übergeben
    QVBoxLayout *west = new QVBoxLayout;     //wird window übergeben und enthält Labels, Buttons und andere Layouts
    QVBoxLayout *center = new QVBoxLayout;   //wird später Bilder des Nutzers darstellen
    QVBoxLayout *menu = new QVBoxLayout;     //menu wird westpart übergeben
    QWidget *westpart = new QWidget;         //westpart entält das Menu mit allen Optionen
    QVBoxLayout *east = new QVBoxLayout;   //wird später Bilder des Nutzers darstellen

    QLabel *filter = new QLabel(tr("Filter"));
    QLabel *hintergrund = new QLabel(tr("Hintergrund"));
    QLabel *anzahlBilder = new QLabel(tr("Anzahl Bilder"));
    QLabel *vollbild = new QLabel(tr("Vollbildmodus"));
    QRadioButton *vollbildmodus = new QRadioButton(tr("Vollbildmodus"));
    QLabel *option = new QLabel(tr("Optionen"));
    QPushButton *zwanzig = new QPushButton(tr("20"));
    QPushButton *vierzig = new QPushButton(tr("40"));
    QPushButton *sechsig = new QPushButton(tr("60"));
    QLabel *sprache = new QLabel(tr("Sprache"));
    QRadioButton *deutsch = new QRadioButton(tr("Deutsch"));
    QRadioButton *englisch = new QRadioButton(tr("Englisch"));
    QPushButton *vollbildModusDeaktiviern = new QPushButton(tr("Vollbildmodus deaktiviern"));

signals:
    void clicked() const;

private slots:
    void zweitesFensterDarstellen();
    void schwarz();
    void beige();
    void weiss();
    void pink();
    void vollbildModusAktiv();
    void vollbildModusInaktiv();
    vector<string> gefundeneBidler();
};

#endif // MAINWINDOW_H
