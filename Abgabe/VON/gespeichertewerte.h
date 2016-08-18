#ifndef GESPEICHERTEWERTE_H
#define GESPEICHERTEWERTE_H

/**
 * @brief The GespeichertWerte class dient zur Speicherung und dem Zugriff der Handkoordinaten
 */
class GespeichertWerte
{
public:

    /**
     * @brief GespeichertWerte initialisiert und speichert x- und y-Koordinaten der
     *        Hand ab
     * @param x: &double ist der x-Wert der der Handkoordinate
     * @param y: &double ist der y-Wert der der Handkoordinate
     */
    GespeichertWerte(double &x, double &y);

    /**
     * @brief getYWert gibt den y-Koordinate der Hand zurück
     * @return double
     */
    double getYWert()
    {
        return y;
    }

    /**
     * @brief getXWert gibt den x-Koordinate der Hand zurück
     * @return: double
     */
    double getXWert()
    {
        return x;
    }

private: //Membervariablen
    double x;
    double y;

};
#endif // GESPEICHERTEWERTE_H
