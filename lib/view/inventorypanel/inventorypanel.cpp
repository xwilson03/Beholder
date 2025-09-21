#include <QHBoxLayout>
#include <QVBoxLayout>

#include "panel.h"
#include "badge.h"
#include "inventorypanel.h"


InventoryPanel::InventoryPanel(
    QWidget *parent
)
: Panel("Inventory", parent)
{
    mContent = new QWidget();
    mContent->setObjectName("inventoryPanelContent");
    setContent(mContent);

    QVBoxLayout* layout = new QVBoxLayout();
    mContent->setLayout(layout);

    layout->setSpacing(0);
}

void InventoryPanel::clearItems() {
    QLayoutItem* item = nullptr;
    while ((item = mContent->layout()->takeAt(0)) != nullptr) {
        assert(!item->layout());
        dynamic_cast<QWidget*>(item)->deleteLater();
    }
}

void InventoryPanel::addItem(
    std::string name,
    std::string category,
    bool equipped
)
{
    QWidget* inventoryItem = new QWidget();
    inventoryItem->setObjectName("inventoryItem");

    QHBoxLayout* inventoryItemLayout = new QHBoxLayout();
    inventoryItemLayout->setContentsMargins(0,0,0,0);
    inventoryItem->setLayout(inventoryItemLayout);

    QWidget* inventoryText = new QWidget();
    inventoryText->setObjectName("inventoryText");

    QVBoxLayout* inventoryTextLayout = new QVBoxLayout();
    inventoryText->setLayout(inventoryTextLayout);

    QLabel* inventoryLabel = new QLabel(name.c_str());
    inventoryLabel->setObjectName("inventoryNameLabel");

    QLabel* inventoryCategoryLabel = new QLabel(category.c_str());
    inventoryCategoryLabel->setObjectName("inventoryCategoryLabel");

    inventoryTextLayout->addWidget(inventoryLabel);
    inventoryTextLayout->addWidget(inventoryCategoryLabel);

    Badge* inventoryBadge;
    if (equipped) {
        inventoryBadge = new Badge();
        inventoryBadge->setText("Equipped");
    }

    inventoryItemLayout->addWidget(inventoryText);
    inventoryItemLayout->addStretch();
    if (equipped) {
        inventoryItemLayout->addWidget(inventoryBadge, 0, Qt::AlignVCenter);
    }

    mContent->layout()->addWidget(inventoryItem);
}
