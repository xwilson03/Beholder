#include <QMainWindow>
#include <QWidget>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Beholder");
    setMinimumSize(400, 300);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
}
