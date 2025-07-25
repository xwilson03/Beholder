#include <QLayout>
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Beholder");
    setMinimumSize(400, 300);

    QSplitter *centralWidget = new QSplitter(this);
    setCentralWidget(centralWidget);


    const int sidebar_width = 100;


    QWidget *leftSidebar = new QWidget(this);
    leftSidebar->setMinimumWidth(sidebar_width);
    leftSidebar->setLayout(new QVBoxLayout(leftSidebar));

    QWidget *centralArea = new QWidget(this);

    QWidget *rightSidebar = new QWidget(this);
    rightSidebar->setMinimumWidth(sidebar_width);
    rightSidebar->setLayout(new QVBoxLayout(rightSidebar));


    centralWidget->addWidget(leftSidebar);
    centralWidget->addWidget(centralArea);
    centralWidget->addWidget(rightSidebar);
}
