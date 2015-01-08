#include "baseplugin.h"

#include "circlefigure.h"
#include "squarefigure.h"
#include "trianglefigure.h"

BasePlugin::BasePlugin(QObject *parent) : QObject(parent)
{
    _factories.append(new CircleFigureFactory);
    _factories.append(new SquareFigureFactory);
    _factories.append(new TriangleFigureFactory);
}

BasePlugin::~BasePlugin()
{
    qDeleteAll(_factories);
}

QVector<IFigureFactory *> BasePlugin::factories() const
{
    return _factories;
}

