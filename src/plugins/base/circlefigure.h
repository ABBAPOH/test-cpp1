#ifndef CIRCLEFIGURE_H
#define CIRCLEFIGURE_H

#include "abstractfigure.h"
#include <IFigureFactory>

#include <QtCore/QCoreApplication>

class CircleFigure : public AbstractFigure
{
public:
    CircleFigure(int x, int y, int radius);
    ~CircleFigure();

    void draw(QPainter *painter);

private:
    int _radius {0};
};

class CircleFigureFactory : public IFigureFactory
{
    Q_DECLARE_TR_FUNCTIONS(CircleFigureFactory)
    Q_DISABLE_COPY(CircleFigureFactory)
public:
    CircleFigureFactory() = default;

    // IFigureFactory interface
    QString name() const;
    QString toolTip() const;
    IFigure *create(int x, int y);
};

#endif // CIRCLEFIGURE_H
