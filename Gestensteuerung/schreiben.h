#ifndef SCHREIBEN_H
#define SCHREIBEN_H

#include <iostream>
#include <QThread>

using namespace std;

class Schreiben : public QThread
{
public:
    Schreiben();
    ~Schreiben();
    void run();

};

#endif // SCHREIBEN_H
