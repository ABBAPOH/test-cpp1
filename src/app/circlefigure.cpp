#include "circlefigure.h"

#include <QtGui/QPainter>

CircleFigure::CircleFigure(int x, int y, int radius) :
    AbstractFigure(x, y),
    _radius(radius)
{

}

CircleFigure::~CircleFigure()
{

}

void CircleFigure::draw(QPainter *painter)
{
    QRect rect(x() - _radius, y() - _radius, 2*_radius, 2*_radius);
    painter->drawArc(rect, 0, 16*360);
}

