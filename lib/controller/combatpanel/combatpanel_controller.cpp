#include "combatpanel_controller.h"

#include "store.h"

CombatPanelController::CombatPanelController(
    CombatPanel* aView,
    Store& aStore,
    QObject* parent
)
: QObject(parent)
, mView(aView)
, mStore(aStore)
{

    int HP;
    int maxHP;
    int tempHP;
    int AC;
    int initiative;
    int speed;

    {
        auto state = mStore.getState();

        HP         = state->combatStats.HP;
        maxHP      = state->combatStats.maxHP;
        tempHP     = state->combatStats.tempHP;
        AC         = state->combatStats.AC;
        initiative = state->combatStats.initiative;
        speed      = state->combatStats.speed;
    }

    mView->setHP(HP);
    mView->setMaxHP(maxHP);
    mView->setTempHP(tempHP);
    mView->setAC(AC);
    mView->setInitiative(initiative);
    mView->setSpeed(speed);

    mView->updateHPBadge();
    mView->updateTempHPBadge();
    mView->updateACBadge();
    mView->updateInitiativeBadge();
    mView->updateSpeedBadge();
}
