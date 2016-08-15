#include "lesen.h"
#include <stdio.h>

Lesen::Lesen()
{

}

Lesen::~Lesen()
{

}

void Lesen::run(){

    ifstream datei("C:\\Users\\Christopher\\Documents\\example.txt", ios::in);
    string zeile;
    while (getline(datei, zeile)) {
    for (unsigned int i = 0; i < zeile.size(); i++) {
        if (zeile[i] == ';') {
            zeile[i] = ' ';
        }
            }
            stringstream zeilenpuffer(zeile);
            zeilenpuffer >> a;
            zeilenpuffer >> x;
            zeilenpuffer >> y;

            if(a == "Geschlossen"){
                cout << x << ";" << y << endl;
            }
            if(a == "Offen"){
                cout << x << ";" << y << endl;
            }
            else if(a == "Drehung"){
                cout << x << ";" << y << endl;
            }
        }
    cout << 2 << endl;
    datei.close();
    std::remove("C:\\Users\\Christopher\\Documents\\example.txt");
}

