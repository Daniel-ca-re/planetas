#include "planet.h"
#include <cmath>

planet::planet()
{

}

planet::planet(float m, std::array<float, 2> p, std::array<float, 2> v)
{
    mass=m;
    ace[0]=0;
    ace[1]=0;
    vel=v;
    pos=p;
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
    pos[1]=y;
    pos[0]=x;
}

void planet::setvel(float x, float y)
{
    vel[1]=y;
    vel[0]=x;
}

void planet::setacewithforce(float x, float y)
{
    ace[1]=y/mass;
    ace[0]=x/mass;
}

void planet::Advance(float t)
{
    pos[0]+=vel[0]*t+(ace[0]/2)*pow(t,2);
    pos[1]+=vel[1]*t+(ace[1]/2)*pow(t,2);
}

QRectF planet::boundingRect() const
{
    return QRectF(-rad,-rad,2*rad,2*rad);
}

void planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
