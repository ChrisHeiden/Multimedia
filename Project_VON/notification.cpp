#include "notification.h"

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
    const QString nachricht(tr("Kinect ist aktiviert und bereit Daten zu übermitteln."));
    notiz->showMessage(title, nachricht,QSystemTrayIcon::Information,10000);
    notiz->show();
}

void Notification::deaktiviert(){
    const QString title(tr("Information"));
    const QString nachricht(tr("Kinect ist deaktiviert."));
    notiz->showMessage(title, nachricht,QSystemTrayIcon::Information,10000);
    notiz->show();
}
