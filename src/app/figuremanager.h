#ifndef FIGUREMANAGER_H
#define FIGUREMANAGER_H

#include "ifigurefactory.h"

#include <QVector>

class FigureManager
{
public:
    FigureManager();
    ~FigureManager();

    static FigureManager *instance();

    QVector<IFigureFactory *> factories() const;

private:
    void loadPlugins();

private:
    QVector<IFigureFactory *> _factories;
};

#endif // FIGUREMANAGER_H
