#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTextBrowser>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget *fenster = new QWidget;          //erzeugt Widget(komplete)
    QGridLayout *window = new QGridLayout;   //wird fenster übergeben
    QVBoxLayout *west = new QVBoxLayout;     //wird window übergeben und enthält Labels, Buttons und andere Layouts
    QHBoxLayout *center = new QHBoxLayout;   //wird später Bilder des Nutzers darstellen
    QVBoxLayout *menu = new QVBoxLayout;     //menu wird westpart übergeben
    QWidget *westpart = new QWidget;         //westpart entält das Menu mit allen Optionen
    QWidget *centerpart = new QWidget;

    QLabel *filter = new QLabel("Filter");
    QLabel *hintergrund = new QLabel("Hintergrund");
    QLabel *anzahlBilder = new QLabel("Anzahl Bilder");
    QLabel *vollbild = new QLabel("Vollbildmodus");
    QRadioButton *vollbildmodus = new QRadioButton("Vollbildmodus");
    QLabel *option = new QLabel("Optionen");
    QPushButton *zwanzig = new QPushButton("20");
    QPushButton *vierzig = new QPushButton("40");
    QPushButton *sechsig = new QPushButton("60");



signals:
    void clicked() const;

private slots:

    void schwarz();
    void beige();
    void weiss();
    void pink();
};

#endif // MAINWINDOW_H
