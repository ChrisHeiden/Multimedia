#include "mytimer.h"
#include <iostream>

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyTimer::timeOut);
    auslesen = true;
    helfer = true;
    cout << 1 << endl;
}
MyTimer::~MyTimer(){
    delete (timer);
}

bool MyTimer::starten(){
    timer->start(5000);
    cout << 2 << endl;
    return true;
}

void MyTimer::timeOut(){
    if(helfer == false){
        auslesenStarten();
        helfer = true;
    }
    else{
        cout << 3 << endl;
        auslesenStoppen();
        helfer = false;
    }
}

void MyTimer::auslesenStoppen()
{
    cout << 4 << endl;
    auslesen = false;
    timer->stop();
}

void MyTimer::auslesenStarten()
{
    auslesen = true;
    timer->stop();
}


bool MyTimer::getAuslesen()
{
    return auslesen;
}

void MyTimer::setAuslesen(bool auslesen)
{
    this->auslesen = auslesen;
}

