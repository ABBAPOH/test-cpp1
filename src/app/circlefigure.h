#ifndef CIRCLEFIGURE_H
#define CIRCLEFIGURE_H

#include "abstractfigure.h"

class CircleFigure : public AbstractFigure
{
public:
    CircleFigure(int x, int y, int radius);
    ~CircleFigure();

    void draw(QPainter *painter);

private:
    int _radius {0};
};

#endif // CIRCLEFIGURE_H
