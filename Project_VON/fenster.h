#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "bilderSucheThread.h"
#include "soundthread.h"
#include "bilderdarstellenThread.h"
#include "bilderausordnertherad.h"




/*! Einbindung aller benutzen Dateien und Quellprogramme */
/*! Erste Fenster */
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
#include <QMediaPlayer>

/*!zweite Fenster*/
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

/*!Bidlersuche*/
#include <QDirIterator>
#include <QString>
#include <regex>
#include <String>
#include <vector>
#include <string>
#include <QFileDialog>

/*!Für Hilfe*/
#include <QMessageBox>
#include <QTranslator>
#include <QThread>

using namespace std;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    /*!
      \class MainWindow
      \brief MainWindow präsentiert das erste Fenster fü den Nutzer und navigiert dann durch das
             Programm
      \param parent

      Das erste Fenster, welches der Nutzer zu gesicht bekommen wird mit diesem Konstruktor
      dargestellt. Dabei enthalten ist eine QGraphicsView, QGraphicsScene, QMediaPlayer, QLabel
      und 3 QPushButtons.

      Die QGraphicsView und QGraphicsScene weden dabei genutzt um das Hintergrundbild zu
      generieren.
      Der QMediaPlayer wird benötigt um einen Sound abspielen zu können beim Öffnen der
      Applikation.
      Das QLabel weißt den Nutzer auf einen der Buttons anzuklicken um.
      Die QPushButtons werden benötigt um, mit dem Nutzer zu interagieren. Je nachdem, welcher
      Button gedrückt wird, wird ein leicht anderes zweites Fenster erzeugt.

     */
    explicit MainWindow(QWidget *parent = 0);


private: 

    QWidget *fenster = new QWidget;          //zur Dastellung aller Objekte innerhalb des Fensters

    /*!
      Für das erste Fenster
    */
    QGraphicsView *view;
    QGraphicsScene *scene;
//    QMediaPlayer *sound = new QMediaPlayer();
    Soundthread *soundthread;
    QPushButton *jaButton = new QPushButton();
    QPushButton *neinButton = new QPushButton();
    QPushButton *letztenOrdnerButton = new QPushButton();
    QLabel *txt = new QLabel();
    QPushButton *bestaetigen = new QPushButton("Bestätigung");
    QLineEdit *qpath = new QLineEdit;
    QString path;


    /*!
      Für das Zweite Fenster
    */
    QGridLayout *window = new QGridLayout;   //wird fenster übergeben
    QVBoxLayout *west = new QVBoxLayout;     //wird window übergeben und enthält Labels, Buttons und andere Layouts
    QVBoxLayout *center = new QVBoxLayout;   //wird später Bilder des Nutzers darstellen
    QVBoxLayout *menu = new QVBoxLayout;     //menu wird westpart übergeben
    QWidget *westpart = new QWidget;         //westpart entält das Menu mit allen Optionen
    QVBoxLayout *east = new QVBoxLayout;     //wird später Bilder des Nutzers darstellen


    /*!
      Genutz für die Interaktion mit Benutzer im Menu
    */
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
    AlleBilderSuchThread *alleBilder;
    QLabel *myLabel = new QLabel;
    BilderAusOrdnerTherad *OrdnerBilder;

    /*!
      Sprache ändern
    */
    QTranslator spracheEN;
    QTranslator spracheDE;


    /*!
      \class MainWindow
      \brief run()-Funktion wird benötigt um Threads zu starten
             Programm

      Damit die Suche von bestimmten Bildern in einem Verzeichnis schneller
      von statten geht, werden Threads benötigt, die miteinander kommunizieren
      können.
      In der Funktion, geht der Thread in die Suchfunktion und speichert alle
      Bilder, die er findet in ein Vektor, welcher später genutzt wird. Um die
      Bilder im Programm dazustellen.
    */

signals:
    /*!
      \class MainWindow
      \brief clicked ist eine Funktion zur Interaktion mut dem Nutzer, welche aufgerufen wird
             wenn dieser ein Button drücket.
     */
    void clicked() const;

private slots:

    /*!
      \class MainWindow
      \brief ja()-Funktion wird aufgerufen wenn der Nutzer im ersten Fenster auf den Button ja
             klicket.
     */
    void ja();

    /*!
      \class MainWindow
      \brief nein()-Funktion wird aufgerufen wenn der Nutzer im ersten Fenster auf den Button nein
             klicket.
     */
    void nein();

    /*!
      \class MainWindow
      \brief schwarz()-Funktion wird aufgerufen wenn der Nutzer im zweiten Fenster auf den Button
      schwarzen Button drückt.

      Beim drücken der schwarzen Buttons wird die Funktion schwarz() aufgerufen. Dadurch wird die
      Hintergrundfarbe des Fensters schwarz und die Menuleiste grau. Die Schriftzüge indess werden
      weiß dargestellt.
     */
    void schwarz();

    /*!
      \class MainWindow
      \brief beige()-Funktion wird aufgerufen wenn der Nutzer im zweiten Fenster auf den Button
      beigen Button drückt.

      Beim drücken der schwarzen Buttons wird die Funktion beige() aufgerufen. Dadurch wird die
      Hintergrundfarbe des Fensters beige und die Menuleiste organge/braun. Die Schriftzüge indess
      werden gelblich dargestellt.
     */
    void beige();

    /*!
      \class MainWindow
      \brief weiss()-Funktion wird aufgerufen wenn der Nutzer im zweiten Fenster auf den Button
      weiss Button drückt.

      Beim drücken der weiss Buttons wird die Funktion weiss() aufgerufen. Dadurch wird die
      Hintergrundfarbe des Fensters weiss und die Menuleiste grau. Die Schriftzüge indess
      werden schwarz dargestellt.
     */
    void weiss();

    /*!
      \class MainWindow
      \brief pink()-Funktion wird aufgerufen wenn der Nutzer im zweiten Fenster auf den Button
      pinken Button drückt.

      Beim drücken der pinken Buttons wird die Funktion pink() aufgerufen. Dadurch wird die
      Hintergrundfarbe des Fensters weiss und die Menuleiste dunkel pink/lila. Die Schriftzüge
      indess werden pink dargestellt.
     */
    void pink();

    /*!
      \class MainWindow
      \brief vollbildModusAktiv()-Funktion wird aufgerufen wenn der Nutzer im zweiten Fenster auf den Button
      Radiobutton Vollbildmodus drückt.

      Im zweiten Fenster in der Menuleiste kann man einstellen, dass die Menuleiste entfernt
      werden sollen, sodas nur die Bilder dargestellt werden. Zudem wird ein Button sichtbar, der den
      Vollbildmodus beenden kann
     */
    void vollbildModusAktiv();

    /*!
      \class MainWindow
      \brief vollbildModusInaktiv()-Funktion wird aufgerufen wenn der Nutzer im zweiten Fenster den
             Vollbildmodus aktiviert hat und ihn beenden möchte

      Wenn der Nutzer im Vollbildmodus ist und er den Button für die Beendigung des Modus (unten Rechts)
      gedrückt hat, erscheint die Menuleiste wieder und die Bilder werden nach links verschoben. Der
      Button zur Beendigung des Vollbildmoduses schwindet.
     */
    void vollbildModusInaktiv();

    /*!
      \class MainWindow
      \brief gefundeneBidlerImOrdner()-Funktion wird aufgerufen, wenn der Nutzer im ersten Fenster den
             Button für nein anklickt.
      \param QString
      \return vektor<string> : Rückgabewert ist ein Vector vom Typ string, der alle Pfade enthält zu
                               Bildern, die der Algorithmus gefunden hat

      Wenn der Nutzer den nein-Button im ersten Fenster betätigt hat, erscheint eine Ordnerstruktur mit Hilfe
      er sich nun den gewünschten Ordner raussuchen kann den er öffnen möchte. Der Pfad wird gespeichert.
      Die Bilder, die sich innerhalb des Verzeichnisses befinden werden extrahiert und in ein Vecor gespeichert
      um diese dann im zweiten Fenster dazustellen.
     */
    vector<string> gefundeneBidlerImOrdner(QString name);

    /*!
      \class MainWindow
      \brief ausgewaehlterOrdnern()-Funktion wird aufgerufen, wenn der Nutzer im ersten Fenster den
             Button für nein anklickt.
      \param QString
      \return QString: Pfade zum gewünschten Bildordner

     Wenn der Nutzer den nein-Button betätigt hat, werden Bilder eines bestimmten Typs innerhalb des zweiten Fensters dargestellt, die der Nutzer ausgesucht hat. Dafür öffnet sich
     eine Ordnerstruktor in der er den gewünschten Ordner angeben kann
     */
    QString ausgewaehlterOrdnern();

    /*!
      \class MainWindow
      \brief hilfeAngeklicket()-Funktion wird aufgerufen, wenn der Nutzer im zweiten Fenster den
             Button für Hilfe anklickt hat.

     Wenn der Nutzer nicht weiß, dass er alles mit der Applikation tun kann, kann er den Button für Hilfe
     anklicken. Wenn er dies tut, öffnet sich ein Fenster, in alle Funktionen der Applikation aufgelisten
     sind
     */
    void hilfeAngeklicket();

    /*!
      \class MainWindow
      \brief aendereSpracheEN()-Funktion wird aufgerufen, wenn der Nutzer im zweiten Fenster den
             QRadioButton für Englisch anklickt.

     Wenn der Nutzer anstelle der deutschen die englische Sprache priorisiert, kann der den RadioButton
     Englisch/English bedienen. Dadurch werden sämtliche Text auf Englisch darsgestellt.
     */
    void aendereSpracheEN();

    /*!
      \class MainWindow
      \brief aendereSpracheDE()-Funktion wird aufgerufen, wenn der Nutzer im zweiten Fenster den
             QRadioButton für Deutsch anklickt.

     Wenn der Nutzer anstelle der englischen die deutsche Sprache priorisiert, kann der den RadioButton
     Deutsch/German bedienen. Dadurch werden sämtliche Text auf Deutsch darsgestellt. Standart wird
     die deutsche Sprache angegeben, wurdurch der Button nur bedient werden kann, wenn der Nutzer
     die englische Fassung bevorzugt hat und nun wieder wechseln möchte.
     */
    void aendereSpracheDE();

    void BilderDarstellen(vector<QImage *> *qimages);

    void textFeldanzeigen();

};

#endif // MAINWINDOW_H
