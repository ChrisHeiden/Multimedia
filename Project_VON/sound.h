#include <QThread>
#include <QMediaPlayer>
#include <iostream>
#include <QDir>

#ifndef SOUND_H
#define SOUND_H

/**
 * @brief The Sound class ist ein Thread, welches sich darum kümmert den Willkommmenston abzuspielen
 */
class Sound : public QThread
{
public:
    /**
     * @brief Sound ist der Konstruktor der Klasse Sound, welcher keine Intialisierung oder sonstiges
     *        durchführt
     */
    Sound();
    /**
     * @brief run ist der Start des Threads, welcher sagt, dass dieser in die private Funktion
     *        soundabspielen() gehen soll.
     */
    void run();


signals: //SIGNAL-Funktionen
    void soundbeenden();


private: //Funktionen
    void soundabspielen();

};

#endif // SOUND_H
