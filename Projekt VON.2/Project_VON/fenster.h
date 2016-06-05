#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* Einbindung aller benutzen Dateien und Quellprogramme */
/* Erste Fenster */
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

/*zweite Fenster*/
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
#include <vector>
#include <string>
#include <QFileDialog>

using namespace std;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    /**
     *
     *
     */
    explicit MainWindow(QWidget *parent = 0);


private: 

    /*Für das erste Fenster*/
    QWidget *fenster = new QWidget;          //erzeugt Widget
    QGraphicsView *view;
    QGraphicsScene *scene;

    /*Für das Zweite Fenster*/
    QGridLayout *window = new QGridLayout;   //wird fenster übergeben
    QVBoxLayout *west = new QVBoxLayout;     //wird window übergeben und enthält Labels, Buttons und andere Layouts
    QVBoxLayout *center = new QVBoxLayout;   //wird später Bilder des Nutzers darstellen
    QVBoxLayout *menu = new QVBoxLayout;     //menu wird westpart übergeben
    QWidget *westpart = new QWidget;         //westpart entält das Menu mit allen Optionen
    QVBoxLayout *east = new QVBoxLayout;     //wird später Bilder des Nutzers darstellen

    /*Genutz für die Interaktion mit Benutzer im Menu */
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
    void clicked() const;   //Buttons sollen beim klicken etwas machen

private slots:

    /**
     * @content: die ja-Funktion wird aufgerufen wenn der Nutze im ersten Fenster
     * den ja-Button betätigt. Daraufhin öffnet sich das zweite Fenster mit all seinen
     * Optionen und Bilder, die der Nutzer auf dem Rechner hat
     */
    void ja();

    /*
     * @content: die nein-Funktion wird aufgerufen wenn der Nutze im ersten Fenster
     * den nein-Button betätigt. Daraufhin öffnet sich das zweite Fenster mit all seinen
     * Optionen und es werden nur die Bilder dargestellt, die der Nutzer vorher ausgewählt hat
     */
    void nein();

    /*
     * @content: im zweiten Fenster in der Menuleiste kann man die Farben des Hintergrundes auswählen
     * wenn der Nutzer den schwazen Button betätigt, werden der Hintergrund schwarz und die Texturen weiß
     * dargestellt
     */
    void schwarz();

    /*
     * @content: im zweiten Fenster in der Menuleiste kann man die Farben des Hintergrundes auswählen
     * wenn der Nutzer den beigen Button betätigt, wird der Hintergrund beige und die Texturen gelblich
     * dargestellt
     */
    void beige();

    /*
     * @content: im zweiten Fenster in der Menuleiste kann man die Farben des Hintergrundes auswählen
     * wenn der Nutzer den weißen Button betätigt, wird der Hintergrund weiß und die Texturen schwarz
     * dargestellt
     */
    void weiss();

    /*
     * @content: im zweiten Fenster in der Menuleiste kann man die Farben des Hintergrundes auswählen
     * wenn der Nutzer den pinken Button betätigt, wird der Hintergrund pink und die Texturen dunkelpink
     * dargestellt
     */
    void pink();

    /*
     * @content: im zweiten Fenster in der Menuleiste kann man einstellen, das die Menuleiste entfernt
     * werden sollen, sodas nur die Bilder dargestellt werden. Zudem wird ein Button sichtbar, der den
     * Vollbildmodus beenden kann
     */
    void vollbildModusAktiv();

    /*
     * @content: wenn der Nutzer im Vollbildmodus war und er den Button für die Beendigung des Modus
     * gedrückt hat, erscheint die Menuleiste wieder
     */
    void vollbildModusInaktiv();

    /**
     * @content: wenn der Nutzer den ja-Button betätigt hat, werden alle Bilder (.jpg) innerhalb des
     * Verzeichnisses rausgesucht und innerhalb des zweiten Fensters dargestellt
     * @return vektor<string> : Rückgabewert ist ein Vector vom Typ string, der alle Pfade enthält zu
     *                          Bilder, di der Algorithmus gefunden hat
     */
    vector<string> alleGefundeneBidler();

    /**
     * @content: wenn der Nutzer den nein-Button betätigt hat und der Nutzer den gewünschten Ordner
     * ausgewählt hat, werden die Bilder innerhalb des Verzeichnisses erfasst und die Pfade in einem
     * Vector gespeichert
     * @param QString
     * @return vektor<string> : Rückgabewert ist ein Vector vom Typ string, der alle Pfade enthält zu
     *                          Bildern, die der Algorithmus gefunden hat
     */
    vector<string> gefundeneBidlerImOrdner(QString name);

    /**
     * @content: wenn der Nutzer den nein-Button betätigt hat, werden Bilder eines bestimmten Typs
     * innerhalb des zweiten Fensters dargestellt, die der Nutzer ausgesucht hat. Dafür öffnet sich
     * eine Ordnerstruktor in der er den gewünschten Ordner angeben kann
     * @return QString : Pfade zum gewünschten Bildordner
     */
    QString ausgewaehlterOrdnern();
};

#endif // MAINWINDOW_H
