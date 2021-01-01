#include "new_planet.h"
#include "ui_new_planet.h"

new_planet::new_planet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::new_planet)
{
    ui->setupUi(this);
}

new_planet::~new_planet()
{
    delete ui;
}

void new_planet::on_pushButton_clicked()
{
    information.reserve(6);
    information.push_back(ui->mass->text().toFloat());

    information.push_back(ui->rad->text().toFloat());
    information.push_back(ui->Px->text().toFloat());
    information.push_back(ui->Py->text().toFloat());
    information.push_back(ui->Vx->text().toFloat());
    information.push_back(ui->Vy->text().toFloat());
}
