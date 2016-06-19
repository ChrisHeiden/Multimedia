#include "sound.h"
#include <iostream>

Sound::Sound()
{

}

void Sound::run(){
    soundabspielen();
}

void Sound::soundabspielen(){
    QMediaPlayer sound;
    QDir soundDir = QDir("./sound");
    if (!soundDir.exists()) // erstellt ein Soundordner, falls dieser nicht existiert
        soundDir.mkdir(".");

    /* kopiert von der Ressource zur Festplatte */
    QFile::copy(":/sound/Zankyou no Terror OST - geschnitten.mp3", "./sound/Zankyou no Terror OST - geschnitten.mp3");

    sound.setMedia(QUrl("./sound/Zankyou no Terror OST - geschnitten.mp3"));
    sound.play();  //Startet abspielen des Sounds
    sleep(7);
}
