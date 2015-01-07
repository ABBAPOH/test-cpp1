#ifndef SQUAREFIGURE_H
#define SQUAREFIGURE_H

#include "abstractfigure.h"
#include "ifigurefactory.h"

#include <QtCore/QCoreApplication>

class SquareFigure : public AbstractFigure
{
    Q_DISABLE_COPY(SquareFigure)
public:
    SquareFigure(int x, int y, int size);

    void draw(QPainter *painter);

private:
    int _size;
};

class SquareFigureFactory : public IFigureFactory
{
    Q_DECLARE_TR_FUNCTIONS(SquareFigureFactory)
    Q_DISABLE_COPY(SquareFigureFactory)
public:
    SquareFigureFactory() = default;

    // IFigureFactory interface
    QString name() const;
    QString toolTip() const;
    IFigure *create(int x, int y);
};

#endif // SQUAREFIGURE_H
