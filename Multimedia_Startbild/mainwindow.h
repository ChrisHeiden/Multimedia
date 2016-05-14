#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsItem>
#include <QPolygonF>
#include <QPointF>
#include <QPen>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
