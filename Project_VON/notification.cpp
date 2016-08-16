#include "notification.h"
#include <iostream>
Notification::Notification()
{
    notiz = new QSystemTrayIcon(this);
    notiz->setIcon(QIcon(":/icon/Icon.png"));
}

Notification::~Notification(){
    delete (notiz);
}


void Notification::aktiviert(){
    const QString title(tr("Information"));
    const QString nachricht(tr("Kinect aktiviert."));
    notiz->showMessage(title, nachricht,QSystemTrayIcon::Information,10000);
    notiz->show();
}

void Notification::deaktiviert(){
    const QString title(tr("Information"));
    const QString nachricht(tr("Kinect deaktiviert."));
    notiz->showMessage(title, nachricht,QSystemTrayIcon::Information,10000);
    notiz->show();
}
