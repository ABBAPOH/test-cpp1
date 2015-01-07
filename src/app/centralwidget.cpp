#include "centralwidget.h"

#include "figuremanager.h"

#include <QtWidgets/QActionGroup>

#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>

#include <QtCore/QDateTime>
#include <QDebug>

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent),
    _toolbarGroup(new QActionGroup(this))
{
    qsrand(QDateTime::currentMSecsSinceEpoch());

    createActions();
}

CentralWidget::~CentralWidget()
{

}

void CentralWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), Qt::white);

    for (const auto &figure : _figures)
        figure->draw(&painter);
}

void CentralWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (_currentFactory)
        _figures.emplace_back(_currentFactory->create(event->x(), event->y()));
    update();
}

void CentralWidget::createActions()
{
    int count = 1;
    auto manager = FigureManager::instance();
    for (auto factory : manager->factories()) {
        auto action = new QAction(this);
        action->setText(factory->name());
        action->setToolTip(factory->toolTip());
        action->setData(qintptr(factory));
        action->setCheckable(true);
        if (count < 10)
            action->setShortcut(QKeySequence(QString("Ctrl+%1").arg(count)));
        _toolbarGroup->addAction(action);
        connect(action, &QAction::triggered, this, &CentralWidget::onActionTriggered);
        if (count == 1) // select first figure by default
            action->trigger();
        _toolbarActions.append(action);
    }
}

void CentralWidget::onActionTriggered()
{
    auto action = qobject_cast<QAction *>(sender());
    _currentFactory = action ? (IFigureFactory *)(action->data().value<qintptr>()) : Q_NULLPTR;
}

