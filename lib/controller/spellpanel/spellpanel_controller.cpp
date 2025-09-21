#include "spellpanel_controller.h"

#include "store.h"

SpellPanelController::SpellPanelController(
    SpellPanel* aView,
    Store&     aStore,
    QObject*   parent
)
: QObject(parent)
, mView(aView)
, mStore(aStore)
{
    connect(
        &mStore, &Store::stateChanged,
        this, &SpellPanelController::onStateChanged
    );
}

void SpellPanelController::onStateChanged() {

    std::map<
        uint8_t, State::SpellLevel
    > spellLevels = {};
    {
        auto state = mStore.getState();
        spellLevels = state->spellLevels;
    }

    mView->clearSpellLevels();
    for (const auto [level, spellSlots] : spellLevels) {
        mView->addSpellLevel(
            level,
            spellSlots.spellSlots,
            spellSlots.maxSpellSlots
        );
    }
}
