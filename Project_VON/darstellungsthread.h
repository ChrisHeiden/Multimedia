#ifndef DARSTELLUNGSTHREAD_H
#define DARSTELLUNGSTHREAD_H
#include <QThread>

class darstellungsthread :public QThread
{
public:
    darstellungsthread();
    void run();
    void darstellen();
signals:
    void darstellungbeenden();
};

#endif // DARSTELLUNGSTHREAD_H
