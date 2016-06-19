#ifndef SOUND_H
#define SOUND_H

#include <QThread>
#include <QMediaPlayer>
#include <iostream>
#include <QDir>

/**
 * @brief The Sound class ist ein Thread, welches sich darum kümmert den Willkommmenston abzuspielen
 */
class Sound :public QThread
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
private:
    /**
     * @brief soundabspielen, erzeugt eine temporären Ordner mit dem Sound, welcher sich
     *        im Ressourcenordner befindet, da man ohne diese den Sound nicht abspielen kann.
     *        Der Sound wird abgespielt.
     */
    void soundabspielen();
signals:
    void soundbeenden();
};

#endif // SOUND_H
