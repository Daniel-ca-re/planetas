#ifndef NEW_PLANET_H
#define NEW_PLANET_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class new_planet;
}

class new_planet : public QMainWindow
{
    Q_OBJECT

public:
    explicit new_planet(QWidget *parent = nullptr);
    ~new_planet();
    std::vector<float> information;

public slots:
    void on_pushButton_clicked();

private:
    Ui::new_planet *ui;
};

#endif // NEW_PLANET_H
