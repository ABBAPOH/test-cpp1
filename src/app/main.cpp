#include "mainwindow.h"

#include "figuremanager.h"
#include "circlefigure.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CircleFigureFactory factory1;
    FigureManager manager;
    manager.addFactory(&factory1);

    MainWindow window;
    window.show();

    return app.exec();
}
