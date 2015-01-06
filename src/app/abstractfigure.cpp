#include "abstractfigure.h"

AbstractFigure::AbstractFigure()
{
}

AbstractFigure::AbstractFigure(int x, int y) :
    _x(x),
    _y(y)
{
}

AbstractFigure::~AbstractFigure()
{

}

void AbstractFigure::draw(QPainter *painter)
{
    Q_UNUSED(painter);
}

