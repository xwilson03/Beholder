#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QStackedLayout>

#include "map.h"
#include "topbar.h"


MainWindow::MainWindow(
    QWidget* aParent
)
: QMainWindow(aParent)
{
    setMinimumSize(680, 480);
    resize(800, 600);

    // Central Widget
    auto mainWidget = new QWidget();
    setCentralWidget(mainWidget);

    auto mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainWidget->setLayout(mainLayout);

    // Layout
    auto topbar = new Topbar();
    mainLayout->addWidget(topbar, 0);

    auto pageDisplay = new QStackedLayout();
    mainLayout->addLayout(pageDisplay, 1);

    // Content
    auto mapPage = new Map();
    pageDisplay->addWidget(mapPage);
}
