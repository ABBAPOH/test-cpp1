#ifndef IPLUGIN
#define IPLUGIN

#include <QtPlugin>

class IFigureFactory;

class IPlugin
{
    Q_DISABLE_COPY(IPlugin)
public:
    IPlugin() = default;
    virtual ~IPlugin() {}

    virtual QVector<IFigureFactory *> factories() const = 0;
};

Q_DECLARE_INTERFACE(IPlugin, "com.arch.Test-Cpp1.IPlugin")

#endif // IPLUGIN

