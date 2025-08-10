#include "statpanel_controller.h"

#include "store.h"

StatPanelController::StatPanelController(
    StatBox* aStrView,
    StatBox* aDexView,
    StatBox* aConView,
    StatBox* aIntView,
    StatBox* aWisView,
    StatBox* aChaView,
    Store&     aStore,
    QObject*   parent
)
: QObject(parent)
, mStrView(aStrView)
, mDexView(aDexView)
, mConView(aConView)
, mIntView(aIntView)
, mWisView(aWisView)
, mChaView(aChaView)
, mStore(aStore)
{

    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

    {
        auto state = mStore.getState();

        strength     = state->abilityScores.strength;
        dexterity    = state->abilityScores.dexterity;
        constitution = state->abilityScores.constitution;
        intelligence = state->abilityScores.intelligence;
        wisdom       = state->abilityScores.wisdom;
        charisma     = state->abilityScores.charisma;
    }

    mStrView->setValue(strength);
    mDexView->setValue(dexterity);
    mConView->setValue(constitution);
    mIntView->setValue(intelligence);
    mWisView->setValue(wisdom);
    mChaView->setValue(charisma);
}
