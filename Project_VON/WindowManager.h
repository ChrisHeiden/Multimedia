#include <QWidget>
#include <QStackedLayout>
#include "erstesfenster.h"
#include "zweitesfenster.h"
#include "drittesfenster.h"
#include "datenbank.h"
#include "mylabel.h"

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

/**
 * @brief The WindowManager class erbt von QWidget und hat die Aufgabe vom ersten
 *        dargestellten Fenster auf das zweite zu wechseln
 */
class WindowManager : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief WindowManager ist der Konstruktor der Klasse, welcher die Layouts initialisiert
     * @param translator: *QTranslator
     */
    WindowManager(QTranslator *translator);

    /**
     * @brief ~WindowManager ist der Destruktor der Klasse, welcher sich um die Entfernung des
     *        Widgets fenster kümmert.
     */
    virtual ~WindowManager();


private: //Membervariablen
    QWidget *fenster;
    QStackedLayout *layout;
    QVBoxLayout *layout2;
    erstesFenster *erstes;
    zweitesFenster *zweites;
    drittesFenster *drittes;
    QTranslator *m_translator;
    Datenbank *bank;


private slots: //SLOT-Funktionen
    void showZweitesFenster();
    void showDrittesFenster(string pfad);
    void letzteBilder();
    void showBilderGalerie();
};

#endif // WINDOWMANAGER_H
