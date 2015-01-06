#include "figuremanager.h"

static FigureManager *m_instance = nullptr;

FigureManager::FigureManager()
{
    Q_ASSERT_X(!m_instance, "FigureManager::FigureManager", "FigureManager is already created");
    m_instance = this;
}

FigureManager::~FigureManager()
{
    m_instance = nullptr;
}

FigureManager *FigureManager::instance()
{
    return m_instance;
}

QVector<IFigureFactory *> FigureManager::factories() const
{
    return _factories;
}

void FigureManager::addFactory(IFigureFactory *factory)
{
    if (_factories.contains(factory))
        return;
    _factories.append(factory);
}

