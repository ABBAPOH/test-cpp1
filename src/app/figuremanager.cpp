#include "figuremanager.h"

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QCoreApplication>
#include <QtCore/QPluginLoader>

#include "iplugin.h"

static FigureManager *m_instance = nullptr;

FigureManager::FigureManager()
{
    Q_ASSERT_X(!m_instance, "FigureManager::FigureManager", "FigureManager is already created");
    m_instance = this;
    loadPlugins();
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

static QString getRootPath()
{
    // Figure out root:  Up one from 'bin' or 'MacOs'
    QDir rootDir = QCoreApplication::applicationDirPath();
    rootDir.cdUp();
    return rootDir.canonicalPath();
}

static inline QString getPluginPath()
{
    const QString rootDirPath = getRootPath();
    // Build path
    QString pluginPath = rootDirPath;
#if defined Q_OS_MACX
    pluginPath += QLatin1Char('/');
    pluginPath += QLatin1String("PlugIns");
#elif defined Q_OS_WIN
    pluginPath += QLatin1Char('/');
    pluginPath += QLatin1String("plugins");
#elif defined Q_OS_UNIX
    // not Mac UNIXes
    pluginPath += QLatin1Char('/');
    pluginPath += QLatin1String("lib");
    pluginPath += QLatin1String(LIB_SUFFIX);
    pluginPath += QLatin1Char('/');
    pluginPath += QLatin1String("andromeda");
    pluginPath += QLatin1Char('/');
    pluginPath += QLatin1String("plugins");
#endif
    return pluginPath;
}

void FigureManager::loadPlugins()
{
    QDir pluginsDir(getPluginPath());
    for (const auto &pluginName : pluginsDir.entryList(QDir::NoDotDot | QDir::Files)) {
        const auto path = pluginsDir.absoluteFilePath(pluginName);
        QPluginLoader loader(path);
        if (!loader.load()) {
            qWarning() << "can't load" << path << ":" << loader.errorString();
            continue;
        }
        auto instance = loader.instance();
        if (!instance) {
            qWarning() << "Can't get instance object from" << path;
            continue;
        }
        auto plugin = qobject_cast<IPlugin *>(instance);
        if (!plugin) {
            qWarning() << "Can't cast instance object to IPlugin interface for" << path;
            continue;
        }

        for (auto factory : plugin->factories()) // QVector doesn't support range append:(
            _factories.append(factory);
    }
}

