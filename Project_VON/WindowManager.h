#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#include "erstesfenster.h"
#include "zweitesfenster.h"
#include "drittesfenster.h"
#include "mylabel.h"
#include <QWidget>
#include <QStackedLayout>

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
     */
    WindowManager(QTranslator *translator);

    /**
     * @brief ~WindowManager ist der Destruktor der Klasse, welcher sich um die Entfernung des
     *        Widgets fenster kümmert.
     */
    virtual ~WindowManager();


private:
    QWidget *fenster;        //zur Dastellung aller Objekte innerhalb des Fensters
    QStackedLayout *layout;
    QVBoxLayout *layout2;

    erstesFenster *erstes;
    zweitesFenster *zweites;
    drittesFenster *drittes;

    QTranslator *m_translator;

    void showZweitesFenster();
    void showLetzteBilder();
    void showDrittesFenster(string pfad);
    void letzteBilder();

};

#endif // WINDOWMANAGER_H
