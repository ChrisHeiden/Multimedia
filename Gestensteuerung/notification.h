#include <QSystemTrayIcon>
#include <QObject>
#ifndef NOTIFICATION_H
#define NOTIFICATION_H


class Notification : public QObject
{
    Q_OBJECT
public:
    Notification();
    ~Notification();
    void aktiviert();
    void deaktiviert();
    void starten();

private: //Membervariablen
    QSystemTrayIcon *notiz;
};

#endif // NOTIFICATION_H
