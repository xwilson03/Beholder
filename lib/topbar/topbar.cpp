#include "topbar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>


Topbar::Topbar(
    QWidget* parent
)
: QWidget(parent)
{
    // Layout
    auto main_layout = new QHBoxLayout();
    setLayout(main_layout);

    // Navigation
    auto navbar = new QWidget();
    main_layout->addWidget(navbar, 1);

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
    main_layout->addWidget(area_label, 0);

    // Encounter Status
    auto encounter_status = new QWidget();
    main_layout->addWidget(encounter_status, 1);

    auto encounter_status_layout = new QHBoxLayout();
    encounter_status_layout->setAlignment(Qt::AlignRight);
    encounter_status->setLayout(encounter_status_layout);

    auto encounter_stage_badge = new QLabel("Combat");
    encounter_status_layout->addWidget(encounter_stage_badge);

    auto encounter_round_badge = new QLabel("Round: 5");
    encounter_status_layout->addWidget(encounter_round_badge);

    auto encounter_turn_badge = new QLabel("Your Turn");
    encounter_status_layout->addWidget(encounter_turn_badge);
}
