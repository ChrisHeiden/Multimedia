#ifndef LESEN_H
#define LESEN_H

#include <QThread>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>


using namespace std;


class Lesen : public QThread
{
public:
    Lesen();
    ~Lesen();
    void run();

private:
    string a;
    float x;
    float y;
};

#endif // LESEN_H
