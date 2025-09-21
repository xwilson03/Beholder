#include "nameplate_controller.h"

#include "store.h"

NamePlateController::NamePlateController(
    NamePlate* aView,
    Store& aStore,
    QObject* parent
)
: QObject(parent)
, mView(aView)
, mStore(aStore)
{
    connect(
        &mStore, &Store::stateChanged,
        this, &NamePlateController::onStateChanged
    );
}

void NamePlateController::onStateChanged() {

    std::string name;
    int         level;
    std::string characterClass;
    std::string race;

    {
        auto state = mStore.getState();

        name           = state->name;
        level          = state->level;
        characterClass = state->characterClass;
        race           = state->race;
    }

    mView->setName(name);
    mView->setLevel(level);
    mView->setClass(characterClass);
    mView->setRace(race);

    mView->updateNameLabel();
    mView->updateSplashLabel();
}
