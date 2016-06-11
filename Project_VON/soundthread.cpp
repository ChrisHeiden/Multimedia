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
    sound.setMedia(QUrl("C:/Users/Delia/Documents/Studium/Sommersemester 2016/Entwicklung Multimediasysteme/Projekt/Multimedia-Git/Multimedia/Project_VON/Zankyou no Terror OST - geschnitten.mp3")); //Angabe des Pfades in dem sich der Sound befindet
    sound.play();  //Startet abspielen des Sounds
    sleep(7);
}
