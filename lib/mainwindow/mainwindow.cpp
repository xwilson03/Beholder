#include <QLayout>
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>

#include "mainwindow.h"
#include "nameplate.h"
#include "statpanel.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Beholder");
    setMinimumSize(400, 300);

    QSplitter *centralWidget = new QSplitter(this);
    setCentralWidget(centralWidget);


    const int sidebar_width = 100;

    std::string default_name  = "Default Name";
    int         default_level = 0;
    std::string default_class = "Fighter";
    std::string default_race  = "Human";



    QWidget* leftSidebar = new QWidget(this);
    leftSidebar->setMinimumWidth(sidebar_width);
    QVBoxLayout* leftLayout = new QVBoxLayout(leftSidebar);
    leftSidebar->setLayout(leftLayout);

    leftLayout->addWidget(
        new NamePlate(
            default_name,
            default_level,
            default_class,
            default_race,
            leftSidebar
        )
    );

    leftLayout->addWidget(
        new StatPanel(
            leftSidebar
        )
    );

    leftLayout->addStretch(1);


    QWidget *centralArea = new QWidget(this);


    QWidget *rightSidebar = new QWidget(this);
    rightSidebar->setMinimumWidth(sidebar_width);
    QVBoxLayout* rightLayout = new QVBoxLayout(rightSidebar);
    rightSidebar->setLayout(rightLayout);

    rightLayout->addStretch(1);


    centralWidget->addWidget(leftSidebar);
    centralWidget->addWidget(centralArea);
    centralWidget->addWidget(rightSidebar);
}
