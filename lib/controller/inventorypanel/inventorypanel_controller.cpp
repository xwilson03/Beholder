#include "inventorypanel_controller.h"

#include "store.h"
#include <iostream>

InventoryPanelController::InventoryPanelController(
    InventoryPanel* aView,
    Store&     aStore,
    QObject*   parent
)
: QObject(parent)
, mView(aView)
, mStore(aStore)
{
    connect(
        &mStore, &Store::stateChanged,
        this, &InventoryPanelController::onStateChanged
    );
}

void InventoryPanelController::onStateChanged() {

    std::vector<State::Item> items = {};
    {
        auto state = mStore.getState();
        items = state->items;
    }

    mView->clearItems();
    for (const auto item : items) {
        mView->addItem(
            item.name,
            item.category,
            item.equipped
        );
    }
}
