#include <QHBoxLayout>
#include <QVBoxLayout>

#include "panel.h"
#include "badge.h"
#include "spellpanel.h"


SpellPanel::SpellPanel(
    QWidget *parent
)
: Panel("Spell Levels", parent)
{
    mContent = new QWidget();
    mContent->setObjectName("spellPanelContent");
    setContent(mContent);

    QVBoxLayout* layout = new QVBoxLayout();
    mContent->setLayout(layout);

    layout->setSpacing(0);
}

void SpellPanel::clearSpellLevels() {
    QLayoutItem* item = nullptr;
    while ((item = mContent->layout()->takeAt(0)) != nullptr) {
        assert(!item->layout());
        dynamic_cast<QWidget*>(item)->deleteLater();
    }
}

void SpellPanel::addSpellLevel(
    uint8_t level,
    uint8_t spellSlots,
    uint8_t maxSpellSlots
)
{
    QWidget* spellLevel = new QWidget();
    spellLevel->setObjectName("spellLevel");

    QHBoxLayout* spellLevelLayout = new QHBoxLayout();
    spellLevelLayout->setContentsMargins(0,0,0,0);
    spellLevel->setLayout(spellLevelLayout);

    QLabel* spellLabel = new QLabel((std::string("Level ") + std::to_string(level)).c_str());
    spellLabel->setObjectName("spellLevelLabel");

    QWidget* spellSlotBubbles = new QWidget();
    spellSlotBubbles->setObjectName("spellSlotBubbles");

    QHBoxLayout* spellSlotBubblesLayout = new QHBoxLayout();
    spellSlotBubbles->setLayout(spellSlotBubblesLayout);

    for (uint8_t i = 0; i < maxSpellSlots; i++) {

        QFrame* bubble = new QFrame();

        std::string color = (i < spellSlots) ? "purple" : "whitesmoke";

        bubble->setFixedSize(18, 18);
        bubble->setStyleSheet(
            "QFrame {"
                "background-color: " + QString(color.c_str()) + ";"
                "border: 1px solid gainsboro;"
                "border-radius: 9px;"
            "}"
        );

        spellSlotBubblesLayout->addWidget(bubble);
    }

    spellLevelLayout->addWidget(spellLabel);
    spellLevelLayout->addStretch();
    spellLevelLayout->addWidget(spellSlotBubbles, 0, Qt::AlignVCenter);

    mContent->layout()->addWidget(spellLevel);
}
