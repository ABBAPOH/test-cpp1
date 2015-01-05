#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtWidgets/QWidget>
#include <QtCore/QVector>

struct CircleFigure
{
    CircleFigure() {}
    CircleFigure(int x, int y, int r) : x(x), y(y), radius(r) {}

    int x {0};
    int y {0}; // X, Y coordinates of circle center;
    int radius {0}; // Circle radius
};

static const int CircleCount = 10;

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
    QVector<CircleFigure> _arr;
};

#endif // CENTRALWIDGET_H
