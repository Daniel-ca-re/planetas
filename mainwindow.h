#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "planet.h"
#include <QTimer>
#include <QMainWindow>
#include "txtinfo.h"
#include "new_planet.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getforces();
    void passtime(float t);


public slots:

        void ADVANCE();

private:
    Ui::MainWindow *ui;
    QList <planet *> planets;
    QTimer * timer;
    txtinfo info;
    new_planet *ventana;
    QGraphicsScene *scene;
    int numplaneta;
    int how_slow;


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_p1_pressed();
    void on_p2_pressed();
    void on_p3_pressed();
    void on_p4_pressed();
    void on_p5_pressed();
    void getplanets();
    void deleteplanets();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_dial_valueChanged(int value);
};
#endif // MAINWINDOW_H
