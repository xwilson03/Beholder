#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>

MainWindow::MainWindow(
    QWidget* parent
)
: QMainWindow(parent)
{

    setStyleSheet(
        "min-width: 640px;"
        "min-height: 480px;"
    );

    auto main_widget = new QWidget();
    setCentralWidget(main_widget);

    auto main_layout = new QVBoxLayout();
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_widget->setLayout(main_layout);

    auto topbar = new QHBoxLayout();
    main_layout->addLayout(topbar, 0);

    auto page_display = new QStackedWidget();
    page_display->setStyleSheet("background-color: white;");
    main_layout->addWidget(page_display, 1);

    auto main_page = new QWidget();
    page_display->addWidget(main_page);
}
