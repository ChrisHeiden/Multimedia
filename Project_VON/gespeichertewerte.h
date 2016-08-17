#ifndef GESPEICHERTEWERTE_H
#define GESPEICHERTEWERTE_H

/**
 * @brief The GespeichertWerte class dient zur Speicherung und zugriff der Handkoordinaten
 */
class GespeichertWerte
{
public:

    /**
     * @brief GespeichertWerte initialisiert und speichert x- und y-Koordinaten der
     *        Hand ab
     * @param x: &double
     * @param y: &double
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
