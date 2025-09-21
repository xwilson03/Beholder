#include <QObject>

#include "store.h"

Store::Store(QObject* parent)
 : QObject(parent)
{
    mState.name = "Default Name";
    mState.level = 0;
    mState.characterClass = "Fighter";
    mState.race = "Human";

    mState.abilityScores.strength = 0;
    mState.abilityScores.dexterity = 0;
    mState.abilityScores.constitution = 0;
    mState.abilityScores.intelligence = 0;
    mState.abilityScores.wisdom = 0;
    mState.abilityScores.charisma = 0;

    mState.combatStats.HP = 0;
    mState.combatStats.maxHP = 0;
    mState.combatStats.tempHP = 0;
    mState.combatStats.AC = 0;
    mState.combatStats.initiative = 0;
    mState.combatStats.speed = 0;

    mState.features = {
        {
            "Action Surge",
            "Combat",
            false, 1, 1
        },
        {
            "Second Wind",
            "Healing",
            false, 0, 1
        },
        {
            "Fighting Style",
            "Combat",
            true, 0, 0
        }
    };
}

Store::Accessor Store::getState()
{
    return Store::Accessor(mLock, mState);
}

Store::Accessor::Accessor(
    std::mutex &aLock,
    const State &aState
)
: mLock(aLock)
, mState(aState)
{
}

const State* Store::Accessor::operator->() const
{
    return &mState;
}
