#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#include "erstesfenster.h"
#include "zweitesfenster.h"
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
     * @brief ~WindowManager ist der Dekonstruktor der Klasse, welcher sich um die Entfernung des
     *        Widgets Fenster kümmert. Dieser darf überschrieben werden
     */
    virtual ~WindowManager();


private:
    QWidget *fenster = new QWidget;          //zur Dastellung aller Objekte innerhalb des Fensters
    void showZweitesFenster();
    QVBoxLayout *layout2;

    erstesFenster *erstes;
    zweitesFenster *zwei;
    QStackedLayout *layout;
    QTranslator *m_translator;
};

#endif // WINDOWMANAGER_H
