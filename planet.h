#ifndef PLANET_H
#define PLANET_H
#include <QGraphicsItem>
#include <QPainter>
#include <array>


class planet : public QGraphicsItem
{
protected:

    float mass;
    std::array <float,2> pos;
    std::array <float,2> vel;
    std::array <float,2> ace;
    float rad;

public:
    planet();
    planet(float m,std::array <float,2>p,std::array <float,2> v);
    std::array <float,2> getpos();
    std::array <float,2> getvel();
    std::array <float,2> getace();
    float getmass();
    float getrad();
    void setmass(float);
    void setpos(float x,float y);
    void setvel(float x,float y);
    void setacewithforce(float x,float y);
    void Advance(float t);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);




public slots:

};

#endif // PLANET_H
