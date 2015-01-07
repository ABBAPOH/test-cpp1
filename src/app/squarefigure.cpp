#include "squarefigure.h"

#include <QtGui/QPainter>

SquareFigure::SquareFigure(int x, int y, int size) :
    AbstractFigure(x, y),
    _size(size)
{
}

void SquareFigure::draw(QPainter *painter)
{
    const QRect rect(x() - _size, y() - _size, 2*_size, 2*_size);
    painter->drawRect(rect);
}



QString SquareFigureFactory::name() const
{
    return tr("Square");
}

QString SquareFigureFactory::toolTip() const
{
    return tr("Create square");
}

IFigure *SquareFigureFactory::create(int x, int y)
{
    return new SquareFigure(x, y, qrand() % 180 + 20);
}
