#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <IFigure>

class AbstractFigure : public IFigure
{
public:
    AbstractFigure();
    AbstractFigure(int x, int y);
    ~AbstractFigure();

    void draw(QPainter *painter) override;

    inline int x() const { return _x; }
    inline int y() const { return _y; }

private:
    int _x {0};
    int _y {0};
};

#endif // ABSTRACTFIGURE_H
