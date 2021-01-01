#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "new_planet.h"
#include <cmath>
#include <QLCDNumber>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1561,941);
    info= txtinfo("../planets/planetas/planets data2.txt");
    numplaneta=0;
    how_slow=1;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getforces()
{
    std::vector <std::array<float,2>> forces;
    //forces.reserve(planets.size());
    for(int i=0;forces.size()<planets.size();i++)
    {
        forces.push_back({0,0});
    }
    for(int i=0;i!=planets.size();i++)
    {
        for(int ii=i+1;ii!=planets.size();ii++)
        {


           std::array<float,2>pospt1=planets.at(i)->getpos();
           std::array<float,2>pospt2=planets.at(ii)->getpos();
           float deltax=pospt2[0]-pospt1[0];
           float deltay=pospt2[1]-pospt1[1];
           float hipotenuza=sqrt(pow(deltax,2)+pow(deltay,2));
           float sin=deltay/hipotenuza;
           float cos=deltax/hipotenuza;

           float force=(6.67384*(pow(10,-1))*(planets.at(i)->getmass())*(planets.at(ii)->getmass()))/(pow(hipotenuza,2));
           forces[i][0]+=force*cos;
           forces[i][1]+=force*sin;
           forces[ii][0]-=force*cos;
           forces[ii][1]-=force*sin;

        }
    }
    for(int i=0;i<planets.size();i++)
    {
        planets.at(i)->setacewithforce(forces[i]);
    }

}

void MainWindow::getplanets()
{
    auto i =info.info.begin();
    int I=0;
    while(i!=info.info.end())
    {
        planets.push_back(new planet((*i)[0],(*i)[1],info.getarray(I,2),info.getarray(I,4)));
        scene->addItem(planets.back());
        I++;
        i++;

    }
}

void MainWindow::deleteplanets()
{
        while(planets.size()!=0)
        {
            scene->removeItem(planets.at(0));
            planets.removeAt(0);
        }
}

void MainWindow::ADVANCE()
{
    getforces();
    for(auto i=planets.begin();i!=planets.end();i++)
    {
        (*i)->Advance(1000/(30*how_slow));
    }
    ui->px->display(planets.at(numplaneta)->getpos()[0]);
    ui->py->display(planets.at(numplaneta)->getpos()[1]);
    ui->vx->display(planets.at(numplaneta)->getvel()[0]);
    ui->vy->display(planets.at(numplaneta)->getvel()[1]);
    ui->ax->display(planets.at(numplaneta)->getace()[0]);
    ui->ay->display(planets.at(numplaneta)->getace()[1]);
}


void MainWindow::on_pushButton_clicked()
{
    ventana= new new_planet(this);
    ventana->show();


}

void MainWindow::on_pushButton_2_clicked()
{
    info.add_new_info(ventana->information);
    info.saveinfo();
}

void MainWindow::on_p1_pressed()
{
    if (planets.size()>=1)
    {
        numplaneta=0;
        for(auto i=0;i!=planets.size();i++)
        {
            if(numplaneta==i)
            {
                planets.at(i)->isselected='1';
            }
            else
            {
                planets.at(i)->isselected='0';
            }
        }
    }
}

void MainWindow::on_p2_pressed()
{
            if (planets.size()>=2)
            {
                numplaneta=1;
                for(auto i=0;i!=planets.size();i++)
                {
                    if(numplaneta==i)
                    {
                        planets.at(i)->isselected='1';
                    }
                    else
                    {
                        planets.at(i)->isselected='0';
                    }
                }
            }
}

void MainWindow::on_p3_pressed()
{
            if (planets.size()>=3)
            {
                numplaneta=2;
                for(auto i=0;i!=planets.size();i++)
                {
                    if(numplaneta==i)
                    {
                        planets.at(i)->isselected='1';
                    }
                    else
                    {
                        planets.at(i)->isselected='0';
                    }
                }
            }
}

void MainWindow::on_p4_pressed()
{
            if (planets.size()>=4)
            {
                numplaneta=3;
                for(auto i=0;i!=planets.size();i++)
                {
                    if(numplaneta==i)
                    {
                        planets.at(i)->isselected='1';
                    }
                    else
                    {
                        planets.at(i)->isselected='0';
                    }
                }
            }
}

void MainWindow::on_p5_pressed()
{
            if (planets.size()>=5)
            {
                numplaneta=4;
                for(auto i=0;i!=planets.size();i++)
                {
                    if(numplaneta==i)
                    {
                        planets.at(i)->isselected='1';
                    }
                    else
                    {
                        planets.at(i)->isselected='0';
                    }
                }
            }
}

void MainWindow::on_pushButton_3_clicked()
{
    deleteplanets();
    getplanets();
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this, SLOT(ADVANCE()));
    timer->start(1000/60);
}

void MainWindow::on_pushButton_4_clicked()
{
    auto i= info.info.begin();
    advance(i,numplaneta);
    scene->removeItem(planets.at(numplaneta));
    planets.removeAt(numplaneta);
    info.info.remove(*i);
    info.saveinfo();

}

void MainWindow::on_dial_valueChanged(int value)
{
    how_slow=value;
}
