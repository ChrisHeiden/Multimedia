#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <String>
#include <vector>
#include <QDirIterator>
#include <QString>
#include <regex>
#include <QFileDialog>
#include <QImage>
#include <QGridLayout>

using namespace std;

/*
 * Die Bildersuche, die speicherung in einen Vector und die Umwandlung der gefundenen Bilder in Images
 * und die Darstellung der Bilder im Hauptfenster dauert zu lang.
 * Idee: Threading
 * Problem: ein Thread alleine schafft schon die ersten beide Dinge nicht.
 */
class AlleBilderSuchThread : public QThread
{
    Q_OBJECT
public:
    AlleBilderSuchThread(QString str);
    void run();
    vector<string> alleGefundenenBilder();
    vector<QImage*> umwandeln(vector<string> *images);
    QString m_string;
signals:
    void sucheBeendet(vector<QImage*> *images);

};

#endif // THREAD_H

