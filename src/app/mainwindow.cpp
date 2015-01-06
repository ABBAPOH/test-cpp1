#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "centralwidget.h"

#include <QtWidgets/QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
    auto widget = new CentralWidget(this);
    ui->toolBar->addActions(widget->toolbarActions());
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About"), tr("This is the sample program"));
}

void MainWindow::setupConnections()
{
    connect(ui->actionQuit, &QAction::triggered, qApp, &QApplication::quit);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
}
