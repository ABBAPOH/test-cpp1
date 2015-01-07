#include "mainwindow.h"

#include "figuremanager.h"
#include "circlefigure.h"
#include "squarefigure.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CircleFigureFactory factory1;
    SquareFigureFactory factory2;
    FigureManager manager;
    manager.addFactory(&factory1);
    manager.addFactory(&factory2);

    MainWindow window;
    window.show();

    return app.exec();
}
