#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QStackedLayout>

#include "map.h"
#include "topbar.h"


MainWindow::MainWindow(
    QWidget* parent
)
: QMainWindow(parent)
{
    setMinimumSize(680, 480);
    resize(800, 600);

    // Central Widget
    auto main_widget = new QWidget();
    setCentralWidget(main_widget);

    auto main_layout = new QVBoxLayout();
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_widget->setLayout(main_layout);

    // Layout
    auto topbar = new Topbar();
    main_layout->addWidget(topbar, 0);

    auto page_display = new QStackedLayout();
    main_layout->addLayout(page_display, 1);

    // Content
    auto map_page = new Map();
    page_display->addWidget(map_page);
}
