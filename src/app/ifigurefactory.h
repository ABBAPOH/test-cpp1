#ifndef IFIGUREFACTORY
#define IFIGUREFACTORY

#include <qglobal.h>
#include <QtCore/QString>

class IFigure;

class IFigureFactory
{
    Q_DISABLE_COPY(IFigureFactory)
public:
    IFigureFactory() = default;
    virtual ~IFigureFactory() {}

    virtual QString name() const = 0;
    virtual QString toolTip() const = 0;
    virtual IFigure *create(int x, int y) = 0;
};

#endif // IFIGUREFACTORY

