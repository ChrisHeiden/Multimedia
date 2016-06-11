#ifndef SOUNDTHREAD_H
#define SOUNDTHREAD_H
#include <QThread>
#include <QMediaPlayer>
#include <iostream>


class Soundthread : public QThread
{
public:
    Soundthread();
    void run();
    void soundabspielen();
signals:
    void soundbeenden();
};

#endif // SOUNDTHREAD_H
