#include "mainwindow.h"

#include "figuremanager.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FigureManager manager;
    Q_UNUSED(manager);

    MainWindow window;
    window.show();

    return app.exec();
}
