#include "centralwidget.h"

#include "circlefigure.h"

#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>

#include <QtCore/QDateTime>
#include <QDebug>

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
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
    _figures.emplace_back(new CircleFigure(event->x(), event->y(), qrand() % 90 + 10));
    update();
}

