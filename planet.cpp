#include "planet.h"
#include <cmath>

planet::planet()
{

}
planet::planet(float m, float r, std::array<float, 2> p, std::array<float, 2> v)
{
    mass=m;
    ace[0]=0;
    ace[1]=0;
    vel=v;
    pos=p;
    rad=r;
    setpos(pos[0],pos[1]);
    isselected='0';
}


std::array<float, 2> planet::getvel()
{
    return vel;
}

std::array<float, 2> planet::getpos()
{
    return pos;
}
std::array<float, 2> planet::getace()
{
    return ace;
}
float planet::getmass()
{
    return mass;
}

float planet::getrad()
{
    return rad;
}

void planet::setmass(float m)
{
    mass=m;
}

void planet::setpos(float x, float y)
{
    x=x/20+800;
    y=y/20+450;
    setPos(int(x),int(y));
}

void planet::setvel(float x, float y)
{
    vel[1]=y;
    vel[0]=x;
}

void planet::setacewithforce(std::array<float,2> force)
{
    ace[1]=force[1]/mass;
    ace[0]=force[0]/mass;
}

void planet::Advance(float t)
{
    pos[0]+=vel[0]*t+(ace[0]/2)*pow(t,2);
    pos[1]+=vel[1]*t+(ace[1]/2)*pow(t,2);
    vel[0]+=ace[0]*t;
    vel[1]+=ace[1]*t;
    setpos(pos[0],pos[1]);
}

QRectF planet::boundingRect() const
{
    return QRectF(-rad,-rad,2*rad,2*rad);
}

void planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isselected=='1')
    {
        painter->setBrush(Qt::darkCyan);
        painter->drawEllipse(boundingRect());
    }
    else if(mass>1000)
    {
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(boundingRect());
    }
    else if(mass>100)
    {
        painter->setBrush(Qt::red);
        painter->drawEllipse(boundingRect());
    }
    else
    {
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());
    }

}

