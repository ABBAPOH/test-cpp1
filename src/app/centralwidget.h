#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include "ifigure.h"

#include <QtWidgets/QWidget>
#include <QtCore/QVector>

#include <memory>

class IFigureFactory;
class QActionGroup;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

    inline QList<QAction *> toolbarActions() const { return _toolbarActions; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void createActions();

private slots:
    void onActionTriggered();

private:
    // Can't use QVector as long as it doesn't have emplace_back
    std::vector<std::unique_ptr<IFigure>> _figures;
    QList<QAction *> _toolbarActions;
    QActionGroup *_toolbarGroup;
    IFigureFactory *_currentFactory {Q_NULLPTR};
};

#endif // CENTRALWIDGET_H
