#ifndef TRIANGLEFIGURE_H
#define TRIANGLEFIGURE_H

#include "abstractfigure.h"

#include <IFigureFactory>

#include <QtCore/QCoreApplication>

class TriangleFigure : public AbstractFigure
{
public:
    TriangleFigure(int x, int y, int size, qreal rotation);

    // IFigure interface
    void draw(QPainter *painter);

private:
    int _size {0};
    qreal _rotation {0};
};

class TriangleFigureFactory : public IFigureFactory
{
    Q_DECLARE_TR_FUNCTIONS(TriangleFigureFactory)
    Q_DISABLE_COPY(TriangleFigureFactory)
public:
    TriangleFigureFactory() = default;

    // IFigureFactory interface
    QString name() const;
    QString toolTip() const;
    IFigure *create(int x, int y);
};

#endif // TRIANGLEFIGURE_H
