#ifndef IFIGURE
#define IFIGURE

#include <qglobal.h>

class QPainter;

class IFigure
{
    Q_DISABLE_COPY(IFigure)
public:
    IFigure() = default;
    virtual ~IFigure() {}

    virtual void draw(QPainter *painter) = 0;
};

#endif // IFIGURE

