#include "topbar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>


Topbar::Topbar(
    QWidget* aParent
)
: QWidget(aParent)
{
    // Layout
    auto mainLayout = new QHBoxLayout();
    setLayout(mainLayout);

    // Navigation
    auto navbar = new QWidget();
    mainLayout->addWidget(navbar, 1);

    auto navbarLayout = new QHBoxLayout();
    navbarLayout->setAlignment(Qt::AlignLeft);
    navbar->setLayout(navbarLayout);

    const auto pageNames = {"Character", "Map", "Wiki", "Save & Exit"};
    for (const auto& pageName : pageNames) {
        auto pageLabel = new QLabel(pageName);
        navbarLayout->addWidget(pageLabel);
    }

    // Area Label
    const auto areaName = "Gravekeeper's Tomb";
    auto areaLabel = new QLabel(areaName);
    mainLayout->addWidget(areaLabel, 0);

    // Encounter Status
    auto encounterStatus = new QWidget();
    mainLayout->addWidget(encounterStatus, 1);

    auto encounterStatusLayout = new QHBoxLayout();
    encounterStatusLayout->setAlignment(Qt::AlignRight);
    encounterStatus->setLayout(encounterStatusLayout);

    auto encounterStageBadge = new QLabel("Combat");
    encounterStatusLayout->addWidget(encounterStageBadge);

    auto encounterRoundBadge = new QLabel("Round: 5");
    encounterStatusLayout->addWidget(encounterRoundBadge);

    auto encounterTurnBadge = new QLabel("Your Turn");
    encounterStatusLayout->addWidget(encounterTurnBadge);
}
