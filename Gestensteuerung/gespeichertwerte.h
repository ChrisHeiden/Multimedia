#ifndef GESPEICHERTWERTE_H
#define GESPEICHERTWERTE_H


class GespeichertWerte
{
public:
    GespeichertWerte(double &x, double &y);

    double getYWert()
    {
        return y;
    }

    double getXWert()
    {
        return x;
    }

private:
    double x;
    double y;

};

#endif // GESPEICHERTWERTE_H
