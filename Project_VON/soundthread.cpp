#include "soundthread.h"
using namespace std;


Soundthread::Soundthread()
{
}

void Soundthread::run(){
    soundabspielen();
}

void Soundthread::soundabspielen(){
    QMediaPlayer sound;
    sound.setMedia(QUrl("C:/Users/Christopher/Documents/Privat/Studium/Semester 4/Entwicklung von Multimediasysteme/Projekt VON/Project_VON/Zankyou no Terror OST - geschnitten.mp3")); //Angabe des Pfades in dem sich der Sound befindet
    sound.play();  //Startet abspielen des Sounds
    sleep(7);
}
