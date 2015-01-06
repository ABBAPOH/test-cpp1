#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include "ifigure.h"

#include <QtWidgets/QWidget>
#include <QtCore/QVector>

#include <memory>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // Can't use QVector as long as it doesn't have emplace_back
    std::vector<std::unique_ptr<IFigure>> _figures;
};

#endif // CENTRALWIDGET_H
