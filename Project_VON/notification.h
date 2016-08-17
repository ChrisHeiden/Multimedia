#include <QSystemTrayIcon>
#include <QObject>

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

/**
 * @brief The Notification class stellt die Notiz am unteren Rand des Bildschirmes dar
 */
class Notification : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief Notification initialisiert die Notification
     */
    Notification();

    /**
     * @brief ~Notification gibt genutzten Speicher der Klasse wieder frei
     */
    ~Notification();

    /**
     * @brief aktiviert gibt dem Nutzer zur Kenntnis, dass die Kinect wieder einsatzbereit ist
     */
    void aktiviert();

    /**
     * @brief deaktiviert gibt dem Nutzer eine Information, dass das Auslesen der Handdaten deaktiviert ist
     */
    void deaktiviert();

private: //Membervariablen
    QSystemTrayIcon *notiz;
};

#endif // NOTIFICATION_H
