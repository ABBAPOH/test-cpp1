#include "centralwidget.h"

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

    for (const auto circle : _arr) {
        const auto radius = circle.radius;
        QRect rect(circle.x - radius, circle.y - radius, 2*radius, 2*radius);
        painter.drawArc(rect, 0, 16*360);
    }
}

void CentralWidget::mouseReleaseEvent(QMouseEvent *event)
{
    auto circle = CircleFigure(event->x(), event->y(), qrand() % 90 + 10);
    _arr.append(circle);
    update();
}

