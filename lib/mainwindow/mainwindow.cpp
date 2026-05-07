#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedLayout>

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
    auto topbar = new QHBoxLayout();
    main_layout->addLayout(topbar, 0);

    auto page_display = new QStackedLayout();
    main_layout->addLayout(page_display, 1);

    // Navigation
    auto navbar = new QWidget();
    topbar->addWidget(navbar, 1);

    auto navbar_layout = new QHBoxLayout();
    navbar_layout->setAlignment(Qt::AlignLeft);
    navbar->setLayout(navbar_layout);

    const auto page_names = {"Character", "Map", "Wiki", "Save & Exit"};
    for (const auto& page_name : page_names) {
        auto page_label = new QLabel(page_name);
        navbar_layout->addWidget(page_label);
    }

    // Area Label
    const auto area_name = "Gravekeeper's Tomb";
    auto area_label = new QLabel(area_name);
    topbar->addWidget(area_label, 0);

    // Encounter Status
    auto encounter_status = new QWidget();
    topbar->addWidget(encounter_status, 1);

    auto encounter_status_layout = new QHBoxLayout();
    encounter_status_layout->setAlignment(Qt::AlignRight);
    encounter_status->setLayout(encounter_status_layout);

    auto encounter_stage_badge = new QLabel("Combat");
    encounter_status_layout->addWidget(encounter_stage_badge);

    auto encounter_round_badge = new QLabel("Round: 5");
    encounter_status_layout->addWidget(encounter_round_badge);

    auto encounter_turn_badge = new QLabel("Your Turn");
    encounter_status_layout->addWidget(encounter_turn_badge);

    // Content
    auto map_graphics_scene = new QGraphicsScene();
    auto map_page = new QGraphicsView(map_graphics_scene);
    page_display->addWidget(map_page);
}
