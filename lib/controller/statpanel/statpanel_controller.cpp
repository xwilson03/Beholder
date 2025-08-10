#include "statpanel_controller.h"

#include "store.h"

StatPanelController::StatPanelController(
    StatPanel* aView,
    Store&     aStore,
    QObject*   parent
)
: QObject(parent)
, mView(aView)
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

    mView->setStrength(strength);
    mView->setDexterity(dexterity);
    mView->setConstitution(constitution);
    mView->setIntelligence(intelligence);
    mView->setWisdom(wisdom);
    mView->setCharisma(charisma);
}
