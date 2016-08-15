#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <vector>
#include <iostream>
#include "gespeichertwerte.h"
#include "mytimer.h"
#include <time.h>
#include "notification.h"
#include <QPushButton>


using namespace std;

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QProcess *process;
    GespeichertWerte *speichert;
    vector<GespeichertWerte*> *alleGespeichertenWerte;
    vector<GespeichertWerte*> *alleWerte;
    Notification *n;
    MyTimer *t;


private slots:
    void readOut();
    void connectionAktivieren();

private:
    void gestenErkennung();
    void verkleinerGeste();
    void wischGeste();
    void drehGeste();
    void vergroesserGeste();
    QPushButton *aktiv;
    unsigned int mengeAnG;


};

#endif // MAINWINDOW_H
