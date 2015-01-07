#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include <IPlugin>
#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include <QtCore/QVector>

class BasePlugin : public QObject, public IPlugin
{
    Q_OBJECT
    Q_DISABLE_COPY(BasePlugin)
    Q_INTERFACES(IPlugin)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface")
public:
    explicit BasePlugin(QObject *parent = 0);
    ~BasePlugin();

    QVector<IFigureFactory *> factories() const override;

private:
    QVector<IFigureFactory *> _factories;
};

#endif // BASEPLUGIN_H
