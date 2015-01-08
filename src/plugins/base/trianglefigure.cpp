#include "trianglefigure.h"

#include <QtGui/QPainter>
#include <QtCore/QPoint>

#include <qmath.h>

TriangleFigure::TriangleFigure(int x, int y, int size, qreal rotation) :
    AbstractFigure(x, y),
    _size(size),
    _rotation(rotation)
{

}

void TriangleFigure::draw(QPainter *painter)
{
    static const auto square3 = qSqrt(3.0);

    painter->save();

    QTransform matrix;
    matrix.translate(x(), y());
    matrix.rotate(_rotation);
    painter->setTransform(matrix);

    const QPoint top(0, - _size/square3);
    const QPoint left(- _size/2, _size/2/square3);
    const QPoint right(+ _size/2, _size/2/square3);

    painter->drawLine(top, left);
    painter->drawLine(left, right);
    painter->drawLine(right, top);

    painter->restore();
}

QString TriangleFigureFactory::name() const
{
    return tr("Triangle");
}

QString TriangleFigureFactory::toolTip() const
{
    return tr("Create triangle");
}

IFigure *TriangleFigureFactory::create(int x, int y)
{
    return new TriangleFigure(x, y, qrand() % 140 + 10, qrand() % 360);
}
