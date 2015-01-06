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

QString CircleFigureFactory::name() const
{
    return tr("Circle");
}

QString CircleFigureFactory::toolTip() const
{
    return tr("Creates a circle with random radius");
}

IFigure *CircleFigureFactory::create(int x, int y)
{
    return new CircleFigure(x, y, qrand() % 90 + 10);
}
